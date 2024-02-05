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
    output wire [4:0] reg_dest_decoded,
    output wire [6:0] funct7_decoded,
    output wire [2:0] funct3_decoded,
    output wire write_enable_decoded

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

    // OP will be used in this module to support other types of instructions
    // We'll have both a wire and a reg for this
    wire [6:0] opcode;
    assign opcode = instruction[6:0];

    // latch this value and sends it forward to future stages of the pipe which might need this value?
    //reg [6:0] opcode_reg; // NOT SURE IF THIS IS NEEDED



    // decode the remaining parts of the instruction
    reg [4:0] reg_source1 = 0; 
    reg [4:0] reg_source2 = 0;
    reg [6:0] funct7 = 0;
    reg [2:0] funct3 = 0;

    // reg_dest is a passthorugh for the writeback stage
    reg [4:0] reg_dest = 0;
    reg write_enable_reg = 0;

    // update all of the relevant information on the posedge of the clock
    always @ (posedge clock) begin
        // [REVIEW: is this needed?] opcode_reg <= instruction[6:0]; // latch the opcode :)

        reg_source1 <= instruction[19:15];
        reg_source2 <= instruction[24:20];
        reg_dest <= instruction[11:7];

        funct7 <= instruction[31:25];
        funct3 <= instruction[14:12];
    end

    // some updates need to be done on the negedge to as they depend on some of the decoded
    // values from the posedge block
    always @ (negedge clock) begin
        // currently only supports R-type instructions
        write_enable_reg <= (opcode === 7'b0110011) ? 1 : 0;
    end

    // Instantiate the register file
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
    assign funct3_decoded = funct3;
    assign funct7_decoded = funct7;
    assign reg_dest_decoded = reg_dest;
    assign write_enable_decoded = write_enable_reg;

endmodule