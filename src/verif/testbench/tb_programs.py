"""
cocotb Testbench: rv_cpu  —  Real-Program Integration Tests
============================================================

Tests multi-instruction programs that exercise the complete pipeline:
loads, stores, arithmetic, branches (forward + backward), and loops.

All hazards (load-use stalls, RAW stalls, forwarding) are handled
automatically by the hazard unit.  No manual NOPs are inserted.

Programs
--------
  1. test_array_sum              — iterative sum of 8 integers in memory
  2. test_array_max              — find maximum value in an array of 8
  3. test_multiply               — compute A×B via repeated addition
  4. test_fibonacci              — iterative fib(10) = 55
  5. test_xor_checksum           — XOR-reduce 8 memory words, store result
  6. test_popcount               — bit population count of a 32-bit word
  7. test_bubble_sort            — in-place bubble sort, 4 elements
  8. test_divmod                 — integer division via repeated subtraction
  9. test_binary_search          — search sorted array, O(log n)
 10. test_shift_add_multiply     — binary long multiplication (no HW mul)
 11. test_fibonacci_to_memory    — first 10 Fibonacci numbers stored to dmem
 12. test_collatz_steps          — Collatz conjecture step count
 13. test_count_trailing_zeros   — CTZ of a 32-bit word
 14. test_minmax_single_pass     — simultaneous min/max in one traversal
 15. test_palindrome_check_true  — two-pointer palindrome (symmetric data)
 16. test_palindrome_check_false — two-pointer palindrome (asymmetric data)

Run with:
    inv sim --testbench tb_programs
"""

import cocotb
from cocotb.clock import Clock

import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent))
from tb_helpers import (
    CLK_PERIOD_NS, PIPE_DEPTH,
    NOP, ADD, SUB, AND, XOR, SRL,
    ADDI, ANDI, SLLI, SRLI, LW, SW,
    BEQ, BNE, BLT, BGE,
    u32,
    load_imem, do_reset, clock_n,
    write_reg, read_reg, write_dmem, read_dmem,
)


# ---------------------------------------------------------------------------
# Helper
# ---------------------------------------------------------------------------

async def _run(dut, program, *, reg_init={}, dmem_init={}, n_cycles,
               exp_regs={}, exp_dmem={}):
    """Reset, load program, pre-populate registers and memory, run, verify."""
    load_imem(dut, program)
    await do_reset(dut)
    for reg, val in reg_init.items():
        write_reg(dut, reg, val)
    for wa, val in dmem_init.items():
        write_dmem(dut, wa, val)
    await clock_n(dut, n_cycles)

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
# Test 1 — Iterative array sum
# ===========================================================================

@cocotb.test()
async def test_array_sum(dut):
    """Sum 8 signed 32-bit integers stored in data memory.

    Exercises: LW, ADD, ADDI, BNE (loop back-edge), load-use hazards,
    and RAW hazards between ADDI and the loop-closing BNE.

    Assembly (no manual NOPs — hardware stalls/forwards automatically):

        [0]  ADDI x1, x0, 0    # ptr  = byte addr 0
        [1]  ADDI x2, x0, 8    # n    = 8  (element count)
        [2]  ADDI x3, x0, 0    # sum  = 0
        ─── loop ───────────────────────────  ← PC=12 (index 3)
        [3]  LW   x4, x1, 0    # x4 = mem[ptr]
        [4]  ADD  x3, x3, x4   # sum += x4         (0-gap load-use: 2 stalls)
        [5]  ADDI x1, x1, 4    # ptr += 4
        [6]  ADDI x2, x2, -1   # n--
        [7]  BNE  x2, x0, -16  # if n != 0: PC=28→12  (RAW on x2: 1 stall)
        ─────────────────────────────────────

    Data memory: word_addr 0..7 = [10, 20, 30, 40, 50, 60, 70, 80]
    Expected  : x3 = 10+20+30+40+50+60+70+80 = 360
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] ptr = 0
        ADDI(2, 0,  8),    # [1] n   = 8
        ADDI(3, 0,  0),    # [2] sum = 0
        # ── loop (PC=12) ──
        LW  (4, 1,  0),    # [3] x4 = mem[ptr]
        ADD (3, 3,  4),    # [4] sum += x4
        ADDI(1, 1,  4),    # [5] ptr += 4
        ADDI(2, 2, -1),    # [6] n--
        BNE (2, 0, -16),   # [7] PC=28 → target=12  (offset=-16)
    ]
    # fmt: on

    data = [10, 20, 30, 40, 50, 60, 70, 80]   # word_addr 0..7

    await _run(dut, prog,
               dmem_init={i: v for i, v in enumerate(data)},
               n_cycles=100,
               exp_regs={3: sum(data)})          # x3 = 360


# ===========================================================================
# Test 2 — Find the maximum value in an array
# ===========================================================================

@cocotb.test()
async def test_array_max(dut):
    """Iterate over 8 elements and track the running maximum.

    Uses BGE for the conditional update (skip if current max >= new element).
    Exercises: BGE forward branch (taken/not-taken), load-use hazards on
    the element being compared, and BNE loop-back.

    Assembly:

        [0]  ADDI x1, x0, 0    # ptr   = byte addr 0
        [1]  LW   x3, x1, 0    # max   = a[0]
        [2]  ADDI x2, x0, 7    # rem   = 7  (comparisons remaining)
        ─── loop ───────────────────────────  ← PC=12 (index 3)
        [3]  ADDI x1, x1, 4    # ptr  += 4
        [4]  LW   x4, x1, 0    # x4   = mem[ptr]         (load)
        [5]  BGE  x3, x4, +8   # if max>=x4 skip; PC=20→28  (0-gap load-use: 2 stalls)
        [6]  ADD  x3, x4, x0   # max   = x4  (branch not taken: new max found)
        [7]  ADDI x2, x2, -1   # rem--                   ← BGE target
        [8]  BNE  x2, x0, -20  # if rem != 0: PC=32→12
        ─────────────────────────────────────

    Data memory: word_addr 0..7 = [3, 99, 7, 42, 1, 100, 55, 8]
    Expected  : x3 = 100
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] ptr = 0
        LW  (3, 1,  0),    # [1] max = a[0]
        ADDI(2, 0,  7),    # [2] rem = 7
        # ── loop (PC=12) ──
        ADDI(1, 1,  4),    # [3] ptr += 4
        LW  (4, 1,  0),    # [4] x4 = mem[ptr]
        BGE (3, 4,  8),    # [5] if max>=x4, skip to [7]; PC=20→28  (offset=+8)
        ADD (3, 4,  0),    # [6] max = x4  (new maximum)
        ADDI(2, 2, -1),    # [7] rem--          ← BGE target
        BNE (2, 0, -20),   # [8] PC=32 → target=12  (offset=-20)
    ]
    # fmt: on

    data = [3, 99, 7, 42, 1, 100, 55, 8]   # word_addr 0..7

    await _run(dut, prog,
               dmem_init={i: v for i, v in enumerate(data)},
               n_cycles=120,
               exp_regs={3: max(data)})           # x3 = 100


# ===========================================================================
# Test 3 — Multiply via repeated addition
# ===========================================================================

@cocotb.test()
async def test_multiply(dut):
    """Compute A × B using a counted loop (A added B times).

    Exercises: BEQ loop-exit (forward branch), inner-loop ADD + ADDI,
    always-taken backward BEQ (BEQ x0, x0, offset), and RAW between
    ADDI x2 and the loop-exit BEQ.

    Assembly (x1=A, x2=B pre-initialised via reg_init):

        [0]  ADDI x3, x0, 0    # result = 0
        ─── loop ───────────────────────────  ← PC=4 (index 1)
        [1]  BEQ  x2, x0, +16  # if B==0 done; PC=4→20  (offset=+16)
        [2]  ADD  x3, x3, x1   # result += A
        [3]  ADDI x2, x2, -1   # B--
        [4]  BEQ  x0, x0, -12  # always back to [1]; PC=16→4  (offset=-12)
        ─────────────────────────────────────
        [5+] done

    A=7, B=6  →  expected x3 = 42
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    A, B = 7, 6

    # fmt: off
    prog = [
        ADDI(3, 0,  0),    # [0] result = 0
        # ── loop (PC=4) ──
        BEQ (2, 0, 16),    # [1] if B==0: PC=4→20  (offset=+16)
        ADD (3, 3,  1),    # [2] result += A
        ADDI(2, 2, -1),    # [3] B--
        BEQ (0, 0, -12),   # [4] always back to [1]; PC=16→4  (offset=-12)
        # ── done (PC=20) ──
        NOP,               # [5] padding
    ]
    # fmt: on

    load_imem(dut, prog)
    await do_reset(dut)
    write_reg(dut, 1, A)
    write_reg(dut, 2, B)
    await clock_n(dut, 60)

    got = read_reg(dut, 3)
    assert got == A * B, f"x3: expected {A*B}, got {got}"


@cocotb.test()
async def test_multiply_by_zero(dut):
    """Multiply A × 0 — the loop body never executes; result must be 0."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    A, B = 42, 0

    # fmt: off
    prog = [
        ADDI(3, 0,  0),
        BEQ (2, 0, 16),
        ADD (3, 3,  1),
        ADDI(2, 2, -1),
        BEQ (0, 0, -12),
        NOP,
    ]
    # fmt: on

    load_imem(dut, prog)
    await do_reset(dut)
    write_reg(dut, 1, A)
    write_reg(dut, 2, B)
    await clock_n(dut, 30)

    got = read_reg(dut, 3)
    assert got == 0, f"x3: expected 0, got {got}"


# ===========================================================================
# Test 4 — Iterative Fibonacci
# ===========================================================================

@cocotb.test()
async def test_fibonacci(dut):
    """Compute the 10th Fibonacci number iteratively.

    Sequence (0-indexed): 0 1 1 2 3 5 8 13 21 34 55 89 ...
    fib(10) = 55,  fib(11) = 89.

    Exercises: multi-instruction dependency chains across iterations,
    WB→EX forwarding for the 2-instruction gap between the temp
    calculation and its consumption, BEQ loop-exit and backward BEQ.

    Register usage:
        x1 = a = fib(n)       (initially fib(0)=0)
        x2 = b = fib(n+1)     (initially fib(1)=1)
        x3 = iteration count  (starts at 10)
        x4 = temp = a + b

    Assembly:

        [0]  ADDI x1, x0,  0   # a     = 0
        [1]  ADDI x2, x0,  1   # b     = 1
        [2]  ADDI x3, x0, 10   # count = 10
        ─── loop ───────────────────────────  ← PC=12 (index 3)
        [3]  BEQ  x3, x0, +24  # if count==0 done; PC=12→36
        [4]  ADD  x4, x1, x2   # temp = a + b
        [5]  ADD  x1, x0, x2   # a    = b       (no RAW: x0+x2)
        [6]  ADD  x2, x0, x4   # b    = temp    (2-gap RAW on x4: WB→EX fwd)
        [7]  ADDI x3, x3, -1   # count--
        [8]  BEQ  x0, x0, -20  # always back to [3]; PC=32→12  (offset=-20)
        ─────────────────────────────────────
        [9+] done (PC=36)

    After 10 iterations: x1=fib(10)=55, x2=fib(11)=89.
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] a     = 0
        ADDI(2, 0,  1),    # [1] b     = 1
        ADDI(3, 0, 10),    # [2] count = 10
        # ── loop (PC=12) ──
        BEQ (3, 0, 24),    # [3] if count==0: PC=12→36  (offset=+24)
        ADD (4, 1,  2),    # [4] temp  = a + b
        ADD (1, 0,  2),    # [5] a     = b
        ADD (2, 0,  4),    # [6] b     = temp  (2-gap fwd from [4])
        ADDI(3, 3, -1),    # [7] count--
        BEQ (0, 0, -20),   # [8] always back to [3]; PC=32→12  (offset=-20)
        # ── done (PC=36) ──
        NOP,               # [9] padding
    ]
    # fmt: on

    # Fibonacci reference
    def fib(n):
        a, b = 0, 1
        for _ in range(n):
            a, b = b, a + b
        return a

    await _run(dut, prog,
               n_cycles=120,
               exp_regs={1: fib(10), 2: fib(11)})   # x1=55, x2=89


# ===========================================================================
# Test 5 — XOR checksum (load-reduce-store)
# ===========================================================================

@cocotb.test()
async def test_xor_checksum(dut):
    """XOR-reduce 8 memory words and store the result back to memory.

    Exercises: LW, XOR, ADDI, BNE (loop back), SW — a full load/compute/
    store pipeline.  The final SW uses the post-loop pointer (x1=32) as
    the base address, storing to word_addr 8.

    Assembly:

        [0]  ADDI x1, x0, 0    # ptr   = byte addr 0
        [1]  ADDI x2, x0, 8    # n     = 8
        [2]  ADDI x3, x0, 0    # cksum = 0
        ─── loop ───────────────────────────  ← PC=12 (index 3)
        [3]  LW   x4, x1, 0    # x4   = mem[ptr]
        [4]  XOR  x3, x3, x4   # cksum ^= x4     (0-gap load-use: 2 stalls)
        [5]  ADDI x1, x1, 4    # ptr  += 4
        [6]  ADDI x2, x2, -1   # n--
        [7]  BNE  x2, x0, -16  # if n!=0: PC=28→12  (offset=-16)
        ─────────────────────────────────────
        [8]  SW   x1, x3, 0    # mem[x1+0] = cksum; x1=32 → word_addr 8

    Data memory: word_addr 0..7 = [0xDEAD, 0xBEEF, 0xCAFE, 0xBABE,
                                   0x1234, 0x5678, 0x9ABC, 0xDEF0]
    Expected  : word_addr 8 = XOR of all 8 words
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(1, 0,  0),    # [0] ptr   = 0
        ADDI(2, 0,  8),    # [1] n     = 8
        ADDI(3, 0,  0),    # [2] cksum = 0
        # ── loop (PC=12) ──
        LW  (4, 1,  0),    # [3] x4 = mem[ptr]
        XOR (3, 3,  4),    # [4] cksum ^= x4
        ADDI(1, 1,  4),    # [5] ptr += 4
        ADDI(2, 2, -1),    # [6] n--
        BNE (2, 0, -16),   # [7] PC=28 → target=12  (offset=-16)
        # ── post-loop ────
        SW  (1, 3,  0),    # [8] mem[x1+0] = cksum; x1=32 → word_addr 8
    ]
    # fmt: on

    data = [0xDEAD, 0xBEEF, 0xCAFE, 0xBABE, 0x1234, 0x5678, 0x9ABC, 0xDEF0]
    expected_cksum = 0
    for v in data:
        expected_cksum ^= v

    await _run(dut, prog,
               dmem_init={i: v for i, v in enumerate(data)},
               n_cycles=300,
               exp_regs={3: expected_cksum},
               exp_dmem={8: expected_cksum})


# ===========================================================================
# Test 6 — Byte population count (count set bits in a 32-bit word)
# ===========================================================================

@cocotb.test()
async def test_popcount(dut):
    """Count the number of 1-bits in a 32-bit word (population count).

    Algorithm: extract LSB, add to count, logical-shift right, repeat
    until the word is zero.  Uses a register holding the constant 1 to
    avoid needing ANDI or SRLI.

    Assembly (x1 = input word, pre-set via reg_init):

        [0]  ADDI x2, x0, 1    # x2 = 1  (shift amount and AND mask)
        [1]  ADDI x3, x0, 0    # count = 0
        ─── loop ───────────────────────────  ← PC=8 (index 2)
        [2]  BEQ  x1, x0, +20  # if word==0 done; PC=8→28=index7
        [3]  AND  x4, x1, x2   # x4 = LSB of x1
        [4]  ADD  x3, x3, x4   # count += LSB
        [5]  SRL  x1, x1, x2   # x1 >>= 1  (logical)
        [6]  BEQ  x0, x0, -16  # always back to [2]; PC=24→8  (offset=-16)
        ─────────────────────────────────────
        [7+] done (PC=28)

    Input: x1 = 0b10110101 = 181  (binary: 1011_0101 → 5 set bits)
    Expected: x3 = 5
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    test_cases = [
        (0b10110101,        5),   # 181 — 5 bits
        (0xFFFF_FFFF,      32),   # all ones
        (0x0000_0000,       0),   # zero
        (0x8000_0001,       2),   # MSB + LSB only
    ]

    for word, expected_count in test_cases:
        # fmt: off
        prog = [
            ADDI(2, 0,  1),    # [0] x2 = 1
            ADDI(3, 0,  0),    # [1] count = 0
            # ── loop (PC=8) ──
            BEQ (1, 0, 20),    # [2] if x1==0: PC=8→28=index7  (offset=+20)
            AND (4, 1,  2),    # [3] x4 = x1 & 1
            ADD (3, 3,  4),    # [4] count += x4
            SRL (1, 1,  2),    # [5] x1 >>= 1
            BEQ (0, 0, -16),   # [6] always back to [2]; PC=24→8  (offset=-16)
            # ── done (PC=28) ──
            NOP,               # [7] padding
        ]
        # fmt: on

        load_imem(dut, prog)
        await do_reset(dut)
        write_reg(dut, 1, word)
        await clock_n(dut, 350)   # worst case: 32 iters × ~8 cycles/iter + overhead

        got = read_reg(dut, 3)
        assert got == expected_count, (
            f"popcount(0x{word:08x}): expected {expected_count}, got {got}"
        )


# ===========================================================================
# Test 7 — Bubble sort (in-place, 4 elements)
# ===========================================================================

@cocotb.test()
async def test_bubble_sort(dut):
    """Bubble sort 4 elements in-place in data memory.

    Two nested loops: outer controls the number of passes (n-1),
    inner bubbles the largest unsorted element to its final position.
    Each inner iteration loads two adjacent words, compares them,
    and swaps if out of order.

    Exercises: LW (adjacent pair), SW (swap pair), BGE (comparison),
    nested BEQ loops (inner + outer), ADDI (counters + pointer).

    Register usage:
        x1 = outer loop counter  (starts at n-1 = 3)
        x2 = pointer (byte address of current pair)
        x3 = inner loop counter
        x4 = a[j]    (left element)
        x5 = a[j+1]  (right element)

    Assembly:

        [0]   ADDI x1, x0, 3       # outer = n-1
        ─── outer_loop ───────────────────── ← PC=4 (index 1)
        [1]   BEQ  x1, x0, +56     # if outer==0: done
        [2]   ADDI x2, x0, 0       # ptr = 0
        [3]   ADD  x3, x1, x0      # inner = outer
        ─── inner_loop ───────────────────── ← PC=16 (index 4)
        [4]   BEQ  x3, x0, +36     # if inner==0: outer_dec
        [5]   LW   x4, x2, 0       # x4 = a[j]
        [6]   LW   x5, x2, 4       # x5 = a[j+1]
        [7]   BGE  x5, x4, +12     # if a[j+1] >= a[j]: no_swap
        [8]   SW   x2, x5, 0       # a[j]   = old a[j+1]
        [9]   SW   x2, x4, 4       # a[j+1] = old a[j]
        ─── no_swap ──────────────────────── ← PC=40 (index 10)
        [10]  ADDI x2, x2, 4       # ptr += 4
        [11]  ADDI x3, x3, -1      # inner--
        [12]  BEQ  x0, x0, -32     # goto inner_loop
        ─── outer_dec ────────────────────── ← PC=52 (index 13)
        [13]  ADDI x1, x1, -1      # outer--
        [14]  BEQ  x0, x0, -52     # goto outer_loop
        ─── done ─────────────────────────── ← PC=60 (index 15)
        [15]  NOP

    Data    : [40, 10, 30, 20]  (word addrs 0..3)
    Expected: [10, 20, 30, 40]
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(1, 0,  3),       # [0]  outer = 3
        # ── outer_loop (PC=4) ──
        BEQ (1, 0, 56),       # [1]  if outer==0: done; PC=4+56=60=idx15
        ADDI(2, 0,  0),       # [2]  ptr = 0
        ADD (3, 1,  0),       # [3]  inner = outer
        # ── inner_loop (PC=16) ──
        BEQ (3, 0, 36),       # [4]  if inner==0: outer_dec; PC=16+36=52=idx13
        LW  (4, 2,  0),       # [5]  x4 = a[j]
        LW  (5, 2,  4),       # [6]  x5 = a[j+1]
        BGE (5, 4, 12),       # [7]  no swap if a[j+1] >= a[j]; PC=28+12=40=idx10
        SW  (2, 5,  0),       # [8]  a[j]   = x5
        SW  (2, 4,  4),       # [9]  a[j+1] = x4
        # ── no_swap (PC=40) ──
        ADDI(2, 2,  4),       # [10] ptr += 4
        ADDI(3, 3, -1),       # [11] inner--
        BEQ (0, 0, -32),      # [12] goto inner_loop; PC=48-32=16=idx4
        # ── outer_dec (PC=52) ──
        ADDI(1, 1, -1),       # [13] outer--
        BEQ (0, 0, -52),      # [14] goto outer_loop; PC=56-52=4=idx1
        # ── done (PC=60) ──
        NOP,                   # [15]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={0: 40, 1: 10, 2: 30, 3: 20},
               n_cycles=300,
               exp_dmem={0: 10, 1: 20, 2: 30, 3: 40})


# ===========================================================================
# Test 8 — Integer division via repeated subtraction
# ===========================================================================

@cocotb.test()
async def test_divmod(dut):
    """Integer division via repeated subtraction: 47 ÷ 7 = 6 remainder 5.

    The loop subtracts the divisor from the dividend each iteration
    and counts the number of subtractions until the dividend is
    smaller than the divisor.

    Exercises: SUB, BLT (exit when dividend < divisor), ADDI, BEQ.

    Register usage:
        x1 = dividend (input, becomes remainder at exit)
        x2 = divisor  (constant)
        x3 = quotient (output)

    Assembly:

        [0]  ADDI x3, x0, 0      # quotient = 0
        ─── loop ─────────────────────── ← PC=4 (index 1)
        [1]  BLT  x1, x2, +16    # if dividend < divisor: done
        [2]  SUB  x1, x1, x2     # dividend -= divisor
        [3]  ADDI x3, x3, 1      # quotient++
        [4]  BEQ  x0, x0, -12    # goto loop
        ─── done ─────────────────────── ← PC=20 (index 5)
        [5]  NOP

    47 ÷ 7 → 6 iterations of subtract:
      47-7=40(q=1), 40-7=33(q=2), 33-7=26(q=3),
      26-7=19(q=4), 19-7=12(q=5), 12-7=5(q=6), 5<7 → done
    Result: x3=6 (quotient), x1=5 (remainder)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(3, 0,  0),       # [0] quotient = 0
        # ── loop (PC=4) ──
        BLT (1, 2, 16),       # [1] if dividend < divisor: done; PC=4+16=20=idx5
        SUB (1, 1,  2),       # [2] dividend -= divisor
        ADDI(3, 3,  1),       # [3] quotient++
        BEQ (0, 0, -12),      # [4] goto loop; PC=16-12=4=idx1
        # ── done (PC=20) ──
        NOP,                   # [5]
    ]
    # fmt: on

    await _run(dut, prog,
               reg_init={1: 47, 2: 7},
               n_cycles=80,
               exp_regs={3: 6, 1: 5})


# ===========================================================================
# Test 9 — Binary search
# ===========================================================================

@cocotb.test()
async def test_binary_search(dut):
    """Binary search for a value in a sorted 8-element array.

    Computes mid = (lo + hi) / 2, converts the word index to a byte
    address via SLLI, loads the element, and narrows the search range
    based on comparison.

    Exercises: ADD, SRLI (divide by 2), SLLI (index → byte addr),
    LW, BEQ (found), BGE (comparison), BLT (loop exit), ADDI.

    Register usage:
        x1  = lo        (word index, starts at 0)
        x2  = hi        (word index, starts at 7)
        x3  = target    (value to find = 42)
        x4  = mid       (computed each iteration)
        x5  = byte_addr (mid × 4)
        x6  = arr[mid]  (loaded element)
        x10 = result    (-1 if not found, else word index)

    Assembly:

        [0]   ADDI x1, x0, 0       # lo = 0
        [1]   ADDI x2, x0, 7       # hi = 7
        [2]   ADDI x3, x0, 42      # target
        [3]   ADDI x10, x0, -1     # result = -1 (not found)
        ─── loop ──────────────────────── ← PC=16 (index 4)
        [4]   BLT  x2, x1, +48     # if hi < lo: done
        [5]   ADD  x4, x1, x2      # x4 = lo + hi
        [6]   SRLI x4, x4, 1       # mid = (lo + hi) / 2
        [7]   SLLI x5, x4, 2       # byte_addr = mid × 4
        [8]   LW   x6, x5, 0       # x6 = arr[mid]
        [9]   BEQ  x6, x3, +24     # if found: set_result
        [10]  BGE  x6, x3, +12     # if arr[mid] > target: hi_update
        ─── lo_update ─────────────────── ← PC=44 (index 11)
        [11]  ADDI x1, x4, 1       # lo = mid + 1
        [12]  BEQ  x0, x0, -32     # goto loop
        ─── hi_update ─────────────────── ← PC=52 (index 13)
        [13]  ADDI x2, x4, -1      # hi = mid - 1
        [14]  BEQ  x0, x0, -40     # goto loop
        ─── set_result ────────────────── ← PC=60 (index 15)
        [15]  ADD  x10, x4, x0     # result = mid
        ─── done ──────────────────────── ← PC=64 (index 16)
        [16]  NOP

    Data  : [5, 12, 23, 34, 42, 55, 67, 78]  (word addrs 0..7)
    Search: target = 42
    Trace : mid=3(34<42→lo=4), mid=5(55>42→hi=4), mid=4(42==42→found)
    Result: x10 = 4
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI( 1, 0,  0),      # [0]  lo = 0
        ADDI( 2, 0,  7),      # [1]  hi = 7
        ADDI( 3, 0, 42),      # [2]  target
        ADDI(10, 0, -1),      # [3]  result = -1 (not found)
        # ── loop (PC=16) ──
        BLT ( 2, 1, 48),      # [4]  if hi < lo: done; PC=16+48=64=idx16
        ADD ( 4, 1,  2),      # [5]  x4 = lo + hi
        SRLI( 4, 4,  1),      # [6]  mid = (lo+hi) / 2
        SLLI( 5, 4,  2),      # [7]  byte_addr = mid × 4
        LW  ( 6, 5,  0),      # [8]  x6 = arr[mid]
        BEQ ( 6, 3, 24),      # [9]  found; PC=36+24=60=idx15
        BGE ( 6, 3, 12),      # [10] arr[mid] > target: hi_update; PC=40+12=52=idx13
        # ── lo_update (PC=44) ──
        ADDI( 1, 4,  1),      # [11] lo = mid + 1
        BEQ ( 0, 0, -32),     # [12] goto loop; PC=48-32=16=idx4
        # ── hi_update (PC=52) ──
        ADDI( 2, 4, -1),      # [13] hi = mid - 1
        BEQ ( 0, 0, -40),     # [14] goto loop; PC=56-40=16=idx4
        # ── set_result (PC=60) ──
        ADD (10, 4,  0),      # [15] result = mid
        # ── done (PC=64) ──
        NOP,                   # [16]
    ]
    # fmt: on

    sorted_data = [5, 12, 23, 34, 42, 55, 67, 78]

    await _run(dut, prog,
               dmem_init={i: v for i, v in enumerate(sorted_data)},
               n_cycles=150,
               exp_regs={10: 4})


# ===========================================================================
# Test 10 — Shift-and-add multiply (binary long multiplication)
# ===========================================================================

@cocotb.test()
async def test_shift_add_multiply(dut):
    """Multiply two numbers via the shift-and-add algorithm.

    The multiplier is shifted right one bit per iteration.  When the
    current bit is 1, the (shifted) multiplicand is added to the result.
    This is equivalent to long multiplication in binary — the standard
    approach when no hardware multiplier is available.

    Exercises: ANDI (bit test), BEQ (conditional skip + loop),
    ADD, SLLI (shift multiplicand), SRLI (shift multiplier).

    Register usage:
        x1 = multiplicand (shifted left each iteration)
        x2 = multiplier   (shifted right each iteration)
        x3 = result

    Assembly:

        [0]  ADDI x3, x0, 0      # result = 0
        ─── loop ─────────────────────── ← PC=4 (index 1)
        [1]  BEQ  x2, x0, +28    # if multiplier==0: done
        [2]  ANDI x4, x2, 1      # x4 = multiplier LSB
        [3]  BEQ  x4, x0, +8     # if bit==0: skip_add
        [4]  ADD  x3, x3, x1     # result += multiplicand
        ─── skip_add ─────────────────── ← PC=20 (index 5)
        [5]  SLLI x1, x1, 1      # multiplicand <<= 1
        [6]  SRLI x2, x2, 1      # multiplier   >>= 1
        [7]  BEQ  x0, x0, -24    # goto loop
        ─── done ─────────────────────── ← PC=32 (index 8)
        [8]  NOP

    Example: 13 × 11 = 143
    Trace (multiplier=1011b):
      bit1: +13=13; bit1: +26=39; bit0: skip; bit1: +104=143
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(3, 0,  0),       # [0] result = 0
        # ── loop (PC=4) ──
        BEQ (2, 0, 28),       # [1] if multiplier==0: done; PC=4+28=32=idx8
        ANDI(4, 2,  1),       # [2] x4 = multiplier & 1
        BEQ (4, 0,  8),       # [3] if bit==0: skip; PC=12+8=20=idx5
        ADD (3, 3,  1),       # [4] result += multiplicand
        # ── skip_add (PC=20) ──
        SLLI(1, 1,  1),       # [5] multiplicand <<= 1
        SRLI(2, 2,  1),       # [6] multiplier >>= 1
        BEQ (0, 0, -24),      # [7] goto loop; PC=28-24=4=idx1
        # ── done (PC=32) ──
        NOP,                   # [8]
    ]
    # fmt: on

    test_cases = [
        (13, 11,   143),   # 1101b × 1011b
        ( 0, 42,     0),   # zero multiplicand
        (42,  0,     0),   # zero multiplier
        (255, 255, 65025), # max 8-bit × 8-bit
    ]

    for a, b, expected in test_cases:
        load_imem(dut, prog)
        await do_reset(dut)
        write_reg(dut, 1, a)
        write_reg(dut, 2, b)
        await clock_n(dut, 150)

        got = read_reg(dut, 3)
        assert got == expected, (
            f"multiply({a}, {b}): expected {expected}, got {got}"
        )


# ===========================================================================
# Test 11 — Fibonacci sequence stored to memory
# ===========================================================================

@cocotb.test()
async def test_fibonacci_to_memory(dut):
    """Compute and store the first 10 Fibonacci numbers to data memory.

    Each iteration stores the current Fibonacci value and advances
    the pair (a, b) → (b, a+b) using a temporary register.

    Exercises: SW (sequential stores), ADD (three-register chain),
    ADDI (pointer + counter), BEQ (loop exit + always-back).

    Register usage:
        x1 = a     (current Fibonacci number)
        x2 = b     (next Fibonacci number)
        x3 = ptr   (byte address for next store)
        x4 = count (iterations remaining)
        x5 = temp  (a + b)

    Assembly:

        [0]   ADDI x1, x0, 0       # a = F(0) = 0
        [1]   ADDI x2, x0, 1       # b = F(1) = 1
        [2]   ADDI x3, x0, 0       # ptr = byte addr 0
        [3]   ADDI x4, x0, 10      # count = 10
        ─── loop ──────────────────────── ← PC=16 (index 4)
        [4]   BEQ  x4, x0, +32     # if count==0: done
        [5]   SW   x3, x1, 0       # mem[ptr] = a
        [6]   ADD  x5, x1, x2      # temp = a + b
        [7]   ADD  x1, x2, x0      # a = b
        [8]   ADD  x2, x5, x0      # b = temp
        [9]   ADDI x3, x3, 4       # ptr += 4
        [10]  ADDI x4, x4, -1      # count--
        [11]  BEQ  x0, x0, -28     # goto loop
        ─── done ──────────────────────── ← PC=48 (index 12)
        [12]  NOP

    Expected memory (word addrs 0..9):
        F(0)=0, F(1)=1, F(2)=1, F(3)=2, F(4)=3,
        F(5)=5, F(6)=8, F(7)=13, F(8)=21, F(9)=34
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(1, 0,  0),       # [0]  a = 0
        ADDI(2, 0,  1),       # [1]  b = 1
        ADDI(3, 0,  0),       # [2]  ptr = 0
        ADDI(4, 0, 10),       # [3]  count = 10
        # ── loop (PC=16) ──
        BEQ (4, 0, 32),       # [4]  if count==0: done; PC=16+32=48=idx12
        SW  (3, 1,  0),       # [5]  mem[ptr] = a
        ADD (5, 1,  2),       # [6]  temp = a + b
        ADD (1, 2,  0),       # [7]  a = b
        ADD (2, 5,  0),       # [8]  b = temp
        ADDI(3, 3,  4),       # [9]  ptr += 4
        ADDI(4, 4, -1),       # [10] count--
        BEQ (0, 0, -28),      # [11] goto loop; PC=44-28=16=idx4
        # ── done (PC=48) ──
        NOP,                   # [12]
    ]
    # fmt: on

    fib = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]

    await _run(dut, prog,
               n_cycles=150,
               exp_dmem={i: v for i, v in enumerate(fib)})


# ===========================================================================
# Test 12 — Collatz conjecture step count
# ===========================================================================

@cocotb.test()
async def test_collatz_steps(dut):
    """Count steps in the Collatz sequence until n reaches 1.

    Collatz rules:
        if n is even: n = n / 2     (SRLI by 1)
        if n is odd : n = 3n + 1    (ADD + ADD + ADDI)

    Tests the ANDI-based parity branch (even vs odd path) and
    the multi-instruction 3n+1 computation using only ADD/ADDI.

    Exercises: ANDI (parity test), BNE/BEQ (even/odd branch),
    SRLI (divide by 2), ADD (triple), ADDI (increment + step count).

    Register usage:
        x1 = n      (pre-set via reg_init)
        x2 = steps  (output)
        x3 = constant 1 (termination sentinel)
        x4 = temp   (parity bit)
        x5 = temp   (2n for odd path)

    Assembly:

        [0]   ADDI x2, x0, 0       # steps = 0
        [1]   ADDI x3, x0, 1       # constant 1
        ─── loop ──────────────────────── ← PC=8 (index 2)
        [2]   BEQ  x1, x3, +40     # if n==1: done
        [3]   ANDI x4, x1, 1       # x4 = n & 1
        [4]   BNE  x4, x0, +12     # if odd: goto odd_path
        ─── even_path ─────────────────── ← PC=20 (index 5)
        [5]   SRLI x1, x1, 1       # n /= 2
        [6]   BEQ  x0, x0, +16     # goto continue
        ─── odd_path ──────────────────── ← PC=28 (index 7)
        [7]   ADD  x5, x1, x1      # x5 = 2n
        [8]   ADD  x1, x5, x1      # x1 = 3n
        [9]   ADDI x1, x1, 1       # x1 = 3n + 1
        ─── continue ──────────────────── ← PC=40 (index 10)
        [10]  ADDI x2, x2, 1       # steps++
        [11]  BEQ  x0, x0, -36     # goto loop
        ─── done ──────────────────────── ← PC=48 (index 12)
        [12]  NOP

    n=6:  6→3→10→5→16→8→4→2→1  (8 steps)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(2, 0,  0),       # [0]  steps = 0
        ADDI(3, 0,  1),       # [1]  constant 1
        # ── loop (PC=8) ──
        BEQ (1, 3, 40),       # [2]  if n==1: done; PC=8+40=48=idx12
        ANDI(4, 1,  1),       # [3]  x4 = n & 1
        BNE (4, 0, 12),       # [4]  if odd: PC=16+12=28=idx7
        # ── even (PC=20) ──
        SRLI(1, 1,  1),       # [5]  n /= 2
        BEQ (0, 0, 16),       # [6]  goto continue; PC=24+16=40=idx10
        # ── odd (PC=28) ──
        ADD (5, 1,  1),       # [7]  x5 = 2n
        ADD (1, 5,  1),       # [8]  x1 = 3n
        ADDI(1, 1,  1),       # [9]  x1 = 3n + 1
        # ── continue (PC=40) ──
        ADDI(2, 2,  1),       # [10] steps++
        BEQ (0, 0, -36),      # [11] goto loop; PC=44-36=8=idx2
        # ── done (PC=48) ──
        NOP,                   # [12]
    ]
    # fmt: on

    await _run(dut, prog,
               reg_init={1: 6},
               n_cycles=180,
               exp_regs={2: 8})


# ===========================================================================
# Test 13 — Count trailing zeros (CTZ)
# ===========================================================================

@cocotb.test()
async def test_count_trailing_zeros(dut):
    """Count the number of trailing zero bits (CTZ) in a 32-bit word.

    Algorithm: test the LSB via ANDI, increment count and shift right
    until the first 1-bit is found.  Special-cases n=0 → CTZ=32.

    Exercises: BEQ (zero check + done), ANDI (LSB test),
    BNE (first-1-found exit), SRLI (logical right shift), ADDI.

    Register usage:
        x1 = n      (input word, shifted right each iteration)
        x2 = count  (output)
        x3 = temp   (LSB of n)

    Assembly:

        [0]  ADDI x2, x0, 0      # count = 0
        [1]  BEQ  x1, x0, +24    # if n==0: set_32 (all zeros)
        ─── loop ─────────────────────── ← PC=8 (index 2)
        [2]  ANDI x3, x1, 1      # x3 = LSB
        [3]  BNE  x3, x0, +20    # if LSB==1: done (first set bit)
        [4]  SRLI x1, x1, 1      # n >>= 1
        [5]  ADDI x2, x2, 1      # count++
        [6]  BEQ  x0, x0, -16    # goto loop
        ─── set_32 ──────────────────── ← PC=28 (index 7)
        [7]  ADDI x2, x0, 32     # count = 32 (n was zero)
        ─── done ────────────────────── ← PC=32 (index 8)
        [8]  NOP
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(2, 0,  0),       # [0] count = 0
        BEQ (1, 0, 24),       # [1] if n==0: set_32; PC=4+24=28=idx7
        # ── loop (PC=8) ──
        ANDI(3, 1,  1),       # [2] x3 = LSB
        BNE (3, 0, 20),       # [3] if LSB==1: done; PC=12+20=32=idx8
        SRLI(1, 1,  1),       # [4] n >>= 1
        ADDI(2, 2,  1),       # [5] count++
        BEQ (0, 0, -16),      # [6] goto loop; PC=24-16=8=idx2
        # ── set_32 (PC=28) ──
        ADDI(2, 0, 32),       # [7] count = 32
        # ── done (PC=32) ──
        NOP,                   # [8]
    ]
    # fmt: on

    test_cases = [
        (0x80,        7),   # 10000000b → 7 trailing zeros
        (0,          32),   # zero → 32
        (1,           0),   # 1b → 0 trailing zeros
        (0xABCD0000, 16),   # trailing 16 zeros
    ]

    for word, expected_ctz in test_cases:
        load_imem(dut, prog)
        await do_reset(dut)
        write_reg(dut, 1, word)
        await clock_n(dut, 350)

        got = read_reg(dut, 2)
        assert got == expected_ctz, (
            f"ctz(0x{word:08x}): expected {expected_ctz}, got {got}"
        )


# ===========================================================================
# Test 14 — Simultaneous min and max in one pass
# ===========================================================================

@cocotb.test()
async def test_minmax_single_pass(dut):
    """Find both minimum and maximum in one pass over an 8-element array.

    Initialises min and max to a[0], then iterates over a[1]..a[7],
    updating min or max via conditional branches at each step.

    Exercises: LW (load-use), BGE (two comparisons per element),
    ADD (conditional register copy), ADDI, BEQ (loop).

    Register usage:
        x1 = ptr     (byte address)
        x2 = n       (remaining elements)
        x3 = min     (running minimum, output)
        x4 = max     (running maximum, output)
        x5 = current element

    Assembly:

        [0]   ADDI x1, x0, 0       # ptr = 0
        [1]   ADDI x2, x0, 8       # n = 8
        [2]   LW   x3, x1, 0       # min = a[0]
        [3]   ADD  x4, x3, x0      # max = a[0]
        [4]   ADDI x1, x1, 4       # ptr → a[1]
        [5]   ADDI x2, x2, -1      # n = 7 remaining
        ─── loop ──────────────────────── ← PC=24 (index 6)
        [6]   BEQ  x2, x0, +36     # if n==0: done
        [7]   LW   x5, x1, 0       # x5 = a[ptr]
        [8]   BGE  x5, x3, +8      # if x5 >= min: skip min update
        [9]   ADD  x3, x5, x0      # min = x5
        ─── check_max ────────────────── ← PC=40 (index 10)
        [10]  BGE  x4, x5, +8      # if max >= x5: skip max update
        [11]  ADD  x4, x5, x0      # max = x5
        ─── next ─────────────────────── ← PC=48 (index 12)
        [12]  ADDI x1, x1, 4       # ptr += 4
        [13]  ADDI x2, x2, -1      # n--
        [14]  BEQ  x0, x0, -32     # goto loop
        ─── done ─────────────────────── ← PC=60 (index 15)
        [15]  NOP

    Data    : [42, 17, 88, 3, 55, 23, 99, 7]
    Expected: x3 = 3 (min), x4 = 99 (max)
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI(1, 0,  0),       # [0]  ptr = 0
        ADDI(2, 0,  8),       # [1]  n = 8
        LW  (3, 1,  0),       # [2]  min = a[0]
        ADD (4, 3,  0),       # [3]  max = a[0]  (copy min)
        ADDI(1, 1,  4),       # [4]  ptr → a[1]
        ADDI(2, 2, -1),       # [5]  n = 7
        # ── loop (PC=24) ──
        BEQ (2, 0, 36),       # [6]  if n==0: done; PC=24+36=60=idx15
        LW  (5, 1,  0),       # [7]  x5 = a[ptr]
        BGE (5, 3,  8),       # [8]  if x5 >= min: skip; PC=32+8=40=idx10
        ADD (3, 5,  0),       # [9]  min = x5
        # ── check_max (PC=40) ──
        BGE (4, 5,  8),       # [10] if max >= x5: skip; PC=40+8=48=idx12
        ADD (4, 5,  0),       # [11] max = x5
        # ── next (PC=48) ──
        ADDI(1, 1,  4),       # [12] ptr += 4
        ADDI(2, 2, -1),       # [13] n--
        BEQ (0, 0, -32),      # [14] goto loop; PC=56-32=24=idx6
        # ── done (PC=60) ──
        NOP,                   # [15]
    ]
    # fmt: on

    data = [42, 17, 88, 3, 55, 23, 99, 7]

    await _run(dut, prog,
               dmem_init={i: v for i, v in enumerate(data)},
               n_cycles=200,
               exp_regs={3: 3, 4: 99})


# ===========================================================================
# Test 15 — Palindrome check (symmetric data — true)
# ===========================================================================

@cocotb.test()
async def test_palindrome_check_true(dut):
    """Check that a symmetric 5-element array is detected as a palindrome.

    Two pointers (lo and hi) converge toward the middle.  Each iteration
    loads and compares the elements at both ends.  On mismatch the result
    is immediately set to 0 and the loop exits early.

    Exercises: LW (two loads per iteration), BEQ (match check),
    BGE (termination when pointers meet), ADDI (pointer update).

    Register usage:
        x1  = lo  (byte address, ascending)
        x2  = hi  (byte address, descending)
        x3  = a[lo]
        x4  = a[hi]
        x10 = result  (1 = palindrome, 0 = not)

    Assembly:

        [0]   ADDI x1, x0, 0       # lo = byte 0
        [1]   ADDI x2, x0, 16      # hi = byte 16 (5th element)
        [2]   ADDI x10, x0, 1      # result = 1 (assume palindrome)
        ─── loop ──────────────────────── ← PC=12 (index 3)
        [3]   BGE  x1, x2, +36     # if lo >= hi: done (palindrome)
        [4]   LW   x3, x1, 0       # x3 = a[lo]
        [5]   LW   x4, x2, 0       # x4 = a[hi]
        [6]   BEQ  x3, x4, +12     # if match: advance
        [7]   ADDI x10, x0, 0      # mismatch → result = 0
        [8]   BEQ  x0, x0, +16     # goto done (early exit)
        ─── advance ───────────────────── ← PC=36 (index 9)
        [9]   ADDI x1, x1, 4       # lo += 4
        [10]  ADDI x2, x2, -4      # hi -= 4
        [11]  BEQ  x0, x0, -32     # goto loop
        ─── done ──────────────────────── ← PC=48 (index 12)
        [12]  NOP

    Data    : [10, 20, 30, 20, 10]  (word addrs 0..4)
    Trace   : (10==10→advance), (20==20→advance), lo=8 >= hi=8 → done
    Expected: x10 = 1
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI( 1, 0,  0),      # [0]  lo = byte 0
        ADDI( 2, 0, 16),      # [1]  hi = byte 16
        ADDI(10, 0,  1),      # [2]  result = 1
        # ── loop (PC=12) ──
        BGE ( 1, 2, 36),      # [3]  if lo >= hi: done; PC=12+36=48=idx12
        LW  ( 3, 1,  0),      # [4]  x3 = a[lo]
        LW  ( 4, 2,  0),      # [5]  x4 = a[hi]
        BEQ ( 3, 4, 12),      # [6]  match → advance; PC=24+12=36=idx9
        ADDI(10, 0,  0),      # [7]  mismatch → result = 0
        BEQ ( 0, 0, 16),      # [8]  goto done; PC=32+16=48=idx12
        # ── advance (PC=36) ──
        ADDI( 1, 1,  4),      # [9]  lo += 4
        ADDI( 2, 2, -4),      # [10] hi -= 4
        BEQ ( 0, 0, -32),     # [11] goto loop; PC=44-32=12=idx3
        # ── done (PC=48) ──
        NOP,                   # [12]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={0: 10, 1: 20, 2: 30, 3: 20, 4: 10},
               n_cycles=100,
               exp_regs={10: 1})


# ===========================================================================
# Test 16 — Palindrome check (asymmetric data — false)
# ===========================================================================

@cocotb.test()
async def test_palindrome_check_false(dut):
    """Non-palindrome: early exit on first mismatch → result = 0.

    Uses the same program as test_palindrome_check_true but with
    non-symmetric data.  The first comparison (a[0]=10 vs a[4]=50)
    mismatches, setting result to 0 and exiting the loop immediately.

    Data    : [10, 20, 30, 40, 50]  (word addrs 0..4)
    Expected: x10 = 0
    """
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())

    # fmt: off
    prog = [
        ADDI( 1, 0,  0),      # [0]  lo = byte 0
        ADDI( 2, 0, 16),      # [1]  hi = byte 16
        ADDI(10, 0,  1),      # [2]  result = 1
        BGE ( 1, 2, 36),      # [3]  if lo >= hi: done
        LW  ( 3, 1,  0),      # [4]  x3 = a[lo]
        LW  ( 4, 2,  0),      # [5]  x4 = a[hi]
        BEQ ( 3, 4, 12),      # [6]  match → advance
        ADDI(10, 0,  0),      # [7]  mismatch → result = 0
        BEQ ( 0, 0, 16),      # [8]  goto done
        ADDI( 1, 1,  4),      # [9]  lo += 4
        ADDI( 2, 2, -4),      # [10] hi -= 4
        BEQ ( 0, 0, -32),     # [11] goto loop
        NOP,                   # [12]
    ]
    # fmt: on

    await _run(dut, prog,
               dmem_init={0: 10, 1: 20, 2: 30, 3: 40, 4: 50},
               n_cycles=100,
               exp_regs={10: 0})
