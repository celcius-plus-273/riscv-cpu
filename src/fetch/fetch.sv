module fetch
#(
    parameter WORD_SIZE = 32
)
(
    // control signals   
    input wire clock,
    input wire enable,
    input wire reset_n,

    // input PC
    input wire [WORD_SIZE-1:0] pc,

    output wire [WORD_SIZE-1:0] instruction
);

    /**
     *  Fetch Stage
     *
     *  Fetch the next instruction indicated by PC
     */

    reg [WORD_SIZE-1:0] pc_reg = 0;
    wire [WORD_SIZE-1:0] instruction_output;

    always @ (posedge clock) begin
        pc_reg <= pc;
    end

    // instantiate the instruction register
    instruction_register instruction_reg (
        .clock(clock),
        .reset_n(reset_n),
        .pc(pc_reg),
        .instruction(instruction_output)
    );

    assign instruction = enable ? instruction_output : 0;

endmodule