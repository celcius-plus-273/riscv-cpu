module cache_simple
#(
    parameter CACHE_DEPTH     = 256,  // cache size
    parameter CACHE_AX_DELAY  = 1,    // cache access delay (in cycles)
    parameter HIT_RATE        = 50,   // hit rate in percentage

    // derived parameters
    localparam CACHE_ADDR_WIDTH     = $clog2(CACHE_DEPTH),
    localparam DELAY_BITS           = $clog2(CACHE_AX_DELAY)
) (
    // clk, rst
    input logic         clk_i,
    input logic         rstn_i,
    cpu_cache_if.slave  cache_if,  // interface to pipeline memory stage
    axi4_lite_if.master axl_if      // AXI4-Lite interface to memory bus
);
    // Enums
    typedef enum logic [1:0] {
        READY   = 2'b00,
        WAIT    = 2'b01,
        STATEX  = 2'bxx
    } cache_state_e;

    // Functions
    function automatic bit generate_prob_bit(int unsigned percent_prob);
        // Catch out-of-bounds inputs
        if (percent_prob == 0) return 1'b0;
        if (percent_prob >= 100) return 1'b1;

        // $urandom_range(0, 99) yields 100 possible values.
        // If percent_prob is 25, values 0-24 will evaluate to true.
        return ($urandom_range(99) < percent_prob);
    endfunction


    // ============================== //
    //         Variables
    // ============================== //
    // FSM state register
    cache_state_e state_r, next_state;

    // Counter for simulating access delay
    logic [DELAY_BITS:0] delay_cnt_r, delay_cnt_next;

    // random wait logic
    logic is_wait;

    // stall
    logic stall;

    // Internal memory signals
    logic                           cache_cenb;
    logic                           cache_wenb;
    logic [CACHE_ADDR_WIDTH-1:0]    cache_addr;
    logic [31:0]                    cache_wdata;
    logic [3:0]                     cache_mask;
    logic [31:0]                    cache_rdata;

    // always ff
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (~rstn_i) begin
            state_r     <= READY;
            delay_cnt_r <= '0;
            is_wait     <= 1'b0;
        end else begin
            state_r     <= next_state;
            delay_cnt_r <= delay_cnt_next;

            // compute next accesses wait
            // - in a real cache you would ax the tag array to determine hit/miss
            //   which is used to determine wait vs no wait
            // - here we just randomize the "next" access
            if (CACHE_AX_DELAY > 1) begin
                is_wait <= ($urandom_range(100) < (100 - HIT_RATE));
                // $display("CACHE: Access requested. Random wait = %b", is_wait);
            end else begin
                is_wait <= 1'b0; // no wait if AXI delay is 1 cycle
            end
        end
    end

    // comb logic for next state and delay counter
    always_comb begin
        // default values
        next_state      = state_r;
        delay_cnt_next  = delay_cnt_r;

        case (state_r)
            READY: begin
                if (cache_if.rd_en | cache_if.wr_en) begin

                    // if wait, go to WAIT state and start delay counter
                    next_state = is_wait ? WAIT : READY;
                end
            end
            WAIT: begin
                // increment delay counter
                delay_cnt_next = delay_cnt_r + 1;

                // if we've reached the access delay, go back to READY for next access
                // - note that we use next_cnt to account current cycle
                // - e.g. if AX_DELAY is 2 cycles, we stay in wait for 1 cycle
                if (delay_cnt_next == (CACHE_AX_DELAY - 1)) begin
                    next_state = READY;
                    delay_cnt_next = '0; // reset counter for next access
                end
            end
            default: next_state = STATEX;
        endcase
    end

    // generate
    //     if (CACHE_AX_DELAY > 1) begin
    //         assign is_wait = 1'b1;
    //     end
    //     else begin
    //         assign is_wait = 1'b0;
    //     end
    // endgenerate

    // assign logic
    assign stall = next_state == WAIT;

    // assign outputs
    assign cache_cenb           = ~(cache_if.rd_en | cache_if.wr_en) | stall; // active low enable
    assign cache_wenb           = ~cache_if.wr_en; // active low write enable
    assign cache_addr           = cache_if.addr[CACHE_ADDR_WIDTH-1:0];
    assign cache_mask           = cache_if.mask;
    assign cache_wdata          = cache_if.wr_data;
    assign cache_if.rd_data     = cache_rdata;
    assign cache_if.stall       = stall;

    // ============================== //
    //         SRAM Instance
    // ============================== //
    `ifdef SRAM_MACRO
    `else
        sram_rw_dff #(
            .WIDTH(32),
            .DEPTH(CACHE_DEPTH)
        ) sram_inst (
            .clk_i(clk_i),
            .rstn_i(rstn_i),   // for cleaner sims
            .cenb_i(cache_cenb),
            .wenb_i(cache_wenb),
            .mask_i(cache_mask),
            .addr_i(cache_addr),
            .data_i(cache_wdata),
            .data_o(cache_rdata)
        );
    `endif

endmodule
