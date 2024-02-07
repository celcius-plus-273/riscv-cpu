module alu_tb;

    // instantiate variables to test ALU 
    reg [31:0] data_source1, data_source2;
    reg [6:0] funct7;
    reg [2:0] funct3;

    wire [31:0] data_out;

    // instantiate alu module
    alu alu_unit (
        .funct7(funct7),
        .funct3(funct3),
        .source1(data_source1),
        .source2(data_source2),
        .result(data_out)
    );

    // clock!
    reg clock = 0;

    always begin
        #1 clock = !clock;
    end

    initial begin
        // initialize all values to 0
        #1;
        data_source1 = 0;
        data_source2 = 0; 
        funct3 = 0;
        funct7 = 0;

        // jump 10 time units and set values to test sum
        #10;
        data_source1 = 32'h2; // 2 + 1
        data_source2 = 32'h1;
        // funct3 and funct7 stay as 0        
        
        #10; // jump 10 more time units and test subtraction
        // use same data inputs (2 - 1)
        funct7 = 7'b010_0000;
    end

    // Now let's monitor the values of the alu
    initial begin
        // check that everything is not initialized! at time 0
        $display("[Time: %0t] funct7: %0b", $time, funct7);
        $display("[Time: %0t] funct3: %0b", $time, funct3);
        $display("[Time: %0t] data_source1: %0b", $time, data_source1);
        $display("[Time: %0t] data_source2: %0b", $time, data_source2);
        $display("[Time: %0t] data_out: %0b", $time, data_out);

        // jump 1 time unit to make sure everything is initialized to 0
        #5;
        $display("[Time: %0t] funct7: %0b", $time, funct7);
        $display("[Time: %0t] funct3: %0b", $time, funct3);
        $display("[Time: %0t] data_source1: %0d", $time, data_source1);
        $display("[Time: %0t] data_source2: %0d", $time, data_source2);
        $display("[Time: %0t] data_out: %0d", $time, data_out);

        #10; // jump 10 time units and verify that add is reflected
        $display("[Time: %0t] funct7: %0b", $time, funct7);
        $display("[Time: %0t] funct3: %0b", $time, funct3);
        $display("[Time: %0t] data_source1: %0d", $time, data_source1);
        $display("[Time: %0t] data_source2: %0d", $time, data_source2);
        $display("[Time: %0t] data_out: %0d", $time, data_out);

        #10; // now verify subtract
        $display("[Time: %0t] funct7: %0b", $time, funct7);
        $display("[Time: %0t] funct3: %0b", $time, funct3);
        $display("[Time: %0t] data_source1: %0d", $time, data_source1);
        $display("[Time: %0t] data_source2: %0d", $time, data_source2);
        $display("[Time: %0t] data_out: %0d", $time, data_out);

        #10 $finish;
    end

endmodule