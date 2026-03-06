import rv_cpu_pkg::alu_op_e;
module alu
(
    // input op type
    input logic [3:0] op_i, // determines the ALU operation to be performed
    // input data
    input logic [31:0] srcA_i,
    input logic [31:0] srcB_i,
    // output result
    output logic [31:0] result_o
);
    // ALU is big combinational logic
    always_comb begin
        case (op_i)
            ALU_ADD:    result_o = srcA_i + srcB_i;
            ALU_SUB:    result_o = srcA_i - srcB_i;
            ALU_SLL:    result_o = srcA_i << srcB_i[4:0];
            ALU_SLT:    result_o = ($signed(srcA_i) < $signed(srcB_i)) ? 32'b1 : 32'b0;
            ALU_SLTU:   result_o = (srcA_i < srcB_i) ? 32'b1 : 32'b0;
            ALU_XOR:    result_o = srcA_i ^ srcB_i;
            ALU_SRL:    result_o = srcA_i >> srcB_i[4:0];
            ALU_SRA:    result_o = $signed(srcA_i) >>> srcB_i[4:0];
            ALU_OR:     result_o = srcA_i | srcB_i;
            ALU_AND:    result_o = srcA_i & srcB_i;
            ALU_NOP:    result_o = '0;
            default:    result_o = 'x;
        endcase
    end

endmodule
