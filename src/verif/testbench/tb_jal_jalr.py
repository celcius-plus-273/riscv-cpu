"""
cocotb Testbench: rv_cpu  —  JAL & JALR Comprehensive Tests
============================================================

Exercises the two unconditional jump-and-link instructions:

    JAL   rd, imm20  — PC-relative jump; rd = PC+4, PC += sext(imm)
    JALR  rd, rs1, imm12  — Register-indirect jump; rd = PC+4, PC = rs1 + sext(imm)

Tests are organized in three groups:

  JAL instruction (Tests 1-6):
      1. test_jal_forward_small          — small forward offset (+8)
      2. test_jal_forward_large          — large forward offset over padding
      3. test_jal_backward               — negative offset (loop with counter)
      4. test_jal_to_x0_discards_link    — JAL x0: link discarded, jump taken
      5. test_jal_link_at_nonzero_pc     — JAL at nonzero PC, verify link = PC+4
      6. test_jal_chain                  — two consecutive JALs, both links correct

  JALR instruction (Tests 7-13):
      7. test_jalr_positive_offset       — rs1 + positive imm
      8. test_jalr_negative_offset       — rs1 + negative imm
      9. test_jalr_zero_base             — x0 as base, target = 0 + imm
     10. test_jalr_to_x0_discards_link   — JALR x0: link discarded, jump taken
     11. test_jalr_same_rd_rs1           — rd == rs1, old rs1 used for target
     12. test_jalr_forwarded_base        — 0-gap RAW hazard on base register
     13. test_jalr_link_at_nonzero_pc    — JALR at nonzero PC, verify link = PC+4

  Function call/return patterns (Tests 14-18):
     14. test_call_and_return            — JAL call, JALR return
     15. test_nested_calls               — two-level call with stack save/restore
     16. test_auipc_jalr_long_jump       — AUIPC + JALR computed jump
     17. test_recursive_countdown        — recursive JAL/JALR with memory stack
     18. test_jalr_jump_table            — indexed indirect jump via JALR

Run with:
    inv sim --testbench tb_jal_jalr
"""

import cocotb
from cocotb.clock import Clock

import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent))
from tb_helpers import (
    CLK_PERIOD_NS, PIPE_DEPTH, N_NOPS,
    NOP, ADD, ADDI, SLLI, LW, SW,
    BEQ, BNE,
    JAL, JALR, AUIPC,
    u32,
    load_imem, do_reset, clock_n,
    write_reg, read_reg, write_dmem, read_dmem,
    run_r_test,
)


# ===========================================================================
# JAL — Jump and Link (PC-relative)
# ===========================================================================

@cocotb.test()
async def test_jal_forward_small(dut):
    """JAL with a small forward offset: skip one instruction.

    Assembly:

        [0]  JAL   x10, +8      # x10 = 0+4 = 4; jump to PC=8=[2]
        [1]  ADDI  x11, x0, 0xAA  # shadow — must NOT execute
        [2]  ADDI  x12, x0, 0xCC  # target — must execute

    Expected: x10=4 (link), x11=0 (shadow killed), x12=0xCC (target reached)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        JAL (10, 8),            # [0] PC=0  link=4, target=8=[2]
        ADDI(11, 0, 0xAA),     # [1] PC=4  shadow
        ADDI(12, 0, 0xCC),     # [2] PC=8  target
        NOP,                    # [3]
    ]

    await run_r_test(dut, prog, reg_init={}, expected={10: 4, 11: 0, 12: 0xCC})


@cocotb.test()
async def test_jal_forward_large(dut):
    """JAL over a large block of NOP padding.

    Assembly:

        [0]   JAL  x10, +48     # x10=4, jump to PC=48=[12]
        [1-11] NOP padding
        [12]  ADDI x11, x0, 0x42  # target

    Expected: x10=4, x11=0x42
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [JAL(10, 48)]          # [0]  link=4, target=48=[12]
        + [NOP] * 11           # [1..11] padding
        + [ADDI(11, 0, 0x42)]  # [12] target
        + [NOP]
    )

    await run_r_test(dut, prog, reg_init={}, expected={10: 4, 11: 0x42})


@cocotb.test()
async def test_jal_backward(dut):
    """JAL with a negative offset — jumps backward.

    Uses a counter (x13) to avoid an infinite loop: the first pass
    falls through the BEQ (counter not yet at threshold), executes
    the backward JAL, and comes back.  The second pass hits the
    threshold and exits via BEQ.

    Assembly:

        [0]  ADDI x13, x13, 1    # counter++ (0→1→2)
        [1]  ADDI x14, x0, 2     # threshold = 2
        [2]  BEQ  x13, x14, +12  # if counter==2: done → [5]=PC=20
        [3]  JAL  x10, -12       # backward; x10=16, target=PC=12-12=0=[0]
        [4]  NOP                  # shadow
        [5]  NOP                  # done (BEQ target)

    Trace:
        Pass 1: x13=1, 1≠2 → JAL at [3] jumps to [0], x10=16
        Pass 2: x13=2, 2==2 → BEQ taken, done

    Expected: x10=16 (link from JAL at PC=12), x13=2 (looped twice)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(13, 13, 1),      # [0] PC=0   counter++
        ADDI(14,  0, 2),      # [1] PC=4   threshold
        BEQ (13, 14, 12),     # [2] PC=8   if done: PC=8+12=20=[5]
        JAL (10, -12),         # [3] PC=12  link=16, target=12-12=0=[0]
        NOP,                   # [4] PC=16  shadow
        NOP,                   # [5] PC=20  done
    ]
    # fmt: on

    load_imem(dut, prog)
    await do_reset(dut)
    await clock_n(dut, 40)

    assert read_reg(dut, 10) == 16, f"x10 (link): expected 16, got {read_reg(dut, 10)}"
    assert read_reg(dut, 13) == 2,  f"x13 (counter): expected 2, got {read_reg(dut, 13)}"


@cocotb.test()
async def test_jal_to_x0_discards_link(dut):
    """JAL x0: the jump is still taken, but the link address is discarded.

    Assembly:

        [0]  JAL  x0, +8       # jump to [2], link → x0 (discarded)
        [1]  ADDI x11, x0, 0xAA  # shadow — must NOT execute
        [2]  ADDI x12, x0, 0xFF  # target — must execute

    Expected: x12=0xFF (jump taken), x11=0 (shadow killed)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        JAL (0, 8),            # [0] PC=0  link discarded, target=8=[2]
        ADDI(11, 0, 0xAA),    # [1] PC=4  shadow
        ADDI(12, 0, 0xFF),    # [2] PC=8  target
        NOP,
    ]

    await run_r_test(dut, prog, reg_init={}, expected={12: 0xFF, 11: 0})


@cocotb.test()
async def test_jal_link_at_nonzero_pc(dut):
    """JAL at a nonzero PC: link = PC_of_JAL + 4, not always 4.

    Two ADDI instructions precede the JAL, placing it at PC=8.
    The link should be 8+4=12.

    Assembly:

        [0]  ADDI x1, x0, 5      # real work
        [1]  ADDI x2, x0, 10     # real work
        [2]  JAL  x10, +8        # x10 = 8+4 = 12; target = PC=8+8=16=[4]
        [3]  ADDI x11, x0, 0xAA  # shadow
        [4]  ADDI x12, x0, 0xFF  # target

    Expected: x10=12, x12=0xFF, x11=0 (shadow killed)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        ADDI( 1, 0,  5),      # [0] PC=0
        ADDI( 2, 0, 10),      # [1] PC=4
        JAL (10, 8),           # [2] PC=8   link=12, target=16=[4]
        ADDI(11, 0, 0xAA),    # [3] PC=12  shadow
        ADDI(12, 0, 0xFF),    # [4] PC=16  target
        NOP,
    ]

    await run_r_test(dut, prog, reg_init={}, expected={10: 12, 12: 0xFF, 11: 0})


@cocotb.test()
async def test_jal_chain(dut):
    """Two consecutive JALs — both link registers must be correct.

    The first JAL jumps to target A, which itself is a JAL to target B.
    Each JAL writes its own PC+4 to a different link register.

    Assembly:

        [0]  JAL  x10, +12     # x10=4, target=PC=12=[3]
        [1]  NOP                # shadow
        [2]  NOP                # shadow
        [3]  JAL  x11, +12     # x11=16, target=PC=24=[6]
        [4]  NOP                # shadow
        [5]  NOP                # shadow
        [6]  ADDI x12, x0, 0xFF  # final target

    Expected: x10=4, x11=16, x12=0xFF
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        JAL (10, 12),          # [0] PC=0   link=4,  target=12=[3]
        NOP,                    # [1] PC=4   shadow
        NOP,                    # [2] PC=8   shadow
        JAL (11, 12),          # [3] PC=12  link=16, target=24=[6]
        NOP,                    # [4] PC=16  shadow
        NOP,                    # [5] PC=20  shadow
        ADDI(12, 0, 0xFF),    # [6] PC=24  final target
        NOP,
    ]

    await run_r_test(dut, prog, reg_init={}, expected={10: 4, 11: 16, 12: 0xFF})


# ===========================================================================
# JALR — Jump and Link Register (indirect)
# ===========================================================================

@cocotb.test()
async def test_jalr_positive_offset(dut):
    """JALR with a positive immediate: target = rs1 + imm.

    Assembly:

        [0]  JALR x10, x1, 8    # x10=4, target=x1+8; x1=4→12=[3]
        [1]  ADDI x11, x0, 0xAA # shadow
        [2]  ADDI x11, x0, 0xBB # shadow
        [3]  ADDI x12, x0, 0xFF # target

    reg_init: x1=4
    Expected: x10=4, x11=0 (shadow killed), x12=0xFF
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        JALR(10, 1,  8),      # [0] PC=0   link=4, target=4+8=12=[3]
        ADDI(11, 0, 0xAA),    # [1] PC=4   shadow
        ADDI(11, 0, 0xBB),    # [2] PC=8   shadow
        ADDI(12, 0, 0xFF),    # [3] PC=12  target
        NOP,
    ]

    await run_r_test(dut, prog, reg_init={1: 4}, expected={10: 4, 11: 0, 12: 0xFF})


@cocotb.test()
async def test_jalr_negative_offset(dut):
    """JALR with a negative immediate: target = rs1 + (-8).

    Assembly:

        [0]  JALR x10, x1, -8   # x10=4, target=x1-8; x1=20→12=[3]
        [1]  ADDI x11, x0, 0xAA # shadow
        [2]  ADDI x11, x0, 0xBB # shadow
        [3]  ADDI x12, x0, 0xFF # target

    reg_init: x1=20
    Expected: x10=4, x11=0, x12=0xFF
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        JALR(10, 1, -8),      # [0] PC=0   link=4, target=20-8=12=[3]
        ADDI(11, 0, 0xAA),    # [1] PC=4   shadow
        ADDI(11, 0, 0xBB),    # [2] PC=8   shadow
        ADDI(12, 0, 0xFF),    # [3] PC=12  target
        NOP,
    ]

    await run_r_test(dut, prog, reg_init={1: 20}, expected={10: 4, 11: 0, 12: 0xFF})


@cocotb.test()
async def test_jalr_zero_base(dut):
    """JALR with x0 as the base register: target = 0 + imm12.

    Assembly:

        [0]  JALR x10, x0, 12   # x10=4, target=0+12=12=[3]
        [1]  ADDI x11, x0, 0xAA # shadow
        [2]  ADDI x11, x0, 0xBB # shadow
        [3]  ADDI x12, x0, 0xFF # target

    Expected: x10=4, x11=0, x12=0xFF
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        JALR(10, 0, 12),      # [0] PC=0   link=4, target=0+12=12=[3]
        ADDI(11, 0, 0xAA),    # [1] PC=4   shadow
        ADDI(11, 0, 0xBB),    # [2] PC=8   shadow
        ADDI(12, 0, 0xFF),    # [3] PC=12  target
        NOP,
    ]

    await run_r_test(dut, prog, reg_init={}, expected={10: 4, 11: 0, 12: 0xFF})


@cocotb.test()
async def test_jalr_to_x0_discards_link(dut):
    """JALR x0: jump is taken, but the link address is discarded.

    Assembly:

        [0]  JALR x0, x1, 0     # target=x1=12, link → x0 (discarded)
        [1]  ADDI x11, x0, 0xAA # shadow
        [2]  ADDI x11, x0, 0xBB # shadow
        [3]  ADDI x12, x0, 0xFF # target

    reg_init: x1=12
    Expected: x12=0xFF (jumped), x11=0 (shadows killed)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        JALR( 0, 1, 0),       # [0] PC=0   link discarded, target=12=[3]
        ADDI(11, 0, 0xAA),    # [1] shadow
        ADDI(11, 0, 0xBB),    # [2] shadow
        ADDI(12, 0, 0xFF),    # [3] target
        NOP,
    ]

    await run_r_test(dut, prog, reg_init={1: 12}, expected={12: 0xFF, 11: 0})


@cocotb.test()
async def test_jalr_same_rd_rs1(dut):
    """JALR where rd == rs1: the OLD rs1 value is used for the target,
    and rd is then overwritten with PC+4.

    Per RISC-V spec, the target address is computed from the original
    rs1 before rd is written.  When rd==rs1 (both x1), the link value
    (PC+4) replaces the old base address.

    Assembly:

        [0]  JALR x1, x1, 0     # target=old_x1=12=[3]; x1(new)=4
        [1]  ADDI x11, x0, 0xAA # shadow
        [2]  ADDI x11, x0, 0xBB # shadow
        [3]  ADDI x12, x0, 0xFF # target
        [4]  ADD  x13, x1, x0   # x13 = x1 (should be 4, the link)

    reg_init: x1=12
    Expected: x12=0xFF, x1=4 (overwritten with link), x13=4, x11=0
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        JALR( 1, 1, 0),       # [0] PC=0   target=old_x1=12, x1_new=4
        ADDI(11, 0, 0xAA),    # [1] shadow
        ADDI(11, 0, 0xBB),    # [2] shadow
        ADDI(12, 0, 0xFF),    # [3] PC=12  target
        ADD (13, 1,  0),      # [4] x13 = x1 = 4
        NOP,
    ]
    # fmt: on

    await run_r_test(dut, prog, reg_init={1: 12},
                     expected={12: 0xFF, 1: 4, 13: 4, 11: 0})


@cocotb.test()
async def test_jalr_forwarded_base(dut):
    """ADDI immediately before JALR creates a 0-gap RAW hazard on the
    base register.  The hazard unit must forward the ADDI result.

    Assembly:

        [0]  ADDI x1, x0, 12   # x1 = 12  (produces x1)
        [1]  JALR x10, x1, 0   # target = forwarded_x1 = 12 = [3]; x10=8
        [2]  ADDI x11, x0, 0xAA  # shadow
        [3]  ADDI x12, x0, 0xFF  # target

    The 0-gap RAW (x1 written at [0], read at [1]) triggers a stall +
    MEM->EX forwarding.  The JALR PC is still 4 regardless of stalls,
    so x10 = 4 + 4 = 8.

    Expected: x10=8, x12=0xFF, x11=0
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        ADDI( 1, 0, 12),      # [0] PC=0  x1 = 12
        JALR(10, 1,  0),      # [1] PC=4  link=8, target=12=[3]
        ADDI(11, 0, 0xAA),    # [2] PC=8  shadow
        ADDI(12, 0, 0xFF),    # [3] PC=12 target
        NOP,
    ]

    await run_r_test(dut, prog, reg_init={}, expected={10: 8, 12: 0xFF, 11: 0})


@cocotb.test()
async def test_jalr_link_at_nonzero_pc(dut):
    """JALR at a nonzero PC: link = PC_of_JALR + 4.

    Two ADDI instructions precede the JALR, placing it at PC=8.
    The link should be 8+4=12.

    Assembly:

        [0]  ADDI x1, x0, 5      # real work
        [1]  ADDI x2, x0, 10     # real work
        [2]  JALR x10, x3, 0     # x10 = 8+4 = 12; target = x3 = 20 = [5]
        [3]  ADDI x11, x0, 0xAA  # shadow
        [4]  ADDI x11, x0, 0xBB  # shadow
        [5]  ADDI x12, x0, 0xFF  # target

    reg_init: x3=20
    Expected: x10=12, x12=0xFF, x11=0
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        ADDI( 1, 0,  5),      # [0] PC=0
        ADDI( 2, 0, 10),      # [1] PC=4
        JALR(10, 3,  0),      # [2] PC=8   link=12, target=20=[5]
        ADDI(11, 0, 0xAA),    # [3] PC=12  shadow
        ADDI(11, 0, 0xBB),    # [4] PC=16  shadow
        ADDI(12, 0, 0xFF),    # [5] PC=20  target
        NOP,
    ]

    await run_r_test(dut, prog, reg_init={3: 20}, expected={10: 12, 12: 0xFF, 11: 0})


# ===========================================================================
# Function call / return patterns
# ===========================================================================

@cocotb.test()
async def test_call_and_return(dut):
    """JAL calls a function; JALR returns to the caller.

    The function doubles x1 and stores the result in x2.
    After return, the caller copies x2 into x10.

    Assembly:

        # caller
        [0]  ADDI x1, x0, 21     # argument = 21
        [1]  JAL  x5, +24        # call func at [7]=PC=28; x5(ra)=8
        [2]  NOP                  # shadow (flushed on call, executed on return)
        [3]  NOP                  # shadow (flushed on call, executed on return)
        [4]  ADD  x10, x2, x0    # x10 = return value
        [5]  BEQ  x0, x0, +16    # skip over func body; PC=20+16=36=[9]
        [6]  NOP                  # shadow

        # function body @ PC=28
        [7]  ADD  x2, x1, x1     # x2 = 21+21 = 42
        [8]  JALR x0, x5, 0      # return to ra=8=[2]; link discarded

        # done
        [9]  NOP

    Trace:
        call:   [0] x1=21 → [1] JAL → [7] x2=42 → [8] JALR → [2]
        return: [2] NOP → [3] NOP → [4] x10=42 → [5] BEQ → [9] done

    Expected: x5=8 (link from JAL), x2=42, x10=42
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        # caller
        ADDI( 1, 0, 21),      # [0]  PC=0   arg=21
        JAL ( 5, 24),          # [1]  PC=4   call; x5=8, target=28=[7]
        NOP,                    # [2]  PC=8   shadow / return landing
        NOP,                    # [3]  PC=12  shadow / return landing
        ADD (10, 2,  0),       # [4]  PC=16  x10 = x2
        BEQ ( 0, 0, 16),      # [5]  PC=20  skip func; target=36=[9]
        NOP,                    # [6]  PC=24  shadow
        # function @ PC=28
        ADD ( 2, 1,  1),       # [7]  PC=28  x2 = x1 + x1 = 42
        JALR( 0, 5,  0),      # [8]  PC=32  return to x5=8
        # done
        NOP,                    # [9]  PC=36
    ]
    # fmt: on

    load_imem(dut, prog)
    await do_reset(dut)
    await clock_n(dut, 40)

    assert read_reg(dut, 5)  == 8,  f"x5 (ra): expected 8, got {read_reg(dut, 5)}"
    assert read_reg(dut, 2)  == 42, f"x2 (retval): expected 42, got {read_reg(dut, 2)}"
    assert read_reg(dut, 10) == 42, f"x10 (result): expected 42, got {read_reg(dut, 10)}"


@cocotb.test()
async def test_nested_calls(dut):
    """Two levels of function calls with save/restore of the return address.

    main calls funcA, funcA calls funcB.  funcA saves ra to memory
    before calling funcB, then restores it to return to main.

    Assembly:

        # main
        [0]   ADDI x1, x0, 10       # arg = 10
        [1]   ADDI x20, x0, 0       # sp = byte 0  (stack pointer)
        [2]   JAL  x5, +28          # call funcA at [9]=PC=36; x5=12
        [3]   NOP                   # shadow / return
        [4]   NOP                   # shadow / return
        [5]   ADD  x10, x2, x0     # x10 = result
        [6]   BEQ  x0, x0, +52     # skip to done=[19]=PC=24+52=76
        [7]   NOP                   # shadow
        [8]   NOP                   # padding

        # funcA @ PC=36
        [9]   SW   x20, x5, 0      # save ra(=12) to mem[0]
        [10]  ADD  x2, x1, x1      # x2 = 10+10 = 20
        [11]  JAL  x5, +24         # call funcB at [17]=PC=68; x5=48
        [12]  NOP                   # shadow / return from funcB
        [13]  NOP                   # shadow / return from funcB
        [14]  LW   x5, x20, 0      # restore ra = 12
        [15]  JALR x0, x5, 0       # return to main=PC=12=[3]
        [16]  NOP                   # shadow

        # funcB @ PC=68
        [17]  ADDI x2, x2, 3       # x2 += 3 = 23
        [18]  JALR x0, x5, 0       # return to funcA=PC=48=[12]

        # done
        [19]  NOP

    Trace:
        main→funcA: x5=12, saved to mem[0]
        funcA→funcB: x5=48, x2=20→23
        funcB→funcA: return to [12], restore x5=12
        funcA→main:  return to [3], x10=23

    Expected: x10=23, x2=23
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        # main
        ADDI( 1, 0, 10),      # [0]  PC=0   arg=10
        ADDI(20, 0,  0),      # [1]  PC=4   sp=0
        JAL ( 5, 28),         # [2]  PC=8   call funcA; x5=12, target=36=[9]
        NOP,                   # [3]  PC=12  shadow / return
        NOP,                   # [4]  PC=16  shadow / return
        ADD (10, 2,  0),      # [5]  PC=20  result = x2
        BEQ ( 0, 0, 52),      # [6]  PC=24  done; target=76=[19]
        NOP,                   # [7]  PC=28  shadow
        NOP,                   # [8]  PC=32  padding

        # funcA @ PC=36
        SW  (20, 5,  0),      # [9]  PC=36  save ra to mem[byte 0]
        ADD ( 2, 1,  1),      # [10] PC=40  x2 = 10+10=20
        JAL ( 5, 24),         # [11] PC=44  call funcB; x5=48, target=68=[17]
        NOP,                   # [12] PC=48  shadow / return from funcB
        NOP,                   # [13] PC=52  shadow / return from funcB
        LW  ( 5, 20, 0),      # [14] PC=56  restore ra=12
        JALR( 0, 5,  0),      # [15] PC=60  return to main=12=[3]
        NOP,                   # [16] PC=64  shadow

        # funcB @ PC=68
        ADDI( 2, 2,  3),      # [17] PC=68  x2 += 3 = 23
        JALR( 0, 5,  0),      # [18] PC=72  return to funcA=48=[12]

        # done
        NOP,                   # [19] PC=76
    ]
    # fmt: on

    load_imem(dut, prog)
    await do_reset(dut)
    await clock_n(dut, 80)

    assert read_reg(dut, 10) == 23, f"x10: expected 23, got {read_reg(dut, 10)}"
    assert read_reg(dut, 2)  == 23, f"x2: expected 23, got {read_reg(dut, 2)}"


@cocotb.test()
async def test_auipc_jalr_long_jump(dut):
    """AUIPC + JALR: standard position-independent computed jump.

    AUIPC captures the PC, then JALR adds an offset to reach the target.
    The 0-gap RAW hazard between AUIPC and JALR is resolved by the
    hazard unit (stall + forward).

    Assembly:

        [0]  NOP                    # padding
        [1]  AUIPC x1, 0           # x1 = PC = 4
        [2]  JALR  x0, x1, 24     # target = 4+24 = 28 = [7]; link discarded
        [3]  NOP                    # shadow
        [4]  NOP                    # shadow
        [5]  NOP
        [6]  NOP
        [7]  ADDI  x10, x0, 0x42  # target sentinel

    Expected: x10=0x42
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        NOP,                    # [0]  PC=0   padding
        AUIPC(1, 0),           # [1]  PC=4   x1 = 4
        JALR (0, 1, 24),      # [2]  PC=8   target=4+24=28=[7]
        NOP,                    # [3]  PC=12  shadow
        NOP,                    # [4]  PC=16  shadow
        NOP,                    # [5]  PC=20
        NOP,                    # [6]  PC=24
        ADDI(10, 0, 0x42),    # [7]  PC=28  target
        NOP,
    ]
    # fmt: on

    await run_r_test(dut, prog, reg_init={}, expected={10: 0x42})


@cocotb.test()
async def test_recursive_countdown(dut):
    """Recursive function: decrement n, accumulate count, recurse until n=0.

    Uses SW/LW with a byte-addressed stack pointer (x20) to save and
    restore the return address across recursive calls.

    Assembly:

        # main
        [0]   ADDI x1, x0, 3        # n = 3
        [1]   ADDI x2, x0, 0        # result = 0
        [2]   ADDI x20, x0, 0       # sp = byte 0
        [3]   JAL  x5, +24          # call func at [9]=PC=36; x5=16
        [4]   NOP                    # shadow / return
        [5]   NOP                    # shadow / return
        [6]   BEQ  x0, x0, 0        # done — self-loop (halt)
        [7]   NOP                    # (not reached)
        [8]   NOP                    # (not reached)

        # func @ PC=36
        [9]   BEQ  x1, x0, +32     # if n==0: skip to unwind=[17]
        [10]  NOP                    # BEQ shadow (taken path)
        [11]  NOP                    # BEQ shadow (taken path)
        [12]  ADDI x2, x2, 1        # result++
        [13]  ADDI x1, x1, -1       # n--
        [14]  SW   x20, x5, 0       # save ra to stack
        [15]  ADDI x20, x20, 4      # sp += 4
        [16]  JAL  x5, -28          # recurse; target=64-28=36=[9]; x5=68
        [17]  NOP                    # JAL shadow / BEQ base-case target
        [18]  NOP                    # JAL shadow
        [19]  ADDI x20, x20, -4     # sp -= 4
        [20]  LW   x5, x20, 0       # restore ra
        [21]  JALR x0, x5, 0        # return
        [22]  NOP                    # shadow

    Trace (n=3):
        call  depth 1: n=3→x2=1,n=2, save ra=16,  sp=4,  recurse x5=68
        call  depth 2: n=2→x2=2,n=1, save ra=68,  sp=8,  recurse x5=68
        call  depth 3: n=1→x2=3,n=0, save ra=68,  sp=12, recurse x5=68
        base  depth 4: n=0, BEQ taken → unwind
        unwind 4→3: sp=8,  restore ra=68  → return to [17]
        unwind 3→2: sp=4,  restore ra=68  → return to [17]
        unwind 2→1: sp=0,  restore ra=16  → return to main [4]

    Expected: x2=3 (incremented 3 times), x1=0 (decremented to 0)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        # main
        ADDI( 1, 0,  3),      # [0]  PC=0   n=3
        ADDI( 2, 0,  0),      # [1]  PC=4   result=0
        ADDI(20, 0,  0),      # [2]  PC=8   sp=0
        JAL ( 5, 24),         # [3]  PC=12  call func; x5=16, target=36=[9]
        NOP,                   # [4]  PC=16  shadow / return
        NOP,                   # [5]  PC=20  shadow / return
        BEQ ( 0, 0,  0),      # [6]  PC=24  done — self-loop (halt)
        NOP,                   # [7]  PC=28  (not reached)
        NOP,                   # [8]  PC=32  (not reached)

        # func @ PC=36
        BEQ ( 1, 0, 32),      # [9]  PC=36  if n==0: unwind; target=68=[17]
        NOP,                   # [10] PC=40  shadow (BEQ taken)
        NOP,                   # [11] PC=44  shadow (BEQ taken)
        ADDI( 2, 2,  1),      # [12] PC=48  result++
        ADDI( 1, 1, -1),      # [13] PC=52  n--
        SW  (20, 5,  0),      # [14] PC=56  save ra
        ADDI(20, 20, 4),      # [15] PC=60  sp += 4
        JAL ( 5, -28),        # [16] PC=64  recurse; x5=68, target=36=[9]
        NOP,                   # [17] PC=68  JAL shadow / BEQ target
        NOP,                   # [18] PC=72  JAL shadow
        ADDI(20, 20, -4),     # [19] PC=76  sp -= 4
        LW  ( 5, 20, 0),      # [20] PC=80  restore ra
        JALR( 0, 5,  0),      # [21] PC=84  return
        NOP,                   # [22] PC=88  shadow
    ]
    # fmt: on

    load_imem(dut, prog)
    await do_reset(dut)
    await clock_n(dut, 250)

    assert read_reg(dut, 2) == 3, f"x2 (result): expected 3, got {read_reg(dut, 2)}"
    assert read_reg(dut, 1) == 0, f"x1 (n): expected 0, got {read_reg(dut, 1)}"


@cocotb.test()
async def test_jalr_jump_table(dut):
    """Indexed indirect jump via JALR — a computed jump table.

    Computes the entry address from an index, builds a pointer via
    SLLI + ADD, and uses JALR to dispatch.  Each table entry writes
    a unique sentinel to x10 and branches to a common exit.

    x1 is pre-loaded via write_reg (not ADDI) so the test loop can
    override the index for each case.

    Assembly:

        [0]   SLLI x2, x1, 3        # x2 = index * 8  (2 instrs/entry = 8 bytes)
        [1]   ADDI x3, x0, 24       # base = PC of entry 0 = 24 = [6]
        [2]   ADD  x4, x3, x2       # target = base + offset
        [3]   JALR x0, x4, 0        # jump to entry; link discarded
        [4]   NOP                    # shadow
        [5]   NOP                    # shadow

        # entry 0 @ PC=24
        [6]   ADDI x10, x0, 100     # sentinel
        [7]   BEQ  x0, x0, +20      # done; PC=28+20=48=[12]

        # entry 1 @ PC=32
        [8]   ADDI x10, x0, 200     # sentinel
        [9]   BEQ  x0, x0, +12      # done; PC=36+12=48=[12]

        # entry 2 @ PC=40
        [10]  ADDI x10, x0, 300     # sentinel
        [11]  BEQ  x0, x0, +4       # done; PC=44+4=48=[12]

        # done
        [12]  NOP

    Expected: x10 = sentinel for the selected entry
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        SLLI( 2, 1,  3),      # [0]  PC=0   offset = index * 8
        ADDI( 3, 0, 24),      # [1]  PC=4   base = 24 (entry 0 @ [6])
        ADD ( 4, 3,  2),      # [2]  PC=8   target = base + offset
        JALR( 0, 4,  0),      # [3]  PC=12  jump to entry; link discarded
        NOP,                   # [4]  PC=16  shadow
        NOP,                   # [5]  PC=20  shadow
        # entry 0 @ PC=24
        ADDI(10, 0, 100),     # [6]  PC=24
        BEQ ( 0, 0, 20),      # [7]  PC=28  done=48=[12]
        # entry 1 @ PC=32
        ADDI(10, 0, 200),     # [8]  PC=32
        BEQ ( 0, 0, 12),      # [9]  PC=36  done=48=[12]
        # entry 2 @ PC=40
        ADDI(10, 0, 300),     # [10] PC=40
        BEQ ( 0, 0,  4),      # [11] PC=44  done=48=[12]
        # done
        NOP,                   # [12] PC=48
    ]
    # fmt: on

    # Test all three entries
    test_cases = [
        (0, 100),
        (1, 200),
        (2, 300),
    ]

    for idx, expected_sentinel in test_cases:
        load_imem(dut, prog)
        await do_reset(dut)
        write_reg(dut, 1, idx)
        await clock_n(dut, 30)

        got = read_reg(dut, 10)
        assert got == expected_sentinel, (
            f"jump_table[{idx}]: expected {expected_sentinel}, got {got}"
        )
