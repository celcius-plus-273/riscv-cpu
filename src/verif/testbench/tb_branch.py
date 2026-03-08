"""
cocotb Testbench: rv_cpu  —  Branch & Jump Instruction Tests
=============================================================

Verifies the taken/not-taken decision for every B-type instruction
and the link+jump behaviour for JAL and JALR.

Test pattern
------------
Every branch test uses the same 4-instruction layout:

    [0]  BXX  x1, x2, +12   # branch under test; target = byte 12 = index 3
    [1]  ADDI x10, x0, 0xAA # shadow-1 → written only if branch NOT taken
    [2]  ADDI x10, x0, 0xBB # shadow-2 → written only if branch NOT taken
    [3]  ADDI x11, x0, 0xFF # target label  → executes in both paths

  Branch TAKEN  : shadows killed by flush → x10 == 0,    x11 == 0xFF
  Branch NOT TAKEN : shadows run normally → x10 == 0xBB, x11 == 0xFF

No RAW hazards — x1 and x2 are pre-initialised via write_reg() before
execution; neither is written inside the test program.

Branch condition truth table  (from control.sv + pipe_ex.sv)
-------------------------------------------------------------
  Instruction  ALU-op  branch_sign  Taken when
  -----------  ------  -----------  --------------------------------------------------
  BEQ          SUB     0            rs1 == rs2             (sub result == 0)
  BNE          SUB     1            rs1 != rs2             (sub result != 0)
  BLT          SLT     1            rs1 <  rs2  (signed)   (SLT result != 0)
  BGE          SLT     0            rs1 >= rs2  (signed)   (SLT result == 0)
  BLTU         SLTU    1            rs1 <  rs2  (unsigned) (SLTU result != 0)
  BGEU         SLTU    0            rs1 >= rs2  (unsigned) (SLTU result == 0)
  JAL          ADD     —            always (is_jump)
  JALR         ADD     —            always (is_jump); target = (rs1 + imm)

Run with:
    inv sim --testbench tb_branch
"""

import cocotb
from cocotb.clock import Clock

import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent))
from tb_helpers import (
    CLK_PERIOD_NS, N_NOPS, PIPE_DEPTH,
    NOP, ADDI, JAL, JALR,
    BEQ, BNE, BLT, BGE, BLTU, BGEU,
    u32, s32,
    load_imem, do_reset, clock_n,
    write_reg, read_reg,
)


# ---------------------------------------------------------------------------
# Shared helpers
# ---------------------------------------------------------------------------

_SHADOW_VAL   = 0xBB   # last value written by shadow-2 (proves shadows ran)
_TARGET_VAL   = 0xFF   # value written at the branch target
_X10_TAKEN    = 0x00   # x10 when branch is taken (shadows killed)
_X10_NOTAKEN  = _SHADOW_VAL  # x10 when branch is not taken (shadows ran)


def _branch_prog(branch_instr):
    """Return the standard 4-instruction branch test program.

    [0]  branch_instr (BXX x1, x2, +12 — target index 3)
    [1]  ADDI x10, x0, 0xAA   (shadow-1)
    [2]  ADDI x10, x0, 0xBB   (shadow-2)
    [3]  ADDI x11, x0, 0xFF   (branch target)
    """
    return (
        [branch_instr]          +
        [ADDI(10, 0, 0xAA)]     +   # shadow-1
        [ADDI(10, 0, 0xBB)]     +   # shadow-2
        [ADDI(11, 0, 0xFF)]     +   # target
        [NOP] * N_NOPS
    )


async def _run_branch(dut, branch_instr, x1, x2, *, expect_taken):
    """Run a branch test and verify x10 and x11.

    Args:
        branch_instr : encoded instruction word for BXX x1, x2, +12
        x1, x2       : pre-initialised register values
        expect_taken : True → assert x10==0 (shadows killed)
                       False → assert x10==0xBB (shadows ran)
    """
    prog = _branch_prog(branch_instr)
    load_imem(dut, prog)
    await do_reset(dut)
    write_reg(dut, 1, x1)
    write_reg(dut, 2, x2)
    await clock_n(dut, len(prog) + PIPE_DEPTH)

    got_x10 = read_reg(dut, 10)
    got_x11 = read_reg(dut, 11)
    exp_x10 = _X10_TAKEN if expect_taken else _X10_NOTAKEN

    assert got_x10 == exp_x10, (
        f"x10: expected 0x{exp_x10:08x} ({'taken' if expect_taken else 'not-taken'}), "
        f"got 0x{got_x10:08x}"
    )
    assert got_x11 == _TARGET_VAL, (
        f"x11 (target sentinel): expected 0x{_TARGET_VAL:08x}, got 0x{got_x11:08x}"
    )


# ===========================================================================
# BEQ — branch if equal
# ===========================================================================

@cocotb.test()
async def test_beq_taken(dut):
    """BEQ taken: rs1 == rs2  →  shadows flushed, target executes."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BEQ(1, 2, 12), x1=42, x2=42, expect_taken=True)


@cocotb.test()
async def test_beq_not_taken(dut):
    """BEQ not taken: rs1 != rs2  →  shadow instructions execute."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BEQ(1, 2, 12), x1=42, x2=99, expect_taken=False)


@cocotb.test()
async def test_beq_taken_zero_operands(dut):
    """BEQ taken: both operands are 0 (x0 hardwired zero)."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # x1=x2=0 → equal
    await _run_branch(dut, BEQ(1, 2, 12), x1=0, x2=0, expect_taken=True)


# ===========================================================================
# BNE — branch if not equal
# ===========================================================================

@cocotb.test()
async def test_bne_taken(dut):
    """BNE taken: rs1 != rs2  →  shadows flushed."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BNE(1, 2, 12), x1=10, x2=20, expect_taken=True)


@cocotb.test()
async def test_bne_not_taken(dut):
    """BNE not taken: rs1 == rs2  →  no flush."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BNE(1, 2, 12), x1=77, x2=77, expect_taken=False)


# ===========================================================================
# BLT — branch if less than (signed)
# ===========================================================================

@cocotb.test()
async def test_blt_taken(dut):
    """BLT taken: rs1 < rs2 (signed)  →  shadows flushed."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BLT(1, 2, 12), x1=5, x2=10, expect_taken=True)


@cocotb.test()
async def test_blt_not_taken_equal(dut):
    """BLT not taken: rs1 == rs2  →  BLT requires strict less-than."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BLT(1, 2, 12), x1=7, x2=7, expect_taken=False)


@cocotb.test()
async def test_blt_not_taken_greater(dut):
    """BLT not taken: rs1 > rs2 (signed)."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BLT(1, 2, 12), x1=20, x2=10, expect_taken=False)


@cocotb.test()
async def test_blt_taken_signed_negative(dut):
    """BLT taken: negative rs1 < positive rs2 using signed interpretation.

    0xFFFF_FFFF = -1 signed; -1 < 1 so BLT should be taken.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BLT(1, 2, 12),
                      x1=u32(-1), x2=1, expect_taken=True)


@cocotb.test()
async def test_blt_not_taken_positive_vs_negative(dut):
    """BLT not taken: positive rs1 > negative rs2 (signed).

    1 > -1 (signed), so BLT(1, -1) should NOT be taken.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BLT(1, 2, 12),
                      x1=1, x2=u32(-1), expect_taken=False)


# ===========================================================================
# BGE — branch if greater-or-equal (signed)
# ===========================================================================

@cocotb.test()
async def test_bge_taken_equal(dut):
    """BGE taken: rs1 == rs2  →  >= satisfied."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BGE(1, 2, 12), x1=50, x2=50, expect_taken=True)


@cocotb.test()
async def test_bge_taken_greater(dut):
    """BGE taken: rs1 > rs2 (signed)."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BGE(1, 2, 12), x1=100, x2=50, expect_taken=True)


@cocotb.test()
async def test_bge_not_taken(dut):
    """BGE not taken: rs1 < rs2 (signed)."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BGE(1, 2, 12), x1=3, x2=10, expect_taken=False)


@cocotb.test()
async def test_bge_taken_positive_vs_negative(dut):
    """BGE taken: positive rs1 >= negative rs2 (signed interpretation).

    1 >= -1 (signed), so BGE should be taken.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BGE(1, 2, 12),
                      x1=1, x2=u32(-1), expect_taken=True)


# ===========================================================================
# BLTU — branch if less than (unsigned)
# ===========================================================================

@cocotb.test()
async def test_bltu_taken(dut):
    """BLTU taken: rs1 < rs2 (unsigned)."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BLTU(1, 2, 12), x1=1, x2=100, expect_taken=True)


@cocotb.test()
async def test_bltu_not_taken(dut):
    """BLTU not taken: rs1 > rs2 (unsigned)."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BLTU(1, 2, 12), x1=100, x2=1, expect_taken=False)


@cocotb.test()
async def test_bltu_taken_sign_bit(dut):
    """BLTU taken: 1 < 0xFFFF_FFFF unsigned (sign bit makes it a large positive).

    0xFFFF_FFFF is the largest unsigned 32-bit value, so 1 < 0xFFFF_FFFF.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BLTU(1, 2, 12),
                      x1=1, x2=0xFFFF_FFFF, expect_taken=True)


@cocotb.test()
async def test_bltu_not_taken_sign_bit(dut):
    """BLTU not taken: 0xFFFF_FFFF is NOT < 1 unsigned.

    Contrasts with BLT: -1 < 1 signed but 0xFFFF_FFFF > 1 unsigned.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BLTU(1, 2, 12),
                      x1=0xFFFF_FFFF, x2=1, expect_taken=False)


# ===========================================================================
# BGEU — branch if greater-or-equal (unsigned)
# ===========================================================================

@cocotb.test()
async def test_bgeu_taken_equal(dut):
    """BGEU taken: rs1 == rs2 → >= satisfied (unsigned)."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BGEU(1, 2, 12), x1=42, x2=42, expect_taken=True)


@cocotb.test()
async def test_bgeu_taken_sign_bit(dut):
    """BGEU taken: 0xFFFF_FFFF >= 1 (unsigned; sign bit = large positive)."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BGEU(1, 2, 12),
                      x1=0xFFFF_FFFF, x2=1, expect_taken=True)


@cocotb.test()
async def test_bgeu_not_taken(dut):
    """BGEU not taken: rs1 < rs2 (unsigned)."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await _run_branch(dut, BGEU(1, 2, 12), x1=0, x2=1, expect_taken=False)


# ===========================================================================
# JAL — unconditional jump and link
# ===========================================================================

@cocotb.test()
async def test_jal_link_and_jump(dut):
    """JAL always jumps; writes PC+4 (the return address) to rd.

    JAL x10, +12 at PC=0:
        rd   (x10) = PC + 4 = 4
        target PC  = 0 + 12 = 12  (index 3)

    Program:
        [0] JAL  x10, +12       x10 = 4, jump to index 3
        [1] ADDI x11, x0, 0xAA  shadow-1 (must be killed)
        [2] ADDI x11, x0, 0xBB  shadow-2 (must be killed)
        [3] ADDI x12, x0, 0xFF  target sentinel
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [JAL (10, 12)]       +   # link x10 = PC+4 = 4; jump to index 3
        [ADDI(11, 0, 0xAA)]  +   # shadow-1 → must be killed
        [ADDI(11, 0, 0xBB)]  +   # shadow-2 → must be killed
        [ADDI(12, 0, 0xFF)]  +   # target
        [NOP] * N_NOPS
    )

    load_imem(dut, prog)
    await do_reset(dut)
    await clock_n(dut, len(prog) + PIPE_DEPTH)

    assert read_reg(dut, 10) == 4, (
        f"x10 (link): expected 4, got {read_reg(dut, 10)}"
    )
    assert read_reg(dut, 11) == 0, (
        f"x11 (shadow sentinel): expected 0 (killed), got 0x{read_reg(dut, 11):08x}"
    )
    assert read_reg(dut, 12) == 0xFF, (
        f"x12 (target sentinel): expected 0xFF, got 0x{read_reg(dut, 12):08x}"
    )


# ===========================================================================
# JALR — indirect jump and link
# ===========================================================================

@cocotb.test()
async def test_jalr_link_and_jump(dut):
    """JALR jumps to rs1 + imm and writes PC+4 to rd.

    JALR x10, x1, 4 at PC=0  (x1=8):
        target = (8 + 4) = 12  (index 3)
        rd (x10) = PC + 4 = 4

    Program:
        [0] JALR x10, x1, 4    link x10=4, target=x1+4=12
        [1] ADDI x11, x0, 0xAA shadow-1 (must be killed)
        [2] ADDI x11, x0, 0xBB shadow-2 (must be killed)
        [3] ADDI x12, x0, 0xFF target sentinel
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [JALR(10, 1, 4)]     +   # link x10=4; target=x1+4=12=index3
        [ADDI(11, 0, 0xAA)]  +   # shadow-1 → must be killed
        [ADDI(11, 0, 0xBB)]  +   # shadow-2 → must be killed
        [ADDI(12, 0, 0xFF)]  +   # target
        [NOP] * N_NOPS
    )

    load_imem(dut, prog)
    await do_reset(dut)
    write_reg(dut, 1, 8)   # x1 = 8  →  target = 8 + 4 = 12
    await clock_n(dut, len(prog) + PIPE_DEPTH)

    assert read_reg(dut, 10) == 4, (
        f"x10 (link): expected 4, got {read_reg(dut, 10)}"
    )
    assert read_reg(dut, 11) == 0, (
        f"x11 (shadow sentinel): expected 0 (killed), got 0x{read_reg(dut, 11):08x}"
    )
    assert read_reg(dut, 12) == 0xFF, (
        f"x12 (target sentinel): expected 0xFF, got 0x{read_reg(dut, 12):08x}"
    )


@cocotb.test()
async def test_jalr_zero_offset(dut):
    """JALR with imm=0: target = rs1 exactly.

    JALR x10, x1, 0  (x1=12):
        target = 12 + 0 = 12  (index 3)
        x10    = PC + 4 = 4
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = (
        [JALR(10, 1, 0)]     +   # link x10=4; target=x1=12
        [ADDI(11, 0, 0xAA)]  +
        [ADDI(11, 0, 0xBB)]  +
        [ADDI(12, 0, 0xFF)]  +   # target
        [NOP] * N_NOPS
    )

    load_imem(dut, prog)
    await do_reset(dut)
    write_reg(dut, 1, 12)   # x1 = 12  →  target = 12
    await clock_n(dut, len(prog) + PIPE_DEPTH)

    assert read_reg(dut, 10) == 4,    f"x10 (link): expected 4"
    assert read_reg(dut, 11) == 0,    f"x11 (shadow): expected 0 (killed)"
    assert read_reg(dut, 12) == 0xFF, f"x12 (target): expected 0xFF"
