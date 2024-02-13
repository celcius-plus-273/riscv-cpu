module control 
#(
    parameter WORD_SIZE = 32
)
(
    // clock signnal
    input wire clock,

    // opcode :)
    input wire [3:0] instruction_type,

    // output control signals
    output wire is_write,
    output wire is_immediate,
    
    // output wire is_branch,
    // output wire is_jump,
    // output wire is_mem_read,
    // output wire is_mem_write,

    // stallng control signal
    output wire stall

);
    // typedef enum bit [3:0] instruction_type {
    //     R_TYPE,
    //     I_TYPE,
    //     I_MEM_TYPE,
    //     S_TYPE,
    //     B_TYPE,
    //     U_TYPE,
    //     J_TYPE,
    //     R4_TYPE,
    //     INVALID
    // } i_type;

    // localparams are used for now because iverilog doesn't support enums
    localparam INVALID = 0;
    localparam R_TYPE = 1;
    localparam I_TYPE = 2;
    localparam I_MEM_TYPE = 3;
    localparam S_TYPE = 4;
    localparam B_TYPE = 5;
    localparam U_TYPE = 6;
    localparam J_TYPE = 7;
    localparam R4_TYPE = 8;

    ///////////////////////////////////
    ////////// CONTROL MODULE /////////
    ///////////////////////////////////
    // The purpose of control module is to determine and coordinate all of the control signals
    // and determine stall conditions to avoid RAW hazards
    // 
    // Control will be more relevant when implementing out-of-order execution

    // control signal registers
    reg is_write_reg = 0;
    reg is_branch_reg = 0;
    reg is_jump_rerg = 0;
    reg is_mem_read_reg = 0;
    reg is_mem_write_reg = 0;
    reg is_immediate_reg = 0;
    reg is_stall_reg = 0;

    // The posedge of the control module will be in charge of detecting stall conditions
    always @ (posedge clock) begin
        // Stalling detectino?
    end

    // update the control signals depending on the input instruction type
    always @ (negedge clock) begin
        case (instruction_type)
            R_TYPE: 
            begin
                // update control signals
                is_write_reg <= 1;
                is_immediate_reg <= 0;
            end

            I_TYPE: 
            begin
                // update control signals
                is_write_reg <= 1;
                is_immediate_reg <= 1;
            end

            I_MEM_TYPE: 
            begin
                // update control signals
                is_write_reg <= 1;
                is_immediate_reg <= 1;
            end          

            INVALID: 
            begin
                // update control signals
                is_write_reg <= 0;
                is_immediate_reg <= 0;
            end
        endcase
    end

    // output wire assignments
    assign is_write = is_write_reg;
    assign is_immediate = is_immediate_reg;
    assign is_stall = is_stall_reg;

endmodule