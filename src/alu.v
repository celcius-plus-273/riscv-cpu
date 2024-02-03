module alu 
#(
    parameter WORD_SIZE = 32
)
(
    // control signals
    input wire [6:0] funct7,
    input wire [2:0] funct3,

    // input ports
    input wire [WORD_SIZE-1:0] source1,
    input wire [WORD_SIZE-1:0] source2, 

    // output port!
    output reg [WORD_SIZE-1:0] result
);
    // some interal wires for the procedural combinational logic
    //reg [WORD_SIZE-1:0] alu_output = 0;

    // ALU is mainly combinational logic :)
    always @ (source1 or source2 or funct7 or funct3) begin
        case (funct3)
            // add and subtract functions :)
            3'b000: begin
                result <= (funct7[5] === 1'b1) ? (source1 - source2) : (source1 + source2); 
            end 
        
            // shift left logical function
        
            default: 
                result <= 0;
        endcase
    end

endmodule