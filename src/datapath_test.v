module tb;
    
    // CLOCK STUFF
    localparam CLOCK_PERIOD = 10;
    reg clock = 0;
    always begin
        $display("Clock: %0b -> %0b", clock, ~clock);
        #(CLOCK_PERIOD/2) clock = ~clock;
    end

    // pipeline input instruction -> this would be normally handled by the PC and fetch stages
    // for now we will simply pass in instructions manually
    reg [31:0] instruction = 0;
    
    // register control signals
    reg reset_reg_n = 1;

    // wb-decode wires
    wire write_enable_wb;
    wire [31:0] write_data_wb;
    wire [4:0] write_addr_wb;

    // decode-execute wires
    wire [31:0] source1_data;
    wire [31:0] source2_data;
    wire [4:0] reg_dest_de;
    wire [6:0] funct7_de;
    wire [2:0] funct3_de;
    wire write_enable_de;

    // instantaite the three stages!
    decode decode_stage (
        .clock(clock),
        .reset_reg_n(reset_reg_n),

        .instruction(instruction),

        .write_enable(write_enable_wb),
        .write_data(write_data_wb),
        .write_addr(write_addr_wb),

        .data_source1(source1_data),
        .data_source2(source2_data),

        .reg_dest_decoded(reg_dest_de),
        .funct7_decoded(funct7_de),
        .funct3_decoded(funct3_de),
        .write_enable_decoded(write_enable_de)
    );

    // exe-wb wires
    wire [31:0] data_result_exwb;
    wire [4:0] reg_dest_exwb;
    wire write_enable_exwb;

    execute execute_stage (
        .clock(clock),

        .data_source1(source1_data),
        .data_source2(source2_data),
        .funct7(funct7_de),
        .funct3(funct3_de),

        .data_out(data_result_exwb),

        .reg_dest_in(reg_dest_de),
        .reg_dest_out(reg_dest_exwb),

        .write_enable_in(write_enable_de),
        .write_enable_out(write_enable_exwb)
    );

    writeback writeback_stage (
        .clock(clock),

        .data_result(data_result_exwb),
        .reg_dest_in(reg_dest_exwb),
        .write_enable_in(reg_dest_exwb),

        .write_data(write_data_wb),
        .write_addr(write_addr_wb),
        .write_enable_out(write_addr_wb)
    );

    initial begin
        // first thing to do is to reset the register file to all 0 values
        write_enable_wb = 0;
        #5 reset_reg_n = 0;
        #5 reset_reg_n = 1;

        // plug in a single add instruction!
        instruction = 32'b0000000_00010_00001_000_00011_0110011;
        $display("[Time: %0t] Inputted instruction add $3, $1, $2");

        // Instruction should be latched on time: 15 so we reset instruction back to NOP afterwards
        #10 instruction = 0;
    end

endmodule