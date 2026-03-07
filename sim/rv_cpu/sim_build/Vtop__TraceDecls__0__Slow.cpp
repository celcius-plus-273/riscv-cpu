// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations
#include "verilated_fst_c.h"


void Vtop___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"r_arith", "i_arith", "i_load", "i_jalr", 
                                "s_type", "b_type", 
                                "u_load", "u_pc", "j_type", 
                                "INVALID", "X_inst"};
        const char* __VenumItemValues[]
        = {"1", "10", "11", "100", "101", "110", "111", 
                                "1000", "1001", "1111", 
                                "xxxx"};
        tracep->declDTypeEnum(1, "rv_cpu_pkg::inst_type_e", 11, 4, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"IMM_none", "IMM_imm", "IMM_uimm", "IMM_upimm", 
                                "IMM_simm", "IMM_bimm", 
                                "IMM_jimm", "IMM_x"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110", 
                                "xxx"};
        tracep->declDTypeEnum(2, "rv_cpu_pkg::imm_sel_e", 8, 3, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"ALU_ADD", "ALU_SUB", "ALU_SLL", "ALU_SLT", 
                                "ALU_SLTU", "ALU_XOR", 
                                "ALU_SRL", "ALU_SRA", 
                                "ALU_OR", "ALU_AND", 
                                "ALU_NOP", "ALU_INVALID", 
                                "ALU_X"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110", 
                                "111", "1000", "1001", 
                                "1010", "1111", "xxxx"};
        tracep->declDTypeEnum(3, "rv_cpu_pkg::alu_op_e", 13, 4, __VenumItemNames, __VenumItemValues);
    }
}

void Vtop___024root__trace_decl_types(VerilatedFst* tracep) {
    Vtop___024root__traceDeclTypesSub0(tracep);
}
