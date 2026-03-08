"""
cocotb Testbench: rv_cpu  —  Memory + Arithmetic Combination Tests
==================================================================

Tests programs that interleave load/store memory instructions with
R-type ALU and I-type (ADDI) arithmetic operations.

RAW hazard handling
-------------------
  No data forwarding — dependent instructions are separated by N_NOPS=4
  NOPs between the producer (writes rd) and the consumer (reads that rd).

  Independent instructions that write to different registers can issue
  back-to-back without any stall NOPs.

  When two independent instructions both produce values needed by a later
  consumer, one N_NOPS block after the *last* producer is sufficient:

      [INST_A, INST_B, NOP×4, INST_C(rd_A, rd_B)]

  INST_A commits 1 cycle before INST_B, and INST_C reads both in the same
  ID stage which falls at least 4 cycles after INST_B's IF stage.  ✓

Verification
------------
  Each test checks both destination registers and data-memory words where
  applicable, using the local _run() helper defined below.

Run with:
    inv sim --testbench tb_mem_arith
"""

import cocotb
from cocotb.clock import Clock

import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent))  # for importing tb_helpers
from tb_helpers import (
    CLK_PERIOD_NS, N_NOPS, PIPE_DEPTH,
    NOP, ADD, SUB, AND, OR, XOR, SLL, ADDI,
    LW, LH, LB, LHU, LBU,
    SW, SH, SB,
    u32, s32,
    load_imem, do_reset, clock_n,
    write_reg, read_reg, write_dmem, read_dmem,
)


# ---------------------------------------------------------------------------
# Shared helper
# ---------------------------------------------------------------------------

async def _run(dut, program, *, reg_init={}, dmem_init={}, exp_regs={}, exp_dmem={}):
    """
    Load a program, initialise state, run, then verify registers and/or memory.

    Args:
        program   : list of 32-bit instruction words
        reg_init  : {reg_num: value}   — written into regfile after reset
        dmem_init : {word_addr: value} — written into data mem after reset
        exp_regs  : {reg_num: value}   — expected register values after program flush
        exp_dmem  : {word_addr: value} — expected data-memory words after program flush
    """
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
# ALU result written to data memory
# ===========================================================================

@cocotb.test()
async def test_add_result_to_memory(dut):
    """Compute ADD then store the result: verifies both the register and memory.

    RAW chain: ADD writes x10  →  N_NOPS  →  SW reads x10.

        ADD  x10, x1, x2   ->  0xAB00 + 0x00CD = 0x0000_ABCD
        SW   x3,  x10, 0   ->  mem[word_addr(x3+0)] = x10   (x3=0 -> word_addr=0)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [ADD(10, 1, 2)]  +
        [NOP] * N_NOPS   +
        [SW(3, 10, 0)]   +
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 0xAB00, 2: 0x00CD, 3: 0},
               exp_regs={10: 0xABCD},
               exp_dmem={0: 0xABCD})


@cocotb.test()
async def test_addi_constant_then_store(dut):
    """ADDI loads an immediate constant; SW stores it.  Combines I-type + S-type.

    RAW chain: ADDI writes x10  →  N_NOPS  →  SW reads x10.

        ADDI x10, x0, 0x7FF   ->  x10 = 2047  (max unsigned 12-bit immediate)
        SW   x1,  x10, 0      ->  mem[0] = 2047
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [ADDI(10, 0, 0x7FF)]  +
        [NOP] * N_NOPS         +
        [SW(1, 10, 0)]         +
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 0},
               exp_regs={10: 0x7FF},
               exp_dmem={0: 0x7FF})


# ===========================================================================
# Value loaded from memory then used in ALU
# ===========================================================================

@cocotb.test()
async def test_load_then_add(dut):
    """Load a value from data memory and add an immediate register operand.

    RAW chain: LW writes x10  →  N_NOPS  →  ADD reads x10.

        LW   x10, x1, 0   ->  x10 = mem[0] = 200
        ADD  x11, x10, x2  ->  x11 = 200 + 55 = 255
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [LW(10, 1, 0)]      +
        [NOP] * N_NOPS       +
        [ADD(11, 10, 2)]    +
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 0, 2: 55},
               dmem_init={0: 200},
               exp_regs={10: 200, 11: 255})


@cocotb.test()
async def test_load_mask_apply(dut):
    """Load a bit-mask from memory and AND it with a register to extract a bit-field.

    Demonstrates a real-world pattern: a mask value lives in data memory,
    gets loaded dynamically, and is applied to isolate the lower 16 bits.

    RAW chain: LW writes x10  →  N_NOPS  →  AND reads x10.

        LW   x10, x1, 0        ->  x10 = 0x0000_FFFF  (mask)
        AND  x11, x2,  x10     ->  x11 = 0x1234_5678 & 0x0000_FFFF = 0x0000_5678
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [LW(10, 1, 0)]      +
        [NOP] * N_NOPS       +
        [AND(11, 2, 10)]    +
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 0, 2: 0x1234_5678},
               dmem_init={0: 0x0000_FFFF},
               exp_regs={10: 0x0000_FFFF, 11: 0x0000_5678})


@cocotb.test()
async def test_load_signed_byte_arithmetic(dut):
    """Sign-extended byte load feeds into ADD; result is stored back to memory.

    LB sign-extends bit 7 — 0x80 becomes 0xFFFF_FF80 (-128 signed).
    Adding 256 to -128 yields +128 = 0x0000_0080 (32-bit unsigned result).

    RAW chains:
        LB  writes x10  →  N_NOPS  →  ADD reads x10
        ADD writes x11  →  N_NOPS  →  SW  reads x11

        LB   x10, x1, 0    ->  x10 = sign_extend(0x80) = 0xFFFF_FF80
        ADD  x11, x10, x2  ->  x11 = 0xFFFF_FF80 + 256 = 0x0000_0080
        SW   x3,  x11, 0   ->  mem[0] = 0x0000_0080
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    expected_sum = u32(0xFFFF_FF80 + 256)   # 0x0000_0080  (128)

    prog = (
        [LB(10, 1, 0)]       +
        [NOP] * N_NOPS        +
        [ADD(11, 10, 2)]     +
        [NOP] * N_NOPS        +
        [SW(3, 11, 0)]       +
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 0, 2: 256, 3: 0},
               dmem_init={0: 0x0000_0080},        # byte[0] = 0x80
               exp_regs={10: 0xFFFF_FF80, 11: expected_sum},
               exp_dmem={0: expected_sum})


# ===========================================================================
# Memory copy
# ===========================================================================

@cocotb.test()
async def test_memory_copy(dut):
    """Copy a 32-bit word from one memory address to another.

    RAW chain: LW writes x10  →  N_NOPS  →  SW reads x10.

        LW   x10, x1, 0   ->  x10 = mem[0] = 0xCAFE_BABE
        SW   x2,  x10, 0  ->  mem[word_addr(x2)] = x10   (x2=4 -> word_addr=1)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [LW(10, 1, 0)]    +
        [NOP] * N_NOPS     +
        [SW(2, 10, 0)]    +
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 0, 2: 4},             # x2=4 -> SW addr byte 4, word_addr=1
               dmem_init={0: 0xCAFE_BABE},
               exp_regs={10: 0xCAFE_BABE},
               exp_dmem={1: 0xCAFE_BABE})


# ===========================================================================
# Two independent ALU ops, then two back-to-back stores
# ===========================================================================

@cocotb.test()
async def test_two_alu_ops_two_stores(dut):
    """Two independent ALU ops back-to-back, followed by two back-to-back stores.

    ADD and SUB write to different registers (x10, x11) with no shared
    source or destination — they issue without any NOPs between them.

    One N_NOPS after the last ALU instruction covers both results
    (ADD commits 1 cycle before SUB; both are ready when the SWs reach ID).

    The two SWs also issue back-to-back: SW reads registers but never writes
    one, so there is no RAW between the two stores.

        ADD  x10, x1, x2   ->  300 +  50 = 350
        SUB  x11, x3, x4   -> 1000 - 333 = 667
        SW   x5,  x10, 0   ->  mem[0] = 350   (x5=0)
        SW   x5,  x11, 4   ->  mem[1] = 667
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [ADD(10, 1, 2), SUB(11, 3, 4)]   +
        [NOP] * N_NOPS                    +
        [SW(5, 10, 0), SW(5, 11, 4)]     +
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 300, 2: 50, 3: 1000, 4: 333, 5: 0},
               exp_regs={10: 350, 11: 667},
               exp_dmem={0: 350, 1: 667})


# ===========================================================================
# Sum two values loaded from adjacent memory words
# ===========================================================================

@cocotb.test()
async def test_sum_of_loaded_values(dut):
    """Load two adjacent words from memory and add them.

    LW x10 and LW x11 are independent (different rd, different addresses).
    One N_NOPS block after the *second* LW is sufficient:
      LW x10 commits 1 cycle before LW x11; both are done before ADD reaches ID.

        LW  x10, x1, 0    ->  x10 = mem[0] = 0x1111_1111
        LW  x11, x1, 4    ->  x11 = mem[1] = 0x2222_2222
        ADD x12, x10, x11  ->  x12 = 0x3333_3333
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [LW(10, 1, 0), LW(11, 1, 4)]    +
        [NOP] * N_NOPS                    +
        [ADD(12, 10, 11)]                 +
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 0},
               dmem_init={0: 0x1111_1111, 1: 0x2222_2222},
               exp_regs={10: 0x1111_1111, 11: 0x2222_2222, 12: 0x3333_3333})


# ===========================================================================
# Three-stage pipeline: load + independent ALU op → combine → store
# ===========================================================================

@cocotb.test()
async def test_load_compute_store(dut):
    """LW and SUB produce independent values; ADD combines them; SW stores the sum.

    LW and SUB are independent (different rd, no shared sources) — they issue
    back-to-back.  One N_NOPS covers both before ADD reads their outputs.
    A second N_NOPS separates ADD from SW.

        LW   x10, x1, 0     ->  x10 = mem[0] = 500
        SUB  x11, x2, x3    ->  x11 = 1000 - 250 = 750   (independent of LW)
        [N_NOPS]
        ADD  x12, x10, x11  ->  x12 = 500 + 750 = 1250
        [N_NOPS]
        SW   x4, x12, 0     ->  mem[word_addr(x4)] = 1250   (x4=4 -> word_addr=1)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [LW(10, 1, 0), SUB(11, 2, 3)]   +
        [NOP] * N_NOPS                    +
        [ADD(12, 10, 11)]                 +
        [NOP] * N_NOPS                    +
        [SW(4, 12, 0)]                    +
        [NOP] * N_NOPS
    )

    await _run(dut, prog,
               reg_init={1: 0, 2: 1000, 3: 250, 4: 4},
               dmem_init={0: 500},
               exp_regs={10: 500, 11: 750, 12: 1250},
               exp_dmem={1: 1250})
