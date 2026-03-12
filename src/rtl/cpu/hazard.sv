import rv_cpu_pkg::id_hzd_s;
import rv_cpu_pkg::ex_hzd_s;
import rv_cpu_pkg::mem_hzd_s;
import rv_cpu_pkg::wb_hzd_s;
import rv_cpu_pkg::fwd_ex_s;
import rv_cpu_pkg::hzd_pipe_s;

module hazard
#(

) (
    // clk, rst
    input logic     clk_i,

    // branch resolution
    input logic     is_taken,

    // ID to Hazard Detection Interface
    input id_hzd_s id_hzd_i,
    input ex_hzd_s ex_hzd_i,
    input mem_hzd_s mem_hzd_i,
    input wb_hzd_s wb_hzd_i,

    // Forwarding to EX Interface (wire)
    output fwd_ex_s fwd_ex_o,

    // Hazard Detection to Control Interface
    hzd_pipe_s hzd_pipe_o
);
    // ======================== //
    //       HAZARD UNIT
    // ======================== //
    /**
     *  The main functions handled by the hazard detection unit are:
     *  1. Detect data hazards and generate stall signals for the pipeline registers
     *      a. Forwards data from mem and wb stages to ex stage if possible
     *  2. Detect control hazards and generate flush signals for the pipeline registers
     */

    // ======================== //
    //        Variables
    // ======================== //
    // intermediate signas for hazard detection logic (wire)
    logic rs1_eq_rd_ex, rs1_eq_rd_mem, rs1_eq_rd_wb;
    logic rs2_eq_rd_ex, rs2_eq_rd_mem, rs2_eq_rd_wb;
    logic is_valid_ex, is_valid_mem, is_valid_wb;

    // hazard detections
    logic raw_ex_load;   // (RAW hazard in EX stage due to load)

    // intermediate forwarding signals (wire)
    logic is_fwd_mem, is_fwd_wb;
    logic mem_fwd_rs1, wb_fwd_rs1;
    logic mem_fwd_rs2, wb_fwd_rs2;

    // ======================== //
    //        Hazard Logic
    // ======================== //
    // Handles stalling for data hazards and flushing for control hazards
    always_comb begin : ex_stage_logic
        // only reason to stall is for load RAW hazards
        is_valid_ex = ex_hzd_i.mem_rd_en & (ex_hzd_i.rd_addr != 0);

        rs1_eq_rd_ex = (ex_hzd_i.rd_addr == id_hzd_i.rs1_addr) & id_hzd_i.r1_en;
        rs2_eq_rd_ex = (ex_hzd_i.rd_addr == id_hzd_i.rs2_addr) & id_hzd_i.r2_en;
        raw_ex_load = (is_valid_ex & (rs1_eq_rd_ex | rs2_eq_rd_ex));

        // If functional units are not ready you also need to stall
        // - Our ALU is single cycle so we never stall for computations
        // - If multi-cycle functional units are needed, modify this stall logic accordingly
    end

    always_comb begin : ex_result_fwd_logic
        // Forwarding logic!
        // check if valid rd write
        is_valid_mem = mem_hzd_i.rd_wen & (mem_hzd_i.rd_addr != 0);

        // check rs1 and rs2 addresses in ex stage
        rs1_eq_rd_mem = (ex_hzd_i.rs1_addr == mem_hzd_i.rd_addr) & ex_hzd_i.r1_en;
        rs2_eq_rd_mem = (ex_hzd_i.rs2_addr == mem_hzd_i.rd_addr) & ex_hzd_i.r2_en;

        // if there's a hazard, fwd the data
        is_fwd_mem  = is_valid_mem & ~mem_hzd_i.mem_rd_en;  // double check if we need this second condition...
        mem_fwd_rs1 = rs1_eq_rd_mem & is_fwd_mem;
        mem_fwd_rs2 = rs2_eq_rd_mem & is_fwd_mem;
    end

    always_comb begin : mem_result_fwd_logic
        // check for valid rd write
        is_valid_wb = wb_hzd_i.rd_wen & (wb_hzd_i.rd_addr != 0);

        // check rs1 and rs2 addresses in ex stage
        rs1_eq_rd_wb = (wb_hzd_i.rd_addr == ex_hzd_i.rs1_addr) & ex_hzd_i.r1_en;
        rs2_eq_rd_wb = (wb_hzd_i.rd_addr == ex_hzd_i.rs2_addr) & ex_hzd_i.r2_en;

        // forward if there is a hazard
        wb_fwd_rs1 = rs1_eq_rd_wb & is_valid_wb;
        wb_fwd_rs2 = rs2_eq_rd_wb & is_valid_wb;
    end

    // Generate stall and flush signals
    assign hzd_pipe_o.if_stall = mem_hzd_i.mem_busy | raw_ex_load;
    assign hzd_pipe_o.id_stall = mem_hzd_i.mem_busy;
    assign hzd_pipe_o.id_bubble = raw_ex_load & ~mem_hzd_i.mem_busy;
    assign hzd_pipe_o.ex_stall = mem_hzd_i.mem_busy;
    assign hzd_pipe_o.flush = is_taken;

    always_comb begin : fwd_out_logic
        // Prioritize mem stage forwarding (newer data)
        fwd_ex_o.is_fwd_rs1 = mem_fwd_rs1 | wb_fwd_rs1;
        fwd_ex_o.rs1_data = mem_fwd_rs1 ? mem_hzd_i.rd_data : (wb_fwd_rs1 ? wb_hzd_i.rd_data : 32'b0);
        fwd_ex_o.is_fwd_rs2 = mem_fwd_rs2 | wb_fwd_rs2;
        fwd_ex_o.rs2_data = mem_fwd_rs2 ? mem_hzd_i.rd_data : (wb_fwd_rs2 ? wb_hzd_i.rd_data : 32'b0);
    end

endmodule
