"""
Shared testbench helpers for the rv_cpu cocotb test suite.
==========================================================

Provides:
  - Simulation constants  (CLK_PERIOD_NS, N_NOPS, PIPE_DEPTH)
  - Instruction encoders  (R-, I-, S-, B-, J-type)
  - 32-bit arithmetic     (u32, s32)
  - DUT access helpers    (read_reg, write_reg, load_imem, read_dmem, write_dmem)
  - Simulation drivers    (do_reset, clock_n)
  - Generic test runners  (run_r_test, run_store_test, run_load_test)

Pipeline timing
---------------
  5-stage in-order pipeline: IF -> ID -> EX -> MEM -> WB
  No data forwarding — insert N_NOPS=4 NOPs between dependent instructions.
  A result is visible in the register file 5 rising edges after the instruction
  first appears at the IF stage output.

Memory layout
-------------
  Instruction memory (i_reg):
      byte PC 0x00 -> imem[0],  PC 0x04 -> imem[4],  ...
      load_imem maps  program[i]  ->  imem[i * 4]

  Data memory (sram_rw_dff):
      byte addr 0x00 -> mem_array[0],  0x04 -> mem_array[1], ...
      read_dmem / write_dmem operate on  word_addr = byte_addr >> 2

Hierarchical paths
------------------
  Instruction memory : dut.fetch_stage.i_reg_inst.mem
  Register file      : dut.decode_stage.reg_file_inst.mem
  Data memory        : dut.memory_stage.sram_inst.mem_array
"""

from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

# ---------------------------------------------------------------------------
# Simulation constants
# ---------------------------------------------------------------------------
CLK_PERIOD_NS = 10   # 100 MHz
N_NOPS        = 4    # NOPs between dependent instructions (pipeline depth - 1)
PIPE_DEPTH    = 7    # extra clock margin after the last instruction


# ---------------------------------------------------------------------------
# R-type instruction encoding
# ---------------------------------------------------------------------------
_OPCODE_R = 0b0110011  # 7'b0110011  (51)


def _r(funct7: int, rs2: int, rs1: int, funct3: int, rd: int) -> int:
    """Assemble one 32-bit R-type instruction word."""
    return (
        ((funct7 & 0x7F) << 25) |
        ((rs2    & 0x1F) << 20) |
        ((rs1    & 0x1F) << 15) |
        ((funct3 & 0x07) << 12) |
        ((rd     & 0x1F) <<  7) |
        _OPCODE_R
    )


NOP  = _r(0x00, 0, 0, 0b000, 0)  # add x0, x0, x0

def ADD (rd, rs1, rs2): return _r(0x00, rs2, rs1, 0b000, rd)
def SUB (rd, rs1, rs2): return _r(0x20, rs2, rs1, 0b000, rd)
def SLL (rd, rs1, rs2): return _r(0x00, rs2, rs1, 0b001, rd)
def SLT (rd, rs1, rs2): return _r(0x00, rs2, rs1, 0b010, rd)
def SLTU(rd, rs1, rs2): return _r(0x00, rs2, rs1, 0b011, rd)
def XOR (rd, rs1, rs2): return _r(0x00, rs2, rs1, 0b100, rd)
def SRL (rd, rs1, rs2): return _r(0x00, rs2, rs1, 0b101, rd)
def SRA (rd, rs1, rs2): return _r(0x20, rs2, rs1, 0b101, rd)
def OR  (rd, rs1, rs2): return _r(0x00, rs2, rs1, 0b110, rd)
def AND (rd, rs1, rs2): return _r(0x00, rs2, rs1, 0b111, rd)


# ---------------------------------------------------------------------------
# I-type instruction encoding  (loads + arithmetic immediate)
# ---------------------------------------------------------------------------
_OPCODE_I_ARITH = 0b0010011  # 7'b0010011  (19)
_OPCODE_I_LOAD  = 0b0000011  # 7'b0000011  (3)


def _i(imm12: int, rs1: int, funct3: int, rd: int, opcode: int) -> int:
    """Assemble one 32-bit I-type instruction word."""
    return (
        ((imm12  & 0xFFF) << 20) |
        ((rs1    & 0x1F)  << 15) |
        ((funct3 & 0x07)  << 12) |
        ((rd     & 0x1F)  <<  7) |
        (opcode  & 0x7F)
    )


def ADDI(rd: int, rs1: int, imm: int) -> int:
    """ADDI rd, rs1, imm  — rd = rs1 + sign_extend(imm)"""
    return _i(imm, rs1, 0b000, rd, _OPCODE_I_ARITH)

def LW (rd: int, rs1: int, imm: int) -> int:
    """LW  rd, imm(rs1)  — 32-bit word load"""
    return _i(imm, rs1, 0b010, rd, _OPCODE_I_LOAD)

def LH (rd: int, rs1: int, imm: int) -> int:
    """LH  rd, imm(rs1)  — sign-extended 16-bit load"""
    return _i(imm, rs1, 0b001, rd, _OPCODE_I_LOAD)

def LB (rd: int, rs1: int, imm: int) -> int:
    """LB  rd, imm(rs1)  — sign-extended 8-bit load"""
    return _i(imm, rs1, 0b000, rd, _OPCODE_I_LOAD)

def LHU(rd: int, rs1: int, imm: int) -> int:
    """LHU rd, imm(rs1)  — zero-extended 16-bit load"""
    return _i(imm, rs1, 0b101, rd, _OPCODE_I_LOAD)

def LBU(rd: int, rs1: int, imm: int) -> int:
    """LBU rd, imm(rs1)  — zero-extended 8-bit load"""
    return _i(imm, rs1, 0b100, rd, _OPCODE_I_LOAD)


# ---------------------------------------------------------------------------
# S-type instruction encoding  (stores)
# ---------------------------------------------------------------------------
_OPCODE_S = 0b0100011  # 7'b0100011  (35)


def _s(imm12: int, rs2: int, rs1: int, funct3: int) -> int:
    """Assemble one 32-bit S-type instruction word."""
    imm12    = imm12 & 0xFFF        # keep 12 bits — handles Python negative ints
    imm_11_5 = (imm12 >> 5) & 0x7F
    imm_4_0  =  imm12        & 0x1F
    return (
        (imm_11_5        << 25) |
        ((rs2  & 0x1F)   << 20) |
        ((rs1  & 0x1F)   << 15) |
        ((funct3 & 0x07) << 12) |
        (imm_4_0         <<  7) |
        _OPCODE_S
    )


def SW(rs1: int, rs2: int, imm: int) -> int:
    """SW rs2, imm(rs1)  — store 32-bit word"""
    return _s(imm, rs2, rs1, 0b010)

def SH(rs1: int, rs2: int, imm: int) -> int:
    """SH rs2, imm(rs1)  — store lower 16 bits"""
    return _s(imm, rs2, rs1, 0b001)

def SB(rs1: int, rs2: int, imm: int) -> int:
    """SB rs2, imm(rs1)  — store lowest byte"""
    return _s(imm, rs2, rs1, 0b000)


# ---------------------------------------------------------------------------
# B-type instruction encoding  (branches)
# ---------------------------------------------------------------------------
_OPCODE_B = 0b1100011  # 7'b1100011  (99)


def _b(imm: int, rs2: int, rs1: int, funct3: int) -> int:
    """Assemble one 32-bit B-type instruction word.

    The 13-bit signed immediate encodes a byte offset (bit 0 is always 0).
    Bit layout:
        [31]    = imm[12]
        [30:25] = imm[10:5]
        [24:20] = rs2
        [19:15] = rs1
        [14:12] = funct3
        [11:8]  = imm[4:1]
        [7]     = imm[11]
        [6:0]   = opcode
    """
    imm      = imm & 0x1FFF       # keep 13 bits (handles Python negative ints)
    imm12    = (imm >> 12) & 0x1
    imm11    = (imm >> 11) & 0x1
    imm10_5  = (imm >>  5) & 0x3F
    imm4_1   = (imm >>  1) & 0xF
    return (
        (imm12           << 31) |
        (imm10_5         << 25) |
        ((rs2  & 0x1F)   << 20) |
        ((rs1  & 0x1F)   << 15) |
        ((funct3 & 0x7)  << 12) |
        (imm4_1          <<  8) |
        (imm11           <<  7) |
        _OPCODE_B
    )


def BEQ (rs1, rs2, imm): return _b(imm, rs2, rs1, 0b000)
def BNE (rs1, rs2, imm): return _b(imm, rs2, rs1, 0b001)
def BLT (rs1, rs2, imm): return _b(imm, rs2, rs1, 0b100)
def BGE (rs1, rs2, imm): return _b(imm, rs2, rs1, 0b101)
def BLTU(rs1, rs2, imm): return _b(imm, rs2, rs1, 0b110)
def BGEU(rs1, rs2, imm): return _b(imm, rs2, rs1, 0b111)


# ---------------------------------------------------------------------------
# J-type instruction encoding  (JAL) + JALR
# ---------------------------------------------------------------------------
_OPCODE_J    = 0b1101111  # 7'b1101111  (111)
_OPCODE_JALR = 0b1100111  # 7'b1100111  (103)


def _j(imm: int, rd: int) -> int:
    """Assemble one 32-bit J-type instruction word.

    The 21-bit signed immediate encodes a byte offset (bit 0 is always 0).
    Bit layout:
        [31]    = imm[20]
        [30:21] = imm[10:1]
        [20]    = imm[11]
        [19:12] = imm[19:12]
        [11:7]  = rd
        [6:0]   = opcode
    """
    imm      = imm & 0x1FFFFF      # keep 21 bits
    imm20    = (imm >> 20) & 0x1
    imm10_1  = (imm >>  1) & 0x3FF
    imm11    = (imm >> 11) & 0x1
    imm19_12 = (imm >> 12) & 0xFF
    return (
        (imm20           << 31) |
        (imm10_1         << 21) |
        (imm11           << 20) |
        (imm19_12        << 12) |
        ((rd   & 0x1F)   <<  7) |
        _OPCODE_J
    )


def JAL (rd, imm):        return _j(imm, rd)
def JALR(rd, rs1, imm):   return _i(imm, rs1, 0b000, rd, _OPCODE_JALR)


# ---------------------------------------------------------------------------
# 32-bit arithmetic helpers
# ---------------------------------------------------------------------------
def u32(v: int) -> int:
    """Truncate to unsigned 32-bit integer."""
    return v & 0xFFFF_FFFF


def s32(v: int) -> int:
    """Reinterpret a 32-bit unsigned integer as a signed Python int."""
    v = u32(v)
    return v - 0x1_0000_0000 if v >= 0x8000_0000 else v


# ---------------------------------------------------------------------------
# DUT register-file helpers
# ---------------------------------------------------------------------------
def read_reg(dut, reg_num: int) -> int:
    """Return the value of x{reg_num} as an unsigned 32-bit int."""
    if reg_num == 0:
        return 0
    return int(dut.decode_stage.reg_file_inst.mem[reg_num].value)


def write_reg(dut, reg_num: int, value: int) -> None:
    """Directly write a value into x{reg_num}, bypassing the WB stage."""
    if reg_num != 0:
        dut.decode_stage.reg_file_inst.mem[reg_num].value = u32(value)


# ---------------------------------------------------------------------------
# DUT instruction-memory helper
# ---------------------------------------------------------------------------
def load_imem(dut, instructions: list) -> None:
    """
    Write a program into instruction memory.

    program[i] is placed at imem[i * 4] to match the byte-addressed PC.
    All remaining slots are filled with NOPs.
    """
    imem = dut.fetch_stage.i_reg_inst.mem

    for i in range(64):
        imem[i].value = NOP

    for i, instr in enumerate(instructions):
        pc_idx = i # note that this is not idx*4 becuase i_mem uses pc >> 2
        # print(f"Loading instruction 0x{instr:08x} at imem[{pc_idx}] (PC=0x{pc_idx:02x})")
        assert pc_idx < 64, (
            f"Program too large for imem (depth=64): "
            f"instruction {i} needs PC={pc_idx}"
        )
        imem[pc_idx].value = instr


# ---------------------------------------------------------------------------
# DUT data-memory helpers
# ---------------------------------------------------------------------------
def read_dmem(dut, word_addr: int) -> int:
    """
    Return the 32-bit word at data-memory word address `word_addr`.

    The SRAM indexes its array as  mem_array[byte_addr >> 2]:
        word_addr 0  <->  byte address 0x00
        word_addr 1  <->  byte address 0x04, etc.
    """
    return int(dut.memory_stage.sram_inst.mem_array[word_addr].value)


def write_dmem(dut, word_addr: int, value: int) -> None:
    """Directly initialise a data-memory word, bypassing the pipeline."""
    dut.memory_stage.sram_inst.mem_array[word_addr].value = u32(value)


# ---------------------------------------------------------------------------
# Simulation drivers
# ---------------------------------------------------------------------------
async def do_reset(dut, cycles: int = 4) -> None:
    """Assert active-low reset for `cycles` rising edges, then release."""
    dut.rstn_i.value     = 0
    dut.riscv_en_i.value = 0
    for _ in range(cycles):
        await RisingEdge(dut.clk_i)
    dut.rstn_i.value     = 1
    dut.riscv_en_i.value = 1


async def clock_n(dut, n: int) -> None:
    """Advance simulation by n rising clock edges."""
    for _ in range(n):
        await RisingEdge(dut.clk_i)


# ---------------------------------------------------------------------------
# Generic test runners
# ---------------------------------------------------------------------------
async def run_r_test(dut, program: list, reg_init: dict, expected: dict) -> None:
    """
    Load a program, reset DUT, inject register values, run, and verify registers.

    Args:
        program  : flat list of 32-bit instruction words.
        reg_init : {reg_num: value} — registers to initialise after reset.
        expected : {reg_num: value} — expected register values after commit.
    """
    load_imem(dut, program)
    await do_reset(dut)
    for reg_num, val in reg_init.items():
        write_reg(dut, reg_num, val)
    await clock_n(dut, len(program) + PIPE_DEPTH)
    for reg_num, exp_val in expected.items():
        got     = read_reg(dut, reg_num)
        exp_u32 = u32(exp_val)
        assert got == exp_u32, (
            f"x{reg_num}: expected 0x{exp_u32:08x} ({exp_u32}), "
            f"got 0x{got:08x} ({got})"
        )


async def run_store_test(
    dut,
    program: list,
    reg_init: dict,
    dmem_expected: dict,
) -> None:
    """
    Load a program, reset DUT, inject register values, run, verify data memory.

    Args:
        program       : flat list of 32-bit instruction words.
        reg_init      : {reg_num: value} — registers to initialise after reset.
        dmem_expected : {word_addr: expected_u32} — data-memory words to check
                        after commit  (word_addr = byte_addr >> 2).
    """
    load_imem(dut, program)
    await do_reset(dut)
    for reg_num, val in reg_init.items():
        write_reg(dut, reg_num, val)
    await clock_n(dut, len(program) + PIPE_DEPTH)
    for word_addr, exp_val in dmem_expected.items():
        got     = read_dmem(dut, word_addr)
        exp_u32 = u32(exp_val)
        assert got == exp_u32, (
            f"dmem[{word_addr}] (byte addr 0x{word_addr * 4:04x}): "
            f"expected 0x{exp_u32:08x}, got 0x{got:08x}"
        )


async def run_load_test(
    dut,
    program: list,
    reg_init: dict,
    dmem_init: dict,
    expected: dict,
) -> None:
    """
    Load a program, reset DUT, inject registers and data memory, run, verify registers.

    Args:
        program   : flat list of 32-bit instruction words.
        reg_init  : {reg_num: value} — registers to initialise after reset.
        dmem_init : {word_addr: value} — data-memory words to pre-load after reset.
        expected  : {reg_num: expected_u32} — expected register values after commit.
    """
    load_imem(dut, program)
    await do_reset(dut)
    for reg_num, val in reg_init.items():
        write_reg(dut, reg_num, val)
    for word_addr, val in dmem_init.items():
        write_dmem(dut, word_addr, val)
    await clock_n(dut, len(program) + PIPE_DEPTH)
    for reg_num, exp_val in expected.items():
        got     = read_reg(dut, reg_num)
        exp_u32 = u32(exp_val)
        assert got == exp_u32, (
            f"x{reg_num}: expected 0x{exp_u32:08x} ({exp_u32}), "
            f"got 0x{got:08x} ({got})"
        )
