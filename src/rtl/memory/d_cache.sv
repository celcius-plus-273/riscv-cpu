module d_cache
#(
    parameter D_CACHE_DEPTH     = 256,  // D-cache size
    parameter D_CACHE_AX_DELAY  = 1,    // D-cache access delay (in cycles)

    // derived parameters
    localparam D_CACHE_ADDR_WIDTH   = $clog2(D_CACHE_DEPTH),
    localparam DELAY_BITS           = $clog2(D_CACHE_AX_DELAY)
) (
    // clk, rst
    input logic         clk_i,
    input logic         rstn_i,
    mem_dcache_if.slave dcache_if,  // interface to pipeline memory stage
    axi4_lite_if.master axl_if      // AXI4-Lite interface to memory bus
);

    typedef enum logic [1:0] {
        IDLE = 2'b00,
        WAIT = 2'b01,
        STATEX = 2'bxx
    } cache_state_e;

    // ============================== //
    //         Variables
    // ============================== //
    // FSM state register
    cache_state_e state_r, next_state;

    // Counter for simulating access delay
    logic [DELAY_BITS:0] delay_cnt_r, delay_cnt_next;

    // fake delay finish signal
    logic finish_ax;

    // Internal memory signals
    logic                           cache_cenb;
    logic                           cache_wenb;
    logic [D_CACHE_ADDR_WIDTH-1:0]  cache_addr;
    logic [31:0]                    cache_wdata;
    logic [3:0]                     cache_wstrb;
    logic [31:0]                    cache_rdata;

    // always ff
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (~rstn_i) begin
            state_r <= IDLE;
            delay_cnt_r <= '0;
        end else begin
            state_r <= next_state;
            delay_cnt_r <= delay_cnt_next;
        end
    end

    // comb logic for next state and delay counter
    always_comb begin
        // default values
        next_state = state_r;
        delay_cnt_next = delay_cnt_r;

        case (state_r)
            IDLE: begin
                // Delay counter is not used if AX delay is 1 cycle
                if (D_CACHE_AX_DELAY == 1) begin
                    next_state = IDLE;
                end else begin
                    next_state = cache_cenb ? IDLE : WAIT;
                end
            end
            WAIT: begin
                delay_cnt_next = delay_cnt_r + 1'b1;
                next_state = (delay_cnt_next == (D_CACHE_AX_DELAY - 1)) ? IDLE : WAIT;
            end
            default: next_state = STATEX;
        endcase
    end

    // assign outputs
    assign cache_cenb           = ~(dcache_if.rd_en | dcache_if.wr_en); // active low enable
    assign cache_wenb           = ~dcache_if.wr_en; // active low write enable
    assign cache_addr           = dcache_if.addr[D_CACHE_ADDR_WIDTH-1:0];
    assign cache_wdata          = dcache_if.wr_data;
    assign cache_wstrb          = dcache_if.wr_strb;
    assign finish_ax            = delay_cnt_r == (D_CACHE_AX_DELAY - 1);

    assign dcache_if.rd_data    = finish_ax ? cache_rdata : '0;
    assign dcache_if.stall      = (next_state == WAIT);

    // ============================== //
    //         SRAM Instance
    // ============================== //
    `ifdef SRAM_MACRO
    `else
        sram_rw_dff #(
            .WIDTH(32),
            .DEPTH(D_CACHE_DEPTH)
        ) sram_inst (
            .clk_i(clk_i),
            .rstn_i(rstn_i),   // for cleaner sims
            .cenb_i(cache_cenb),
            .wenb_i(cache_wenb),
            .mask_i(cache_wstrb),
            .addr_i(cache_addr),
            .data_i(cache_wdata),
            .data_o(cache_rdata)
        );
    `endif

endmodule
