import rv_cpu_pkg::ex_if_s;
import rv_cpu_pkg::if_id_s;
import rv_cpu_pkg::if_hzd_s;

module pipe_if
(
    // clk, rstn, en
    input logic     clk_i,
    input logic     rstn_i,

    input logic     en_i,   // ~stall
    input logic     flush_i,   // for control hazard detection
    // input logic     bubble_i,   // when I-cache is stalled

    // I-cache interface (wire)
    cpu_cache_if.master icache_if, // interface to I-cache

    // Execute Stage Interface (wire)
    input ex_if_s   ex_if_i,

    // Hazard Detection Interface (wire)
    output if_hzd_s if_hzd_o, // IF to Hazard interface for hazard detection

    // Decode Stage Interface (pipeline register)
    output if_id_s if_id_o
);
    /**
    *  Fetch Stage
    *
    *  Fetch the next instruction indicated by PC
    *  - PC is updated every cycle
    *  - Assume a valid PC is available at the beginning of the cycle
    */
    localparam NOP = 32'h00000013; // addi x0, x0, 0

    // ============================== //
    //         Variables
    // ============================== //
    logic [31:0] pc_r;
    logic [31:0] pc_next;
    logic        bubble_r;
    logic        cache_stall;
    logic        pc_en;

    // PC Update Logic
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (!rstn_i) begin
            pc_r <= 0;  // initial pc can be configurable...?
        end
        else begin
            pc_r <= pc_en ? pc_next : pc_r;
            bubble_r <= flush_i | (cache_stall & ~ex_if_i.pc_src); // bubble if flush or stall (load-use hazard)
        end
    end

    // next pc logic (comb assign)
    // current prediction: always not taken (pc + 4)
    // TODO: add branch prediction logic (Gskew or Gshare)
    assign pc_next = ex_if_i.pc_src ? ex_if_i.pc_addr : pc_r + 4;

    // stall when I-cache has a miss
    assign pc_en = en_i & ~cache_stall; // enable is gated by stall signal

    // output reg pipeline
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (~rstn_i) begin
            if_id_o.pc    <= '0;
            if_id_o.pc_p4 <= '0;
        end
        else begin
            if_id_o.pc    <= pc_en ? pc_r : if_id_o.pc;
            if_id_o.pc_p4 <= pc_en ? pc_r + 32'd4 : if_id_o.pc_p4;
        end
    end

    // ============================== //
    //         I-Cache Interface
    // ============================== //
    assign icache_if.rd_en = en_i;      // read enable is gated by stall signal
    assign icache_if.addr  = pc_r;      // use current PC as address for instruction fetch
    assign icache_if.wr_en = 1'b0;      // fetch doesn't write to i-cache
    assign icache_if.wr_data = '0;      // no writes to I-cache
    assign icache_if.mask = '1;         // full word access
    // NOP if flush is signaled (incorrect prediction)
    assign if_id_o.inst = bubble_r ? NOP : icache_if.rd_data;
    assign cache_stall = icache_if.stall; // stall if i-cache is stalled

    // ============================== //
    //         Hazard Interface
    // ============================== //
    assign if_hzd_o.stall = icache_if.stall; // stall if i-cache is stalled

endmodule
