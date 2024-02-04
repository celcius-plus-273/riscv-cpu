module execute 
#(
    parameter WORD_SIZE = 32;
)
(
    /*
        SINGLE EXECUTE UNIT
        -- MORE WILL BE ADDED ONCE OUT-OF-ORDER IS SUPPORTED
    */
    // the main inputs are the data sources
    input wire [WORD_SIZE-1:0] data_source1,
    input wire [WORD_SIZE-1:0] data_source2,
    input wire [6:0] funct7,
    input wire [2:0] funct3,

    // the output is the ALU output
    output wire [WORD_SIZE-1:0] data_out,

    // passthrough data/signals
    input wire [4:0] reg_dest_in,
    output wire [4:0] reg_dest_out,
    input wire write_enable_in,
    output wire write_enable_out,

    // control signal
    input wire clock
);
    /*
        For now this module will simply instantiate the ALU unit and connect it to the other 
        stages of the pipeline
    */

    // pipeline latches for incoming data
    reg [WORD_SIZE-1:0] data_source1_reg = 0;
    reg [WORD_SIZE-1:0] data_source2_reg = 0;
    reg [6:0] funct7_reg = 0;
    reg [2:0] funct3_reg = 0;
    reg [4:0] reg_dest_reg = 0;
    reg write_enable_reg = 0;

    // latch the input data on posedge
    always @ (posedge clock) begin
        // latch data
        data_source1_reg <= data_source1;
        data_source2_reg <= data_source2;

        // latch function input
        funct7_reg <= funct7;
        funct3_reg <= funct3;

        // latch passthrough data
        reg_dest_reg <= reg_dest_in;
        write_enable_reg <= write_enable_in;
    end

    // instantiate alu module
    alu alu_unit #(WORD_SIZE = WORD_SIZE) (
        .clock(clock),
        .funct7(funct7_reg),
        .funct3(funct3_reg),
        .source1(data_source1_reg),
        .source2(data_source2_reg),
        .result(data_out)
        // data_out gets updated on every negedge of the clock 
    );

    // passthrough assignments
    assign reg_dest_out = reg_dest_reg;
    assign write_enable_out = write_enable_reg;

endmodule