/*
 *  Register File
 *
 *  Implements a register file with DEPTH registers, each WIDTH bits wide
 *  - Supports one write port and two read ports
 *  - Writes occur on the rising edge of the clock when write enable is high
 *  - Reads occur on the rising edge of the clock, providing data from the specified addresses
 *
 *  Note: Register x0 is hardwired to zero and cannot be written to. Reads from x0 will always return zero.
 *
 *  Read & Write to same address in the same cycle:
 *  - Will return the old value (if there's a RAW dependency, read will have to wait until AFTER write finishes)
 */
module reg_file
#(
    parameter   WIDTH = 32,
    parameter   DEPTH = 32
)
(
    // control signal inputs
    input  logic        clk_i,
    input  logic        rstn_i,

    // Single Write Port
    input  logic                wen_i,
    input  logic [DEPTH-1:0]    w_addr,
    input  logic [WIDTH-1:0]    w_data,

    // Dual Read Port
    input  logic                r1_en_i,
    input  logic [DEPTH-1:0]    r1_addr_i,
    output logic [WIDTH-1:0]    r1_data_o,

    input  logic                r2_en_i,
    input  logic [DEPTH-1:0]    r2_addr_i,
    output logic [WIDTH-1:0]    r2_data_o
);
    // use reg array to model a register file of size 32
    reg [WIDTH-1:0] mem [DEPTH];

    logic [WIDTH-1:0] r1_data_next, r2_data_next;
    logic [WIDTH-1:0] r1_mem_data, r2_mem_data;

    /** Write Logic
     *  - Our register file supports writes on the rising edge of the clock
     *  - Reset is asynchronous
     */
    always_ff @ (posedge clk_i or negedge rstn_i) begin : write_ff
        if (!rstn_i) begin
            // reset all registers to 0 on reset (cleaner simulation waveforms)
            for (int i = 0; i < DEPTH; i++) begin
                mem[i] <= '0;
            end
        end
        else begin
            if (w_addr != 0) begin // enforce x0 is always 0
                mem[w_addr] <= wen_i ? w_data : mem[w_addr];
            end
        end
    end

    // Read Logic
    // - read data will be available on the rising edge of the clock
    always_ff @( posedge clk_i or negedge rstn_i ) begin : read_ff
        if (!rstn_i) begin
            r1_data_o <= '0;
            r2_data_o <= '0;
        end
        else begin
            r1_data_o <= r1_data_next;
            r2_data_o <= r2_data_next;
        end
    end

    always_comb begin : rd_forward_logic
        r1_mem_data = r1_en_i ? mem[r1_addr_i] : mem[0];
        r2_mem_data = r2_en_i ? mem[r2_addr_i] : mem[0];

        // if there's a write in the same cycle to the same address, forward the new data instead of the old data
        r1_data_next = (wen_i && (w_addr == r1_addr_i) && w_addr != 0) ? w_data : r1_mem_data;
        r2_data_next = (wen_i && (w_addr == r2_addr_i) && w_addr != 0) ? w_data : r2_mem_data;
    end

endmodule
