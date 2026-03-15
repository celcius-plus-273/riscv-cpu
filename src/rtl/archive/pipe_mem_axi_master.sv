// ======================== //
//         Imports
// ======================== //
import rv_cpu_pkg::ex_mem_s;
import rv_cpu_pkg::mem_wb_s;
import rv_cpu_pkg::mem_hzd_s;

module pipe_mem
#(
    // parameters
    parameter D_MEM_DEPTH = 256,  // D-cache size

    // derived parameters
    localparam D_MEM_ADDR_WIDTH = $clog2(D_MEM_DEPTH)
) (
    // interfaces
    // clk, rst
    input logic         clk_i,
    input logic         rstn_i,

    input logic         bubble_i,   // bubble signal from hazard unit for load-use hazards

    axi4_lite_if.master axl_if,     // AXI4-Lite interface to data memory (for loads/stores)

    // memory to hazard (wire)
    output mem_hzd_s    mem_hzd_o,  // MEM to Hazard interface for hazard detection

    // Pipeline Interfaces (reg)
    input ex_mem_s      ex_mem_i,   // Execute to Memory pipeline register (reg)
    output mem_wb_s     mem_wb_o    // Memory to Writeback pipeline register (reg)
);
    // ============================== //
    //         MEMORY STAGE
    // ============================== //
    /**
    *  The main functions handled on the memory stage are:
    *  1. Perform the memory read/write as determined by the control signals
    *  2. Pass the read data to the writeback stage
    *  3. Passthrough control signals like rd_wen, rd_addr, and wb_src
    */

    // Internal FSM States
    typedef enum logic [1:0] {
        IDLE = 2'b00,
        R_REQ = 2'b01,
        W_REQ = 2'b11,
        STATEX = 2'bxx
    } mem_state_e;

    // ============================== //
    //         Variables
    // ============================== //
    // FSM state register
    mem_state_e state_r, next_state;

    // busy signal to indicate memory transaction in progress (for stalling in hazard unit)
    logic mem_busy;

    // intermediate logic
    logic vld_r_resp;
    logic vld_w_resp;

    // determine fwd data based on wb_src lol
    // - can be alu_result or addr_result (auipc)
    logic [31:0] mem_fwd_data;

    // state ff
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (!rstn_i) begin
            state_r <= IDLE;
        end
        else begin
            state_r <= next_state;
        end
    end

    // state transition logic
    always_comb begin
        // default to current state
        next_state = state_r;
        case (state_r)
            IDLE: begin
                // start a memory transaction if either rd_en or wr_en
                // Notes:
                // - they are exclusive (will never happen simultaneously)
                // - d cache MUST be ready to accept (no one else should be using it)
                if (ex_mem_i.mem_rd_en & axl_if.ar_rdy)
                    next_state = R_REQ;

                if (ex_mem_i.mem_wr_en & axl_if.aw_rdy & axl_if.w_rdy)
                    next_state = W_REQ;
            end
            R_REQ: begin
                next_state = vld_r_resp ? IDLE : R_REQ;
            end
            W_REQ: begin
                next_state = vld_w_resp ? IDLE : W_REQ;
            end
            default:
                next_state = STATEX; // invalid state, should never happen
        endcase
    end

    // valid read response and valid write response logic
    assign vld_r_resp = axl_if.r_vld && (axl_if.r_resp == 2'b00);
    assign vld_w_resp = axl_if.b_vld && (axl_if.b_resp == 2'b00);

    // Combinational logic for AXI4-Lite signals
    always_comb begin : axi_lite_out
        // default values
        axl_if.aw_vld   = 1'b0;
        axl_if.w_vld    = 1'b0;
        axl_if.ar_vld   = 1'b0;
        mem_busy        = 1'b0;
        case (next_state)
            IDLE: begin
                // do nothing (set all values to default)
            end
            R_REQ: begin
                axl_if.ar_vld   = 1'b1; // assert valid address for read
                mem_busy        = 1'b1;
            end
            W_REQ: begin
                axl_if.aw_vld   = 1'b1;
                axl_if.w_vld    = 1'b1;
                mem_busy        = 1'b1;
            end
            default: begin
                // invalid state, should never happen
                axl_if.aw_vld   = 1'bx;
                axl_if.w_vld    = 1'bx;
                axl_if.ar_vld   = 1'bx;
                mem_busy        = 1'bx;
            end
        endcase
    end

    // ready signals (B and R channels)
    assign axl_if.b_rdy = (state_r == W_REQ);
    assign axl_if.r_rdy = (state_r == R_REQ);

    // AW Channel
    assign axl_if.aw_addr  = ex_mem_i.alu_result; // use ALU result as address for writes
    assign axl_if.aw_prot  = 3'b000; // not used

    // W Channel
    assign axl_if.w_data   = ex_mem_i.mem_wr_data; // data to write comes from rs2 (store instructions)
    assign axl_if.w_strb   = ex_mem_i.mem_mask; // byte enable mask for writes

    // AR Channel
    assign axl_if.ar_addr  = ex_mem_i.alu_result; // use ALU result as address for reads
    assign axl_if.ar_prot  = 3'b000; // not used

    // ALU result forwarding
    always_comb begin : fwd_data
        case (ex_mem_i.wb_src)
            2'b00: mem_fwd_data = ex_mem_i.alu_result;  // ALU result (for ALU ops)
            2'b10: mem_fwd_data = ex_mem_i.pc_p4;       // PC + 4 (for jalr)
            2'b11: mem_fwd_data = ex_mem_i.addr_result; // (for auipc)
            default: mem_fwd_data = '0;
        endcase
    end

    // output reg pipeline
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (~rstn_i | bubble_i) begin
            mem_wb_o.pc_p4          <= '0;
            mem_wb_o.alu_result     <= '0;
            mem_wb_o.addr_result    <= '0;
            mem_wb_o.mem_data       <= '0;
            mem_wb_o.mem_rd_en      <= '0;
            mem_wb_o.mem_mask       <= '0;
            mem_wb_o.mem_signed     <= '0;
            mem_wb_o.wb_src         <= '0;
            mem_wb_o.rd_wen         <= '0;
            mem_wb_o.rd_addr        <= '0;
        end
        else begin
            mem_wb_o.pc_p4          <= ex_mem_i.pc_p4;          // passthrough for pc + 4 (for jalr)
            mem_wb_o.alu_result     <= ex_mem_i.alu_result;     // passthrough for alu result (for alu ops)
            mem_wb_o.addr_result    <= ex_mem_i.addr_result;    // passthrough for address result (for auipc)
            mem_wb_o.mem_data       <= axl_if.r_data;           // read data from memory (for loads)
            mem_wb_o.mem_rd_en      <= ex_mem_i.mem_rd_en;      // passthrough for memory read enable
            mem_wb_o.mem_mask       <= ex_mem_i.mem_mask;       // passthrough for memory mask
            mem_wb_o.mem_signed     <= ex_mem_i.mem_signed;     // passthrough for memory signed/unsigned
            mem_wb_o.wb_src         <= ex_mem_i.wb_src;         // passthrough wb_src
            mem_wb_o.rd_wen         <= ex_mem_i.rd_wen;         // passthrough reg dest write en
            mem_wb_o.rd_addr        <= ex_mem_i.rd_addr;        // passthrough reg dest addr
        end
    end

    // ============================== //
    //         SRAM Instance
    // ============================== //
    // `ifdef SRAM_MACRO
    // `else
    //     sram_rw_dff #(
    //         .WIDTH(32),
    //         .DEPTH(D_MEM_DEPTH)
    //     ) sram_inst (
    //         .clk_i(clk_i),
    //         .rstn_i(rstn_i),   // for cleaner sims
    //         .cenb_i(~ex_mem_i.mem_rd_en & ~ex_mem_i.mem_wr_en), // enable when either read or write is active
    //         .wenb_i(~ex_mem_i.mem_wr_en), // write when mem_wr_en is active
    //         .mask_i(ex_mem_i.mem_mask), // byte enable mask
    //         .addr_i(ex_mem_i.alu_result[D_MEM_ADDR_WIDTH-1:0]), // use lower bits of ALU result as address
    //         .data_i(ex_mem_i.mem_wr_data), // data to write comes from rs2 (store instructions)
    //         .data_o(mem_wb_o.mem_data) // data read from memory goes to MEM/WB pipeline register
    //     );
    // `endif

    assign mem_hzd_o.mem_rd_en  = ex_mem_i.mem_rd_en;
    assign mem_hzd_o.rd_wen     = ex_mem_i.rd_wen;
    assign mem_hzd_o.rd_addr    = ex_mem_i.rd_addr;
    assign mem_hzd_o.rd_data    = mem_fwd_data;      // all data except load
    assign mem_hzd_o.mem_busy   = mem_busy;         // indicate if memory transaction is in progress

endmodule
