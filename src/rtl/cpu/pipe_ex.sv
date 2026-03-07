// ======================== //
//         Imports
// ======================== //
import rv_cpu_pkg::id_ex_s;
import rv_cpu_pkg::ex_mem_s;
import rv_cpu_pkg::ex_if_s;
// import rv_cpu_pkg::*;

module pipe_ex
(
    // clk, rst
    input logic     clk_i,
    input logic     rstn_i,

    // Execute Stage Interfaces (Wires)
    output ex_if_s  ex_if_o,       // EX to IF interface for branch target update

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
    logic [31:0]    alu_srcB;
    logic [31:0]    alu_result;

    // Branch logic variables
    logic           pc_src; // 0 = PC + 4, 1 = branch/jump target
    logic [31:0]    pc_addr; // branch/jump target address
    logic [31:0]    addr_result; // pc + immediate

    // Branch resolution logic
    always_comb begin : branch_logic
        pc_src          = (id_ex_i.is_branch & (~|alu_result)) | id_ex_i.is_jump;

        // target addr logic
        addr_result     = id_ex_i.pc + id_ex_i.imm;
        pc_addr         = (id_ex_i.is_jalr) ? alu_result : addr_result;
    end

    // Combinational Assign
    // TODO: add forwarding
    assign alu_srcA = id_ex_i.rs1_data;
    assign alu_srcB = id_ex_i.alu_src ? id_ex_i.imm : id_ex_i.rs2_data;

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
            // no flush?

            ex_mem_o.pc_p4          <= id_ex_i.pc_p4;
            ex_mem_o.alu_result     <= alu_result;
            ex_mem_o.addr_result    <= addr_result;

            ex_mem_o.mem_rd_en      <= id_ex_i.mem_rd_en;
            ex_mem_o.mem_wr_en      <= id_ex_i.mem_wr_en;
            ex_mem_o.mem_mask       <= id_ex_i.mem_mask;
            ex_mem_o.mem_signed     <= id_ex_i.mem_signed;
            ex_mem_o.mem_wr_data    <= id_ex_i.rs2_data;

            ex_mem_o.wb_src         <= id_ex_i.wb_src;
            ex_mem_o.rd_wen         <= id_ex_i.rd_wen;
            ex_mem_o.rd_addr        <= id_ex_i.rd_addr;
        end
    end

    // Assigned Outputs
    // EX to IF interface (wire)
    assign ex_if_o.pc_src  = pc_src;
    assign ex_if_o.pc_addr = pc_addr;

endmodule
