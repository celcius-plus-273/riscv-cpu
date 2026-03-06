import rv_cpu_pkg::id_ctl_s;
import rv_cpu_pkg::ctl_id_s;
import rv_cpu_pkg::inst_type_e;
import rv_cpu_pkg::alu_op_e;

module control
#(
    parameter WORD_SIZE = 32
)
(
    // clock
    input logic     clk_i,
    // input logic     rstn_i,   // not needed?

    // Control Stage only talks to decode (interfaces will be inferred as wire)
    // - Pipeline is found in output of decode stage
    input id_ctl_s  id_ctl_i,       // control signals from the decode stage
    output ctl_id_s ctl_id_o        // control signals to the decode stage
);

    // ======================== //
    //        Variables
    // ======================== //
    inst_type_e inst_next;

    // opcode intermediate (wire)
    logic [6:0]     opcode;
    logic [2:0]     opcode_A;
    logic [1:0]     opcode_B;
    logic           inst_vld; // lower two bits of opcode must be 1 for vld

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

    // jump & branch control signals (wire)
    logic           is_branch;
    logic           is_jump;

    // ALU operation type signal
    alu_op_e        alu_op; // determines the ALU operation to be performed

    // ALU srcB control signal
    logic           alu_src; // second ALU operand: reg file vs immediate

    // break down the opcode into its different bits
    /**
     *  |   A: 3 bits  |   B: 2 bits  |   V: 2 bits  |
     *
     *  I (arithmetic): 001 + 00
     *  I (load): 000 + 00
     *  R: 011 + 00
     *  S: 010 + 00
     *  B: 110 + 00
     *  J:
     *      jal: 110 + 11
     *      jalr: 110 + 01 (I)
     *  U:
     *      auipc: 001 + 01
     *      lui: 011 + 01
    */
    always_comb begin : inst_type_decode
        // ------------------------- //
        //  Parallel Muxing Approach
        // ------------------------- //
        inst_next = X_inst; // default to X (invalid) instruction
        if (opcode_A == 3'b000) begin
            // all I-type instructions with opcode_A == 000 are load instructions
            inst_next = I_TYPE;
        end
        if (opcode_A == 3'b001) begin
            inst_next = (opcode_B == 2'b01) ? U_TYPE : I_TYPE; // auipc vs alu_imm
        end
        if (opcode_A == 3'b010) begin
            inst_next = S_TYPE;
        end
        if (opcode_A == 3'b011) begin
            inst_next = (opcode_B == 2'b01) ? U_TYPE : R_TYPE; // lui vs add/sub/and/or/xor
        end
        if (opcode_A == 3'b110) begin
            if (opcode_B == 2'b00) inst_next = B_TYPE; // conditional branches
            if (opcode_B == 2'b01) inst_next = I_TYPE; // jalr uses I-type format
            if (opcode_B == 2'b11) inst_next = J_TYPE; // jump
        end

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

        // There's definitely a better way to set this... but for now this will work
        // - taking advantage of blokcing assignments to override inst type :)
        if (!inst_vld) begin
            inst_next = INVALID;
        end
    end

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

    // Determine control signals based on instruction type
    always_comb begin : control_signal_gen
        // default values for control signals
        r1_en       = 1'b0;     // default to no register read
        r2_en       = 1'b0;     // default to no register read
        rd_wen      = 1'b0;     // default to no register writeback
        wb_src      = 2'b00;    // default to alu result writeback
        mem_rd_en   = 1'b0;     // default to no memory read
        mem_wr_en   = 1'b0;     // default to no memory write
        is_branch   = 1'b0;     // default to no branch
        is_jump     = 1'b0;     // default to no jump
        alu_src     = 1'b0;     // default to reg file operand
        case (inst_next)
            R_type: begin
                r1_en       = 1'b1; // R-type instructions always read from rs1
                r2_en       = 1'b1; // R-type instructions always read from rs2
                rd_wen      = 1'b1; // R-type writes to reg_dest
                wb_src      = 2'b00; // R-type writes alu result
                alu_src     = 1'b0; // R-type instructions use reg file operand
            end
            I_type: begin
                r1_en       = 1'b1; // I-type instructions always read from rs1
                r2_en       = 1'b0; // I-type instructions do not read from rs2
                rd_wen      = 1'b1; // I-type writes to reg_dest
                alu_src     = 1'b1; // I-type instructions use immediate operand

                // load instructions write mem result (opA == 3'b000)
                // arithmetic instructions write alu result
                wb_src      = (opcode_A == 3'b000) ? 2'b01 : 2'b00;

                // memory read enable for load instructions (opA == 3'b000)
                mem_rd_en   = (opcode_A == 3'b000) ? 1'b1 : 1'b0;

                // is_jump for jalr (opcode_A == 3'b110)
                is_jump     = (opcode_A == 3'b110) ? 1'b1 : 1'b0;

            end
            S_type: begin
                // store instructions
                r1_en       = 1'b1; // S-type instructions always read from rs1
                r2_en       = 1'b1; // S-type instructions always read from rs2 (data to be stored)
                rd_wen      = 1'b0; // S-type instructions do not write to reg_dest
                alu_src     = 1'b1; // S-type instructions use immediate operand for address calculation
                mem_wr_en   = 1'b1; // S-type instructions write to memory
            end
            B_type: begin
                r1_en       = 1'b1; // B-type instructions always read from rs1
                r2_en       = 1'b1; // B-type instructions always read from rs2
                rd_wen      = 1'b0; // B-type instructions do not write to reg_dest
                alu_src     = 1'b0; // B-type instructions use reg file operand for branch comparison
                is_branch   = 1'b1; // B-type instructions are branches
            end
            J_type: begin
                r1_en       = 1'b0; // J-type instructions do not read from rs1
                r2_en       = 1'b0; // J-type instructions do not read from rs2
                rd_wen      = 1'b1; // J-type instructions write to reg_dest (for jal)
                alu_src     = 1'b1; // J-type instructions use immediate operand for jump address calculation
                is_jump     = 1'b1; // J-type instructions are jumps
            end
            U_type: begin
                r1_en       = 1'b0; // U-type instructions do not read from rs1
                r2_en       = 1'b0; // U-type instructions do not read from rs2
                rd_wen      = 1'b1; // U-type instructions write to reg_dest
                alu_src     = 1'b1; // U-type instructions use immediate operand for address calculation
                wb_src      = 2'b00; // U-type writes alu result (which is just the immediate)
            end
            INVALID: begin
                // flush pipeline??
                $display("[Time: %0t] Invalid instruction detected", $time);
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
            end
        endcase
    end

    // determine alu operation type based on instruction type and funct fields
    always_comb begin : alu_op_gen
        case (inst_next)
            R_type: begin
                case (funct3)
                    3'b000: alu_op = (funct7[6] == 1'b1) ? ALU_SUB : ALU_ADD; // sub vs add
                    3'b001: alu_op = ALU_SLL; // sll
                    3'b010: alu_op = ALU_SLT; // slt
                    3'b011: alu_op = ALU_SLTU; // sltu
                    3'b100: alu_op = ALU_XOR; // xor
                    3'b101: alu_op = (funct7[6] == 1'b1) ? ALU_SRA : ALU_SRL; // sra vs srl
                    3'b110: alu_op = ALU_OR; // or
                    3'b111: alu_op = ALU_AND; // and
                    default: alu_op = ALU_INVALID;
                endcase
            end
            I_type: begin
                if (opcode_A == 3'b001) begin
                    // arithmetic immediate instructions
                    case (funct3)
                        3'b000: alu_op = ALU_ADD; // addi
                        3'b010: alu_op = ALU_SLT; // slti
                        3'b011: alu_op = ALU_SLTU; // sltiu
                        3'b100: alu_op = ALU_XOR; // xori
                        3'b110: alu_op = ALU_OR; // ori
                        3'b111: alu_op = ALU_AND; // andi
                        3'b001: alu_op = ALU_SLL; // slli
                        3'b101: alu_op = (funct7[6] == 1'b1) ? ALU_SRA : ALU_SRL; // srai vs srli
                        default: alu_op = ALU_INVALID;
                    endcase
                end
                else begin
                    // mem load uses add for address calculation
                    // jalr uses add for jump address calculation
                    alu_op = ALU_ADD;
                end
            end
            S_type: begin
                alu_op = ALU_ADD; // add for address calculation
            end
            B_type: begin
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
            J_type: begin
                alu_op = ALU_ADD; // jal uses add for jump address calculation
            end
            default: begin
                alu_op = ALU_X; // helps with debug :)
            end
        endcase
    end

    // Assigned Outputs (to Decode)
    assign ctl_id_o.inst_type   = inst_next;
    assign ctl_id_o.r1_en       = r1_en;
    assign ctl_id_o.r2_en       = r2_en;
    assign ctl_id_o.rd_wen      = rd_wen;
    assign ctl_id_o.wb_src      = wb_src;
    assign ctl_id_o.mem_rd_en   = mem_rd_en;
    assign ctl_id_o.mem_wr_en   = mem_wr_en;
    assign ctl_id_o.is_branch   = is_branch;
    assign ctl_id_o.is_jump     = is_jump;
    assign ctl_id_o.alu_src     = alu_src;
    assign ctl_id_o.alu_op      = alu_op;

endmodule
