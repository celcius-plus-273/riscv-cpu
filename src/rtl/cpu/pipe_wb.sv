// ======================== //
//         Imports
// ======================== //
import rv_cpu_pkg::mem_wb_s;
import rv_cpu_pkg::wb_id_s;
// import rv_cpu_pkg::*;

module pipe_wb
(
    // clk, rst
    input logic     clk_i,
    input logic     rstn_i, // not needed hm

    // Memory to Writeback pipeline register (reg)
    input mem_wb_s mem_wb_i,

    // Writeback to Reg File Interface (wire)
    output wb_id_s wb_id_o
);
    // ============================== //
    //         WRITEBACK STAGE
    // ============================== //
    /**
    *  The main functions handled on the writeback stage are:
    *  1. Perform the final writeback to the register file as determined by the control signals
    *  2. Passthrough any necessary signals for debugging (e.g. for the testbench to check the correct execution of instructions)
    */

    // =========================== //
    //           Logic
    // =========================== //
    logic [31:0] mem_data;      // data read from memory
    logic [31:0] mem_data_ext;  // signed/zero extended memory data

    // use wb_src to determine the data to write back to the reg file
    always_comb begin : wb_logic
        // sign extend the memory data based on mem_mask and mem_signed
        if (mem_wb_i.mem_rd_en && mem_wb_i.mem_signed) begin
            case (mem_wb_i.mem_mask)
                4'b0001: mem_data_ext = {{24{mem_data[7]}}, mem_data[7:0]}; // lb
                4'b0011: mem_data_ext = {{16{mem_data[15]}}, mem_data[15:0]}; // lh
                4'b1111: mem_data_ext = mem_data; // lw
                default: mem_data_ext = 'x;
            endcase
        end
        else if (mem_wb_i.mem_rd_en && ~mem_wb_i.mem_signed) begin
            case (mem_wb_i.mem_mask)
                4'b0001: mem_data_ext = {24'b0, mem_data[7:0]}; // lbu
                4'b0011: mem_data_ext = {16'b0, mem_data[15:0]}; // lhu
                4'b1111: mem_data_ext = mem_data; // lw
                default: mem_data_ext = 'x;
            endcase
        end
        else begin
            mem_data_ext = mem_data; // for store instructions, data is not modified
        end

        // select the data to write back based on wb_src
        case (mem_wb_i.wb_src)
            2'b00: wb_id_o.rd_data = mem_wb_i.alu_result;
            2'b01: wb_id_o.rd_data = mem_data_ext;
            2'b10: wb_id_o.rd_data = mem_wb_i.pc_p4;
            2'b11: wb_id_o.rd_data = mem_wb_i.alu_result; // for auipc, write back the target addr (pc + imm)
            default: wb_id_o.rd_data = 32'b0;
        endcase
    end

    assign mem_data         = mem_wb_i.mem_data;    // input
    assign wb_id_o.rd_wen   = mem_wb_i.rd_wen;      // outputs
    assign wb_id_o.rd_addr  = mem_wb_i.rd_addr;

endmodule
