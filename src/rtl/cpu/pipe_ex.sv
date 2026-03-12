// ======================== //
//         Imports
// ======================== //
import rv_cpu_pkg::id_ex_s;
import rv_cpu_pkg::ex_mem_s;
import rv_cpu_pkg::ex_if_s;
import rv_cpu_pkg::ex_hzd_s;
import rv_cpu_pkg::fwd_ex_s;

module pipe_ex
(
    // clk, rst
    input logic     clk_i,
    input logic     rstn_i,

    input logic     stall_i,    // stall signal from hazard unit for data hazards

    // Execute Stage Interfaces (Wires)
    input  fwd_ex_s fwd_ex_i,      // Forwarding from hazard detection
    output ex_if_s  ex_if_o,       // EX to IF interface for branch target update
    output ex_hzd_s ex_hzd_o,      // EX to Hazard interface for hazard detection

    // Execute Stage Interfaces (Reg Pipelines)
    input id_ex_s   id_ex_i,        // ID to EX interface
    output ex_mem_s ex_mem_o        // EX to MEM interface
);
    // ============================== //
    //        EXECUTE STAGE
    // ============================== //
    /**
     *  The main functions handled on the execute stage are:
     *  1. Perform the ALU operation as determined by the control signals
     *  2. Pass the ALU result to the memory stage
     *  3. Passthrough control signals like write_enable and rd_addr
    */

    // ============================== //
    //           Variables
    // ============================== //
    logic [31:0]    alu_srcA;
    logic [31:0]    rs1_src;
    logic [31:0]    alu_srcB;
    logic [31:0]    rs2_src;
    logic [31:0]    alu_result;

    // Branch logic variables
    logic           pc_src; // 0 = PC + 4, 1 = branch/jump target
    logic [31:0]    pc_addr; // branch/jump target address
    logic [31:0]    addr_result; // pc + immediate
    logic           is_zero; // for branch resolution

    // Branch resolution logic
    always_comb begin : branch_logic
        is_zero         = alu_result == 0;
        pc_src          = (id_ex_i.is_branch & ((id_ex_i.branch_sign & ~is_zero) | (~id_ex_i.branch_sign & is_zero))) | id_ex_i.is_jump;

        // target addr logic
        addr_result     = id_ex_i.pc + id_ex_i.imm;
        pc_addr         = (id_ex_i.is_jalr) ? alu_result : addr_result;
    end

    // Combinational Assign
    assign rs1_src = fwd_ex_i.is_fwd_rs1 ? fwd_ex_i.rs1_data : id_ex_i.rs1_data;    // forwarded rs1
    assign rs2_src = fwd_ex_i.is_fwd_rs2 ? fwd_ex_i.rs2_data : id_ex_i.rs2_data;    // forwarded rs2
    assign alu_srcA = rs1_src;
    assign alu_srcB = id_ex_i.alu_src ? id_ex_i.imm : rs2_src;

    // Instantiate the ALU
    alu alu_inst (
        .op_i(id_ex_i.alu_op),
        .srcA_i(alu_srcA),
        .srcB_i(alu_srcB),
        .result_o(alu_result)
    );

    // output reg pipeline
    always_ff @(posedge clk_i or negedge rstn_i) begin
        if (!rstn_i) begin
            ex_mem_o.pc_p4          <= '0;
            ex_mem_o.alu_result     <= '0;
            ex_mem_o.addr_result    <= '0;
            ex_mem_o.mem_rd_en      <= '0;
            ex_mem_o.mem_wr_en      <= '0;
            ex_mem_o.mem_mask       <= '0;
            ex_mem_o.mem_signed     <= '0;
            ex_mem_o.mem_wr_data    <= '0;
            ex_mem_o.wb_src         <= '0;
            ex_mem_o.rd_wen         <= '0;
            ex_mem_o.rd_addr        <= '0;
        end else begin
            if (~stall_i) begin
                ex_mem_o.pc_p4          <= id_ex_i.pc_p4;
                ex_mem_o.alu_result     <= alu_result;
                ex_mem_o.addr_result    <= addr_result;

                ex_mem_o.mem_rd_en      <= id_ex_i.mem_rd_en;
                ex_mem_o.mem_wr_en      <= id_ex_i.mem_wr_en;
                ex_mem_o.mem_mask       <= id_ex_i.mem_mask;
                ex_mem_o.mem_signed     <= id_ex_i.mem_signed;
                ex_mem_o.mem_wr_data    <= rs2_src; // need to consider forwarded rs2!

                ex_mem_o.wb_src         <= id_ex_i.wb_src;
                ex_mem_o.rd_wen         <= id_ex_i.rd_wen;
                ex_mem_o.rd_addr        <= id_ex_i.rd_addr;
            end
        end
    end

    // Assigned Outputs
    // EX to IF interface (wire)
    assign ex_if_o.pc_src       = pc_src;
    assign ex_if_o.pc_addr      = pc_addr;

    // EX to Hazard interface (wire)
    assign ex_hzd_o.mem_rd_en  = id_ex_i.mem_rd_en;
    assign ex_hzd_o.rd_addr     = id_ex_i.rd_addr;
    assign ex_hzd_o.r1_en       = id_ex_i.r1_en;
    assign ex_hzd_o.rs1_addr    = id_ex_i.rs1_addr;
    assign ex_hzd_o.r2_en       = id_ex_i.r2_en;
    assign ex_hzd_o.rs2_addr    = id_ex_i.rs2_addr;

    //  Veri--lator interprets any change in the struct as an entire new struct value
    // -> It flagged the pc_src signal as a circular comb logic dependency
    // -> to avoid: we will just take pc_src (aka branch resolution) from ex_if_s
    //     NOTE: check rv_cpu.sv
    //            ... .is_taken(ex_if_w.pc_src) ...
    // assign ex_hzd_o.is_taken    = pc_src; // only a hazard if branch is taken

endmodule
