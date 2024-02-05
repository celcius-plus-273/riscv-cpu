module tb;
    
    // CLOCK STUFF
    localparam CLOCK_PERIOD = 10;
    reg clock = 0;
    always begin
        if (clock)
            $display("Falling Edge: %0b -> %0b", clock, ~clock);
        else
            $display("Rising Edge: %0b -> %0b", clock, ~clock);

        #(CLOCK_PERIOD/2) clock = ~clock;
    end

    // keep track of the cycle count (for debugging :))
    integer cycles = 0;    
    always begin
        #(CLOCK_PERIOD) cycles = cycles + 1;
        $display("Cycle count: %0d", cycles);
    end

    // pipeline input instruction -> this would be normally handled by the PC and fetch stages
    // for now we will simply pass in instructions manually
    //reg [31:0] instruction = 0;

    // PC counter always starts at 0 and linearly executes the stored instructions on the
    // instruction register
    reg [31:0] pc = 0;
    reg pc_enable = 0;

    always begin
        $display("[Time: %0t] Incrementing PC: %0d -> %0d", $time, pc, pc + 1);
        #(CLOCK_PERIOD) pc <= pc_enable ? pc + 1 : pc;
    end
    
    // register control signals
    reg reset_reg_n = 1;
    reg reset_inst_n = 1;
    reg enable_inst_reg = 1;

    // fetch-decode wires
    wire [31:0] instruction;

    // FETCH STAGE
    fetch fetch_stage (
        .clock(clock),
        .reset_n(reset_inst_n),
        .enable(enable_inst_reg),
        .pc(pc),
        .instruction(instruction)
    );

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
        .write_enable_in(write_enable_exwb),

        .write_data(write_data_wb),
        .write_addr(write_addr_wb),
        .write_enable_out(write_enable_wb)
    );

    initial begin
        $display("Cycle count %0d", cycles); // initial cycle count output

        // issue initial reset to register file (consumes one clock cycle)
        #5 reset_reg_n = 0;
        #3 reset_reg_n = 1;

        // now we can enable the pc
        pc_enable = 1;
        
        // add should be seen in the following 3 clock cycles

        #50 $finish;
    end

endmodule