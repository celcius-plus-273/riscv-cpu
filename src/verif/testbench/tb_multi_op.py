"""
cocotb Testbench: rv_cpu  —  Multi-Operation R-type Tests
=========================================================

Tests sequences of independent R-type instructions in a single program.
No RAW hazards — every instruction reads only from pre-initialised registers,
never from a register written by an instruction still in the pipeline.

RAW-hazard avoidance strategy
------------------------------
  With no data forwarding, a write is not visible until the WB stage completes
  (5 pipeline stages after IF).  These tests side-step hazards entirely by:
    1. Writing each result to a *unique* destination register (x10 and above).
    2. Reading only from registers initialised via write_reg() before execution.
  No NOPs are inserted between instructions — the pipeline runs full speed.

Run with:
    inv sim --testbench tb_multi_op
"""

import cocotb
from cocotb.clock import Clock

import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent))  # for importing tb_helpers
from tb_helpers import (
    CLK_PERIOD_NS,
    NOP, ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND,
    u32, s32,
    run_r_test,
)


# ===========================================================================
# Four different ALU ops, each to a unique destination
# ===========================================================================

@cocotb.test()
async def test_four_independent_alu_ops(dut):
    """Four independent ALU ops issued back-to-back — no NOPs, no hazards.

    Each instruction writes to a unique rd and reads only pre-initialised regs.

        ADD  x10, x1, x2   ->  10 +  3        = 13
        SUB  x11, x3, x4   -> 100 - 37        = 63
        AND  x12, x5, x6   -> 0xF0 & 0x0F     = 0x00
        OR   x13, x5, x6   -> 0xF0 | 0x0F     = 0xFF
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        ADD(10, 1, 2),
        SUB(11, 3, 4),
        AND(12, 5, 6),
        OR (13, 5, 6),
    ]

    await run_r_test(dut, prog,
                     reg_init={1: 10, 2: 3, 3: 100, 4: 37, 5: 0xF0, 6: 0x0F},
                     expected={10: 13, 11: 63, 12: 0x00, 13: 0xFF})


# ===========================================================================
# Shift battery — SLL / SRL / SRA show sign-fill difference on INT32_MIN
# ===========================================================================

@cocotb.test()
async def test_shift_battery(dut):
    """SLL / SRL / SRA on INT32_MIN (0x8000_0000) back-to-back.

    SRL and SRA on the same signed-negative value demonstrate the difference
    between logical (zero-fill) and arithmetic (sign-fill) right shifts.
    XOR of a register with itself always produces zero regardless of value.

        SLL x10, x1, x2   ->  1 << 8                  = 0x0000_0100
        SRL x11, x3, x4   ->  0x8000_0000 >> 4         = 0x0800_0000  (zero fill)
        SRA x12, x3, x4   ->  0x8000_0000 >>> 4        = 0xF800_0000  (sign fill)
        XOR x13, x5, x5   ->  0xA5A5_A5A5 ^ self       = 0x0000_0000
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    int32_min = 0x8000_0000

    prog = [
        SLL(10, 1, 2),
        SRL(11, 3, 4),
        SRA(12, 3, 4),
        XOR(13, 5, 5),
    ]

    await run_r_test(dut, prog,
                     reg_init={1: 1, 2: 8, 3: int32_min, 4: 4, 5: 0xA5A5_A5A5},
                     expected={
                         10: 1 << 8,
                         11: int32_min >> 4,            # Python >> on positive int = logical  → 0x0800_0000
                         12: u32(s32(int32_min) >> 4),  # arithmetic (sign extends) → 0xF800_0000
                         13: 0,
                     })


# ===========================================================================
# Comparison battery — signed vs unsigned semantics on the same bit pattern
# ===========================================================================

@cocotb.test()
async def test_comparison_battery(dut):
    """SLT and SLTU on the same register values to expose signed/unsigned difference.

    0xFFFF_FFFF is -1 when interpreted as signed but the maximum uint32 unsigned.

    x1 = 0xFFFF_FFFF, x2 = 1, x3 = 10, x4 = 5

        SLT  x10, x1, x2   -> signed:   -1          < 1   = 1
        SLT  x11, x3, x4   -> signed:   10          < 5   = 0
        SLTU x12, x1, x2   -> unsigned: 0xFFFF_FFFF < 1   = 0
        SLTU x13, x2, x1   -> unsigned: 1 < 0xFFFF_FFFF   = 1
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        SLT (10, 1, 2),
        SLT (11, 3, 4),
        SLTU(12, 1, 2),
        SLTU(13, 2, 1),
    ]

    await run_r_test(dut, prog,
                     reg_init={1: 0xFFFF_FFFF, 2: 1, 3: 10, 4: 5},
                     expected={10: 1, 11: 0, 12: 0, 13: 1})


# ===========================================================================
# All 10 R-type ops — one of each in a single un-stalled program
# ===========================================================================

@cocotb.test()
async def test_all_r_type_ops_independent(dut):
    """All 10 R-type ALU operations in one program, each to a unique destination.

    Source registers x1..x5 are pre-initialised; results go to x10..x19.
    No NOPs needed — none of the 10 instructions share rs/rd with each other.

    x1=20, x2=7, x3=0xAAAA_AAAA, x4=0x5555_5555, x5=3

        ADD  x10, x1, x2   -> 20 + 7                          = 27
        SUB  x11, x1, x2   -> 20 - 7                          = 13
        SLL  x12, x1, x5   -> 20 << 3                         = 160
        SLT  x13, x2, x1   ->  7 < 20 (signed)                = 1
        SLTU x14, x2, x1   ->  7 < 20 (unsigned)              = 1
        XOR  x15, x3, x4   -> 0xAAAA_AAAA ^ 0x5555_5555       = 0xFFFF_FFFF
        SRL  x16, x3, x5   -> 0xAAAA_AAAA >> 3  (logical)     = 0x1555_5555
        SRA  x17, x3, x5   -> 0xAAAA_AAAA >>> 3 (arithmetic)  = 0xF555_5555
        OR   x18, x3, x4   -> 0xAAAA_AAAA | 0x5555_5555       = 0xFFFF_FFFF
        AND  x19, x3, x4   -> 0xAAAA_AAAA & 0x5555_5555       = 0x0000_0000
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    a, b, shamt = 0xAAAA_AAAA, 0x5555_5555, 3

    prog = [
        ADD (10, 1, 2),
        SUB (11, 1, 2),
        SLL (12, 1, 5),
        SLT (13, 2, 1),
        SLTU(14, 2, 1),
        XOR (15, 3, 4),
        SRL (16, 3, 5),
        SRA (17, 3, 5),
        OR  (18, 3, 4),
        AND (19, 3, 4),
    ]

    await run_r_test(dut, prog,
                     reg_init={1: 20, 2: 7, 3: a, 4: b, 5: shamt},
                     expected={
                         10: 27,
                         11: 13,
                         12: 20 << shamt,           # 160
                         13: 1,
                         14: 1,
                         15: u32(a ^ b),             # 0xFFFF_FFFF
                         16: a >> shamt,             # 0x1555_5555  (positive Python int → logical)
                         17: u32(s32(a) >> shamt),   # 0xF555_5555  (arithmetic, sign extends)
                         18: u32(a | b),             # 0xFFFF_FFFF
                         19: u32(a & b),             # 0x0000_0000
                     })


# ===========================================================================
# x0 as a source in multiple operations — hardwired zero in every position
# ===========================================================================

@cocotb.test()
async def test_x0_source_in_sequence(dut):
    """x0 permanently reads zero regardless of pipeline state or instruction order.

    Six operations use x0 as rs1 or rs2 in different positions.  Because x0
    is hardwired to 0, each result is independent of any pipeline value.

        ADD  x10, x0, x1   ->  0 + 20 = 20  (x0 as rs1)
        ADD  x11, x1, x0   -> 20 +  0 = 20  (x0 as rs2)
        SUB  x12, x1, x0   -> 20 -  0 = 20
        AND  x13, x0, x1   ->  0 & 20 =  0  (AND with zero clears result)
        OR   x14, x0, x1   ->  0 | 20 = 20  (OR  with zero is identity)
        XOR  x15, x0, x1   ->  0 ^ 20 = 20  (XOR with zero is identity)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        ADD(10, 0, 1),
        ADD(11, 1, 0),
        SUB(12, 1, 0),
        AND(13, 0, 1),
        OR (14, 0, 1),
        XOR(15, 0, 1),
    ]

    await run_r_test(dut, prog,
                     reg_init={1: 20},
                     expected={10: 20, 11: 20, 12: 20, 13: 0, 14: 20, 15: 20})
