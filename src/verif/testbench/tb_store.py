"""
cocotb Testbench: rv_cpu  —  Store Instruction Tests
=====================================================

Tests all three store instructions:
    SW  (store word,      funct3=010, mem_mask=4'b1111)
    SH  (store half-word, funct3=001, mem_mask=4'b0011)
    SB  (store byte,      funct3=000, mem_mask=4'b0001)

Each test runs a single store instruction, then directly reads the SRAM
array to verify the correct bytes were written.

Data memory address scheme
--------------------------
  sram_rw_dff indexes its array as  mem_array[byte_addr >> 2]:
      byte addr  0x00  ->  mem_array[0]
      byte addr  0x04  ->  mem_array[1]
      byte addr  0x08  ->  mem_array[2], ...

Run with:
    inv sim --testbench tb_store
"""

import cocotb
from cocotb.clock import Clock

# Need to add (..) to path so that it can find tb_helpers
import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent))  # for importing tb_helpers
from tb_helpers import (
    CLK_PERIOD_NS, N_NOPS,
    NOP, SW, SH, SB,
    run_store_test,
)


# ===========================================================================
# SW — store word
# ===========================================================================

@cocotb.test()
async def test_sw_basic(dut):
    """SW: store word at zero base address  — mem[0] = 0xDEAD_BEEF.

    SW x2, 0(x1)  with x1=0, x2=0xDEAD_BEEF -> mem_array[0] = 0xDEAD_BEEF.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, src = 1, 2
    prog = [SW(base, src, 0)] + [NOP] * N_NOPS

    await run_store_test(dut, prog,
                         reg_init={base: 0, src: 0xDEAD_BEEF},
                         dmem_expected={0: 0xDEAD_BEEF})


@cocotb.test()
async def test_sw_positive_offset(dut):
    """SW: store word at a positive byte offset  — SW x2, 8(x1) -> mem_array[2].

    x1=0, offset=8 -> effective addr=8, word_addr=8>>2=2.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, src = 1, 2
    prog = [SW(base, src, 8)] + [NOP] * N_NOPS

    await run_store_test(dut, prog,
                         reg_init={base: 0, src: 0xCAFE_BABE},
                         dmem_expected={2: 0xCAFE_BABE})


@cocotb.test()
async def test_sw_negative_offset(dut):
    """SW: store word with a negative immediate offset  — SW x2, -4(x1).

    x1=0x10 (16), offset=-4 -> effective addr=12, word_addr=12>>2=3.
    The S-type immediate is sign-extended; -4 encodes as 12'hFFC.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, src = 1, 2
    prog = [SW(base, src, -4)] + [NOP] * N_NOPS

    await run_store_test(dut, prog,
                         reg_init={base: 0x10, src: 0x1234_5678},
                         dmem_expected={3: 0x1234_5678})


# ===========================================================================
# SH — store half-word
# ===========================================================================

@cocotb.test()
async def test_sh_basic(dut):
    """SH: only rs2[15:0] written; upper half of the destination word unchanged.

    x2=0xABCD_5678 -> mem_array[0][15:0]=0x5678, mem_array[0][31:16]=0x0000.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, src = 1, 2
    prog = [SH(base, src, 0)] + [NOP] * N_NOPS

    await run_store_test(dut, prog,
                         reg_init={base: 0, src: 0xABCD_5678},
                         dmem_expected={0: 0x0000_5678})


@cocotb.test()
async def test_sh_positive_offset(dut):
    """SH: store half-word at a positive offset  — SH x2, 4(x1) -> mem_array[1].

    x1=0, offset=4 -> byte addr=4, word_addr=1.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, src = 1, 2
    prog = [SH(base, src, 4)] + [NOP] * N_NOPS

    await run_store_test(dut, prog,
                         reg_init={base: 0, src: 0xABCD_1234},
                         dmem_expected={1: 0x0000_1234})


# ===========================================================================
# SB — store byte
# ===========================================================================

@cocotb.test()
async def test_sb_basic(dut):
    """SB: only rs2[7:0] written; upper three bytes of the destination word unchanged.

    x2=0xABCD_EF42 -> mem_array[0][7:0]=0x42, mem_array[0][31:8]=0x00_0000.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, src = 1, 2
    prog = [SB(base, src, 0)] + [NOP] * N_NOPS

    await run_store_test(dut, prog,
                         reg_init={base: 0, src: 0xABCD_EF42},
                         dmem_expected={0: 0x0000_0042})


@cocotb.test()
async def test_sb_positive_offset(dut):
    """SB: store byte at a positive offset  — SB x2, 8(x1) -> mem_array[2].

    x1=0, offset=8 -> byte addr=8, word_addr=2.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    base, src = 1, 2
    prog = [SB(base, src, 8)] + [NOP] * N_NOPS

    await run_store_test(dut, prog,
                         reg_init={base: 0, src: 0xABCD_EFAB},
                         dmem_expected={2: 0x0000_00AB})
