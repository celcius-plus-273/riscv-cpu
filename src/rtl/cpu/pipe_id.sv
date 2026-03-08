// ============================== //
//         Package Imports
// ============================== //
// // Wire Interfaces
// import rv_cpu_pkg::id_ctl_s;    // decode to control
// import rv_cpu_pkg::ctl_id_s;    // control to decode
// import rv_cpu_pkg::id_hzd_s;    // decode to hazard

// // Pipeline Registers
// import rv_cpu_pkg::if_id_s;    // IF to ID interface
// import rv_cpu_pkg::id_ex_s;
// import rv_cpu_pkg::wb_id_s;

// // Enums
// import rv_cpu_pkg::imm_sel_e;

module pipe_id
#(
    // parameters
    parameter int RF_DEPTH = 32    // reg file depth

    // derived parameters
    // localparam int RF_ADDR_WIDTH = $clog2(RF_DEPTH)
)
(
    // clk and rst
    input logic         clk_i,
    input logic         rstn_i,

    // input flush (control hazard detection)
    input logic         flush_i,

    // Control Stage Interfaces (wire)
    input ctl_id_s      ctl_id_i,   // Control to ID Interface
    output id_ctl_s     id_ctl_o,   // ID to Control Interface

    // Hazard Detection Interfaces (wire)
    output id_hzd_s    id_hzd_o,   // ID to Hazard Detection Interface

    // Decode Stage Interfaces (pipeline registers)
    input if_id_s       if_id_i,    // IF to ID interface
    input wb_id_s       wb_id_i,    // WB to ID interface
    output id_ex_s      id_ex_o     // ID to EX Interface
);

    import rv_cpu_pkg::*;
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
    logic [6:0]     opcode;     // opcode field of the instruction (for control)

    // inst_i becuase I am too lazy to change all of the references
    logic [31:0]    inst_i;     // instruction input from IF stage (assigned from if_id_i)

    // reg file read (wire)
    logic [4:0]     rs1_addr;
    logic [4:0]     rs2_addr;

    // decoded immediate and funct fields (wire)
    logic [6:0]     funct7;
    logic [2:0]     funct3;

    // Decode all immediate combinations
    logic [11:0]    imm;    // signed immediate   [12 bits]
    logic [4:0]     uimm;   // unsigned immediate [5 bits]
    logic [19:0]    upimm;  // upper immediate    [20 bits]
    logic [11:0]    st_imm; // store immediate    [12 bits]
    logic [11:0]    bta_imm; // branch target imm [12 bits]
    logic [19:0]    jta_imm; // jump target imm   [20 bits]

    // immediate for ex stage
    logic [31:0]    imm_next;

    // decoded reg dest (wire)
    logic [4:0]     rd_addr; // reg_dest addr

    always_comb begin : static_inst_decode
        // opcode decode
        opcode      = inst_i[6:0];

        // register addr decode
        rs1_addr    = inst_i[19:15];
        rs2_addr    = inst_i[24:20];
        rd_addr     = inst_i[11:7];

        // funct 3 & funct 7
        funct3      = inst_i[14:12];    // do we want to gate this?
        funct7      = inst_i[31:25];    // do we want to gate this?

        // immediate decode
        imm         = inst_i[31:20];
        uimm        = inst_i[24:20];
        upimm       = inst_i[31:12];
        st_imm      = {inst_i[31:25], inst_i[11:7]};    // store immediate value

        // BTA Immediate Value
        // inst[31:25] = imm[12], imm[10:5]
        // inst[11:7] = imm[4:1], imm[11]
        bta_imm     = {inst_i[31], inst_i[7], inst_i[30:25], inst_i[11:8]};

        // JTA Immediate Value
        // inst[31:12] = imm[20], imm[10:1], imm[11], imm[19:12]
        jta_imm     = {inst_i[31], inst_i[19:12], inst_i[20], inst_i[30:21]};
    end

    // decode immediate value based on instruction type
    always_comb begin : immediate_decode
        case (ctl_id_i.imm_sel)
            IMM_none: begin
                imm_next = '0;
            end
            IMM_imm: begin
                imm_next = { {20{imm[11]}}, imm};
            end
            IMM_uimm: begin
                imm_next = { {27{1'b0}}, uimm};
            end
            IMM_upimm: begin
                imm_next = { upimm, 12'b0};
            end
            IMM_simm: begin
                imm_next = { {20{st_imm[11]}}, st_imm};
            end
            IMM_bimm: begin
                imm_next = { {19{bta_imm[11]}}, bta_imm, 1'b0};
            end
            IMM_jimm: begin
                imm_next = { {11{jta_imm[19]}}, jta_imm, 1'b0};
            end
            default: begin
                imm_next   = 'x;
            end
        endcase
    end

    // instantiate the register file
    reg_file #(
        .WIDTH(32),
        .DEPTH(RF_DEPTH)
    ) reg_file_inst (
        // clk, rst
        .clk_i(clk_i),
        .rstn_i(rstn_i),

        // Edge Case
        // - there is a scenario where r1 and r2 and enabled and data is read from RF
        // - however, because all control signals are cleared on a flush, this data is just
        //   bubbling through the pipeline and will not do anything... it will consume power though
        // .en_i(~flush_i),

        // write port (connected to writeback stage)
        .wen_i(wb_id_i.rd_wen),
        .w_addr(wb_id_i.rd_addr),
        .w_data(wb_id_i.rd_data),

        // read ports
        // - data goes to execute stage
        // - src addr (and enable) comes from decode
        .r1_en_i(ctl_id_i.r1_en),
        .r1_addr_i(rs1_addr),
        .r1_data_o(id_ex_o.rs1_data),   // might propagate data even on a flush...
        .r2_en_i(ctl_id_i.r2_en),
        .r2_addr_i(rs2_addr),
        .r2_data_o(id_ex_o.rs2_data)    // might propagate data even on a flush...
    );

    // Decode to EX pipeline register
    always_ff @( posedge clk_i or negedge rstn_i ) begin : output_ff
        if (~rstn_i | flush_i) begin
            id_ex_o.pc          <= '0;
            id_ex_o.pc_p4       <= '0;
            id_ex_o.imm         <= '0;
            id_ex_o.alu_op      <= '0;
            id_ex_o.alu_src     <= '0;
            id_ex_o.r1_en       <= '0;
            id_ex_o.r2_en       <= '0;
            id_ex_o.rs1_addr    <= '0;
            id_ex_o.rs2_addr    <= '0;
            id_ex_o.mem_rd_en   <= '0;
            id_ex_o.mem_wr_en   <= '0;
            id_ex_o.mem_mask    <= '0;
            id_ex_o.mem_signed  <= '0;
            id_ex_o.is_branch   <= '0;
            id_ex_o.branch_sign <= '0;
            id_ex_o.is_jump     <= '0;
            id_ex_o.is_jalr     <= '0;
            id_ex_o.wb_src      <= '0;
            id_ex_o.rd_wen      <= '0;
            id_ex_o.rd_addr     <= '0;
        end
        else begin
            // decode to execute
            id_ex_o.pc         <= if_id_i.pc;
            id_ex_o.pc_p4      <= if_id_i.pc_p4;

            id_ex_o.imm         <= imm_next;
            id_ex_o.alu_op      <= ctl_id_i.alu_op;
            id_ex_o.alu_src     <= ctl_id_i.alu_src;

            id_ex_o.r1_en       <= ctl_id_i.r1_en;
            id_ex_o.r2_en       <= ctl_id_i.r2_en;
            id_ex_o.rs1_addr    <= rs1_addr;
            id_ex_o.rs2_addr    <= rs2_addr;

            id_ex_o.mem_rd_en   <= ctl_id_i.mem_rd_en;
            id_ex_o.mem_wr_en   <= ctl_id_i.mem_wr_en;
            id_ex_o.mem_mask    <= ctl_id_i.mem_mask;
            id_ex_o.mem_signed  <= ctl_id_i.mem_signed;

            id_ex_o.is_branch   <= ctl_id_i.is_branch;
            id_ex_o.branch_sign <= ctl_id_i.branch_sign;
            id_ex_o.is_jump     <= ctl_id_i.is_jump;
            id_ex_o.is_jalr     <= ctl_id_i.is_jalr;
            id_ex_o.wb_src      <= ctl_id_i.wb_src;
            id_ex_o.rd_wen      <= ctl_id_i.rd_wen;
            id_ex_o.rd_addr     <= rd_addr;
        end
    end

    // Assigned Inputs
    assign inst_i = if_id_i.inst;

    // =========================== //
    //      Assigned Outputs
    // =========================== //
    // decode to control
    assign id_ctl_o.opcode = opcode;
    assign id_ctl_o.funct3 = funct3;
    assign id_ctl_o.funct7 = funct7;

    // decode to hazard detection
    assign id_hzd_o.r1_en    = ctl_id_i.r1_en;
    assign id_hzd_o.r2_en    = ctl_id_i.r2_en;
    assign id_hzd_o.rs1_addr = rs1_addr;
    assign id_hzd_o.rs2_addr = rs2_addr;

endmodule
