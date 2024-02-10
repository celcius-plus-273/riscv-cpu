module instruction_register
#(
    parameter REGISTER_SIZE = 64, // default is 2**6 = 64 instructions
    parameter WORD_SIZE = 32
)
(
    input wire clock,
    input wire reset_n,
    
    input wire [WORD_SIZE-1:0] pc,
    
    output reg [WORD_SIZE-1:0] instruction
);

    // simulate instruction register the same as with the gp register file
    reg [WORD_SIZE-1:0] instruction_reg [0:REGISTER_SIZE-1];

    // output instruction
    always @ (negedge clock) begin
        instruction = instruction_reg[pc]; // change to blocking to use debug display message
        $display("[Time: %0t] PC: %0d | Instruction: %0b", $time, pc, instruction);
    end

    // THIS IS THE CURRENT WAY TO INCLUDE INSTRUCTIONS INTO THE REGISTER :)
    integer i;
    initial begin
        // initial reset
        for (i = 0; i < REGISTER_SIZE; i = i + 1)
            instruction_reg[i] = 0;     
        
        /**
        *   WE CURRENTLY ASSIGN INSTRUCTIONS MANUALLY
        *   
        *   One possible improvement would be to automate this process
        *   - using some tool to compile RV32I into instrucitons
        *   - can I dump data into this array using some sort of script?
        */

        // lw   x1, 1(0)
        //instruction_reg[0] = 32'b000000000001_00000_010_00001_0000011;

        // add  x3, x1, x2
        instruction_reg[1] = 32'b0000000_00010_00001_000_00011_0110011;

    end

endmodule