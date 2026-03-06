import rv_cpu_pkg::ex_if_s;
import rv_cpu_pkg::if_id_s;

module fetch
#(
    parameter I_MEM_DEPTH = 64
)
(
    // clk, rstn, en
    input logic     clk_i,
    input logic     en_i,
    input logic     rstn_i,

    // Execute Stage Interface (wire)
    input ex_if_s   ex_if_i,

    // Decode Stage Interface (pipeline register)
    output if_id_s if_id_o
);
    /**
    *  Fetch Stage
    *
    *  Fetch the next instruction indicated by PC
    *  - PC is updated every cycle
    *  - Assume a valid PC is available at the beginning of the cycle
    */

    // ============================== //
    //         Variables
    // ============================== //
    logic [31:0] pc_r;
    logic [31:0] pc_next;

    // PC Update Logic
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (!rstn_i) begin
            pc_r <= 0;  // initial pc can be configurable...?
        end
        else begin
            pc_r <= en_i ? pc_next : pc_r;
        end
    end

    // next pc logic (comb assign)
    // current prediction: always not taken (pc + 4)
    // TODO: add branch prediction logic (Gskew or Gshare)
    assign pc_next = ex_if_i.pc_src ? ex_if_i.pc_addr : pc_r + 4;

    // output reg pipeline
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (!rstn_i) begin
            if_id_o <= '0;
        end
        else begin
            // add flush?
            if_id_o.pc    <= pc_r;
            if_id_o.pc_p4 <= pc_r + 4;
        end
    end

    /**
    *  Instruction Register
    *
    *  Store the instruction fetched from memory
    *  - For now, we will use a simple register to hold the instruction
    *  - TODO: upgrade to an I-Cache
    */
    i_reg #(
        .DEPTH(I_MEM_DEPTH) // for now we will just support 64 instructions, can be increased later
    ) i_reg_inst (
        .clk_i(clk_i),
        .rstn_i(rstn_i),
        .en_i(en_i),    // we will use this for stalling :)
        .pc_i(pc_r),
        .inst_o(if_id_o.inst) // registered output
    );

endmodule
