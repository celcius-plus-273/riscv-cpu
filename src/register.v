// General Purpose Register module for RISCV datapath
module register 
#(
    parameter   WORD_SIZE=32
)
(
    // control signal inputs
    input   wire    clock,
    input   wire    reset_n,
    input   wire    write_enable,

    // address selection inputs
    input   wire [4:0]  write_addr,
    input   wire [4:0]  read_addr1,
    input   wire [4:0]  read_addr2,

    // data input and output ports
    input   wire [WORD_SIZE-1:0]    write_data,
    output  reg [WORD_SIZE-1:0]    read_data1,
    output  reg [WORD_SIZE-1:0]    read_data2
);
    // use reg array to model a register file of size 32
    reg [WORD_SIZE-1:0] register_file [0:31];
    integer i; // used to flush the register file upon reset

    /** Write Logic
    * Our register file supports writes on the rising edge of the clock
    * Reset is asynchronous
    */
    always @ (posedge clock or negedge reset_n) begin
        if (!reset_n) begin
            $display("[Time: %0t] resetting values in register file...", $time);
            for (i = 0; i < 32; i = i + 1) 
                register_file[i] <= 32'b1; // REMINDER TO CHANGE BACK TO 0. SET TO 1 FOR TESTING
        end
        else begin                
            // do we need to specify what happens if write is not enabled? -> seems like we don't have to!
            // [Intuition]: reg types can store values. these values are only updated when assigned (do not confuse with)
            // assignment operator). Therefore if we never assign a specific addr in the reg file, nothing should change! 
            if (write_enable) begin
                register_file[write_addr] = write_data; // defined as blocking just for simulation debug
                $display("[Time: %0t] Addr: %0d | Data: %0d", write_addr, register_file[write_addr]);
            end
        end
    end

    /** Read Logic
    * Always reads on the negedge of the clock
    * Guarantees that read is done after write (if clocked properly) 
    */
    always @ (negedge clock) begin
        // does it make a different if I use blocking statements here?
        // bc this is sequential logic you are supposed to drive it with non-blockng statements...
        // why would this matter?
        read_data1 <= register_file[read_addr1];
        read_data2 <= register_file[read_addr2];
    end

endmodule