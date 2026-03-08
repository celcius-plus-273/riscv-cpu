# RISC-V CPU

A 32-bit RISC-V CPU implemented in SystemVerilog, simulated with Verilator and verified with cocotb.

**Notes:** 
- Microarchitecture is based on Harris & Harris DDCA 5-stage In-Order Pipelined RV32I processor ~ with added optimizations :)
- Custom SystemVerilog design (no templates / no agents)
- Verification flow was accelerated with the help of an Agent

## Motivation

- Putting concepts learned from Advanced Computer Architecture into practice
- Getting hands-on experience with microarchitecture design outside of coursework
- Deepening understanding of general-purpose computing
- Building foundations for implementing domain-specific accelerators

## Supported ISA

**RV32I** -- the base 32-bit integer instruction set.

| Category          | Instructions                                            |
|-------------------|---------------------------------------------------------|
| R-type arithmetic | ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND      |
| I-type arithmetic | ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI  |
| Loads             | LB, LH, LW, LBU, LHU                                  |
| Stores            | SB, SH, SW                                             |
| Branches          | BEQ, BNE, BLT, BGE, BLTU, BGEU                        |
| Jumps             | JAL, JALR                                               |
| Upper immediate   | LUI, AUIPC                                             |

**Total: 37 instructions** (full RV32I minus FENCE, ECALL, EBREAK, and CSR instructions).

## Microarchitecture

### Overview

5-stage in-order pipeline with always-not-taken branch prediction, 2-level data forwarding, and load-use stall detection.

```
                          Hazard Unit
                 ┌─────────────────────────┐
                 │  forwarding / stall /   │
                 │  flush control          │
                 └──┬──────┬──────┬────────┘
                    │      │      │
                    ▼      ▼      ▼
  ┌──────┐   ┌──────┐   ┌──────┐   ┌──────┐   ┌──────┐
  │  IF  │──▶│  ID  │──▶│  EX  │──▶│  MEM │──▶│  WB  │
  │      │   │      │   │      │   │      │   │      │
  │fetch │   │decode│   │alu + │   │dmem  │   │write │
  │+ PC  │   │+ regs│   │branch│   │access│   │back  │
  └──────┘   └──────┘   └──────┘   └──────┘   └──────┘
      ▲                      │          │          │
      │          branch/jump │          │          │
      └──────────────────────┘          │          │
                                        │          │
                           MEM→EX fwd   │  WB→EX   │
                        (priority) ─────┘  fwd ────┘
```

### Pipeline Stages

| Stage | Module    | File                     | Description                                                     |
|-------|-----------|--------------------------|-----------------------------------------------------------------|
| IF    | `pipe_if` | `src/rtl/cpu/pipe_if.sv` | Program counter, instruction memory read, PC+4 computation      |
| ID    | `pipe_id` | `src/rtl/cpu/pipe_id.sv` | Instruction decode, register file read, immediate generation     |
| EX    | `pipe_ex` | `src/rtl/cpu/pipe_ex.sv` | ALU execution, branch/jump resolution, forwarding mux selection |
| MEM   | `pipe_mem`| `src/rtl/cpu/pipe_mem.sv`| Data memory read/write, byte/halfword alignment                  |
| WB    | `pipe_wb` | `src/rtl/cpu/pipe_wb.sv` | Writeback mux: ALU result, memory data, PC+4, or address result |

Supporting modules:

| Module     | File                          | Description                                       |
|------------|-------------------------------|---------------------------------------------------|
| `control`  | `src/rtl/cpu/control.sv`      | Instruction decoder (opcode, funct3, funct7)       |
| `hazard`   | `src/rtl/cpu/hazard.sv`       | Forwarding, stall, and flush logic                 |
| `alu`      | `src/rtl/f_unit/alu.sv`       | 10-operation arithmetic/logic unit                 |

### Hazard Detection and Forwarding

**Data forwarding** -- 2-level forwarding resolves most RAW hazards without stalling:

- **MEM->EX** (priority): forwards the ALU result from the MEM stage to EX operands (1-cycle-old result)
- **WB->EX**: forwards the writeback data from WB to EX operands (2-cycle-old result)

**Load-use stall** -- when EX needs a register that MEM is currently loading from data memory, the pipeline inserts a 1-cycle bubble (stalls IF and ID, inserts NOP into EX). The loaded data is then forwarded via MEM->EX on the next cycle.

**Branch/jump flush** -- the pipeline uses always-not-taken prediction. Branches and jumps are resolved in the EX stage. When a branch is taken or a jump executes, IF and ID are flushed (2 instructions squashed).

### ALU

| Operation | Encoding   | Description                   |
|-----------|------------|-------------------------------|
| ADD       | `4'b0000`  | Addition                      |
| SUB       | `4'b0001`  | Subtraction                   |
| SLL       | `4'b0010`  | Shift left logical            |
| SLT       | `4'b0011`  | Set less than (signed)        |
| SLTU      | `4'b0100`  | Set less than (unsigned)      |
| XOR       | `4'b0101`  | Bitwise XOR                   |
| SRL       | `4'b0110`  | Shift right logical           |
| SRA       | `4'b0111`  | Shift right arithmetic        |
| OR        | `4'b1000`  | Bitwise OR                    |
| AND       | `4'b1001`  | Bitwise AND                   |

### Writeback Sources

The WB stage selects one of four sources based on `wb_src`:

| `wb_src` | Source       | Used by                     |
|----------|--------------|-----------------------------|
| `2'b00`  | ALU result   | R-type, I-type arithmetic   |
| `2'b01`  | Memory data  | Loads (LB, LH, LW, etc.)   |
| `2'b10`  | PC + 4       | JAL, JALR (link address)    |
| `2'b11`  | Address result | AUIPC                     |

### Memory Subsystem

| Module        | File                              | Description                                                      |
|---------------|-----------------------------------|------------------------------------------------------------------|
| `i_reg`       | `src/rtl/memory/i_reg.sv`         | Instruction memory -- 4096 x 32-bit words, single-port read      |
| `reg_file`    | `src/rtl/memory/reg_file.sv`      | Register file -- 32 x 32-bit, 2 read / 1 write, x0 hardwired to zero |
| `sram_rw_dff` | `src/rtl/memory/sram_rw_dff.sv`   | Data memory -- 4096 x 32-bit words, byte-masked writes (LB/LH/LW/SB/SH/SW) |

## Project Structure

```
src/
  rtl/
    rv_cpu.sv              # top-level module
    rv_cpu_pkg.sv          # package (structs, enums, parameters)
    cpu/
      control.sv           # instruction decoder
      hazard.sv            # forwarding + stall + flush
      pipe_if.sv           # fetch stage
      pipe_id.sv           # decode stage
      pipe_ex.sv           # execute stage
      pipe_mem.sv          # memory stage
      pipe_wb.sv           # writeback stage
    f_unit/
      alu.sv               # arithmetic logic unit
    memory/
      i_reg.sv             # instruction memory
      reg_file.sv          # register file
      sram_rw_dff.sv       # data memory
  verif/
    include/
      rv_cpu.include       # Verilator filelist
    testbench/
      tb_helpers.py        # shared encoders + DUT access helpers
      tb_*.py              # cocotb testbenches (12 files)
sim/
  tasks.py                 # Invoke task definitions
  invoke.yaml              # Verilator build configuration
  rv_cpu/
    sim_build/             # Verilator build output
```

## Prerequisites

- Python 3.13
- Verilator 5.x
- cocotb 2.x
- Invoke

## Verification

### Infrastructure

Tests are written in Python using **cocotb** and run on **Verilator**-compiled RTL. **Invoke** provides the task runner interface. Each testbench directly manipulates DUT signals (instruction memory, register file, data memory) through `tb_helpers.py`, which provides:

- 37 instruction encoder functions matching the RV32I ISA
- DUT access helpers: `read_reg`, `write_reg`, `load_imem`, `read_dmem`, `write_dmem`
- Simulation drivers: `do_reset`, `clock_n`
- Generic test runners: `run_r_test`, `run_store_test`, `run_load_test`

### Running Tests

```bash
# Go into simulation directory
cd sim

# Build the Verilator model
inv build

# Run a single testbench
inv sim --testbench tb_r_type

# Run all testbenches
inv sim-all
```

### Testbenches

| Testbench        | Tests | Description                                               |
|------------------|-------|-----------------------------------------------------------|
| `tb_r_type`      |    18 | R-type ALU operations (ADD, SUB, SLL, etc.)               |
| `tb_i_arith`     |    20 | I-type arithmetic (ADDI, SLTI, SLLI, SRAI, etc.)         |
| `tb_load`        |    15 | Load instructions (LW, LH, LB, LHU, LBU)                |
| `tb_store`       |     7 | Store instructions (SW, SH, SB)                           |
| `tb_branch`      |    24 | Branch instructions (BEQ, BNE, BLT, BGE, BLTU, BGEU)    |
| `tb_jal_jalr`    |    18 | JAL/JALR jumps, call/return, recursive patterns           |
| `tb_u_type`      |     9 | LUI and AUIPC                                            |
| `tb_hazard`      |    13 | Data forwarding, load-use stalls, RAW hazard chains       |
| `tb_mem_arith`   |     9 | Load-modify-store sequences                               |
| `tb_multi_op`    |     5 | Multi-instruction dependency chains                       |
| `tb_integration` |    24 | Mixed instruction types: straight-line and loop programs  |
| `tb_programs`    |    17 | Full programs: sort, search, fibonacci, checksum, etc.    |

**Total: 179 tests**

## Roadmap

- [ ] Multi-level cache hierarchy (L1 I-cache, L1 D-cache, unified L2 cache)
- [ ] Extended verification via [riscv-arch-test](https://github.com/riscv-non-isa/riscv-arch-test) compliance suite and compiled C programs
- [ ] Memory-mapped peripheral bus
- [ ] Multi-functional unit support (superscalar execution)
