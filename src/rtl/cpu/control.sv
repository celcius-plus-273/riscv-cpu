// import rv_cpu_pkg::id_ctl_s;
// import rv_cpu_pkg::ctl_id_s;
// import rv_cpu_pkg::inst_type_e;
// import rv_cpu_pkg::imm_sel_e;
// import rv_cpu_pkg::alu_op_e;

module control
(
    // clock
    input logic     clk_i,
    // input logic     rstn_i,   // not needed?

    // Control Stage only talks to decode (interfaces will be inferred as wire)
    // - Pipeline is found in output of decode stage
    input id_ctl_s  id_ctl_i,       // control signals from the decode stage
    output ctl_id_s ctl_id_o        // control signals to the decode stage
);

    import rv_cpu_pkg::*;

    // ======================== //
    //        Variables
    // ======================== //
    inst_type_e inst_next;

    // opcode intermediate (wire)
    logic [6:0]     opcode;
    logic [2:0]     funct3;
    logic [6:0]     funct7;

    // Immediate select
    imm_sel_e       imm_sel; // determines how the immediate should be generated

    // reg file read enables (wire)
    logic           r1_en;
    logic           r2_en;
    // reg dest write enable (wire)
    logic           rd_wen;

    // wb_src
    logic [1:0]     wb_src; // determines what is written back (alu vs mem vs pc+4)

    // memory read/write enables (wire)
    logic           mem_rd_en;
    logic           mem_wr_en;
    // note that mask is one-hot byte encoded (bit[0] = byte 0, bit[1] = byte 1, etc.)
    logic [3:0]     mem_mask; // determines which bytes to enable for load/store
    logic           mem_signed; // signed vs unsinged load

    // jump & branch control signals (wire)
    logic           is_branch;
    logic           is_jump;
    logic           is_jalr;

    // ALU operation type signal
    alu_op_e        alu_op; // determines the ALU operation to be performed

    // ALU srcB control signal
    logic           alu_src; // second ALU operand: reg file vs immediate

    // break down the opcode into its different bits
    /**
     * ------------------------------------------------
     *                  OPCODE (7 bits)
     * ------------------------------------------------
     *  |   A: 3 bits  |   B: 2 bits  |   V: 2 bits  |
     * ------------------------------------------------
     *
     *             |  A |  B |  V |
     *  I (arith):  001 + 00 + 11   (19)
     *  I (load):   000 + 00 + 11   (03)
     *  I (jalr):   110 + 01 + 11   (103)
     *  R:          011 + 00 + 11   (51)
     *  S:          010 + 00 + 11   (35)
     *  B:          110 + 00 + 11   (99)
     *  J:
     *      jal:    110 + 11 + 11   (111)
     *  U:
     *      auipc:  001 + 01 + 11   (23)
     *      lui:    011 + 01 + 11   (55)
    */
    always_comb begin : inst_type_decode
        // ------------------------- //
        //  Parallel Muxing Approach
        // ------------------------- //
        inst_next = INVALID; // default to invalid instruction

        // R-type instructions have opcode 0110011 (51)
        if (opcode == 7'd51) inst_next = r_arith;

        // I-type arith instructions have opcode 0010011 (19)
        if (opcode == 7'd19) inst_next = i_arith;

        // I-type load instructions have opcode 0000011 (3)
        if (opcode == 7'd3) inst_next = i_load;

        // I-type jalr instruction has opcode 1100111 (103)
        if (opcode == 7'd103) inst_next = i_jalr;

        // S-type instructions have opcode 0100011 (35)
        if (opcode == 7'd35) inst_next = s_type;

        // B-type instructions have opcode 1100011 (99)
        if (opcode == 7'd99) inst_next = b_type;

        // J-type jal instruction has opcode 1101111 (111)
        if (opcode == 7'd111) inst_next = j_type;

        // U-type auipc instruction has opcode 0010111 (23)
        if (opcode == 7'd23) inst_next = u_pc;

        // U-type lui instruction has opcode 0110111 (55)
        if (opcode == 7'd55) inst_next = u_load;
    end

    // Determine control signals based on instruction type
    always_comb begin : control_signal_gen
        // default values for control signals
        r1_en       = 1'b0;     // default to no register read
        r2_en       = 1'b0;     // default to no register read
        rd_wen      = 1'b0;     // default to no register writeback
        wb_src      = 2'b00;    // default to alu result writeback
        mem_rd_en   = 1'b0;     // default to no memory read
        mem_wr_en   = 1'b0;     // default to no memory write
        mem_signed  = 1'b0;     // default to unsigned load
        mem_mask    = 4'b0000;  // default to no bytes enabled for memory access
        is_branch   = 1'b0;     // default to no branch
        is_jump     = 1'b0;     // default to no jump
        is_jalr     = 1'b0;     // default to no jalr (for special target address calculation)
        alu_src     = 1'b0;     // default to reg file operand
        alu_op      = ALU_INVALID; // default to invalid ALU operation
        imm_sel     = IMM_none; // default to no immediate
        case (inst_next)
            r_arith: begin
                r1_en       = 1'b1; // R-type instructions always read from rs1
                r2_en       = 1'b1; // R-type instructions always read from rs2
                rd_wen      = 1'b1; // R-type writes to reg_dest

                // ALU OP
                case (funct3)
                    3'b000: alu_op = (funct7[5] == 1'b1) ? ALU_SUB : ALU_ADD; // sub vs add
                    3'b001: alu_op = ALU_SLL; // sll
                    3'b010: alu_op = ALU_SLT; // slt
                    3'b011: alu_op = ALU_SLTU; // sltu
                    3'b100: alu_op = ALU_XOR; // xor
                    3'b101: alu_op = (funct7[5] == 1'b1) ? ALU_SRA : ALU_SRL; // sra vs srl
                    3'b110: alu_op = ALU_OR; // or
                    3'b111: alu_op = ALU_AND; // and
                    default: alu_op = ALU_INVALID;
                endcase
            end
            i_arith: begin
                r1_en       = 1'b1; // I-type instructions always read from rs1
                rd_wen      = 1'b1; // I-type writes to reg_dest
                alu_src     = 1'b1; // I-type instructions use immediate operand

                // immediate select (5 bits if shift op)
                imm_sel     = (funct3 == 3'b001 || funct3 == 3'b101) ? IMM_uimm : IMM_imm;

                // arithmetic immediate instructions
                case (funct3)
                    3'b000: alu_op = ALU_ADD; // addi
                    3'b010: alu_op = ALU_SLT; // slti
                    3'b011: alu_op = ALU_SLTU; // sltiu
                    3'b100: alu_op = ALU_XOR; // xori
                    3'b110: alu_op = ALU_OR; // ori
                    3'b111: alu_op = ALU_AND; // andi
                    3'b001: alu_op = ALU_SLL; // slli
                    3'b101: alu_op = (funct7[5] == 1'b1) ? ALU_SRA : ALU_SRL; // srai vs srli
                    default: alu_op = ALU_INVALID;
                endcase
            end
            i_load: begin
                r1_en       = 1'b1; // I-type instructions always read from rs1
                rd_wen      = 1'b1; // I-type writes to reg_dest
                alu_src     = 1'b1; // I-type instructions use immediate operand
                wb_src      = 2'b01;// I-type load writes memory data
                mem_rd_en   = 1'b1; // I-type load reads from memory
                alu_op      = ALU_ADD; // load uses add for address calculation
                imm_sel     = IMM_imm; // load uses I-type immediate

                case (funct3)
                    3'b000: begin
                        mem_mask = 4'b0001; // lb
                        mem_signed = 1'b1; // signed load
                    end
                    3'b001: begin
                        mem_mask = 4'b0011; // lh
                        mem_signed = 1'b1; // signed load
                    end
                    3'b010: begin
                        mem_mask = 4'b1111; // lw
                        mem_signed = 1'b1; // signed load
                    end
                    3'b100: begin
                        mem_mask = 4'b0001; // lbu
                        mem_signed = 1'b0; // unsigned load
                    end
                    3'b101: begin
                        mem_mask = 4'b0011; // lhu
                        mem_signed = 1'b0; // unsigned load
                    end
                    default: begin
                        mem_mask = 'x;
                        mem_signed = 'x;
                    end
                endcase
            end
            i_jalr: begin
                r1_en       = 1'b1; // I-type instructions always read from rs1
                rd_wen      = 1'b1; // I-type writes to reg_dest
                wb_src      = 2'b10;// I-type jalr writes pc+4
                alu_src     = 1'b1; // I-type instructions use immediate operand
                is_jump     = 1'b1; // jalr is a jump instruction
                is_jalr     = 1'b1; // used for special target addr calculation
                alu_op      = ALU_ADD; // jalr uses add for jump address calculation
                imm_sel     = IMM_imm; // jalr uses I-type immediate
            end
            s_type: begin
                // store instructions
                r1_en       = 1'b1; // S-type instructions always read from rs1
                r2_en       = 1'b1; // S-type instructions always read from rs2 (data to be stored)
                alu_src     = 1'b1; // S-type instructions use immediate operand for address calculation
                mem_wr_en   = 1'b1; // S-type instructions write to memory
                alu_op      = ALU_ADD; // S-type uses add for address calculation
                imm_sel     = IMM_simm; // S-type uses S-type immediate

                case (funct3)
                    3'b000: mem_mask = 4'b0001; // sb
                    3'b001: mem_mask = 4'b0011; // sh
                    3'b010: mem_mask = 4'b1111; // sw
                    default: mem_mask = 'x;
                endcase
            end
            b_type: begin
                r1_en       = 1'b1; // B-type instructions always read from rs1
                r2_en       = 1'b1; // B-type instructions always read from rs2
                is_branch   = 1'b1; // B-type instructions are branches
                imm_sel     = IMM_bimm; // B-type uses B-type immediate

                // branching ALU operations
                case (funct3)
                    3'b000: alu_op = ALU_SUB; // beq uses sub for comparison
                    3'b001: alu_op = ALU_SUB; // bne uses sub for comparison
                    3'b100: alu_op = ALU_SLT; // blt uses slt for comparison
                    3'b101: alu_op = ALU_SLT; // bge uses slt for comparison (with operands reversed in execute)
                    3'b110: alu_op = ALU_SLTU; // bltu uses sltu for comparison
                    3'b111: alu_op = ALU_SLTU; // bgeu uses sltu for comparison (with operands reversed in execute)
                    default: alu_op = ALU_INVALID;
                endcase
            end
            j_type: begin
                wb_src      = 2'b10;// J-type jal writes pc+4
                rd_wen      = 1'b1; // J-type instructions write to reg_dest (for jal)
                alu_src     = 1'b1; // J-type instructions use immediate operand for jump address calculation
                is_jump     = 1'b1; // J-type instructions are jumps
                alu_op      = ALU_ADD; // J-type uses add for jump address calculation
                imm_sel     = IMM_jimm; // J-type uses J-type immediate
            end
            u_load: begin
                rd_wen      = 1'b1; // U-type instructions write to reg_dest
                alu_src     = 1'b1; // U-type instructions use immediate operand for address calculation
                alu_op      = ALU_ADD; // U-type uses add for pc + upimm calculation
                imm_sel     = IMM_upimm; // upper immediate
            end
            u_pc: begin
                wb_src      = 2'b11;    // U-type auipc writes pc+immediate
                rd_wen      = 1'b1;     // U-type instructions write to reg_dest
                alu_src     = 1'b1;     // U-type instructions use immediate operand for address calculation
                alu_op      = ALU_NOP;  // no operation needed
                imm_sel     = IMM_upimm; // upper immediate
            end
            INVALID: begin
                // flush pipeline??
                // $display("[Time: %0t] Invalid instruction detected", $time);
            end
            default: begin
                r1_en       = 1'bx;
                r2_en       = 1'bx;
                rd_wen      = 1'bx;
                wb_src      = 'x;
                mem_rd_en   = 1'bx;
                mem_wr_en   = 1'bx;
                is_branch   = 1'bx;
                is_jump     = 1'bx;
                alu_src     = 1'bx;
                alu_op      = ALU_X;
                imm_sel     = IMM_x;
            end
        endcase
    end

    // Assigned inputs (from Decode)
    // I just got lazy and didn't want to replace it
    assign opcode = id_ctl_i.opcode;
    assign funct3 = id_ctl_i.funct3;
    assign funct7 = id_ctl_i.funct7;

    // Assigned Outputs (to Decode)
    assign ctl_id_o.imm_sel     = imm_sel;
    assign ctl_id_o.r1_en       = r1_en;
    assign ctl_id_o.r2_en       = r2_en;
    assign ctl_id_o.rd_wen      = rd_wen;
    assign ctl_id_o.wb_src      = wb_src;
    assign ctl_id_o.mem_rd_en   = mem_rd_en;
    assign ctl_id_o.mem_wr_en   = mem_wr_en;
    assign ctl_id_o.mem_mask    = mem_mask;
    assign ctl_id_o.mem_signed  = mem_signed;
    assign ctl_id_o.is_branch   = is_branch;
    assign ctl_id_o.is_jump     = is_jump;
    assign ctl_id_o.is_jalr     = is_jalr;
    assign ctl_id_o.alu_src     = alu_src;
    assign ctl_id_o.alu_op      = alu_op;

endmodule

    // ======================================================================== //
    //               What should we do with INVALID instructions???
    // ======================================================================== //
        // else begin
        //     // if isntruction didn't have a valid opcode then tag it as INVALID
        //     instruction_type <= INVALID;

        //     /**
        //      *  Invalid can be potentially used to detect errors in the pipeline
        //      *
        //      *  Note that it must never be the case that an invalid isntruction is detected
        //      *  unless it's intenttionally a bad instruction (NOP is not INVALID)
        //      *
        //      *  Could be trigger signal to flush the pipeline as it would mean that an instruction
        //      *  error is detected
        //     */

        //     //DEBUG PRINT
        //     $display("[Time: %0t] Got invalid instruction", $time);
        // end
    // ======================================================================== //

// ARCHIVE UNUSED
        // ------------------------- //
        //  Parallel Muxing Approach
        // ------------------------- //
        // if (opcode_A == 3'b000) begin
        //     // all I-type instructions with opcode_A == 000 are load instructions
        //     inst_next = I_type;
        // end
        // if (opcode_A == 3'b001) begin
        //     inst_next = (opcode_B == 2'b01) ? U_type : I_type; // auipc vs alu_imm
        // end
        // if (opcode_A == 3'b010) begin
        //     inst_next = S_type;
        // end
        // if (opcode_A == 3'b011) begin
        //     inst_next = (opcode_B == 2'b01) ? U_type : R_type; // lui vs add/sub/and/or/xor
        // end
        // if (opcode_A == 3'b110) begin
        //     if (opcode_B == 2'b00) inst_next = B_type; // conditional branches
        //     if (opcode_B == 2'b01) inst_next = I_type; // jalr uses I-type format
        //     if (opcode_B == 2'b11) inst_next = J_type; // jump
        // end
        // ------------------------- //
        //  Case Statement Approach
        // ------------------------- //
        // case (opcode_A)
        //     // I-type instruction
        //     3'b000: inst_next = I_TYPE; // load instructions
        //     3'b001: inst_next = (opcode_B == 2'b01) ? U_TYPE : I_TYPE; // auipc

        //     // S-type instruction
        //     3'b010: inst_next = S_TYPE;

        //     // R-type instruction
        //     3'b011: inst_next = (opcode_B == 2'b01) ? U_TYPE : R_TYPE; // lui

        //     // B-type and J-type instructions
        //     3'b110:
        //     begin
        //         case (opcode_B)
        //             2'b00: inst_next = B_TYPE; // conditional branches
        //             2'b01: inst_next = I_TYPE; // jalr uses I-type format
        //             2'b11: inst_next = J_TYPE; // jump instructions
        //         endcase
        //     end
        //     default: inst_next = X_inst;
        // endcase
