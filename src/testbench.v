module tb;
    // Declare testbench variables
    // control variables
    reg clock = 0;
    reg reset_n = 0;
    reg write_enable = 0;

    // data input and output
    reg [31:0] write_data;
    wire [31:0] data_source1, data_source2;

    // address selection
    reg [4:0] write_addr, source1_addr, source2_addr;

    // initalize instance of register
    register register_file (
        .clock(clock),
        .reset_n(reset_n),
        .write_enable(write_enable),
        .write_addr(write_addr),
        .read_addr1(source1_addr),
        .read_addr2(source2_addr),
        .write_data(write_data),
        .read_data1(data_source1),
        .read_data2(data_source2)
    );

    // Start clock with frequency of 0.1 time units
    always begin 
        $display("[Time: %0t] clock: %0b -> %0b", $time, clock, ~clock);
        #10 clock = ~clock;
    end

    // test writing to address 1 and then reading it!
    initial begin
        // initialize source address to 0
        source1_addr = 5'b0;
        
        #15
        // read what data_source1 is in between a rising edge and falling edge of the clock -> expected: 32'bx
        $display("[Time: %0t] reset_n = %0b | source1 = %b", $time, reset_n, data_source1);

        #10 
        // this would read data_source1 after the falling edge of the clock -> expected: 32'b0
        $display("[Time: %0t] reset_n = %0b | source1 = %b", $time, reset_n, data_source1);
        // disable the reset
        reset_n = 1'b1;

        // now let's try writing a value and reading it
        $display("[Time: %0t] Initialized reset and write_enable", $time);
        write_enable = 1'b1;
        write_addr = 5'b1;
        write_data = 32'b1111;
        source1_addr = 5'b1;

        #20
        // check if output was written and read properly
        $display("[Time: %0t] reset_n = %0b | source1 = %b", $time, reset_n, data_source1);
        
        #10 $stop; // advance one clock cycle
    end
    
endmodule