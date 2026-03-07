// Single Port DFF-based SRAM model
module sram_rw_dff
#(
    // size of memory
    parameter DEPTH,
    parameter WIDTH,

    // localparams
    parameter NUM_BYTES = WIDTH / 8,
    parameter ADDR_WIDTH = $clog2(DEPTH)
) (
    // clk, rst
    input logic clk_i,
    input logic rstn_i,

    // chip enable and write enable
    input logic cenb_i,         // chip enable (active low)
    input logic wenb_i,         // write enable (active low)

    // Single Port memory
    input  logic [NUM_BYTES-1 : 0]      mask_i, // byte mask for read & writes
    input  logic [ADDR_WIDTH-1 : 0]     addr_i,
    input  logic [WIDTH-1  : 0]         data_i,
    output logic [WIDTH-1  : 0]         data_o
);
    // localparams and variables
    integer i;

    // simple behavioral memory :)
    logic [WIDTH-1 : 0] mem_array [DEPTH];

    // ff read and write logic
    always @( posedge clk_i or negedge rstn_i ) begin : read_write_ff
        // reset memory
        if (!rstn_i) begin
            // reset mem array
            for (i = 0; i < DEPTH; i += 1) begin
                mem_array[i] <= '0;
            end
            // reset output ff
            data_o <= '0;
        end
        // normal behavior
        else begin
            // memory can only read OR write (can't do both)
            if (~cenb_i) begin
                if (wenb_i) begin
                    // wenb = 1: READ
                    for (i = 0; i < NUM_BYTES; i += 1) begin
                        if (mask_i[i]) begin
                            data_o[((i+1)*8)-1 -: 8] <= mem_array[addr_i >> 2][((i+1)*8)-1 -: 8];
                        end
                    end
                end
                else begin
                    // wenb = 0: WRITE
                    for (i = 0; i < NUM_BYTES; i += 1) begin
                        if (mask_i[i]) begin
                            mem_array[addr_i >> 2][((i+1)*8)-1 -: 8] <= data_i[((i+1)*8)-1 -: 8];
                        end
                    end
                end
            end
        end
    end

endmodule
