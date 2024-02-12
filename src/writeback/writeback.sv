module writeback 
#(
    parameter WORD_SIZE = 32
)
(
    /*
        The writeback stage takes the output from the execute stage and writes it back
        to the register file located on the decode module
    */
    
    // input control signals
    input wire clock,

    // input data from the execute stage
    input wire [WORD_SIZE-1:0] data_result,
    // input destination register
    input wire [4:0] reg_dest_in,
    // input write enable signal
    input wire write_enable_in,

    // output write data and write address
    output reg [WORD_SIZE-1:0] write_data,
    output reg [4:0] write_addr,
    output reg write_enable_out
);

    //
    reg [WORD_SIZE-1:0] write_data_reg = 0;
    reg [4:0] reg_dest_reg = 0;
    reg write_enable_reg = 0;

    // latch all of the incmoing data
    always @ (posedge clock) begin
        write_data_reg <= data_result;
        reg_dest_reg <= reg_dest_in;
        write_enable_reg <= write_enable_in;
    end

    // output regs need to be updated on the negedge
    // value will be stable on the posedge (during the write stage of the reg file) 
    always @ (negedge clock) begin
        write_data <= write_data_reg;
        write_addr <= reg_dest_reg;
        write_enable_out <= write_enable_reg;

        // DEBUG PRINT
        //$display("WRITEBACK STAGE \n[Time: %0t] Write enable: %0b", $time, write_enable_reg);
    end

endmodule