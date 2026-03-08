"""
cocotb Testbench: rv_cpu  —  Integration Tests (Mixed Instruction Types)
=========================================================================

Combines R-type, I-type, loads, stores, branches, and U-type instructions
in realistic program patterns.  No manual NOPs — the hazard unit handles
all forwarding stalls automatically.

Tests are split into two groups:

  Straight-line programs (Tests 1-7):
      Multi-instruction idioms with no branches.

  Loop-based programs (Tests 8-20):
      Multi-iteration algorithms that drive the full pipeline under
      repeated branch flushes, load-use stalls, and forwarding.

Run with:
    inv sim --testbench tb_integration
"""

import cocotb
from cocotb.clock import Clock

import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent))
from tb_helpers import (
    CLK_PERIOD_NS, PIPE_DEPTH,
    NOP,
    ADD, SUB, XOR, OR, AND, SRL, SRA, SLL, SLT, SLTU,
    ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI,
    LW, SW,
    LUI, AUIPC,
    BEQ, BNE, BGE, BLT,
    u32,
    load_imem, do_reset, clock_n,
    write_reg, read_reg, write_dmem, read_dmem,
)


# ---------------------------------------------------------------------------
# Shared helper
# ---------------------------------------------------------------------------

async def _run(dut, program, *, reg_init={}, dmem_init={},
               n_cycles=None, exp_regs={}, exp_dmem={}):
    """Reset, load program, optionally seed regs and dmem, run, verify.

    n_cycles defaults to 2*len(program) + PIPE_DEPTH, which budgets one
    MEM->EX stall per instruction for straight-line programs.  For loop
    programs supply n_cycles explicitly.
    """
    load_imem(dut, program)
    await do_reset(dut)
    for reg, val in reg_init.items():
        write_reg(dut, reg, val)
    for wa, val in dmem_init.items():
        write_dmem(dut, wa, val)

    budget = n_cycles if n_cycles is not None else (2 * len(program) + PIPE_DEPTH)
    await clock_n(dut, budget)

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
            f"dmem[{wa}]: expected 0x{exp32:08x} ({exp32}), got 0x{got:08x} ({got})"
        )


# ===========================================================================
# Straight-line programs  (no branches)
# ===========================================================================

@cocotb.test()
async def test_byte_swap_32(dut):
    """bswap32: reverse the 4 bytes of a 32-bit word in-place.

    Combines SRLI / SLLI / ANDI / OR.
    Every byte is extracted with SRLI + ANDI, repositioned with SLLI,
    and accumulated into the result with OR.

    Input : x1 = 0x12345678
    Output: x10 = 0x78563412
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        # byte3 (0x12, high) → result[7:0]
        SRLI(10, 1, 24),      # x10 = 0x00000012
        # byte2 (0x34) → result[15:8]
        SRLI(11, 1, 16),      # x11 = 0x00001234
        ANDI(11, 11, 0xFF),   # x11 = 0x00000034
        SLLI(11, 11,  8),     # x11 = 0x00003400
        OR  (10, 10, 11),     # x10 = 0x00003412
        # byte1 (0x56) → result[23:16]
        SRLI(12, 1,  8),      # x12 = 0x00123456
        ANDI(12, 12, 0xFF),   # x12 = 0x00000056
        SLLI(12, 12, 16),     # x12 = 0x00560000
        OR  (10, 10, 12),     # x10 = 0x00563412
        # byte0 (0x78, low) → result[31:24]
        ANDI(13,  1, 0xFF),   # x13 = 0x00000078
        SLLI(13, 13, 24),     # x13 = 0x78000000
        OR  (10, 10, 13),     # x10 = 0x78563412
        NOP,
    ]
    # fmt: on

    await _run(dut, prog, reg_init={1: 0x12345678}, exp_regs={10: 0x78563412})


@cocotb.test()
async def test_sign_extend_16bit(dut):
    """Sign-extend the lower 16 bits of a register to 32 bits.

    SLLI by 16 moves bit 15 into bit 31, then SRAI by 16 propagates the
    sign bit back down — preserving the signed value.

    Input : x1 = 0x00008000  (bit 15 set → negative 16-bit value)
    Output: x10 = 0xFFFF8000 (sign-extended to 32 bits)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [SLLI(10, 1, 16), SRAI(10, 10, 16), NOP]
    await _run(dut, prog, reg_init={1: 0x00008000}, exp_regs={10: 0xFFFF8000})


@cocotb.test()
async def test_twos_complement_negate(dut):
    """Two's complement negation via XORI(-1) + ADDI(+1).

    XORI with imm=-1 (sign-extends to 0xFFFFFFFF) implements bitwise NOT.
    Adding 1 to ~x gives -x in two's complement.

    Tests x1=5 → x10=-5=0xFFFFFFFB  and  x1=0 → x11=0 (edge case).
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        # negate x1 → x10
        XORI(10, 1, -1),  # x10 = ~x1
        ADDI(10, 10,  1), # x10 = ~x1 + 1 = -x1
        # negate x0 (always 0) → x11; verifies the zero edge case
        XORI(11, 0, -1),  # x11 = ~0 = 0xFFFFFFFF
        ADDI(11, 11,  1), # x11 = 0 (wraps around)
        NOP,
    ]
    await _run(dut, prog, reg_init={1: 5},
               exp_regs={10: u32(-5), 11: 0})


@cocotb.test()
async def test_merge_halfwords(dut):
    """Concatenate the upper 16 bits of x1 with the lower 16 bits of x2.

    Algorithm:
        x10 = (x1 >> 16) << 16   — upper 16 from x1
        x11 = (x2 << 16) >> 16   — lower 16 from x2, zero-extended
        x10 |= x11

    Input : x1=0xABCD1234  x2=0x56789ABC
    Output: x10=0xABCD9ABC
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        SRLI(10, 1, 16),   # x10 = upper 16 of x1 at [15:0]
        SLLI(10, 10, 16),  # x10 = upper 16 back at [31:16]
        SLLI(11, 2, 16),   # x11 = lower 16 of x2 at [31:16] (clears upper noise)
        SRLI(11, 11, 16),  # x11 = lower 16 of x2 at [15:0], zero-extended
        OR  (10, 10, 11),  # x10 = merged
        NOP,
    ]
    # fmt: on

    await _run(dut, prog,
               reg_init={1: 0xABCD1234, 2: 0x56789ABC},
               exp_regs={10: 0xABCD9ABC})


@cocotb.test()
async def test_branchless_absolute_value(dut):
    """Branchless |x| using arithmetic right shift by 31 as a sign mask.

    mask = x >> 31  (arithmetic: 0xFFFFFFFF if negative, 0 if non-negative)
    |x|  = (x XOR mask) - mask

    For negative x: (x XOR 0xFFFFFFFF) - 0xFFFFFFFF = ~x - (-1) = ~x + 1 = -x
    For positive x: (x XOR 0) - 0 = x

    Input : x1=-10 (0xFFFFFFF6)
    Output: x10=10
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        SRAI(11,  1, 31), # x11 = sign mask
        XOR (10,  1, 11), # conditionally invert bits
        SUB (10, 10, 11), # add 1 if negative; no-op if positive
        NOP,
    ]
    await _run(dut, prog, reg_init={1: u32(-10)}, exp_regs={10: 10})


@cocotb.test()
async def test_extract_bitfield(dut):
    """Extract an 8-bit field from bits [11:4] of a register.

    SRLI shifts the field to the bottom, ANDI isolates the 8 bits.

    Input : x1=0xABCD7654
    Bits [11:4] of 0xABCD7654 = 0x65  (0xABCD7654 >> 4 = 0x0ABCD765; & 0xFF = 0x65)
    Output: x10=0x65
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        SRLI(10, 1,  4),   # shift field to [7:0]
        ANDI(10, 10, 0xFF),# mask to 8 bits
        NOP,
    ]
    await _run(dut, prog, reg_init={1: 0xABCD7654}, exp_regs={10: 0x65})


@cocotb.test()
async def test_lui_load_store_roundtrip(dut):
    """LUI + ADDI builds a 32-bit constant; SW/LW round-trip through data memory.

    LUI  x1, 0x12345  → x1 = 0x12345000
    ADDI x1, x1, 0x678 → x1 = 0x12345678  (bit 11 of 0x678 = 0, no correction)
    SW   writes x1 to dmem[0]; LW reads it back into x10.

    The LUI → ADDI RAW hazard (0-gap) is resolved by the hazard unit.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    prog = [
        LUI (1,  0x12345),     # x1 = 0x12345000
        ADDI(1,  1, 0x678),    # x1 = 0x12345678  (1 stall + MEM→EX forward)
        SW  (0,  1, 0),        # mem[0] = x1
        LW  (10, 0, 0),        # x10 = mem[0]
        NOP,
    ]
    await _run(dut, prog,
               exp_regs={1: 0x12345678, 10: 0x12345678},
               exp_dmem={0: 0x12345678})


# ===========================================================================
# Loop-based programs
# ===========================================================================

@cocotb.test()
async def test_gcd_iterated_subtraction(dut):
    """GCD via iterated subtraction (binary-subtraction Euclidean algorithm).

    The loop has two arms: a -= b (when a > b) and b -= a (when b > a),
    each with its own unconditional backward branch.  Exercises BGE, SUB,
    and multiple branch-flush sequences per iteration.

    GCD(12, 8) = 4.

    Program layout  (x1=a, x2=b):
        [0] PC=0:  BEQ  x1,x2, +24  → done: a==b; jump to [6]=PC=24
        [1] PC=4:  BGE  x1,x2, +12  → a>=b arm; jump to [4]=PC=16
        [2] PC=8:  SUB  x2,x2,x1    → b -= a (b > a path)
        [3] PC=12: BEQ  x0,x0, -12  → always back to [0]
        [4] PC=16: SUB  x1,x1,x2    → a -= b (a > b path)
        [5] PC=20: BEQ  x0,x0, -20  → always back to [0]
        [6] PC=24: ADD  x10,x1,x0   → result = a (= b = gcd)
        [7] PC=28: NOP
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        BEQ(1, 2,  24),    # [0] done if a==b; target PC=24=index6
        BGE(1, 2,  12),    # [1] a>=b: jump to a-=b arm; target PC=16=index4
        SUB(2, 2,  1),     # [2] b -= a
        BEQ(0, 0, -12),    # [3] back to [0]; target PC=0
        SUB(1, 1,  2),     # [4] a -= b
        BEQ(0, 0, -20),    # [5] back to [0]; target PC=0
        ADD(10, 1, 0),     # [6] result = a
        NOP,               # [7]
    ]
    # fmt: on

    await _run(dut, prog,
               reg_init={1: 12, 2: 8},
               n_cycles=80,
               exp_regs={10: 4})


@cocotb.test()
async def test_gcd_coprime_inputs(dut):
    """GCD of two coprime numbers must be 1.

    GCD(7, 11) = 1.  Tests the worst-case path where no common factor
    exists and the algorithm runs to a single-unit remainder.
    Uses the same program as test_gcd_iterated_subtraction.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        BEQ(1, 2,  24),    # [0]
        BGE(1, 2,  12),    # [1]
        SUB(2, 2,  1),     # [2]
        BEQ(0, 0, -12),    # [3]
        SUB(1, 1,  2),     # [4]
        BEQ(0, 0, -20),    # [5]
        ADD(10, 1, 0),     # [6]
        NOP,               # [7]
    ]
    # fmt: on

    await _run(dut, prog,
               reg_init={1: 7, 2: 11},
               n_cycles=150,
               exp_regs={10: 1})


@cocotb.test()
async def test_conditional_array_sum(dut):
    """Sum only the strictly positive elements of an 8-element array.

    BGE x0, x5 is true when x5 <= 0 (skip) — exploits the signed >= test.
    Tests multiple instruction types: LW, BGE, ADD, ADDI, BNE.

    Data     : [10, -5, 20, 0, 15, -3, 8, -1]  (word addrs 0..7)
    Positives: 10, 20, 15, 8  →  expected sum = 53

    Loop (PC=12, index 3):
        [0..2] setup
        [3] LW  x5, x1, 0      load element
        [4] BGE x0, x5, +8     if x5<=0: skip ADD; offset→ index 6
        [5] ADD x3, x3, x5     sum += x5
        [6] ADDI x1, x1, 4     ptr += 4
        [7] ADDI x2, x2, -1    n--
        [8] BNE  x2, x0, -20   loop back to index 3
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    data = [10, -5, 20, 0, 15, -3, 8, -1]

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] ptr = 0
        ADDI(2, 0,  8),    # [1] n = 8
        ADDI(3, 0,  0),    # [2] sum = 0
        LW  (5, 1,  0),    # [3] (loop, PC=12) load element
        BGE (0, 5,  8),    # [4] if x5<=0: skip; target PC=16+8=24=index6
        ADD (3, 3,  5),    # [5] sum += x5
        ADDI(1, 1,  4),    # [6] ptr += 4  ← BGE skip target
        ADDI(2, 2, -1),    # [7] n--
        BNE (2, 0, -20),   # [8] loop; PC=32-20=12=index3
        NOP,               # [9]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={i: v for i, v in enumerate(data)},
               n_cycles=150,
               exp_regs={3: 53})


@cocotb.test()
async def test_memcpy_loop(dut):
    """Copy 4 words from source (word addrs 0..3) to destination (word addrs 8..11).

    Exercises: LW with load-use stall, SW, ADDI pointer increment, BNE loop.

    Source byte addresses: 0, 4, 8, 12  (i.e. x1 starts at 0)
    Dest   byte addresses: 32, 36, 40, 44 (i.e. x2 starts at 32 = word addr 8)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    src_data = {0: 111, 1: 222, 2: 333, 3: 444}

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] src ptr = byte 0
        ADDI(2, 0, 32),    # [1] dst ptr = byte 32 (word addr 8)
        ADDI(3, 0,  4),    # [2] n = 4
        LW  (4, 1,  0),    # [3] (loop, PC=12) x4 = mem[src]
        SW  (2, 4,  0),    # [4] mem[dst] = x4
        ADDI(1, 1,  4),    # [5] src += 4
        ADDI(2, 2,  4),    # [6] dst += 4
        ADDI(3, 3, -1),    # [7] n--
        BNE (3, 0, -20),   # [8] loop; PC=32-20=12=index3
        NOP,               # [9]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init=src_data,
               n_cycles=100,
               exp_dmem={8: 111, 9: 222, 10: 333, 11: 444})


@cocotb.test()
async def test_reverse_array_in_place(dut):
    """Reverse a 4-element array in-place using a two-pointer approach.

    lo pointer starts at byte 0, hi pointer at byte 12 (last word).
    Each iteration swaps mem[lo] and mem[hi], then lo += 4, hi -= 4.
    Loop terminates when lo >= hi (done after 2 swaps for 4 elements).

    Data    : [5, 10, 15, 20]  (word addrs 0..3)
    Expected: [20, 15, 10, 5]

    Layout:
        [0] ADDI x1, x0, 0    lo = byte 0
        [1] ADDI x2, x0, 12   hi = byte 12
        [2] BGE  x1, x2, +32  if lo>=hi: done (target=40=index10)
        [3] LW   x3, x1, 0
        [4] LW   x4, x2, 0
        [5] SW   x1, x4, 0    mem[lo] = hi element
        [6] SW   x2, x3, 0    mem[hi] = lo element
        [7] ADDI x1, x1, 4
        [8] ADDI x2, x2, -4
        [9] BEQ  x0, x0, -28  back to [2] (target=8=index2)
       [10] NOP  (done)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(1, 0,   0),   # [0] lo = byte 0
        ADDI(2, 0,  12),   # [1] hi = byte 12
        BGE (1, 2,  32),   # [2] (loop) if lo>=hi: done; PC=8+32=40=index10
        LW  (3, 1,   0),   # [3] x3 = mem[lo]
        LW  (4, 2,   0),   # [4] x4 = mem[hi]
        SW  (1, 4,   0),   # [5] mem[lo] = hi element
        SW  (2, 3,   0),   # [6] mem[hi] = lo element
        ADDI(1, 1,   4),   # [7] lo += 4
        ADDI(2, 2,  -4),   # [8] hi -= 4
        BEQ (0, 0, -28),   # [9] back to [2]; PC=36-28=8=index2
        NOP,               # [10] done
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={0: 5, 1: 10, 2: 15, 3: 20},
               n_cycles=100,
               exp_dmem={0: 20, 1: 15, 2: 10, 3: 5})


@cocotb.test()
async def test_bit_parity_of_word(dut):
    """Compute the bit parity of a 32-bit word (1 = odd number of set bits).

    Algorithm: repeatedly extract the LSB with ANDI and XOR into the
    accumulator, then logical right-shift the word by 1.

    Input : x1=0xB5 = 0b10110101 → 5 set bits → odd parity → x3=1
    Relies on: ANDI, XOR, SRLI, BEQ for the zero-test loop exit.

    Loop (PC=4, index 1):
        [1] BEQ  x1, x0, +20   exit if word exhausted (target=24=index6)
        [2] ANDI x4, x1, 1     extract LSB
        [3] XOR  x3, x3, x4   accumulate parity
        [4] SRLI x1, x1, 1    shift out processed bit
        [5] BEQ  x0, x0, -16   always back to [1]
        [6] (done)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(3, 0, 0),     # [0] parity = 0
        BEQ (1, 0, 20),    # [1] (loop) if x1==0: done; PC=4+20=24=index6
        ANDI(4, 1, 1),     # [2] x4 = LSB of x1
        XOR (3, 3, 4),     # [3] parity ^= LSB
        SRLI(1, 1, 1),     # [4] x1 >>= 1
        BEQ (0, 0, -16),   # [5] back to [1]; PC=20-16=4=index1
        NOP,               # [6] done
    ]
    # fmt: on

    # 0xB5 = 10110101b → 5 ones → odd parity → result bit[0]=1
    await _run(dut, prog,
               reg_init={1: 0xB5},
               n_cycles=150,
               exp_regs={3: 1})


@cocotb.test()
async def test_triangle_number(dut):
    """Compute the nth triangle number: 1 + 2 + ... + n.

    Uses a simple decrement loop: sum += counter; counter-- until zero.

    sum(1..8) = 8+7+6+5+4+3+2+1 = 36  (result in x2)

    Loop (PC=8, index 2):
        [2] ADD  x2, x2, x1   sum += counter
        [3] ADDI x1, x1, -1   counter--
        [4] BNE  x1, x0, -8   loop if counter != 0
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(1, 0, 8),     # [0] counter = 8
        ADDI(2, 0, 0),     # [1] sum = 0
        ADD (2, 2, 1),     # [2] (loop) sum += counter
        ADDI(1, 1, -1),    # [3] counter--
        BNE (1, 0, -8),    # [4] loop; PC=16-8=8=index2
        NOP,               # [5]
    ]
    # fmt: on

    await _run(dut, prog, n_cycles=100, exp_regs={2: 36})


@cocotb.test()
async def test_count_elements_below_threshold(dut):
    """Count array elements strictly less than a threshold, using SLTI.

    SLTI produces 1 or 0, then ADD unconditionally accumulates the result —
    a branchless count that avoids the branch-flush penalty per element.

    Exercises: LW (load-use), SLTI, ADD, ADDI, BNE.

    Data      : [3, 7, 1, 8, 4, 6, 2, 9]  (word addrs 0..7)
    Threshold : 5
    Expected  : count = 4  (elements 3, 1, 4, 2 are < 5)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    data = [3, 7, 1, 8, 4, 6, 2, 9]

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] ptr = 0
        ADDI(2, 0,  8),    # [1] n = 8
        ADDI(3, 0,  0),    # [2] count = 0
        LW  (4, 1,  0),    # [3] (loop, PC=12) load element
        SLTI(5, 4,  5),    # [4] x5 = (x4 < 5) ? 1 : 0
        ADD (3, 3,  5),    # [5] count += x5
        ADDI(1, 1,  4),    # [6] ptr += 4
        ADDI(2, 2, -1),    # [7] n--
        BNE (2, 0, -20),   # [8] loop; PC=32-20=12=index3
        NOP,               # [9]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={i: v for i, v in enumerate(data)},
               n_cycles=150,
               exp_regs={3: 4})


@cocotb.test()
async def test_memset_loop(dut):
    """Fill 4 consecutive words in data memory with a constant value.

    Exercises: SW, ADDI (ptr increment + counter decrement), BNE.

    Fills word addrs 0..3 with 0x5A.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    FILL_VAL = 0x5A

    # fmt: off
    prog = [
        ADDI(1, 0,  0),        # [0] ptr = 0
        ADDI(2, 0,  4),        # [1] n = 4
        ADDI(3, 0, FILL_VAL),  # [2] fill value
        SW  (1, 3,  0),        # [3] (loop, PC=12) mem[ptr] = value
        ADDI(1, 1,  4),        # [4] ptr += 4
        ADDI(2, 2, -1),        # [5] n--
        BNE (2, 0, -12),       # [6] loop; PC=24-12=12=index3
        NOP,                   # [7]
    ]
    # fmt: on

    await _run(dut, prog,
               n_cycles=80,
               exp_dmem={0: FILL_VAL, 1: FILL_VAL, 2: FILL_VAL, 3: FILL_VAL})


@cocotb.test()
async def test_find_first_zero_word(dut):
    """Linear search: find the index of the first zero word in an array.

    Stores the zero-word index in x10.  Uses BEQ to test each loaded
    element against x0, with load-use stalls handled by the hazard unit.

    Data            : [10, 20, 0, 30, 40]  (word addrs 0..4)
    Expected result : x10 = 2  (zero is at word addr 2)

    Loop (PC=8, index 2):
        [2] LW  x3, x2, 0    load word
        [3] BEQ x3, x0, +16  if zero: done (target=28=index7)
        [4] ADDI x1, x1, 1   idx++
        [5] ADDI x2, x2, 4   ptr += 4
        [6] BEQ  x0, x0, -16 always back to [2]
        [7] ADD  x10, x1, x0 result = idx
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] idx = 0
        ADDI(2, 0,  0),    # [1] ptr = byte 0
        LW  (3, 2,  0),    # [2] (loop) load word
        BEQ (3, 0, 16),    # [3] if zero: done; PC=12+16=28=index7
        ADDI(1, 1,  1),    # [4] idx++
        ADDI(2, 2,  4),    # [5] ptr += 4
        BEQ (0, 0, -16),   # [6] back to [2]; PC=24-16=8=index2
        ADD (10, 1, 0),    # [7] x10 = idx (result)
        NOP,               # [8]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={0: 10, 1: 20, 2: 0, 3: 30, 4: 40},
               n_cycles=100,
               exp_regs={10: 2})


@cocotb.test()
async def test_rotate_xor_checksum(dut):
    """Checksum via rotate-left-1 then XOR with each data word.

    Each step: cksum = rotl(cksum, 1) XOR word
    rotl(x, 1) = (x << 1) | (x >> 31)  — uses both SLLI and SRLI.

    Exercises: LW, SLLI, SRLI, OR, XOR, ADDI, BNE.
    The OR and XOR have 0-gap RAW dependencies handled by MEM→EX forwarding.

    Data     : [0xABCD, 0x1234, 0x5678, 0xDEF0]  (word addrs 0..3)
    Expected : x3 = 0x000564B8

    Step trace:
        cksum = 0
        rotl(0,1)=0;      0      XOR 0xABCD      = 0x0000ABCD
        rotl(0xABCD,1)=0x0001579A; XOR 0x1234   = 0x000145AE
        rotl(0x000145AE,1)=0x00028B5C; XOR 0x5678 = 0x0002DD24
        rotl(0x0002DD24,1)=0x0005BA48; XOR 0xDEF0 = 0x000564B8
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    data = [0xABCD, 0x1234, 0x5678, 0xDEF0]

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] ptr = 0
        ADDI(2, 0,  4),    # [1] n = 4
        ADDI(3, 0,  0),    # [2] cksum = 0
        LW  (4, 1,  0),    # [3] (loop, PC=12) load word
        SLLI(5, 3,  1),    # [4] x5 = cksum << 1
        SRLI(6, 3, 31),    # [5] x6 = cksum >> 31  (wrap bit)
        OR  (5, 5,  6),    # [6] x5 = rotl(cksum, 1)
        XOR (3, 5,  4),    # [7] cksum = rotl(cksum) XOR word
        ADDI(1, 1,  4),    # [8] ptr += 4
        ADDI(2, 2, -1),    # [9] n--
        BNE (2, 0, -28),   # [10] loop; PC=40-28=12=index3
        NOP,               # [11]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={i: v for i, v in enumerate(data)},
               n_cycles=120,
               exp_regs={3: 0x000564B8})


@cocotb.test()
async def test_sum_of_absolute_values(dut):
    """Compute the sum of |element| for each entry in a mixed-sign array.

    Uses the same branchless absolute-value idiom as test_branchless_absolute_value
    (SRAI for sign mask, XOR + SUB to conditionally negate), combined with a
    LW load-use chain and an accumulate-then-loop structure.

    Exercises: LW, SRAI, XOR, SUB, ADD, ADDI, BNE.
    Multiple consecutive 0-gap RAWs are resolved by MEM→EX forwarding.

    Data     : [-3, 5, -7, 2, -1, 8, -4, 6]  (word addrs 0..7)
    Expected : x3 = 3+5+7+2+1+8+4+6 = 36
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    data = [-3, 5, -7, 2, -1, 8, -4, 6]

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] ptr = 0
        ADDI(2, 0,  8),    # [1] n = 8
        ADDI(3, 0,  0),    # [2] sum = 0
        LW  (4, 1,  0),    # [3] (loop, PC=12) x4 = element
        SRAI(5, 4, 31),    # [4] x5 = sign mask (all-1s if neg, 0 if pos)
        XOR (4, 4,  5),    # [5] conditional bit-flip
        SUB (4, 4,  5),    # [6] x4 = |element|
        ADD (3, 3,  4),    # [7] sum += |element|
        ADDI(1, 1,  4),    # [8] ptr += 4
        ADDI(2, 2, -1),    # [9] n--
        BNE (2, 0, -28),   # [10] loop; PC=40-28=12=index3
        NOP,               # [11]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={i: u32(v) for i, v in enumerate(data)},
               n_cycles=200,
               exp_regs={3: 36})


@cocotb.test()
async def test_scale_array_by_power_of_two(dut):
    """Multiply every element of an array in-place by 4 using SLLI.

    SLLI by 2 is an exact unsigned multiply-by-4 (no overflow for these values).
    The load-use stall (LW → SLLI) is resolved automatically; the modified
    value is stored back via SW before the pointer advances.

    Exercises: LW, SLLI, SW, ADDI, BNE.

    Data     : [1, 2, 3, 4]  (word addrs 0..3)
    Expected : [4, 8, 12, 16]
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] ptr = byte 0
        ADDI(2, 0,  4),    # [1] n = 4
        LW  (3, 1,  0),    # [2] (loop, PC=8) load element
        SLLI(3, 3,  2),    # [3] element *= 4
        SW  (1, 3,  0),    # [4] store back
        ADDI(1, 1,  4),    # [5] ptr += 4
        ADDI(2, 2, -1),    # [6] n--
        BNE (2, 0, -20),   # [7] loop; PC=28-20=8=index2
        NOP,               # [8]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={0: 1, 1: 2, 2: 3, 3: 4},
               n_cycles=100,
               exp_dmem={0: 4, 1: 8, 2: 12, 3: 16})


@cocotb.test()
async def test_unsigned_threshold_count_sltiu(dut):
    """Count elements whose unsigned value is below a threshold, using SLTIU.

    SLTIU sign-extends the immediate to 32 bits and compares unsigned.
    imm=100 sign-extends to 0x64. Each element's SLTIU result (0 or 1) is
    accumulated branchlessly with ADD.

    Exercises: LW, SLTIU, ADD, ADDI, BNE.

    Data                : [1, 200, 50, 300, 2, 150, 75, 400]
    Elements < 100 (u)  : 1, 50, 2, 75  → count = 4
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # Elements strictly < 100 (unsigned): 1, 50, 2, 75 → count = 4
    data = [1, 200, 50, 300, 2, 150, 75, 400]

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] ptr = 0
        ADDI(2, 0,  8),    # [1] n = 8
        ADDI(3, 0,  0),    # [2] count = 0
        LW  (4, 1,  0),    # [3] (loop, PC=12) load element
        SLTIU(5, 4, 100),  # [4] x5 = (x4 <u 100) ? 1 : 0
        ADD (3, 3,  5),    # [5] count += x5
        ADDI(1, 1,  4),    # [6] ptr += 4
        ADDI(2, 2, -1),    # [7] n--
        BNE (2, 0, -20),   # [8] loop; PC=32-20=12=index3
        NOP,               # [9]
    ]
    # fmt: on

    # elements < 100: 1, 50, 2, 75 → count = 4
    await _run(dut, prog,
               dmem_init={i: v for i, v in enumerate(data)},
               n_cycles=150,
               exp_regs={3: 4})


@cocotb.test()
async def test_andi_based_even_odd_split(dut):
    """Split array elements into two sums: evens and odds, using ANDI to test LSB.

    ANDI x5, x4, 1 produces 0 for even elements and 1 for odd elements.
    A BNE on x5 branches to the odd-sum path; the even-sum path falls through.

    Exercises: LW, ANDI, BNE (branch on LSB), ADD (two accumulators), ADDI.

    Data      : [1, 2, 3, 4, 5, 6, 7, 8]
    Sum odd   : 1+3+5+7 = 16  → x10
    Sum even  : 2+4+6+8 = 20  → x11

    Loop (PC=12, index 3):
        [3]  LW   x4, x1, 0
        [4]  ANDI x5, x4, 1    0=even, 1=odd
        [5]  BNE  x5, x0, +8  if odd: jump to [7] to add to x10
        [6]  ADD  x11, x11, x4 even accumulator; fall through to next iter setup
        [7]  ADDI x1, x1, 4    ← BNE target (odd path falls here too via [8])
        ...
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    data = [1, 2, 3, 4, 5, 6, 7, 8]

    # Layout (loop PC=12, index 3):
    # [0] ADDI x1,x0,0   ptr
    # [1] ADDI x2,x0,8   n
    # [2] ADDI x10,x0,0  odd_sum
    # [3] ... we need x11 for even_sum too — use index 3 for that
    # Let me redo: 4 setup instructions

    # [0] ptr=0, [1] n=8, [2] odd_sum=0, [3] even_sum=0
    # loop at [4] (PC=16):
    # [4]  LW   x5, x1, 0
    # [5]  ANDI x6, x5, 1    1=odd  0=even
    # [6]  BEQ  x6, x0, +8  if even: jump to [8]=even_acc; PC=24+8=32
    # [7]  ADD  x10,x10,x5   odd acc
    # [7b] ...but branch to even path skips odd acc...
    # This interleaving is tricky. Let me use a cleaner layout:
    # [4] LW x5, x1, 0
    # [5] ANDI x6, x5, 1
    # [6] BEQ x6, x0, +8    if even: skip to [8]; target=PC=24+8=32=index8
    # [7] ADD x10, x10, x5  odd acc
    # [8] BNE x6, x0, +8    if odd: skip even acc; target=PC=32+8=40=index10
    # [9] ADD x11, x11, x5  even acc
    # [10] ADDI x1, x1, 4   ptr ← both paths land here
    # [11] ADDI x2, x2, -1
    # [12] BNE x2, x0, -32  loop back to [4]; PC=48-32=16=index4
    # [13] NOP

    # fmt: off
    prog = [
        ADDI( 1, 0,  0),   # [0]  ptr = 0
        ADDI( 2, 0,  8),   # [1]  n = 8
        ADDI(10, 0,  0),   # [2]  odd_sum = 0
        ADDI(11, 0,  0),   # [3]  even_sum = 0
        LW  ( 5, 1,  0),   # [4]  (loop, PC=16) load element
        ANDI( 6, 5,  1),   # [5]  x6 = LSB (1=odd, 0=even)
        BEQ ( 6, 0,  8),   # [6]  if even: skip odd acc; PC=24+8=32=index8
        ADD (10,10,  5),   # [7]  odd_sum += x5
        BNE ( 6, 0,  8),   # [8]  if odd: skip even acc; PC=32+8=40=index10
        ADD (11,11,  5),   # [9]  even_sum += x5
        ADDI( 1, 1,  4),   # [10] ptr += 4 (both paths converge here)
        ADDI( 2, 2, -1),   # [11] n--
        BNE ( 2, 0, -32),  # [12] loop; PC=48-32=16=index4
        NOP,               # [13]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={i: v for i, v in enumerate(data)},
               n_cycles=200,
               exp_regs={10: 16, 11: 20})


@cocotb.test()
async def test_auipc_based_pc_relative_load(dut):
    """AUIPC captures PC; use it to compute a PC-relative data address.

    AUIPC x1, 0 at PC=4 captures x1=4.
    Then ADDI x1, x1, 24 offsets to byte address 28 (word addr 7).
    LW x10, x1, 0 reads from that address.

    Verifies that AUIPC correctly captures its own instruction address
    and that the result can be used immediately as a base register
    (0-gap RAW between AUIPC and ADDI, resolved by forwarding unit).

    This pattern is how position-independent code computes data addresses.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # AUIPC at PC=4 (index 1); ADDI offset 24 → byte addr 28 = word addr 7
    # fmt: off
    prog = [
        NOP,               # [0] PC=0  padding so AUIPC is at PC=4
        AUIPC(1, 0),       # [1] PC=4  x1 = 4
        ADDI (1, 1, 24),   # [2]       x1 = 4+24 = 28 (byte addr → word 7)
        LW   (10, 1, 0),   # [3]       x10 = mem[word 7]
        NOP,               # [4]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={7: 0xCAFEBABE},
               exp_regs={10: 0xCAFEBABE})


@cocotb.test()
async def test_srai_signed_division_array(dut):
    """Use SRAI to divide each element by 8 (arithmetic right shift by 3).

    For positive elements: result = floor(x / 8).
    For negative elements: SRAI rounds toward -infinity (not toward zero),
    but for values that are exact multiples of 8, the result is exact.

    Exercises: LW, SRAI, SW, ADDI, BNE.

    Data     : [64, -64, 24, -24, 8, -8, 0, 40]  (exact multiples of 8)
    Expected : [8, -8, 3, -3, 1, -1, 0, 5]
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    data = [64, -64, 24, -24, 8, -8, 0, 40]
    expected = {i: v >> 3 for i, v in enumerate(data)}   # Python >> is arithmetic

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] ptr = 0
        ADDI(2, 0,  8),    # [1] n = 8
        LW  (3, 1,  0),    # [2] (loop, PC=8) load element
        SRAI(3, 3,  3),    # [3] x3 /= 8 (arithmetic)
        SW  (1, 3,  0),    # [4] store back
        ADDI(1, 1,  4),    # [5] ptr += 4
        ADDI(2, 2, -1),    # [6] n--
        BNE (2, 0, -20),   # [7] loop; PC=28-20=8=index2
        NOP,               # [8]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={i: u32(v) for i, v in enumerate(data)},
               n_cycles=150,
               exp_dmem={i: u32(v) for i, v in expected.items()})
