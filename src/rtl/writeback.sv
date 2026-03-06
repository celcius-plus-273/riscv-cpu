module writeback
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
    // use wb_src to determine the data to write back to the reg file
    always_comb begin : wb_data_sel
        case (mem_wb_i.wb_src)
            2'b00: wb_id_o.rd_data = mem_wb_i.alu_result;
            2'b01: wb_id_o.rd_data = mem_wb_i.mem_data;
            2'b10: wb_id_o.rd_data = mem_wb_i.pc_p4;
            default: wb_id_o.rd_data = 32'b0;
        endcase
    end

    assign wb_id_o.rd_wen = mem_wb_i.rd_wen;
    assign wb_id_o.rd_addr = mem_wb_i.rd_addr;

endmodule
