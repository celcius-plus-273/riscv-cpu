// ======================== //
//         Imports
// ======================== //
import rv_cpu_pkg::ex_mem_s;
import rv_cpu_pkg::mem_wb_s;
// import rv_cpu_pkg::*;

module pipe_mem
#(
    // parameters
    parameter D_MEM_DEPTH = 256,  // D-cache size

    // derived parameters
    localparam D_MEM_ADDR_WIDTH = $clog2(D_MEM_DEPTH)
) (
    // interfaces
    // clk, rst
    input logic     clk_i,
    input logic     rstn_i,

    // Execute to Memory pipeline register
    input ex_mem_s ex_mem_i,

    // Memory to Writeback pipeline register
    output mem_wb_s mem_wb_o

);
    // ============================== //
    //         MEMORY STAGE
    // ============================== //
    /**
    *  The main functions handled on the memory stage are:
    *  1. Perform the memory read/write as determined by the control signals
    *  2. Pass the read data to the writeback stage
    *  3. Passthrough control signals like rd_wen, rd_addr, and wb_src
    */

    // ============================== //
    //         Variables
    // ============================== //


    // output reg pipeline
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (!rstn_i) begin
            mem_wb_o.pc_p4          <= '0;
            mem_wb_o.alu_result     <= '0;
            mem_wb_o.addr_result    <= '0;
            mem_wb_o.mem_rd_en      <= '0;
            mem_wb_o.mem_mask       <= '0;
            mem_wb_o.mem_signed     <= '0;
            mem_wb_o.wb_src         <= '0;
            mem_wb_o.rd_wen         <= '0;
            mem_wb_o.rd_addr        <= '0;

        end
        else begin
            // no flush?

            mem_wb_o.pc_p4          <= ex_mem_i.pc_p4;      // passthrough for pc + 4 (for jalr)
            mem_wb_o.alu_result     <= ex_mem_i.alu_result; // passthrough for alu result (for alu ops)
            mem_wb_o.addr_result    <= ex_mem_i.addr_result; // passthrough for address result (for auipc)
            mem_wb_o.mem_rd_en      <= ex_mem_i.mem_rd_en;    // passthrough for memory read enable
            mem_wb_o.mem_mask       <= ex_mem_i.mem_mask;    // passthrough for memory mask
            mem_wb_o.mem_signed     <= ex_mem_i.mem_signed;  // passthrough for memory signed/unsigned
            mem_wb_o.wb_src         <= ex_mem_i.wb_src;     // passthrough wb_src
            mem_wb_o.rd_wen         <= ex_mem_i.rd_wen;     // passthrough reg dest write en
            mem_wb_o.rd_addr        <= ex_mem_i.rd_addr;    // passthrough reg dest addr
        end
    end

    // ============================== //
    //         SRAM Instance
    // ============================== //
    `ifdef SRAM_MACRO
    `else
        sram_rw_dff #(
            .WIDTH(32),
            .DEPTH(D_MEM_DEPTH)
        ) sram_inst (
            .clk_i(clk_i),
            .rstn_i(rstn_i),   // for cleaner sims
            .cenb_i(~ex_mem_i.mem_rd_en & ~ex_mem_i.mem_wr_en), // enable when either read or write is active
            .wenb_i(~ex_mem_i.mem_wr_en), // write when mem_wr_en is active
            .mask_i(ex_mem_i.mem_mask), // byte enable mask
            .addr_i(ex_mem_i.alu_result[D_MEM_ADDR_WIDTH-1:0]), // use lower bits of ALU result as address
            .data_i(ex_mem_i.mem_wr_data), // data to write comes from rs2 (store instructions)
            .data_o(mem_wb_o.mem_data) // data read from memory goes to MEM/WB pipeline register
        );
    `endif

endmodule
