module d_cache
#(
    parameter D_CACHE_DEPTH     = 256,  // D-cache size
    parameter D_CACHE_AX_DELAY  = 2,

    // derived parameters
    localparam D_CACHE_ADDR_WIDTH   = $clog2(D_CACHE_DEPTH),
    localparam DELAY_BITS           = $clog2(D_CACHE_AX_DELAY)
) (
    // clk, rst
    input logic         clk_i,
    input logic         rstn_i,
    axi4_lite_if.slave  axl_if // AXI4-Lite interface to data memory (for loads/stores)
);

    // Internal State Encoding
    typedef enum logic [1:0] {
        IDLE = 2'b00,
        R_RESP = 2'b01,
        W_RESP = 2'b10,
        STATEX = 2'bxx
    } d_cache_state_e;

    // ============================== //
    //         Variables
    // ============================== //
    // FSM state register
    d_cache_state_e state_r, next_state;

    // Simulated delay
    logic [DELAY_BITS-1:0] delay_cnt_r, delay_cnt_next;
    logic finish_delay;

    // Internal memory signals
    logic                           cache_cenb;
    logic                           cache_wenb;
    logic [D_CACHE_ADDR_WIDTH-1:0]  cache_addr;
    logic [31:0]                    cache_wdata;
    logic [3:0]                     cache_wstrb;
    logic [31:0]                    cache_rdata;

    // state ff
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (!rstn_i) begin
            state_r     <= IDLE;
            delay_cnt_r <= '0;
        end
        else begin
            state_r     <= next_state;
            delay_cnt_r <= delay_cnt_next;
        end
    end

    // next state logic
    always_comb begin
        // default values
        next_state = state_r;
        delay_cnt_next = '0;
        case (state_r)
            IDLE: begin
                if (axl_if.ar_vld) next_state = R_RESP; // if read address valid, go to read response state
                if (axl_if.aw_vld && axl_if.w_vld) next_state = W_RESP; // if write address and data valid, go to write response state
            end
            R_RESP: begin
                delay_cnt_next = delay_cnt_r + 1;
                next_state = (finish_delay & axl_if.r_rdy) ? IDLE : R_RESP; // stay in R_RESP until master is ready
            end
            W_RESP: begin
                delay_cnt_next = delay_cnt_r + 1;
                next_state = (finish_delay & axl_if.b_rdy) ? IDLE : W_RESP; // stay in W_RESP until master is ready
            end
            default: begin
                next_state = STATEX;
            end
        endcase
    end

    // memory control logic
    always_comb begin
        // default control signals
        cache_cenb = 1'b1; // disable cache by default
        cache_wenb = 1'b0; // default to read
        cache_addr = '0;
        case (next_state)
            IDLE: begin
                // set to default
            end
            R_RESP: begin
                cache_cenb = 1'b0; // enable cache
                cache_wenb = 1'b1; // read operation
                cache_addr = axl_if.ar_addr[D_CACHE_ADDR_WIDTH-1:0];
            end
            W_RESP: begin
                cache_cenb = 1'b0; // enable cache
                cache_wenb = 1'b0; // write operation
                cache_addr = axl_if.aw_addr[D_CACHE_ADDR_WIDTH-1:0];
            end
            default: begin
                cache_cenb = 1'bx;
                cache_wenb = 1'bx;
                cache_addr = 'x;
            end
        endcase
    end

    // fake delay counter
    assign finish_delay = (delay_cnt_r == (D_CACHE_AX_DELAY - 1'b1));

    // Write Address Channel
    assign axl_if.aw_rdy    = (state_r == IDLE); // ready to accept write address when in IDLE state
    // Write Data Channel
    assign axl_if.w_rdy     = (state_r == IDLE); // ready
    // Write Response Channel
    assign axl_if.b_vld     = (state_r == W_RESP) & finish_delay; // assert write response valid when in W_RESP state and delay is finished
    assign axl_if.b_resp    = 2'b00; // OKAY response for writes
    // Read Address Channel
    assign axl_if.ar_rdy    = (state_r == IDLE); // ready to accept read address when in IDLE state
    // Read Data Channel
    assign axl_if.r_vld     = (state_r == R_RESP) & finish_delay; // assert read valid when in R_RESP state and delay is finished
    assign axl_if.r_resp    = 2'b00; // OKAY response for reads
    assign axl_if.r_data    = (state_r == R_RESP & finish_delay) ? cache_rdata : '0;

    // assign logic
    assign cache_wdata      = axl_if.w_data;
    assign cache_wstrb      = axl_if.w_strb;

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
