"""
cocotb Testbench: rv_cpu  —  R-type Instruction Tests
======================================================

Tests all 10 R-type ALU operations:
    ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND

Run with:
    inv sim --testbench tb_r_type
"""

import cocotb
from cocotb.clock import Clock

# Need to add (..) to path so that it can find tb_helpers
import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent))  # for importing tb_helpers
from tb_helpers import (
    CLK_PERIOD_NS, N_NOPS,
    NOP, ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND,
    u32,
    run_r_test,
)


@cocotb.test()
async def test_add(dut):
    """ADD: x3 = x1 + x2  (15 + 27 = 42)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    a, b = 15, 27
    prog = [ADD(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: a, rs2: b},
                     expected={rd: u32(a + b)})


@cocotb.test()
async def test_add_overflow(dut):
    """ADD: 32-bit unsigned wrap-around  (0xFFFF_FFFF + 1 = 0)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    a, b = 0xFFFF_FFFF, 1
    prog = [ADD(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: a, rs2: b},
                     expected={rd: u32(a + b)})


@cocotb.test()
async def test_sub(dut):
    """SUB: x3 = x1 - x2  (50 - 17 = 33)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    a, b = 50, 17
    prog = [SUB(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: a, rs2: b},
                     expected={rd: u32(a - b)})


@cocotb.test()
async def test_sub_negative_result(dut):
    """SUB: result wraps to 2s-complement  (5 - 10 = 0xFFFF_FFFB)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    a, b = 5, 10
    prog = [SUB(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: a, rs2: b},
                     expected={rd: u32(a - b)})


@cocotb.test()
async def test_and(dut):
    """AND: x3 = x1 & x2  (0xFF00_FF00 & 0x0F0F_0F0F = 0x0F00_0F00)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    a, b = 0xFF00_FF00, 0x0F0F_0F0F
    prog = [AND(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: a, rs2: b},
                     expected={rd: u32(a & b)})


@cocotb.test()
async def test_or(dut):
    """OR: x3 = x1 | x2  (0xF0F0_F0F0 | 0x0F0F_0F0F = 0xFFFF_FFFF)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    a, b = 0xF0F0_F0F0, 0x0F0F_0F0F
    prog = [OR(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: a, rs2: b},
                     expected={rd: u32(a | b)})


@cocotb.test()
async def test_xor(dut):
    """XOR: x3 = x1 ^ x2  (0xAAAA_AAAA ^ 0x5555_5555 = 0xFFFF_FFFF)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    a, b = 0xAAAA_AAAA, 0x5555_5555
    prog = [XOR(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: a, rs2: b},
                     expected={rd: u32(a ^ b)})


@cocotb.test()
async def test_sll(dut):
    """SLL: x3 = x1 << x2[4:0]  (1 << 7 = 128)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    a, shamt = 1, 7
    prog = [SLL(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: a, rs2: shamt},
                     expected={rd: u32(a << shamt)})


@cocotb.test()
async def test_sll_lower5_bits_only(dut):
    """SLL: only the lower 5 bits of rs2 are used as the shift amount."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    a       = 1
    shamt   = 3
    rs2_val = shamt | 0b100000  # bit 5 set — must be ignored
    prog = [SLL(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: a, rs2: rs2_val},
                     expected={rd: u32(a << shamt)})


@cocotb.test()
async def test_srl(dut):
    """SRL: x3 = x1 >> x2[4:0]  logical  (0x8000_0000 >> 4 = 0x0800_0000)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    a, shamt = 0x8000_0000, 4
    prog = [SRL(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: a, rs2: shamt},
                     expected={rd: u32(a >> shamt)})


@cocotb.test()
async def test_sra(dut):
    """SRA: x3 = x1 >>> x2[4:0]  arithmetic  (-256 >>> 4 = -16)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    a_signed = -256    # stored as 0xFFFF_FF00
    shamt    =  4
    expected = u32(a_signed >> shamt)

    prog = [SRA(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: u32(a_signed), rs2: shamt},
                     expected={rd: expected})


@cocotb.test()
async def test_slt_true(dut):
    """SLT: signed compare — true  (-1 < 1 -> 1)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    prog = [SLT(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: u32(-1), rs2: 1},
                     expected={rd: 1})


@cocotb.test()
async def test_slt_false(dut):
    """SLT: signed compare — false  (10 < 5 -> 0)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    prog = [SLT(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: 10, rs2: 5},
                     expected={rd: 0})


@cocotb.test()
async def test_slt_equal(dut):
    """SLT: equal operands -> 0  (7 < 7 -> 0)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    prog = [SLT(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: 7, rs2: 7},
                     expected={rd: 0})


@cocotb.test()
async def test_sltu_true(dut):
    """SLTU: unsigned compare — true  (1 < 0xFFFF_FFFF -> 1)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    prog = [SLTU(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: 1, rs2: 0xFFFF_FFFF},
                     expected={rd: 1})


@cocotb.test()
async def test_sltu_false(dut):
    """SLTU: unsigned compare — false  (0xFFFF_FFFF < 1 -> 0)"""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    prog = [SLTU(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: 0xFFFF_FFFF, rs2: 1},
                     expected={rd: 0})


@cocotb.test()
async def test_sltu_vs_slt_sign_difference(dut):
    """
    SLTU interprets 0xFFFF_FFFF as a large unsigned value (not -1).
    0xFFFF_FFFF (unsigned) is NOT less than 5, so result = 0.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 3
    prog = [SLTU(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: 0xFFFF_FFFF, rs2: 5},
                     expected={rd: 0})


@cocotb.test()
async def test_rd_x0_immutable(dut):
    """Writing to x0 must always read back 0 (hardwired zero register)."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    rs1, rs2, rd = 1, 2, 0   # rd = x0
    prog = [ADD(rd, rs1, rs2)] + [NOP] * N_NOPS

    await run_r_test(dut, prog,
                     reg_init={rs1: 100, rs2: 200},
                     expected={rd: 0})
