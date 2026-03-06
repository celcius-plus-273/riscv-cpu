module i_reg
#(
    parameter WIDTH = 32,
    parameter DEPTH = 64
)
(
    input logic                 clk_i,
    input logic                 en_i,
    input logic                 rstn_i, // ...needed?

    input logic     [WIDTH-1:0] pc_i,
    output logic    [WIDTH-1:0] inst_o
);

    // instruction memory
    reg [WIDTH-1:0] mem [DEPTH];

    // output instruction
    always_ff @(posedge clk_i) begin
        if (!rstn_i) begin
            inst_o <= 0;
        end else begin
            inst_o <= en_i ? mem[pc_i] : inst_o;
        end
    end

    // THIS IS THE CURRENT WAY TO INCLUDE INSTRUCTIONS INTO THE REGISTER :)
    // integer i;
    // initial begin
    //     // initial reset
    //     for (i = 0; i < REGISTER_SIZE; i = i + 1)
    //         instruction_reg[i] = 0;

    //     /**
    //     *   WE CURRENTLY ASSIGN INSTRUCTIONS MANUALLY
    //     *
    //     *   One possible improvement would be to automate this process
    //     *   - using some tool to compile RV32I into instrucitons
    //     *   - can I dump data into this array using some sort of script?
    //     *       - SystemVerilog file system ($fopen, $fread) might be useful here
    //     *
    //     *       - $memread() :)
    //     */

    //     // add  x1, x1, x2
    //     instruction_reg[1] = 32'b0000000_00010_00001_000_00001_0110011;

    //     // increment x2 using immedaite value of 1
    //     instruction_reg[2] = 32'b000000000001_00010_000_00010_0010011;

    //     // add x1, x1, x2
    //     instruction_reg[5] = 32'b0000000_00010_00001_000_00001_0110011;

    // end
endmodule
