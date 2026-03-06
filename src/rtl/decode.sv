// ============================== //
//         Package Imports
// ============================== //
// Wire Interfaces
import rv_cpu_pkg::id_ctl_s;    // decode to control
import rv_cpu_pkg::ctl_id_s;    // control to decode
import rv_cpu_pkg::id_hzd_s;    // decode to hazard

// Pipeline Registers
import rv_cpu_pkg::id_ex_s;
import rv_cpu_pkg::wb_id_s;

// Enums
import rv_cpu_pkg::inst_type_e;

module decode
#(
    // parameters
    parameter int RF_DEPTH = 32,    // reg file depth

    // derived parameters
    localparam int RF_ADDR_WIDTH = $clog2(RF_DEPTH)
)
(
    /*
        THIS PORT LIST WILL BE EXPANDED AS I
        INCLUDE SUPPORT FOR MORE RV32 instructions
    */

    // control signals for decode
    input logic         clk_i,
    input logic         rstn_i,

    // Fetched instruction :D
    input logic [31:0]  inst_i,

    // Control Stage Interfaces (wire)
    input ctl_id_s      ctl_id_i,   // Control to ID Interface
    output id_ctl_s     id_ctl_o,   // ID to Control Interface

    // Hazard Detection Interfaces (wire)
    output id_hzd_s    id_hzd_o,   // ID to Hazard Detection Interface

    // Decode Stage Interfaces (pipeline registers)
    input wb_id_s       wb_id_i,    // WB to ID interface
    output id_ex_s      id_ex_o     // ID to EX Interface
);
    // ======================== //
    //       DECODE STAGE
    // ======================== //
    /**
     *  The main functions handled on the decode stage are:
     *  1. Decode the given instruction input
     *  2. Pass the opcode to control
     *  3. Read the required values from the register file
     *  4. Passthrough control signals like write_enable
    */

    // ======================== //
    //        Variables
    // ======================== //
    // reg file read (wire)
    logic [4:0]     rs1_addr;
    logic [4:0]     rs2_addr;

    // decoded immediate and funct fields (wire)
    logic [6:0]     funct7;
    logic [2:0]     funct3;
    logic [31:0]    immediate;

    // decoded reg dest (wire)
    logic [4:0]     rd_addr; // reg_dest addr

    always_comb begin : static_inst_decode
        // opcode decode
        opcode      = inst_i[6:0];
        opcode_A    = opcode[6:4];
        opcode_B    = opcode[3:2];
        inst_vld    = &opcode[1:0]; // vld = opcode[1] & opcode[0]

        // register addr decode
        rs1_addr    = inst_i[19:15];
        rs2_addr    = inst_i[24:20];
        rd_addr     = inst_i[11:7];

        // funct 3 & funct 7
        funct3      = inst_i[14:12];    // do we want to gate this?
        funct7      = inst_i[31:25];    // do we want to gate this?
    end

    // decode immediate value based on instruction type
    always_comb begin : immediate_decode
        // Supported instructions for now:
        // - R-type (add, sub, and, or, xor)
        // - I-type (addi, andi, ori, xori, load)

        // TODO: add support for other instruction types (S, B, U, J)
        case (inst_next)
            R_TYPE: begin
                immediate   = '0;   // immediate is not used for R-type instructions
            end
            I_TYPE: begin
                // imm <= sign_ext(inst_i[31:20]);
                immediate <= { {20{instruction[31]}}, instruction[31:20]};
            end
            default: begin
                immediate   = 'x;
            end
        endcase
    end

    // instantiate the register file
    reg_file #(
        .WIDTH(32),
        .DEPTH(32)
    ) reg_file_inst (
        // clk, rst
        .clk_i(clk_i),
        .rstn_i(rstn_i),

        // write port (connected to writeback stage)
        .wen_i(wb_id_i.rd_wen),
        .w_addr(wb_id_i.rd_addr),
        .w_data(wb_id_i.rd_data),

        // read ports
        // - data goes to execute stage
        // - src addr (and enable) comes from decode
        .r1_en_i(ctl_id_i.r1_en),
        .r1_addr_i(rs1_addr),
        .r1_data_o(id_ex_o.rs1_data),
        .r2_en_i(ctl_id_i.r2_en),
        .r2_addr_i(rs2_addr),
        .r2_data_o(id_ex_o.rs2_data)
    );

    // Decode to EX pipeline register
    always_ff @( posedge clk_i or negedge rstn_i ) begin : output_ff
        if (!rstn_i) begin
            id_ctl_o <= '0;
            id_ex_o <= '0;
        end
        else begin
            // decode to execute
            id_ex_o.imm     <= immediate;
            id_ex_o.rd_wen  <= ctl_id_i.rd_wen;
            id_ex_o.rd_addr <= rd_addr;
        end
    end

    // =========================== //
    //      Assigned Outputs
    // =========================== //
    // decode to control
    assign id_ctl_o.opcode = opcode;
    assign id_ctl_o.funct3 = funct3;
    assign id_ctl_o.funct7 = funct7;

    // decode to hazard detection
    assign id_hzd_o.rs1_addr = rs1_addr;
    assign id_hzd_o.rs2_addr = rs2_addr;

endmodule
