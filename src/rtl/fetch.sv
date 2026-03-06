module if_id
#(
    parameter INST_WIDTH = 32,
    parameter PC_WIDTH = 32,
    parameter I_MEM_DEPTH = 64
)
(
    // clk, rstn, en
    input logic clk_i,
    input logic en_i,
    input logic rstn_i,

    // input PC
    input logic [PC_WIDTH-1:0] pc_i,

    // output instruction
    output logic [INST_WIDTH-1:0] inst_o
);
    /**
     *  Fetch Stage
     *
     *  Fetch the next instruction indicated by PC
     *  - PC is updated every cycle
     *  - Assume a valid PC is available at the beginning of the cycle
     */

    /**
    *  Instruction Register
    *
    *  Store the instruction fetched from memory
    *  - For now, we will use a simple register to hold the instruction
    *  - TODO: upgrade to an I-Cache
    */
    i_reg #(
        .WIDTH(INST_WIDTH),
        .DEPTH(I_MEM_DEPTH) // for now we will just support 64 instructions, can be increased later
    ) i_reg_inst (
        .clk_i(clk_i),
        .rstn_i(rstn_i),
        .en_i(en_i),    // we will use this for stalling :)
        .pc_i(pc_i),
        .inst_o(inst_o) // registered output
    );

endmodule
