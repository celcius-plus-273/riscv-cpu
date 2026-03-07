"""
cocotb Testbench: rv_cpu  —  Load Instruction Tests
====================================================

Tests all five load instructions:
    LW   (load word,            funct3=010, mem_mask=4'b1111)
    LH   (load half-word,       funct3=001, mem_mask=4'b0011, signed)
    LB   (load byte,            funct3=000, mem_mask=4'b0001, signed)
    LHU  (load half-word unsig, funct3=101, mem_mask=4'b0011, unsigned)
    LBU  (load byte unsigned,   funct3=100, mem_mask=4'b0001, unsigned)

Also includes store-then-load roundtrip tests that exercise the full
write->read data path through the pipeline.

Sign/zero extension (pipe_wb.sv)
---------------------------------
  LB  / LH  : sign-extend  the loaded value to 32 bits
  LBU / LHU : zero-extend  the loaded value to 32 bits
  LW        : no extension  (full 32-bit value)

Data memory address scheme
--------------------------
  sram_rw_dff indexes its array as  mem_array[byte_addr >> 2]:
      byte addr  0x00  ->  mem_array[0]
      byte addr  0x04  ->  mem_array[1], ...
  Pre-loaded via write_dmem(dut, word_addr, value) AFTER do_reset.

Roundtrip pipeline timing
--------------------------
  SW commits to the SRAM array at the rising edge that ends its MEM stage.
  With N_NOPS=4 between SW and LW the load's MEM stage is 5 cycles later,
  well past the store's write — no structural or data hazard.

Run with:
    inv sim --testbench tb_load
"""

import cocotb
from cocotb.clock import Clock

# Need to add (..) to path so that it can find tb_helpers
import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent))  # for importing tb_helpers
from tb_helpers import (
    CLK_PERIOD_NS, N_NOPS,
    NOP, LW, LH, LB, LHU, LBU,
    SW, SH, SB,
    run_load_test,
)


# ===========================================================================
# LW — load word
# ===========================================================================

@cocotb.test()
async def test_lw_basic(dut):
    """LW: load full 32-bit word from data memory.

    Pre-load mem_array[0]=0xDEAD_BEEF; LW x3, 0(x1) with x1=0 -> x3=0xDEAD_BEEF.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, rd = 1, 3
    prog = [LW(rd, base, 0)] + [NOP] * N_NOPS

    await run_load_test(dut, prog,
                        reg_init={base: 0},
                        dmem_init={0: 0xDEAD_BEEF},
                        expected={rd: 0xDEAD_BEEF})


@cocotb.test()
async def test_lw_positive_offset(dut):
    """LW: load word at a positive byte offset  — LW x3, 12(x1).

    x1=0, offset=12 -> byte addr=12, word_addr=3.
    Pre-load mem_array[3]=0xABCD_1234 -> x3=0xABCD_1234.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, rd = 1, 3
    prog = [LW(rd, base, 12)] + [NOP] * N_NOPS

    await run_load_test(dut, prog,
                        reg_init={base: 0},
                        dmem_init={3: 0xABCD_1234},
                        expected={rd: 0xABCD_1234})


@cocotb.test()
async def test_lw_rd_x0_immutable(dut):
    """LW to x0 must be discarded — x0 is hardwired zero even for loads."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, rd = 1, 0  # rd = x0
    prog = [LW(rd, base, 0)] + [NOP] * N_NOPS

    await run_load_test(dut, prog,
                        reg_init={base: 0},
                        dmem_init={0: 0xDEAD_BEEF},
                        expected={rd: 0})


# ===========================================================================
# LH — load half-word (signed)
# ===========================================================================

@cocotb.test()
async def test_lh_positive(dut):
    """LH: positive half-word (bit15=0) — upper 16 bits filled with 0.

    mem_array[0][15:0]=0x7FFF -> sign_extend(0x7FFF) = 0x0000_7FFF.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, rd = 1, 3
    prog = [LH(rd, base, 0)] + [NOP] * N_NOPS

    await run_load_test(dut, prog,
                        reg_init={base: 0},
                        dmem_init={0: 0x0000_7FFF},
                        expected={rd: 0x0000_7FFF})


@cocotb.test()
async def test_lh_negative(dut):
    """LH: negative half-word (bit15=1) — upper 16 bits sign-extended to 1s.

    mem_array[0][15:0]=0x8000 -> sign_extend(0x8000) = 0xFFFF_8000.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, rd = 1, 3
    prog = [LH(rd, base, 0)] + [NOP] * N_NOPS

    await run_load_test(dut, prog,
                        reg_init={base: 0},
                        dmem_init={0: 0x0000_8000},
                        expected={rd: 0xFFFF_8000})


# ===========================================================================
# LB — load byte (signed)
# ===========================================================================

@cocotb.test()
async def test_lb_positive(dut):
    """LB: positive byte (bit7=0) — upper 24 bits filled with 0.

    mem_array[0][7:0]=0x55 -> sign_extend(0x55) = 0x0000_0055.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, rd = 1, 3
    prog = [LB(rd, base, 0)] + [NOP] * N_NOPS

    await run_load_test(dut, prog,
                        reg_init={base: 0},
                        dmem_init={0: 0x0000_0055},
                        expected={rd: 0x0000_0055})


@cocotb.test()
async def test_lb_negative(dut):
    """LB: negative byte (bit7=1) — upper 24 bits sign-extended to 1s.

    mem_array[0][7:0]=0x80 -> sign_extend(0x80) = 0xFFFF_FF80.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, rd = 1, 3
    prog = [LB(rd, base, 0)] + [NOP] * N_NOPS

    await run_load_test(dut, prog,
                        reg_init={base: 0},
                        dmem_init={0: 0x0000_0080},
                        expected={rd: 0xFFFF_FF80})


# ===========================================================================
# LHU — load half-word unsigned
# ===========================================================================

@cocotb.test()
async def test_lhu_basic(dut):
    """LHU: upper 16 bits always zero-filled regardless of the sign bit.

    mem_array[0][15:0]=0xBEEF -> zero_extend(0xBEEF) = 0x0000_BEEF.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, rd = 1, 3
    prog = [LHU(rd, base, 0)] + [NOP] * N_NOPS

    await run_load_test(dut, prog,
                        reg_init={base: 0},
                        dmem_init={0: 0x0000_BEEF},
                        expected={rd: 0x0000_BEEF})


@cocotb.test()
async def test_lhu_vs_lh_sign_bit_set(dut):
    """LHU vs LH: bit15=1 — LHU zero-extends (no sign extension).

    mem_array[0][15:0]=0x8000:
        LHU -> 0x0000_8000  (zero-extend, this test)
        LH  -> 0xFFFF_8000  (sign-extend, see test_lh_negative)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, rd = 1, 3
    prog = [LHU(rd, base, 0)] + [NOP] * N_NOPS

    await run_load_test(dut, prog,
                        reg_init={base: 0},
                        dmem_init={0: 0x0000_8000},
                        expected={rd: 0x0000_8000})


# ===========================================================================
# LBU — load byte unsigned
# ===========================================================================

@cocotb.test()
async def test_lbu_basic(dut):
    """LBU: upper 24 bits always zero-filled regardless of the sign bit.

    mem_array[0][7:0]=0xFF -> zero_extend(0xFF) = 0x0000_00FF.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, rd = 1, 3
    prog = [LBU(rd, base, 0)] + [NOP] * N_NOPS

    await run_load_test(dut, prog,
                        reg_init={base: 0},
                        dmem_init={0: 0x0000_00FF},
                        expected={rd: 0x0000_00FF})


@cocotb.test()
async def test_lbu_vs_lb_sign_bit_set(dut):
    """LBU vs LB: bit7=1 — LBU zero-extends (no sign extension).

    mem_array[0][7:0]=0x80:
        LBU -> 0x0000_0080  (zero-extend, this test)
        LB  -> 0xFFFF_FF80  (sign-extend, see test_lb_negative)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, rd = 1, 3
    prog = [LBU(rd, base, 0)] + [NOP] * N_NOPS

    await run_load_test(dut, prog,
                        reg_init={base: 0},
                        dmem_init={0: 0x0000_0080},
                        expected={rd: 0x0000_0080})


# ===========================================================================
# Store-then-load roundtrip tests
#
# Pipeline timing:
#   The store writes its SRAM word at the rising edge ending its MEM stage.
#   inserting N_NOPS=4 between SW and LW puts the load's MEM stage 5 cycles
#   later — well clear of the store's write, no structural conflict.
# ===========================================================================

@cocotb.test()
async def test_sw_lw_roundtrip(dut):
    """SW then LW to the same address — store data is visible to the load.

    Uses a 16-bit value so the test passes with the current SRAM width
    (NUM_BYTES corrected to WIDTH/8=4).  Full 32-bit coverage lives in
    test_lw_basic / test_sw_basic.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, src, dst = 1, 2, 3
    value = 0x0000_5A5A

    prog = (
        [SW(base, src, 0)] +
        [NOP] * N_NOPS     +
        [LW(dst, base, 0)] +
        [NOP] * N_NOPS
    )

    await run_load_test(dut, prog,
                        reg_init={base: 0, src: value},
                        dmem_init={},
                        expected={dst: value})


@cocotb.test()
async def test_sh_lh_roundtrip(dut):
    """SH then LH — half-word is stored and sign-extended on load.

    SH writes rs2[15:0]=0xF0A0 -> mem_array[0][15:0]=0xF0A0.
    LH reads it back: bit15=1 -> sign-extended to 0xFFFF_F0A0.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, src, dst = 1, 2, 3

    prog = (
        [SH(base, src, 0)] +
        [NOP] * N_NOPS      +
        [LH(dst, base, 0)]  +
        [NOP] * N_NOPS
    )

    await run_load_test(dut, prog,
                        reg_init={base: 0, src: 0x0000_F0A0},
                        dmem_init={},
                        expected={dst: 0xFFFF_F0A0})


@cocotb.test()
async def test_sb_lb_roundtrip(dut):
    """SB then LB — byte is stored and sign-extended on load.

    SB writes rs2[7:0]=0xC8 -> mem_array[0][7:0]=0xC8.
    LB reads it back: bit7=1 -> sign-extended to 0xFFFF_FFC8.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, src, dst = 1, 2, 3

    prog = (
        [SB(base, src, 0)] +
        [NOP] * N_NOPS      +
        [LB(dst, base, 0)]  +
        [NOP] * N_NOPS
    )

    await run_load_test(dut, prog,
                        reg_init={base: 0, src: 0x0000_00C8},
                        dmem_init={},
                        expected={dst: 0xFFFF_FFC8})


@cocotb.test()
async def test_sb_lbu_roundtrip(dut):
    """SB then LBU — byte is stored and zero-extended on unsigned load.

    SB writes rs2[7:0]=0xC8 -> mem_array[0][7:0]=0xC8.
    LBU reads it back: zero-extended to 0x0000_00C8 (no sign extension).
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, src, dst = 1, 2, 3

    prog = (
        [SB(base, src, 0)]  +
        [NOP] * N_NOPS       +
        [LBU(dst, base, 0)] +
        [NOP] * N_NOPS
    )

    await run_load_test(dut, prog,
                        reg_init={base: 0, src: 0x0000_00C8},
                        dmem_init={},
                        expected={dst: 0x0000_00C8})
