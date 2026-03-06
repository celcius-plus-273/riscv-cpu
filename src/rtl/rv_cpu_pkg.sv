`ifndef RV_CPU_PKG
`define RV_CPU_PKG

package rv_cpu_pkg;

    // ============================== //
    //        Global Parameters
    // ============================== //
    parameter REG_FILE_DEPTH = 32;

    // derived parameters
    parameter RF_ADDR_WIDTH = $clog2(REG_FILE_DEPTH);

    // Enums
    typedef enum logic [3:0] {
        r_arith = 4'd1,
        i_arith = 4'd2,
        i_load  = 4'd3,
        i_jalr  = 4'd4,
        s_type  = 4'd5,
        b_type  = 4'd6,
        u_load  = 4'd7,
        u_pc    = 4'd8,
        j_type  = 4'd9,
        INVALID = 4'b1111,
        X_inst  = 4'bxxxx
    } inst_type_e;

    typedef enum logic [2:0] {
        IMM_none    = 3'd0,     // no immediate
        IMM_imm     = 3'd1,     // I-type immediate (sign-extended)
        IMM_uimm    = 3'd2,     // U-type immediate (upper 20 bits)
        IMM_upimm   = 3'd3,     // U-type immediate (upper 20 bits, shifted left by 12)
        IMM_simm    = 3'd4,     // S-type immediate (sign-extended, with bit 11 as sign bit)
        IMM_bimm    = 3'd5,     // B-type immediate (sign-extended, with bit 11 as sign bit)
        IMM_jimm    = 3'd6,     // J-type immediate (sign-extended, with bit 20 as sign bit)
        IMM_x       = 3'bxxx
    } imm_sel_e;

    typedef enum logic [3:0] {
        ALU_ADD     = 4'b0000,  // add
        ALU_SUB     = 4'b0001,  // sub
        ALU_SLL     = 4'b0010,  // shift left logical
        ALU_SLT     = 4'b0011,  // set less than
        ALU_SLTU    = 4'b0100,  // set less than unsigned
        ALU_XOR     = 4'b0101,  // xor
        ALU_SRL     = 4'b0110,  // shift right logical
        ALU_SRA     = 4'b0111,  // shift right arithmetic
        ALU_OR      = 4'b1000,  // or
        ALU_AND     = 4'b1001,  // and
        ALU_NOP     = 4'b1010,  // no operation
        ALU_INVALID = 4'b1111,
        ALU_X       = 4'bxxxx
    } alu_op_e;

    // ======================================= //
    //   Intermediate Signal Structs (Wire)
    // ======================================= //
    typedef struct packed {
        // Signals needed to:
        // - determine instruction type
        // - ALU operation type
        // - jump control signals
        logic [6:0]     opcode;
        logic [2:0]     funct3;
        logic [6:0]     funct7;
    } id_ctl_s;

    typedef struct packed {
        // immediate selection signal
        logic [2:0]     imm_sel;
        // control signals for reg file read enable
        logic           r1_en;
        logic           r2_en;
        // control signals for reg file write enable
        logic           rd_wen;
        logic [1:0]     wb_src;
        // determine ALU op type & srcB
        logic [3:0]     alu_op;
        logic           alu_src;
        // memory rd/wr control signals
        logic           mem_rd_en;
        logic           mem_wr_en;
        // jump & brach control signals
        logic           is_branch;
        logic           is_jump;
    } ctl_id_s;

    typedef struct packed {
        // Signals needed to:
        // - determine RAW hazards
        logic [4:0]     rs1_addr;
        logic [4:0]     rs2_addr;
    } id_hzd_s;

    typedef struct packed {
        // PC source sel
        logic           pc_src;     // 0 = PC + 4, 1 = branch/jump target
        logic [31:0]    pc_addr;    // branch/jump target address
    } ex_if_s;

    // ============================== //
    //        Pipelines (regs)
    // ============================== //
    typedef struct packed {
        logic [31:0]    inst;
        logic [31:0]    pc;
        logic [31:0]    pc_p4; // for link rd
    } if_id_s;

    typedef struct packed {
        // pc passthrough for branch target calculation
        logic [31:0]    pc;
        logic [31:0]    pc_p4; // for link rd

        // ALU control signals and data sources
        logic [31:0]    rs1_data;
        logic [31:0]    rs2_data;
        logic [31:0]    imm;
        logic [3:0]     alu_op;
        logic           alu_src;

        // memory rd/wr control signals
        logic           mem_rd_en;
        logic           mem_wr_en;

        // jump & brach control signals
        logic           is_branch;
        logic           is_jump;
        logic           is_jalr;    // special case for target addr calc

        // WB passthrough
        logic [1:0]     wb_src;
        logic           rd_wen;
        logic [4:0]     rd_addr;
    } id_ex_s;

    typedef struct packed {
        logic [31:0]    pc_p4; // for link rd
        logic [31:0]    alu_result;
        logic [31:0]    addr_result;

        // memory rd/wr control signals
        logic           mem_rd_en;
        logic           mem_wr_en;
        logic [31:0]    mem_wr_data; // from rs2_data

        // passthrough
        logic [1:0]     wb_src;
        logic           rd_wen;
        logic [4:0]     rd_addr;
    } ex_mem_s;

    typedef struct packed {
        // writeback
        logic           rd_wen;
        logic [4:0]     rd_addr;
        logic [31:0]    rd_data;
    } wb_id_s;

endpackage
`endif
