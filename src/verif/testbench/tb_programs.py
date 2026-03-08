"""
cocotb Testbench: rv_cpu  —  Real-Program Integration Tests
============================================================

Tests multi-instruction programs that exercise the complete pipeline:
loads, stores, arithmetic, branches (forward + backward), and loops.

All hazards (load-use stalls, RAW stalls, forwarding) are handled
automatically by the hazard unit.  No manual NOPs are inserted.

Programs
--------
  1. test_array_sum         — iterative sum of 8 integers in memory
  2. test_array_max         — find maximum value in an array of 8
  3. test_multiply          — compute A×B via repeated addition
  4. test_fibonacci         — iterative fib(10) = 55
  5. test_xor_checksum      — XOR-reduce 8 memory words, store result

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
    ADDI, LW, SW,
    BEQ, BNE, BGE,
    u32,
    load_imem, do_reset, clock_n,
    write_reg, read_reg, write_dmem, read_dmem,
)


# ---------------------------------------------------------------------------
# Helper
# ---------------------------------------------------------------------------

async def _run(dut, program, *, dmem_init={}, n_cycles,
               exp_regs={}, exp_dmem={}):
    """Reset, load program, pre-populate memory, run for n_cycles, verify."""
    load_imem(dut, program)
    await do_reset(dut)
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
               n_cycles=100,
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
