// Top Level Module for the RISC-V CPU
module rv_cpu
    import rv_cpu_pkg::*;
(
    // clk, rst
    input logic     clk_i,
    input logic     rstn_i,

    // enable signal
    input logic     riscv_en_i
);

    // ============================== //
    //          RISC-V CPU
    // ============================== //
    /**
    *   Based on the Harris & Harris DDCA (RISC-V Edition) in-order architecture
    *   RISC-V CPU: 5-stage in-order pipeline with the following stages:
    *   1. Fetch (IF)
    *   2. Decode (ID)
    *   3. Execute (EX)
    *   4. Memory (MEM)
    *   5. Writeback (WB)
    *
    *   The main functions of the CPU are:
    *   - Fetch instructions from instruction memory
    *   - Decode instructions and read register operands
    *   - Execute ALU operations and resolve branches
    *   - Perform memory reads/writes
    *   - Write results back to the register file
    */

    // ============================== //
    //     Global Control Signals
    // ============================== //
    logic        stall_w;
    logic        flush_w;

    // ============================== //
    //    Module Interfaces (wire)
    // ============================== //
    id_ctl_s    id_ctl_w;    // ID to Control
    ctl_id_s    ctl_id_w;    // Control to ID
    id_hzd_s    id_hzd_w;    // ID to Hazard Detection
    ex_if_s     ex_if_w;     // EX to IF (for branch target update)
    ex_hzd_s    ex_hzd_w;    // EX to Hazard Detection
    fwd_ex_s    fwd_ex_w;    // Hazard Detection to EX for forwarding
    mem_hzd_s   mem_hzd_w;   // MEM to Hazard Detection
    wb_id_s     wb_id_w;     // WB to ID (for writeback data forwarding)
    wb_hzd_s    wb_hzd_w;    // WB to Hazard Detection

    // ============================== //
    //        Pipeline Regs (reg)
    // ============================== //
    if_id_s     if_id_w;    // IF to ID pipeline register
    id_ex_s     id_ex_w;    // ID to EX pipeline register
    ex_mem_s    ex_mem_w;   // EX to MEM pipeline register
    mem_wb_s    mem_wb_w;   // MEM to WB pipeline register

    // ============================== //
    //            Stages
    // ============================== //
    // Fetch Stage
    pipe_if #(
        .I_MEM_DEPTH(I_MEM_DEPTH)
    ) fetch_stage (
        .clk_i(clk_i),
        .rstn_i(rstn_i),
        .en_i(~stall_w & riscv_en_i),   // enable is inverse of stall
        .flush_i(flush_w),              // flush signal for control hazards
        .ex_if_i(ex_if_w),              // for branch target update
        .if_id_o(if_id_w)               // output to IF/ID pipeline register
    );

    // Decode Stage
    pipe_id #(
        .RF_DEPTH(REG_FILE_DEPTH)
    ) decode_stage (
        .clk_i(clk_i),
        .rstn_i(rstn_i),
        .flush_i(flush_w | stall_w),              // flush signal for control hazards
        .ctl_id_i(ctl_id_w),            // control signals from control stage
        .id_ctl_o(id_ctl_w),            // opcode output to control stage
        .id_hzd_o(id_hzd_w),            // hazard signals to hazard detection
        .if_id_i(if_id_w),              // input from IF/ID pipeline register
        .wb_id_i(wb_id_w),              // input from WB/ID pipeline register
        .id_ex_o(id_ex_w)               // output to ID/EX pipeline register
    );

    // Control Stage
    control control_stage (
        .clk_i(clk_i),
        .id_ctl_i(id_ctl_w),   // opcode input from ID stage
        .ctl_id_o(ctl_id_w)    // control signals output to ID stage
    );

    // Hazard Detection Unit
    hazard hazard_unit (
        .clk_i(clk_i),
        .is_taken(ex_if_w.pc_src),   // input for branch resolution from EX stage
        .id_hzd_i(id_hzd_w),   // input from ID stage for hazard detection
        .ex_hzd_i(ex_hzd_w),   // input from EX stage for hazard detection
        .mem_hzd_i(mem_hzd_w), // input from MEM stage for hazard detection
        .wb_hzd_i(wb_hzd_w),   // input from WB stage for hazard detection
        .fwd_ex_o(fwd_ex_w),   // forwarding signals to EX stage
        .stall_o(stall_w),     // stall signal output
        .flush_o(flush_w)      // flush signal output for control hazards
    );

    // Execute Stage
    pipe_ex execute_stage (
        .clk_i(clk_i),
        .rstn_i(rstn_i),
        .ex_hzd_o(ex_hzd_w),    // output to hazard detection for hazard signals
        .fwd_ex_i(fwd_ex_w),    // input from hazard detection for forwarding
        .ex_if_o(ex_if_w),     // output to EX/IF for branch target
        .id_ex_i(id_ex_w),     // input from ID/EX pipeline register
        .ex_mem_o(ex_mem_w)    // output to EX/MEM pipeline register
    );

    // Memory Stage
    pipe_mem #(
        .D_MEM_DEPTH(D_MEM_DEPTH)
    ) memory_stage (
        .clk_i(clk_i),
        .rstn_i(rstn_i),
        .mem_hzd_o(mem_hzd_w),   // output to hazard detection for hazard signals
        .ex_mem_i(ex_mem_w),   // input from EX/MEM pipeline register
        .mem_wb_o(mem_wb_w)    // output to MEM/WB pipeline register
    );

    // Writeback Stage
    pipe_wb writeback_stage (
        .clk_i(clk_i),
        .rstn_i(rstn_i),
        .wb_hzd_o(wb_hzd_w),    // output to hazard detection for hazard signals
        .mem_wb_i(mem_wb_w),   // input from MEM/WB pipeline register
        .wb_id_o(wb_id_w)      // output to WB/ID pipeline register
    );

endmodule
