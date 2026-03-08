"""
cocotb Testbench: rv_cpu  —  Data Hazard & Control Hazard Tests
===============================================================

Tests the hazard unit's forwarding, stall, and flush logic.

Forwarding paths
----------------
  MEM→EX : producer (non-load) in MEM, consumer in EX
  WB→EX  : producer in WB, consumer in EX

Stall conditions
----------------
  is_hazard_ex  : any writing instruction in EX whose rd matches ID's rs
                  → 1 stall cycle; resolved next cycle by MEM→EX forward
  is_hazard_mem : load instruction in MEM whose rd matches ID's rs
                  → 1 stall cycle; resolved next cycle by WB→EX forward

  Stall affects IF (PC + i-reg hold) only.  The decode stage has no stall
  input, so id_ex_w re-captures the held IF/ID contents each stall cycle.

Effective hazard rules by gap (instructions between producer and consumer)
---------------------------------------------------------------------------
  0-gap non-load : 1 stall  + MEM→EX forward
  0-gap load     : 2 stalls + WB→EX forward  (is_hazard_ex then is_hazard_mem)
  1-gap non-load : 0 stalls + WB→EX forward
  1-gap load     : 1 stall  + WB→EX forward  (is_hazard_mem)
  2+ gap         : 0 stalls, consumer reads from committed register file

Branch / JAL flush
------------------
  flush_o = ex_hzd_i.is_taken
  Taken when: (is_branch & ~|alu_result) | is_jump
  BEQ is taken when rs1 == rs2  (ALU_SUB result == 0)
  Flush clears IF/ID and ID/EX → 2 shadow instructions killed

  NOTE: Only BEQ and JAL are definitively correct in the current RTL.
  BNE/BLT/BLTU branch on the wrong condition and are not tested here.

Run with:
    inv sim --testbench tb_hazard
"""

import cocotb
from cocotb.clock import Clock

import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent))
from tb_helpers import (
    CLK_PERIOD_NS, N_NOPS, PIPE_DEPTH,
    NOP, ADD, SUB, ADDI,
    LW, SW,
    BEQ, JAL,
    u32, s32,
    load_imem, do_reset, clock_n,
    write_reg, read_reg, write_dmem, read_dmem,
)


# ---------------------------------------------------------------------------
# Shared helper
# ---------------------------------------------------------------------------

async def _run(dut, program, *, reg_init={}, dmem_init={}, exp_regs={}, exp_dmem={}):
    """Load program, initialise state, run, verify registers and/or memory."""
    load_imem(dut, program)
    await do_reset(dut)
    for reg, val in reg_init.items():
        write_reg(dut, reg, val)
    for wa, val in dmem_init.items():
        write_dmem(dut, wa, val)
    await clock_n(dut, len(program) + PIPE_DEPTH)

    for reg, exp in exp_regs.items():
        got   = read_reg(dut, reg)
        exp32 = u32(exp)
        assert got == exp32, (
            f"x{reg}: expected 0x{exp32:08x} ({exp32}), got 0x{got:08x} ({got})"
        )
    for wa, exp in exp_dmem.items():
        got   = read_dmem(dut, wa)
        exp32 = u32(exp)
        assert got == exp32, (
            f"dmem[{wa}] (byte addr 0x{wa*4:04x}): "
            f"expected 0x{exp32:08x}, got 0x{got:08x}"
        )


# ===========================================================================
# Forwarding tests  (no branches, no loads)
# ===========================================================================

@cocotb.test()
async def test_fwd_0_gap_stall_mem_to_ex(dut):
    """0-gap RAW hazard: 1 stall then MEM→EX forward resolves the dependency.

    ADD x10 writes x10.  ADD x11 immediately follows and reads x10.
    The hazard unit stalls for 1 cycle so that ADD x10 advances to MEM while
    ADD x11 is in EX, then MEM→EX forwarding delivers the correct value.

        ADD x10, x1, x2   ->  10 + 20 = 30
        ADD x11, x10, x3  ->  x10 (forwarded) + 5 = 35
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [ADD(10, 1, 2)]   +  # producer
        [ADD(11, 10, 3)]  +  # consumer — 0-gap RAW on x10
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 10, 2: 20, 3: 5},
               exp_regs={10: 30, 11: 35})


@cocotb.test()
async def test_fwd_1_gap_wb_to_ex(dut):
    """1-gap RAW hazard: no stall, WB→EX forward delivers the result.

    One independent instruction separates the producer (ADD x10) from the
    consumer (ADD x11).  The hazard unit does not stall; when ADD x11 reaches
    EX the producer is already in WB and WB→EX forwarding fires.

        ADD x10, x1, x2   ->  100 + 200 = 300
        ADD x12, x3, x4   ->  1 + 2  = 3  (independent, fills the gap)
        ADD x11, x10, x3  ->  x10 (forwarded from WB) + 1 = 301
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [ADD(10, 1, 2)]   +  # producer
        [ADD(12, 3, 4)]   +  # independent gap instruction
        [ADD(11, 10, 3)]  +  # consumer — 1-gap RAW on x10
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 100, 2: 200, 3: 1, 4: 2},
               exp_regs={10: 300, 11: 301, 12: 3})


@cocotb.test()
async def test_fwd_2_gap_reg_file(dut):
    """2-gap non-hazard: producer commits to regfile before consumer reaches EX.

    Two independent instructions separate the producer from the consumer.
    No stall occurs and no forwarding path is required — the consumer reads
    the committed value directly from the register file.

        ADD x10, x1, x2   ->  7 + 3 = 10
        ADD x12, x3, x4   ->  independent gap 1
        ADD x13, x3, x4   ->  independent gap 2
        ADD x11, x10, x3  ->  10 (regfile) + 1 = 11
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [ADD(10, 1, 2)]   +  # producer
        [ADD(12, 3, 4)]   +  # independent gap 1
        [ADD(13, 3, 4)]   +  # independent gap 2
        [ADD(11, 10, 3)]  +  # consumer — 2-gap, reads from regfile
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 7, 2: 3, 3: 1, 4: 2},
               exp_regs={10: 10, 11: 11, 12: 3, 13: 3})


@cocotb.test()
async def test_fwd_chain_double_stall(dut):
    """Forwarding chain A→B→C: two consecutive back-to-back RAW hazards.

    ADD x10 produces x10.  ADD x11 immediately reads x10 (0-gap RAW → stall).
    After that stall resolves, ADD x12 immediately reads x11 (another 0-gap
    RAW → second stall).  Each stall is resolved by MEM→EX forwarding.

        ADD x10, x1, x2   ->  4 + 6 = 10
        ADD x11, x10, x3  ->  10 (MEM→EX) + 2 = 12
        ADD x12, x11, x3  ->  12 (MEM→EX) + 2 = 14
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [ADD(10, 1, 2)]   +  # A: producer
        [ADD(11, 10, 3)]  +  # B: 0-gap RAW on x10 → stall #1 + MEM→EX fwd
        [ADD(12, 11, 3)]  +  # C: 0-gap RAW on x11 → stall #2 + MEM→EX fwd
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 4, 2: 6, 3: 2},
               exp_regs={10: 10, 11: 12, 12: 14})


# ===========================================================================
# Load-use stall tests
# ===========================================================================

@cocotb.test()
async def test_load_use_two_stalls(dut):
    """LW immediately followed by a dependent instruction: 2 stall cycles.

    is_hazard_ex fires (LW in EX, consumer in ID) — 1st stall.
    is_hazard_mem then fires (LW in MEM, consumer still in ID) — 2nd stall.
    After two stalls LW is in WB and WB→EX forwarding delivers the result.

        LW  x10, x1, 0     ->  x10 = mem[0] = 999
        ADD x11, x10, x2   ->  999 (WB→EX fwd) + 1 = 1000
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [LW(10, 1, 0)]    +  # load-use producer
        [ADD(11, 10, 2)]  +  # 0-gap RAW on x10 (load) → 2 stalls
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 0, 2: 1},
               dmem_init={0: 999},
               exp_regs={10: 999, 11: 1000})


@cocotb.test()
async def test_load_1_gap_one_stall(dut):
    """LW with 1 independent instruction: is_hazard_mem fires once (1 stall).

    The independent instruction advances through EX without a stall.
    But when the consumer reaches ID, LW is now in MEM (is_hazard_mem fires)
    → one stall cycle.  WB→EX forward then resolves the dependency.

        LW   x10, x1, 0    ->  x10 = mem[0] = 0xABCD
        ADD  x12, x3, x4   ->  independent gap (no shared registers)
        ADD  x11, x10, x2  ->  0xABCD (WB→EX fwd) + 1 = 0xABCE
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [LW (10, 1, 0)]   +  # load producer
        [ADD(12, 3, 4)]   +  # independent gap instruction
        [ADD(11, 10, 2)]  +  # consumer — 1-gap RAW on x10 (load) → 1 stall
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 0, 2: 1, 3: 10, 4: 20},
               dmem_init={0: 0xABCD},
               exp_regs={10: 0xABCD, 11: 0xABCE, 12: 30})


@cocotb.test()
async def test_load_2_gap_no_stall(dut):
    """LW with 2 independent instructions: no stall, reads from regfile.

    After two independent instructions, the LW result has already committed
    to the register file by the time the consumer reaches EX.  No hazard,
    no forwarding path required.

        LW   x10, x1, 0   ->  x10 = mem[0] = 500
        ADD  x12, x3, x4  ->  independent gap 1
        ADD  x13, x3, x4  ->  independent gap 2
        ADD  x11, x10, x2  ->  500 (regfile) + 50 = 550
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [LW (10, 1, 0)]   +  # load producer
        [ADD(12, 3, 4)]   +  # gap 1
        [ADD(13, 3, 4)]   +  # gap 2
        [ADD(11, 10, 2)]  +  # consumer — 2-gap, reads regfile; no stall
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 0, 2: 50, 3: 1, 4: 2},
               dmem_init={0: 500},
               exp_regs={10: 500, 11: 550, 12: 3, 13: 3})


# ===========================================================================
# Control hazard tests  (BEQ flush and JAL)
# ===========================================================================

@cocotb.test()
async def test_branch_not_taken_beq(dut):
    """BEQ not taken: the two instructions after the branch execute normally.

    When rs1 != rs2 the ALU_SUB result is non-zero, so is_taken=0 and the
    pipeline continues sequentially without any flush.

        BEQ  x1, x2, +12    ->  20 != 99  =>  not taken
        ADD  x10, x1, x2    ->  executes (PC+4)  => x10 = 20 + 99 = 119
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # BEQ at index 0 (PC=0), imm=12  →  target would be PC=12 (index 3)
    prog = (
        [BEQ(1, 2, 12)]   +   # not taken (x1 != x2)
        [ADD(10, 1, 2)]   +   # should execute (PC+4)
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 20, 2: 99},
               exp_regs={10: 119})


@cocotb.test()
async def test_branch_taken_beq_flushes_shadows(dut):
    """BEQ taken: the two shadow instructions in the pipeline are flushed.

    When rs1 == rs2 the ALU_SUB result is zero → is_taken=1 → flush fires.
    The two instructions immediately after the branch (in ID and IF) are
    killed; execution resumes at the branch target.

    Program layout  (each index = one word = 4 bytes):
        [0] BEQ  x1, x2, +12   # at PC=0; taken when x1==x2; target=PC+12=12
        [1] ADDI x10, x0, 0xAA # shadow in ID  → killed
        [2] ADDI x11, x0, 0xBB # shadow in IF  → killed
        [3] ADDI x12, x0, 0xFF # target at PC=12 → should execute

    With x1=x2=42: branch taken.
    Expected: x10=0, x11=0 (never written), x12=0xFF.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [BEQ (1, 2, 12)]     +   # [0] taken; target = index 3 (PC=12)
        [ADDI(10, 0, 0xAA)]  +   # [1] shadow1 — must be flushed
        [ADDI(11, 0, 0xBB)]  +   # [2] shadow2 — must be flushed
        [ADDI(12, 0, 0xFF)]  +   # [3] branch target — should execute
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 42, 2: 42},
               exp_regs={10: 0, 11: 0, 12: 0xFF})


@cocotb.test()
async def test_jal_link_and_jump(dut):
    """JAL always-taken: saves PC+4 in rd and flushes the two shadow instructions.

    JAL at PC=0 with imm=12 jumps to PC=12 (instruction index 3) and writes
    the return address (PC+4 = 4) into x10.

    Program layout:
        [0] JAL  x10, +12       # jump to index 3, x10 = PC+4 = 4
        [1] ADDI x11, x0, 0xAA # shadow1 → killed
        [2] ADDI x11, x0, 0xBB # shadow2 → killed
        [3] ADDI x12, x0, 0xFF # JAL target → should execute
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [JAL (10, 12)]       +   # [0] jump; x10 = PC+4 = 4; target = index 3
        [ADDI(11, 0, 0xAA)]  +   # [1] shadow1 — must be flushed
        [ADDI(11, 0, 0xBB)]  +   # [2] shadow2 — must be flushed
        [ADDI(12, 0, 0xFF)]  +   # [3] JAL target — should execute
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               exp_regs={10: 4, 11: 0, 12: 0xFF})


# ===========================================================================
# Forwarding into branch comparison  (stall + forward + flush)
# ===========================================================================

@cocotb.test()
async def test_forward_both_operands_to_branch(dut):
    """Two independent ALU ops feed a BEQ via stall + dual forwarding.

    ADD x10 and ADD x11 are independent — they issue back-to-back without
    a stall between them.  When BEQ is in ID:

      1. ADD x11 is in EX → is_hazard_ex fires (BEQ reads x11) → 1 stall
      2. After stall: ADD x11 in MEM, ADD x10 in WB, BEQ in EX
             MEM→EX forward supplies x11
             WB→EX  forward supplies x10
      3. BEQ evaluates x10 == x11 with both forwarded values.

    When x1==x3 (so x10==x11) the branch is taken and the two shadow
    instructions are flushed.  The target instruction writes x14=0xFF.

    Program layout (BEQ at index 2, PC=8):
        [0] ADD  x10, x1, x0   # x10 = x1 = A  (x0 hardwired 0)
        [1] ADD  x11, x3, x0   # x11 = x3 = B  (independent of x10)
        [2] BEQ  x10, x11, +12 # target = PC+12 = 8+12 = 20 = index 5
        [3] ADDI x12, x0, 1    # shadow1 → killed
        [4] ADDI x13, x0, 2    # shadow2 → killed
        [5] ADDI x14, x0, 0xFF # branch target → executes
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # BEQ is at PC=8, so imm=12 → target = PC 20 = index 5
    prog = (
        [ADD (10, 1, 0)]     +   # [0]
        [ADD (11, 3, 0)]     +   # [1]
        [BEQ (10, 11, 12)]   +   # [2] BEQ at PC=8, target=20
        [ADDI(12, 0, 1)]     +   # [3] shadow1 → killed
        [ADDI(13, 0, 2)]     +   # [4] shadow2 → killed
        [ADDI(14, 0, 0xFF)]  +   # [5] target → executes
        [NOP] * N_NOPS
    )

    # x1 = x3 = 42  →  x10 = x11 = 42  →  BEQ taken
    await _run(dut, prog,
               reg_init={1: 42, 3: 42},
               exp_regs={10: 42, 11: 42, 12: 0, 13: 0, 14: 0xFF})


@cocotb.test()
async def test_forward_both_operands_to_branch_not_taken(dut):
    """Same forwarding setup as above but with A != B so the branch is NOT taken.

    x1=42, x3=99 → x10=42, x11=99 → BEQ not taken → sequential execution.
    x12 and x13 are written by the shadow instructions; x14 is also written
    by [5] since execution continues sequentially through all instructions.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [ADD (10, 1, 0)]     +   # [0]
        [ADD (11, 3, 0)]     +   # [1]
        [BEQ (10, 11, 12)]   +   # [2] BEQ at PC=8, target=20; NOT taken
        [ADDI(12, 0, 1)]     +   # [3] executes (not flushed)
        [ADDI(13, 0, 2)]     +   # [4] executes
        [ADDI(14, 0, 0xFF)]  +   # [5] executes
        [NOP] * N_NOPS
    )

    # x1=42, x3=99 → x10 != x11 → branch not taken
    await _run(dut, prog,
               reg_init={1: 42, 3: 99},
               exp_regs={10: 42, 11: 99, 12: 1, 13: 2, 14: 0xFF})


# ===========================================================================
# Forwarding through a load + store round-trip with stalls
# ===========================================================================

@cocotb.test()
async def test_load_followed_by_stall_then_store(dut):
    """Load-use hazard then an ALU op then a store: verifies the full chain.

    LW  →  (2 stalls)  →  ADD using loaded value  →  (1 stall + fwd)  →  SW

        LW   x10, x1, 0    ->  x10 = mem[0] = 0x1234
        ADD  x11, x10, x2  ->  0x1234 + 1 = 0x1235  (2 stalls for LW, MEM→EX then WB→EX)
        SW   x3,  x11, 0   ->  mem[0] = 0x1235        (1 stall for ADD, MEM→EX fwd)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [LW (10, 1, 0)]    +  # load
        [ADD(11, 10, 2)]   +  # 0-gap RAW (load) → 2 stalls
        [SW (3, 11, 0)]    +  # 0-gap RAW (non-load) → 1 stall
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 0, 2: 1, 3: 0},
               dmem_init={0: 0x1234},
               exp_regs={10: 0x1234, 11: 0x1235},
               exp_dmem={0: 0x1235})
