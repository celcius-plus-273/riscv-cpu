# RISCV CPU
Welcome to my RISCV CPU project. 
This repository hosts all of the source code used to simulate a 32 bit RISCV based CPU architecture.

## Motivation
- Putting all of the concepts learned from Adanvced Comp. Arch. into practice.
- Getting hands-on experience with microarchitecture design outside of coursework
- I want to deepen and solidify my understanding of general purpose computing
- Build the foundations for implementing domain specific accelerators

## End Goals
My end goal of this project is:
- Out-of-Order Pipelined Microarchitecture
- Multi-level Cache (L1 and L2)
- Some sort of I/O Subsystem
- Synthesis on Xilinx Artix 7 Board

**Note**: This goals could change along the exploration of this project.

## Supported ISA:
- RISCV: RV32I

## Current Progress:
RTL Modules:
- [x] General Purpose Register File
- [x] ALU Unit
- [x] Register and ALU integration on simple datapath
- [x] 3-stages: DECODE, EXECUTE, and WRITEBACK
- [x] Instruction register and PC (program counter) -> Fetch Stage
- [ ] Extend pipeline for I-Type instructions
- [ ] Instruction memory -> L1 I-cache
- [ ] Data Memory -> L1 D-cache


## Notes & Questions
- nop is defined as addi x0, x0, 0 -> 32'b0010_0110_0000_0000_0000_0000_0000_0000
    - What happens if instruction 32'b0 is passed into decode? -> invalid?
    - Do we need to make a distinction between NOP and invalid?
    - If so, does it make sense to incorporate a valid bit as a passthrough value?
- should we care a lot about performance of individual modules or simply make them functional?
