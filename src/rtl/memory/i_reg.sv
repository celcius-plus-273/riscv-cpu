// Byte addressable instruction memory register
module i_reg
#(
    parameter DEPTH = 64
)
(
    input logic             clk_i,
    input logic             en_i,
    input logic             rstn_i, // ...needed?

    input logic     [31:0]  pc_i,
    output logic    [31:0]  inst_o
);

    // localparams
    localparam NUM_BYTES = 4; // number of bytes in an instruction (4 for 32-bit instructions)

    // instruction memory
    reg [31:0] mem [DEPTH];

    // output instruction
    always_ff @(posedge clk_i) begin
        if (!rstn_i) begin
            inst_o <= '0;
        end else begin
            // pc >> 2 is fine since we don't need the byte-addressing for instructions
            inst_o <= en_i ? mem[pc_i >> 2] : inst_o;
            // if (en_i) begin
            //     $display("Fetched instruction 0x%08x from imem[%0d] (PC=0x%02x)", mem[pc_i >> 2], pc_i >> 2, pc_i);
            // end
        end
    end

endmodule
