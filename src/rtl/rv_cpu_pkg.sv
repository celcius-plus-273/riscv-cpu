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
    typedef enum logic [2:0] {
        R_type  = 3'b000,
        I_type  = 3'b001,
        S_type  = 3'b010,
        B_type  = 3'b011,
        U_type  = 3'b100,
        J_type  = 3'b101,
        R4_type = 3'b110,   // what is this
        INVALID = 3'b111,
        X_inst  = 3'bxxx
    } inst_type_e;

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
        // Inst type needed to determine how to handle imm generation
        logic [2:0]     inst_type;
        // control signals for reg file read enable
        logic           r1_en;
        logic           r2_en;
        // control signals for reg file write enable
        logic           rd_wen;
        // determine ALU op type & srcB
        logic [3:0]     alu_op;
        logic           alu_src;
        logic [1:0]     wb_src;
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

    // ============================== //
    //        Pipelines (regs)
    // ============================== //
    typedef struct packed {
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

        // WB passthrough
        logic [1:0]     wb_src;
        logic           rd_wen;
        logic [4:0]     rd_addr;
    } id_ex_s;

    typedef struct packed {
        logic [31:0]    alu_result;

        // passthrough
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
