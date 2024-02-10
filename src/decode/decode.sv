module decode 
#(
    parameter WORD_SIZE = 32
)
(
    /* 
        THIS PORT LIST WILL BE EXPANDED AS I 
        INCLUDE SUPPORT FOR MORE RV32 instructions
    */

    // control signals for decode
    input wire clock,
    input wire reset_reg_n, // this should always be held high to avoid resetting register file
    
    // the main input to the decode stage is the instruction :)
    input wire [WORD_SIZE-1:0] instruction,

    // data input from writeback stage
    input wire write_enable, // this signal comes form a writeback stage
    input wire [WORD_SIZE-1:0] write_data,
    input wire [4:0] write_addr,

    // register data output
    output wire [WORD_SIZE-1:0] data_source1,
    output wire [WORD_SIZE-1:0] data_source2,

    // passthrough data
    output wire [31:0] immediate_decoded,
    output wire [4:0] reg_dest_decoded,
    output wire [6:0] funct7_decoded,
    output wire [2:0] funct3_decoded,
    output wire is_write_decoded

);
    ///////////////////////////////////
    ////////// DECODE STAGE ///////////
    ///////////////////////////////////

    /** 
     *  The main functions handled on the decode stage are:
     *  1. Decode the given instruction input
     *  2. Read the required values from the register file
     *  3. Passthrough control signals like write_enable
    */

    // typedef enum bit [2:0] instruction_type {
    //     R_TYPE,
    //     I_TYPE,
    //     I_MEM_TYPE,
    //     S_TYPE,
    //     B_TYPE,
    //     U_TYPE,
    //     J_TYPE,
    //     R4_TYPE
    // } i_type;
    localparam R_TYPE = 0;
    localparam I_TYPE = 1;
    localparam I_MEM_TYPE = 2;
    localparam S_TYPE = 3;
    localparam B_TYPE = 4;
    localparam U_TYPE = 5;
    localparam J_TYPE = 6;
    localparam R4_TYPE = 7;
    localparam INVALID = 8;

    // OP will be used in this module to support other types of instructions
    // We'll have both a wire and a reg for this
    wire [6:0] opcode = instruction[6:0];

    // latch this value and sends it forward to future stages of the pipe which might need this value?
    //reg [6:0] opcode_reg; // NOT SURE IF THIS IS NEEDED

    // break down the opcode into its different bits
    /**
     *  |   A: 3 bits  |   B: 2 bits  |   V: 2 bits  |
     *  
     *  I (arithmetic): 001 + 00
     *  I (load): 000 + 00
     *  R: 011 + 00
     *  S: 010 + 00
     *  B: 110 + 00
     *  J: 
     *      jal: 110 + 11
     *      jalr: 110 + 01 (I)
     *  U:
     *      auipc: 001 + 01
     *      lui: 011 + 01
    */
    wire [2:0] opcode_A = opcode[6:4];
    wire [1:0] opcode_B = opcode[3:2];

    // Is this valid bit really required...? What's the difference between NOP and Invalid?
    wire valid = &opcode[1:0]; // note that the last two bits must be 1 for a valid instruction

    // store the instruction type as an enum
    //i_type [2:0] instruction_type;
    reg [2:0] instruction_type = 0;

    // decode the infomration necessary for a register read and latch this value
    // during the posedge
    reg [4:0] reg_source1 = 0; 
    reg [4:0] reg_source2 = 0;
    reg [4:0] reg_dest = 0; // reg_dest is a passthorugh for the writeback stage

    // update all of the information relevant to read register on the posedge of the clock
    always @ (posedge clock) begin
        // latch the read_source registers
        reg_source1 <= instruction[19:15];
        reg_source2 <= instruction[24:20];

        // decode the instruction type during the posedge
        if (valid) begin
            $display("[Time: %0t] Got valid instruction!", $time);
            case (opcode_A)
                // I-type instruction
                3'b000: instruction_type <= I_MEM_TYPE;
                3'b001: instruction_type <= (opcode_B === 2'b01) ? U_TYPE : I_TYPE; // auipc

                // S-type instruction
                3'b010: instruction_type <= S_TYPE;

                // R-type instruction
                3'b011: instruction_type <= opcode_B === 2'b01 ? U_TYPE : R_TYPE; // lui

                // B-type and J-type instructions
                3'b110: 
                begin
                    case (opcode_B)
                        2'b00: instruction_type <= B_TYPE;
                        2'b01: instruction_type <= I_TYPE; // jalr uses I-type format
                        2'b11: instruction_type <= J_TYPE;
                    endcase
                end
                default: instruction_type <= I_TYPE;
            endcase
        end
        else
            instruction_type <= INVALID;
    end

    // decode the remaining parts of the instruction
    reg [6:0] funct7 = 0;
    reg [2:0] funct3 = 0;

    // will accomodate for all possible immediate values
    reg is_write = 0;
    reg is_branch = 0;
    reg is_jump = 0;
    reg is_mem_read = 0;
    reg is_mem_write = 0;
    reg [31:0] immediate = 0; 

    // some updates need to be done on the negedge to as they depend on some of the decoded
    // values from the posedge block
    always @ (negedge clock) begin
        case (instruction_type)
            R_TYPE: 
            begin
                // update control signals
                is_write <= 1;
                is_branch <= 0;
                is_jump <= 0;
                is_mem_read <= 0;
                is_mem_write <= 0;

                // update appropriate immedaite value
                immediate <= 0;

                // update funct fields
                funct3 <= instruction[14:12];
                funct7 <= instruction[31:25];

                // if it does write, where does it write to?
                reg_dest <= instruction[11:7];
            end

            I_TYPE: 
            begin
                // update control signals
                is_write <= 1;
                is_branch <= 0;
                is_jump <= 0;
                is_mem_read <= 0;
                is_mem_write <= 0;

                // update appropriate immedaite value
                immediate <= { {20{instruction[31]}}, instruction[31:20]};

                // update funct fields
                funct3 <= instruction[14:12];
                funct7 <= 0;

                // if it does write, where does it write to?
                reg_dest <= instruction[11:7];
            end

            I_MEM_TYPE: 
            begin
                // update control signals
                is_write <= 1;
                is_branch <= 0;
                is_jump <= 0;
                is_mem_read <= 1;
                is_mem_write <= 0;

                // update appropriate immedaite value
                immediate <= { {20{instruction[31]}}, instruction[31:20]};

                // update funct fields
                funct3 <= instruction[14:12];
                funct7 <= 0;

                // if it does write, where does it write to?
                reg_dest <= instruction[11:7];
            end          

            default: 
            begin
                // update control signals
                is_write <= 0;
                is_branch <= 0;
                is_jump <= 0;
                is_mem_read <= 0;
                is_mem_write <= 0;

                // update appropriate immedaite value
                immediate <= 0;

                // update funct fields
                funct3 <= 0;
                funct7 <= 0;

                // if it does write, where does it write to?
                reg_dest <= 0;
            end

        endcase

        //debug
        //$display("[Time: %0t] Instruction type: %0d", $time, instruction_type);
    end

    // instantiate the register file
    register register_file (
        .clock(clock),
        .reset_n(reset_reg_n),
        .write_enable(write_enable),
        .write_addr(write_addr),
        .read_addr1(reg_source1),
        .read_addr2(reg_source2),
        .write_data(write_data),
        .read_data1(data_source1),
        .read_data2(data_source2)
    );

    // passthrough data assigment
    assign immediate_decoded = immediate;
    assign funct3_decoded = funct3;
    assign funct7_decoded = funct7;
    assign reg_dest_decoded = reg_dest;
    assign is_write_decoded = is_write;

endmodule