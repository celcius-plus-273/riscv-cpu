"""
cocotb Testbench: rv_cpu  —  I-type Immediate Arithmetic Tests
==============================================================

Verifies all I-type immediate arithmetic instructions other than ADDI:

    SLTI  — set-less-than immediate (signed comparison)
    SLTIU — set-less-than immediate unsigned (unsigned comparison)
    XORI  — XOR immediate (bitwise)
    ORI   — OR immediate  (bitwise)
    ANDI  — AND immediate (bitwise)
    SLLI  — shift left logical immediate
    SRLI  — shift right logical immediate   (zero-fill — distinguishes from SRAI)
    SRAI  — shift right arithmetic immediate (sign-fill)

Key properties exercised
-------------------------
  - Sign-extension of the 12-bit immediate to 32 bits before use
  - SLTI vs SLTIU: signed vs unsigned interpretation of the same bit pattern
  - SRLI vs SRAI: zero-fill vs sign-fill on the same negative input
  - SRAI funct7 bit 30 distinguishes it from SRLI (same funct3, same opcode)
  - Bitwise NOT idiom: XORI rd, rs1, -1  (imm sign-extends to 0xFFFFFFFF)
  - Alignment mask idiom: ANDI rd, rs1, -4 (imm → 0xFFFFFFFC, clears low 2 bits)

Run with:
    inv sim --testbench tb_i_arith
"""

import cocotb
from cocotb.clock import Clock

import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent))
from tb_helpers import (
    CLK_PERIOD_NS, PIPE_DEPTH,
    NOP,
    SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI,
    u32, s32,
    run_r_test,
)


# ===========================================================================
# SLTI — set less than immediate (signed comparison)
# ===========================================================================

@cocotb.test()
async def test_slti_taken(dut):
    """SLTI taken: rs1 < imm (both positive) → result = 1."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 5 < 10 (signed) → x10 = 1
    await run_r_test(dut,
                     program=[SLTI(10, 1, 10), NOP],
                     reg_init={1: 5},
                     expected={10: 1})


@cocotb.test()
async def test_slti_not_taken_equal(dut):
    """SLTI not taken: rs1 == imm → strictly less-than is false → result = 0."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 7 < 7 → false → x10 = 0
    await run_r_test(dut,
                     program=[SLTI(10, 1, 7), NOP],
                     reg_init={1: 7},
                     expected={10: 0})


@cocotb.test()
async def test_slti_signed_negative_rs1(dut):
    """SLTI: rs1 negative (0xFFFFFFFF = -1 signed) < imm=0 → result = 1.

    Verifies that the hardware interprets rs1 as a signed value.
    0xFFFFFFFF looks large unsigned but is -1 signed, so -1 < 0 is true.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # x1 = -1 (signed) = 0xFFFFFFFF; imm = 0 → -1 < 0 signed → x10 = 1
    await run_r_test(dut,
                     program=[SLTI(10, 1, 0), NOP],
                     reg_init={1: u32(-1)},
                     expected={10: 1})


@cocotb.test()
async def test_slti_signed_negative_imm(dut):
    """SLTI: rs1 = -5 signed, imm = -1 signed → -5 < -1 → result = 1."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # x1 = -5; imm = -1 (sign-extends from 0xFFB to 0xFFFFFFFB) → -5 < -1 → 1
    await run_r_test(dut,
                     program=[SLTI(10, 1, -1), NOP],
                     reg_init={1: u32(-5)},
                     expected={10: 1})


# ===========================================================================
# SLTIU — set less than immediate unsigned
# ===========================================================================

@cocotb.test()
async def test_sltiu_taken(dut):
    """SLTIU taken: rs1 < imm (both small positive) → result = 1."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 10 < 50 unsigned → x10 = 1
    await run_r_test(dut,
                     program=[SLTIU(10, 1, 50), NOP],
                     reg_init={1: 10},
                     expected={10: 1})


@cocotb.test()
async def test_sltiu_not_taken(dut):
    """SLTIU not taken: rs1 > imm → result = 0."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 100 < 50 → false → x10 = 0
    await run_r_test(dut,
                     program=[SLTIU(10, 1, 50), NOP],
                     reg_init={1: 100},
                     expected={10: 0})


@cocotb.test()
async def test_sltiu_sign_extends_imm_to_large_unsigned(dut):
    """SLTIU: imm=-1 sign-extends to 0xFFFFFFFF (max uint32).

    Any value of rs1 except 0xFFFFFFFF is less than 0xFFFFFFFF unsigned.
    Contrasts with SLTI: 0 < -1 is FALSE signed, but 0 < 0xFFFFFFFF is TRUE unsigned.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # imm = -1 → 0xFFFFFFFF unsigned; x1 = 0 < 0xFFFFFFFF → x10 = 1
    await run_r_test(dut,
                     program=[SLTIU(10, 1, -1), NOP],
                     reg_init={1: 0},
                     expected={10: 1})


# ===========================================================================
# XORI — XOR immediate
# ===========================================================================

@cocotb.test()
async def test_xori_toggle_bits(dut):
    """XORI: selectively invert bits using a mask immediate.

    Only the bits set in the immediate are flipped; others remain unchanged.
    x1=0xAA (10101010), imm=0x55 (01010101) → result=0xFF (alternating pattern inverted).
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 0xAA XOR 0x55 = 0xFF
    await run_r_test(dut,
                     program=[XORI(10, 1, 0x55), NOP],
                     reg_init={1: 0xAA},
                     expected={10: 0xFF})


@cocotb.test()
async def test_xori_bitwise_not(dut):
    """XORI with imm=-1 implements bitwise NOT.

    imm=-1 sign-extends to 0xFFFFFFFF.  XOR with all-ones flips every bit.
    This is the standard RISC-V bitwise-NOT idiom.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 0x12345678 XOR 0xFFFFFFFF = 0xEDCBA987
    await run_r_test(dut,
                     program=[XORI(10, 1, -1), NOP],
                     reg_init={1: 0x12345678},
                     expected={10: u32(~0x12345678)})


# ===========================================================================
# ORI — OR immediate
# ===========================================================================

@cocotb.test()
async def test_ori_set_low_nibbles(dut):
    """ORI: set the two low nibbles of a value."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 0xF0 OR 0x0F = 0xFF
    await run_r_test(dut,
                     program=[ORI(10, 1, 0x0F), NOP],
                     reg_init={1: 0xF0},
                     expected={10: 0xFF})


@cocotb.test()
async def test_ori_identity_zero_imm(dut):
    """ORI with imm=0 is the identity: result equals rs1 unchanged."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 0xDEAD0000 OR 0 = 0xDEAD0000; tests that OR with zero is a no-op
    await run_r_test(dut,
                     program=[ORI(10, 1, 0), NOP],
                     reg_init={1: 0xDEAD0000},
                     expected={10: 0xDEAD0000})


# ===========================================================================
# ANDI — AND immediate
# ===========================================================================

@cocotb.test()
async def test_andi_extract_low_byte(dut):
    """ANDI with imm=0xFF extracts the low byte of rs1."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 0xDEADBEEF AND 0xFF = 0xEF
    # imm=0xFF: bit 11=0, sign-extends to 0x000000FF ✓
    await run_r_test(dut,
                     program=[ANDI(10, 1, 0xFF), NOP],
                     reg_init={1: 0xDEADBEEF},
                     expected={10: 0xEF})


@cocotb.test()
async def test_andi_clears_all_with_zero_imm(dut):
    """ANDI with imm=0 always produces 0 regardless of rs1."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await run_r_test(dut,
                     program=[ANDI(10, 1, 0), NOP],
                     reg_init={1: 0xFFFFFFFF},
                     expected={10: 0})


@cocotb.test()
async def test_andi_alignment_mask(dut):
    """ANDI with imm=-4 clears the low 2 bits — 4-byte alignment mask.

    imm=-4 (0xFFC in 12 bits) sign-extends to 0xFFFFFFFC.
    AND-ing any address with this rounds down to the nearest 4-byte boundary.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 0x1007 AND 0xFFFFFFFC = 0x1004  (next lower word boundary)
    await run_r_test(dut,
                     program=[ANDI(10, 1, -4), NOP],
                     reg_init={1: 0x1007},
                     expected={10: 0x1004})


# ===========================================================================
# SLLI — shift left logical immediate
# ===========================================================================

@cocotb.test()
async def test_slli_multiply_by_eight(dut):
    """SLLI by 3 is equivalent to unsigned multiply-by-8."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 7 << 3 = 56
    await run_r_test(dut,
                     program=[SLLI(10, 1, 3), NOP],
                     reg_init={1: 7},
                     expected={10: 56})


@cocotb.test()
async def test_slli_moves_byte_to_high_halfword(dut):
    """SLLI by 16 shifts a byte into the upper halfword."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 0xAB << 16 = 0x00AB0000
    await run_r_test(dut,
                     program=[SLLI(10, 1, 16), NOP],
                     reg_init={1: 0xAB},
                     expected={10: 0x00AB0000})


# ===========================================================================
# SRLI — shift right logical immediate (zero-fill)
# ===========================================================================

@cocotb.test()
async def test_srli_zero_fills_msb(dut):
    """SRLI always fills the vacated MSBs with zero, even when MSB is set.

    This is the critical test distinguishing SRLI from SRAI.
    Input 0x80000000 has MSB=1 (negative signed).
    SRLI should fill with 0 → 0x40000000.
    SRAI would fill with 1 → 0xC0000000 (wrong for SRLI).
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 0x80000000 >> 1 (logical) = 0x40000000
    await run_r_test(dut,
                     program=[SRLI(10, 1, 1), NOP],
                     reg_init={1: 0x80000000},
                     expected={10: 0x40000000})


# ===========================================================================
# SRAI — shift right arithmetic immediate (sign-fill)
# ===========================================================================

@cocotb.test()
async def test_srai_negative_sign_fills_msb(dut):
    """SRAI fills vacated MSBs with the sign bit (1 for negative numbers).

    Shifting 0x80000000 (the most-negative 32-bit signed value) right by 31
    should produce 0xFFFFFFFF (all bits = sign bit = 1).
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 0x80000000 >> 31 (arithmetic) = 0xFFFFFFFF
    await run_r_test(dut,
                     program=[SRAI(10, 1, 31), NOP],
                     reg_init={1: 0x80000000},
                     expected={10: u32(-1)})


@cocotb.test()
async def test_srai_positive_zero_fills_msb(dut):
    """SRAI fills vacated MSBs with 0 for positive (non-negative) inputs.

    Shifting 0x7FFFFFFF (max positive signed) right by 31 should produce 0,
    since the sign bit is 0 and all non-sign bits shift out.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 0x7FFFFFFF >> 31 (arithmetic) = 0x00000000
    await run_r_test(dut,
                     program=[SRAI(10, 1, 31), NOP],
                     reg_init={1: 0x7FFFFFFF},
                     expected={10: 0})


@cocotb.test()
async def test_srai_partial_shift_sign_extension(dut):
    """SRAI partial shift: verify sign-bit replication over a multi-bit shift.

    0xFF000000 shifted right by 8 (arithmetic) inserts 8 ones from the top,
    giving 0xFFFF0000.  Verifies sign-fill for a shift amount other than 1/31.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # 0xFF000000 >> 8 (arithmetic) = 0xFFFF0000
    await run_r_test(dut,
                     program=[SRAI(10, 1, 8), NOP],
                     reg_init={1: 0xFF000000},
                     expected={10: 0xFFFF0000})
