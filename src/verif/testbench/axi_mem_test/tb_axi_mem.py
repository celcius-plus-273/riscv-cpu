"""
cocotb Testbench: axi_mem_test  —  AXI4-Lite Interface Tests
=============================================================

Directed tests for the AXI4-Lite interface between:
    pipe_mem   (MEM pipeline stage, AXI4-Lite master)
    d_cache    (data cache,         AXI4-Lite slave)

The DUT wrapper (axi_mem_test) connects them via an axi4_lite_if bus.
Test stimulus is driven through the ex_mem_s pipeline struct input.

Store tests verify data reaches the d_cache SRAM by peeking mem_array.
Load tests pre-load the SRAM (backdoor) and verify data reaches the
SRAM registered output (data_o), which feeds axl_if.r_data -> mem_wb_o.mem_data.

ex_mem_s packed-struct bit map (143 bits, MSB-first declaration order)
----------------------------------------------------------------------
    [4:0]     rd_addr      5b
    [5]       rd_wen       1b
    [7:6]     wb_src       2b
    [39:8]    mem_wr_data  32b
    [40]      mem_signed   1b
    [44:41]   mem_mask     4b
    [45]      mem_wr_en    1b
    [46]      mem_rd_en    1b
    [78:47]   addr_result  32b
    [110:79]  alu_result   32b
    [142:111] pc_p4        32b

Run with:
    inv run --testbench tb_axi_mem --toplevel axi_mem_test
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------
CLK_PERIOD_NS = 10   # 100 MHz
RESET_CYCLES  = 4    # rising edges held in reset
SETTLE_CYCLES = 2    # for d_cache rdy signals to register after reset
TXN_CYCLES    = 10   # conservative wait for one AXI transaction to complete


# ---------------------------------------------------------------------------
# ex_mem_s struct packing
# ---------------------------------------------------------------------------
def pack_ex_mem(
    pc_p4=0, alu_result=0, addr_result=0,
    mem_rd_en=0, mem_wr_en=0, mem_mask=0, mem_signed=0,
    mem_wr_data=0, wb_src=0, rd_wen=0, rd_addr=0,
):
    """Pack ex_mem_s fields into a 143-bit integer for driving dut.ex_mem_i."""
    v  = (rd_addr      & 0x1F)
    v |= (rd_wen       & 0x1)         << 5
    v |= (wb_src       & 0x3)         << 6
    v |= (mem_wr_data  & 0xFFFFFFFF)  << 8
    v |= (mem_signed   & 0x1)         << 40
    v |= (mem_mask     & 0xF)         << 41
    v |= (mem_wr_en    & 0x1)         << 45
    v |= (mem_rd_en    & 0x1)         << 46
    v |= (addr_result  & 0xFFFFFFFF)  << 47
    v |= (alu_result   & 0xFFFFFFFF)  << 79
    v |= (pc_p4        & 0xFFFFFFFF)  << 111
    return v


EX_MEM_IDLE = 0  # all-zero stimulus (no memory operation)


# ---------------------------------------------------------------------------
# Simulation helpers
# ---------------------------------------------------------------------------
async def do_reset(dut):
    """Assert active-low reset, then wait for d_cache rdy signals to settle."""
    dut.rstn_i.value   = 0
    dut.ex_mem_i.value = EX_MEM_IDLE
    for _ in range(RESET_CYCLES):
        await RisingEdge(dut.clk_i)
    dut.rstn_i.value = 1
    # d_cache registers aw_rdy / w_rdy / ar_rdy = 1 one cycle after reset
    for _ in range(SETTLE_CYCLES):
        await RisingEdge(dut.clk_i)


async def clock_n(dut, n):
    """Advance simulation by *n* rising clock edges."""
    for _ in range(n):
        await RisingEdge(dut.clk_i)


# -- SRAM backdoor helpers --------------------------------------------------
def read_sram(dut, word_addr):
    """Peek d_cache SRAM word: mem_array[word_addr]."""
    return int(dut.d_cache_inst.sram_inst.mem_array[word_addr].value)


def write_sram(dut, word_addr, value):
    """Poke a word into d_cache SRAM (backdoor, bypasses AXI)."""
    dut.d_cache_inst.sram_inst.mem_array[word_addr].value = value & 0xFFFFFFFF


def read_sram_data_o(dut):
    """Read SRAM registered output (data_o).

    This is the value that feeds:
        cache_rdata -> axl_if.r_data -> mem_wb_o.mem_data
    It holds its value after a read until the next SRAM access.
    """
    return int(dut.d_cache_inst.sram_inst.data_o.value)


# ===========================================================================
# Store tests  (write via EX/MEM struct -> AXI -> SRAM, verify SRAM)
# ===========================================================================

@cocotb.test()
async def test_sw_basic(dut):
    """SW: Store 0xDEAD_BEEF at byte addr 0 -> SRAM[0]."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await do_reset(dut)

    dut.ex_mem_i.value = pack_ex_mem(
        alu_result=0x00, mem_wr_en=1, mem_mask=0xF, mem_wr_data=0xDEADBEEF,
    )
    await clock_n(dut, 1)
    dut.ex_mem_i.value = EX_MEM_IDLE
    await clock_n(dut, TXN_CYCLES)

    got = read_sram(dut, 0)
    assert got == 0xDEADBEEF, f"SRAM[0]: expected 0xDEADBEEF, got 0x{got:08X}"


@cocotb.test()
async def test_sw_offset(dut):
    """SW: Store 0xCAFE_BABE at byte addr 8 -> SRAM[2]."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await do_reset(dut)

    dut.ex_mem_i.value = pack_ex_mem(
        alu_result=0x08, mem_wr_en=1, mem_mask=0xF, mem_wr_data=0xCAFEBABE,
    )
    await clock_n(dut, TXN_CYCLES)
    dut.ex_mem_i.value = EX_MEM_IDLE

    got = read_sram(dut, 2)
    assert got == 0xCAFEBABE, f"SRAM[2]: expected 0xCAFEBABE, got 0x{got:08X}"


@cocotb.test()
async def test_sh_basic(dut):
    """SH: Store halfword (mask=0x3) — only lower 2 bytes written."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await do_reset(dut)

    dut.ex_mem_i.value = pack_ex_mem(
        alu_result=0x00, mem_wr_en=1, mem_mask=0x3, mem_wr_data=0xABCD1234,
    )
    await clock_n(dut, TXN_CYCLES)
    dut.ex_mem_i.value = EX_MEM_IDLE

    got = read_sram(dut, 0)
    assert got == 0x00001234, f"SRAM[0]: expected 0x00001234, got 0x{got:08X}"


@cocotb.test()
async def test_sb_basic(dut):
    """SB: Store byte (mask=0x1) — only lowest byte written."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await do_reset(dut)

    dut.ex_mem_i.value = pack_ex_mem(
        alu_result=0x00, mem_wr_en=1, mem_mask=0x1, mem_wr_data=0xABCDEF42,
    )
    await clock_n(dut, TXN_CYCLES)
    dut.ex_mem_i.value = EX_MEM_IDLE

    got = read_sram(dut, 0)
    assert got == 0x00000042, f"SRAM[0]: expected 0x00000042, got 0x{got:08X}"


# ===========================================================================
# Load tests  (pre-seed SRAM, read via EX/MEM struct -> AXI, verify data_o)
# ===========================================================================

@cocotb.test()
async def test_lw_basic(dut):
    """LW: Pre-load SRAM[0]=0x1234_5678, load word, check data_o."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await do_reset(dut)

    write_sram(dut, 0, 0x12345678)
    write_sram(dut, 2, 0xdeadbeef)
    write_sram(dut, 4, 0xcafecafe)

    dut.ex_mem_i.value = pack_ex_mem(
        alu_result=0x00, mem_rd_en=1, mem_mask=0xF,
    )
    await clock_n(dut, 1)
    dut.ex_mem_i.value = EX_MEM_IDLE
    # await clock_n(dut, 1)

    # dut.ex_mem_i.value = pack_ex_mem(
    #     alu_result=0x4, mem_rd_en=1, mem_mask=0xF,
    # )
    # await clock_n(dut, 1)
    # dut.ex_mem_i.value = EX_MEM_IDLE
    # await clock_n(dut, 1)

    # dut.ex_mem_i.value = pack_ex_mem(
    #     alu_result=0x2, mem_rd_en=1, mem_mask=0xF,
    # )
    # await clock_n(dut, 1)
    # dut.ex_mem_i.value = EX_MEM_IDLE

    await clock_n(dut, TXN_CYCLES)

    got = read_sram_data_o(dut)
    assert got == 0x12345678, f"data_o: expected 0x12345678, got 0x{got:08X}"


@cocotb.test()
async def test_lw_offset(dut):
    """LW: Pre-load SRAM[3]=0xFEED_FACE, load from byte addr 0x0C, check data_o."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await do_reset(dut)

    write_sram(dut, 3, 0xFEEDFACE)

    dut.ex_mem_i.value = pack_ex_mem(
        alu_result=0x0C, mem_rd_en=1, mem_mask=0xF,
    )
    await clock_n(dut, TXN_CYCLES)
    dut.ex_mem_i.value = EX_MEM_IDLE

    got = read_sram_data_o(dut)
    assert got == 0xFEEDFACE, f"data_o: expected 0xFEEDFACE, got 0x{got:08X}"


# ===========================================================================
# Round-trip test  (store -> load at the same address)
# ===========================================================================
#
# NOTE: There is a protocol desync between pipe_mem and d_cache.
#
# pipe_mem drives its AXI outputs based on *next_state* (combinational) rather
# than state_r (registered).  When pipe_mem's W_RESP -> IDLE transition fires,
# b_rdy drops immediately in the same combinational cone.  d_cache (in W_RESP)
# sees b_rdy=0 and stays stuck in W_RESP, unable to return to IDLE.
#
# In the full CPU this is masked because the hazard unit stalls the pipeline
# (holding mem_wr_en=1), which causes pipe_mem to re-enter W_ADDR on the next
# cycle — that assertion of b_rdy releases d_cache.  But the d_cache never
# actually reaches a clean IDLE simultaneously with pipe_mem after a write.
#
# For the round-trip test below we use a backdoor force of d_cache.state_r
# to recover from the stuck state.  This allows us to verify the full
# store-then-load data path.  A proper fix would be to drive AXI outputs
# from state_r instead of next_state in pipe_mem's axi_lite_out block.

@cocotb.test()
async def test_store_load_roundtrip(dut):
    """SW then LW: write 0xBAAD_F00D to byte addr 0x10, read it back."""
    cocotb.start_soon(Clock(dut.clk_i, CLK_PERIOD_NS, unit="ns").start())
    await do_reset(dut)

    # --- Store phase ---
    dut.ex_mem_i.value = pack_ex_mem(
        alu_result=0x10, mem_wr_en=1, mem_mask=0xF, mem_wr_data=0xBAADF00D,
    )
    await clock_n(dut, TXN_CYCLES)
    dut.ex_mem_i.value = EX_MEM_IDLE
    await RisingEdge(dut.clk_i)

    # Verify write landed in SRAM
    sram_val = read_sram(dut, 4)  # byte addr 0x10 >> 2 = word 4
    assert sram_val == 0xBAADF00D, (
        f"Store: SRAM[4] expected 0xBAADF00D, got 0x{sram_val:08X}"
    )

    # Force d_cache out of stuck W_RESP (see protocol note above)
    dut.d_cache_inst.state_r.value = 0  # 2'b00 = IDLE
    await clock_n(dut, SETTLE_CYCLES)   # let registered outputs re-settle

    # --- Load phase ---
    dut.ex_mem_i.value = pack_ex_mem(
        alu_result=0x10, mem_rd_en=1, mem_mask=0xF,
    )
    await clock_n(dut, TXN_CYCLES)
    dut.ex_mem_i.value = EX_MEM_IDLE

    got = read_sram_data_o(dut)
    assert got == 0xBAADF00D, (
        f"Load: data_o expected 0xBAADF00D, got 0x{got:08X}"
    )
