"""
cocotb Testbench: rv_cpu  —  U-type Instruction Tests (LUI & AUIPC)
====================================================================

Verifies both U-type instructions:

    LUI   — Load Upper Immediate: rd = imm20 << 12  (lower 12 bits zeroed)
    AUIPC — Add Upper Immediate to PC: rd = PC + (imm20 << 12)

Key properties exercised
-------------------------
  LUI
  ----
  - Lower 12 bits of the result are always zero
  - Upper 20 bits come directly from the 20-bit immediate field
  - Classic two-instruction pattern: LUI + ADDI produces any 32-bit constant
    (hazard unit handles the 0-gap RAW between LUI and ADDI automatically)
  - x0 is hard-wired to zero; LUI x0 must not modify x0
  - Sign-bit load: LUI(x10, 0x80000) → 0x80000000 (makes x10 negative as signed)

  AUIPC
  ------
  - Result reflects the PC of the AUIPC instruction itself, not PC+4
  - With imm=0: acts as a pure PC-capture ("what is my address?")
  - PC is a byte address; instructions at indices 0,1,2,... are at byte PCs 0,4,8,...
  - Hazard unit handles any RAW hazard when AUIPC's result is consumed immediately

Run with:
    inv sim --testbench tb_u_type
"""

import cocotb
from cocotb.clock import Clock

import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent))
from tb_helpers import (
    CLK_PERIOD_NS, PIPE_DEPTH,
    NOP,
    ADDI, LUI, AUIPC,
    u32,
    run_r_test,
)


# ===========================================================================
# LUI — Load Upper Immediate
# ===========================================================================

@cocotb.test()
async def test_lui_sets_upper_bits_only(dut):
    """LUI(rd, imm20) puts imm20 in rd[31:12] and zeroes rd[11:0].

    With imm20=1: rd = 0x00001000.
    Verifies that exactly the right bits are set and the lower 12 are zero.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # LUI x10, 1 → x10 = 0x00001000
    await run_r_test(dut,
                     program=[LUI(10, 1), NOP],
                     reg_init={},
                     expected={10: 0x00001000})


@cocotb.test()
async def test_lui_large_immediate(dut):
    """LUI with a non-trivial 20-bit immediate spans all 20 bits."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # LUI x10, 0xABCDE → x10 = 0xABCDE000
    await run_r_test(dut,
                     program=[LUI(10, 0xABCDE), NOP],
                     reg_init={},
                     expected={10: 0xABCDE000})


@cocotb.test()
async def test_lui_max_immediate(dut):
    """LUI with the maximum 20-bit immediate (all ones) fills rd[31:12]."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # LUI x10, 0xFFFFF → x10 = 0xFFFFF000
    await run_r_test(dut,
                     program=[LUI(10, 0xFFFFF), NOP],
                     reg_init={},
                     expected={10: 0xFFFFF000})


@cocotb.test()
async def test_lui_sets_sign_bit(dut):
    """LUI can set the MSB, making the result negative in signed interpretation.

    LUI(x10, 0x80000) → x10 = 0x80000000 = INT32_MIN.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # LUI x10, 0x80000 → x10 = 0x80000000
    await run_r_test(dut,
                     program=[LUI(10, 0x80000), NOP],
                     reg_init={},
                     expected={10: 0x80000000})


@cocotb.test()
async def test_lui_x0_is_hardwired_zero(dut):
    """Writing to x0 via LUI must have no effect; x0 stays 0."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # LUI x0, 0xDEADB → must not alter x0
    # Follow with ADDI x10, x0, 1 to confirm x0 reads as 0
    await run_r_test(dut,
                     program=[LUI(0, 0xDEADB), ADDI(10, 0, 1), NOP],
                     reg_init={},
                     expected={10: 1})


@cocotb.test()
async def test_lui_then_addi_32bit_constant(dut):
    """LUI + ADDI is the standard two-instruction pattern for loading a 32-bit constant.

    LUI  x10, 0x12345   → x10 = 0x12345000
    ADDI x10, x10, 0x678 → x10 = 0x12345678

    The low 12 bits of 0x12345678 are 0x678; bit 11 = 0, so no correction needed.
    The 0-gap RAW hazard (LUI writes x10, ADDI reads x10) is resolved automatically
    by the hazard unit with 1 stall + MEM→EX forwarding.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # LUI x10, 0x12345; ADDI x10, x10, 0x678 → x10 = 0x12345678
    await run_r_test(dut,
                     program=[LUI(10, 0x12345), ADDI(10, 10, 0x678), NOP],
                     reg_init={},
                     expected={10: 0x12345678})


# ===========================================================================
# AUIPC — Add Upper Immediate to PC
# ===========================================================================

@cocotb.test()
async def test_auipc_at_pc_zero(dut):
    """AUIPC as the first instruction: rd = 0 + (imm20 << 12).

    The AUIPC instruction is at byte address 0 (instruction index 0).
    With imm20=1: rd = 0 + 0x1000 = 0x1000.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # AUIPC x10, 1 at PC=0 → x10 = 0x00001000
    await run_r_test(dut,
                     program=[AUIPC(10, 1), NOP],
                     reg_init={},
                     expected={10: 0x00001000})


@cocotb.test()
async def test_auipc_at_nonzero_pc(dut):
    """AUIPC at a non-zero PC: result reflects the instruction's own byte address.

    Two NOPs precede AUIPC so it is at instruction index 2 → byte PC = 8.
    With imm20=2: rd = 8 + (2 << 12) = 8 + 0x2000 = 0x2008.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # AUIPC x10, 2 at PC=8 → x10 = 8 + 0x2000 = 0x2008
    await run_r_test(dut,
                     program=[NOP, NOP, AUIPC(10, 2), NOP],
                     reg_init={},
                     expected={10: 0x2008})


@cocotb.test()
async def test_auipc_zero_imm_captures_pc(dut):
    """AUIPC with imm=0 captures the current PC (rd = PC + 0 = PC).

    Standard idiom for reading the program counter.
    AUIPC is at instruction index 1 → byte PC = 4.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    # AUIPC x10, 0 at PC=4 → x10 = 4
    await run_r_test(dut,
                     program=[NOP, AUIPC(10, 0), NOP],
                     reg_init={},
                     expected={10: 4})
