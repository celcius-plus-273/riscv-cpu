module alu 
#(
    parameter WORD_SIZE = 32
)
(
    // control signas
    input wire clock, // synchronizes alu result with remaining pipeline
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
    always @ (negedge clock) begin
        case (funct3)
            // add and subtract functions :)
            3'b000: begin
                result <= funct7[5] ? (source1 - source2) : (source1 + source2); 
            end 
        
            // shift left logical function
            3'b001: begin
                result <= source1 << source2;
            end

            // set less than
            // THIS COULD BE WRONG... I AM NOT SURE HOW SIGNED BITS ARE TREATED IN VERILOG
            3'b010: begin
                result <= source1 < source2;
            end
            
            // set less than unsigned
            3'b011: begin
                result <= source1 < source2;
            end

            // xor
            3'b100: begin
                result <= source1 ^ source2;
            end

            // shift right logical and arithmetical
            3'b101: begin
                result <= funct7[5] ? (source1 >>> source2) : (source1 >> source2);
            end
                
            // or
            3'b110: begin
                result <= source1 | source2;
            end
 
            // and
            3'b111: begin
                result <= source1 & source2;
            end

            // this is an unkown case for funct3 -> output a value of zero for this case
            default: 
                result <= 0;
        endcase
    end

endmodule