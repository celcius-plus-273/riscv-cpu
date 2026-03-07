// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__rv_cpu_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"riscv_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("rv_cpu_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__rv_cpu_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("rv_cpu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+4,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"riscv_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("id_ctl_w", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+7,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+8,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+9,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("ctl_id_w", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+10,0,"imm_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+11,0,"r1_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"r2_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"rd_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+14,0,"wb_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+15,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+16,0,"alu_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"mem_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"mem_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"mem_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+20,0,"mem_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"is_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"is_jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("id_hzd_w", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+24,0,"rs1_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+25,0,"rs2_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("ex_if_w", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+26,0,"pc_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"pc_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("wb_id_w", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+28,0,"rd_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+29,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+30,0,"rd_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("if_id_w", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+31,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"pc_p4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("id_ex_w", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+34,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"pc_p4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+40,0,"alu_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"mem_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"mem_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+43,0,"mem_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+44,0,"mem_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"is_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"is_jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"wb_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+49,0,"rd_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("ex_mem_w", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+51,0,"pc_p4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"addr_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+54,0,"mem_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"mem_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+56,0,"mem_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+57,0,"mem_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"mem_wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"wb_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+60,0,"rd_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+61,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("mem_wb_w", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+62,0,"pc_p4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"addr_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+65,0,"mem_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+66,0,"mem_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"mem_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+68,0,"mem_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"wb_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+70,0,"rd_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+71,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("control_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+72,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("id_ctl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+73,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+74,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+75,0,"funct7",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("ctl_id_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+76,0,"imm_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+77,0,"r1_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"r2_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"rd_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"wb_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+81,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+82,0,"alu_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"mem_rd_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"mem_wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+85,0,"mem_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+86,0,"mem_signed",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"is_branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"is_jump",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"is_jalr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBus(c+90,0,"inst_next",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+91,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+92,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+93,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+94,0,"imm_sel",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+95,0,"r1_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"r2_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"rd_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"wb_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+99,0,"mem_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"mem_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"mem_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+102,0,"mem_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"is_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"is_jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"alu_op",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+107,0,"alu_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("decode_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+316,0,"RF_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+108,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("ctl_id_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+110,0,"imm_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+111,0,"r1_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"r2_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"rd_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+114,0,"wb_src",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+115,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+116,0,"alu_src",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"mem_rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"mem_wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"mem_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+120,0,"mem_signed",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"is_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"is_jump",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"is_jalr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("id_ctl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+124,0,"opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+125,0,"funct3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+126,0,"funct7",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("id_hzd_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+127,0,"rs1_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+128,0,"rs2_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("if_id_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+129,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"pc_p4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("wb_id_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+132,0,"rd_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+133,0,"rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+134,0,"rd_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("id_ex_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+135,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"pc_p4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"rs1_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+140,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+141,0,"alu_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"mem_rd_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"mem_wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"mem_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+145,0,"mem_signed",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"is_branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+147,0,"is_jump",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+148,0,"is_jalr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+149,0,"wb_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+150,0,"rd_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+151,0,"rd_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->declBus(c+152,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+153,0,"inst_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+154,0,"rs1_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+155,0,"rs2_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+156,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+157,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+158,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+159,0,"uimm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+160,0,"upimm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 19,0);
    tracep->declBus(c+161,0,"st_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+162,0,"bta_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+163,0,"jta_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 19,0);
    tracep->declBus(c+164,0,"imm_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+165,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("reg_file_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+317,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+317,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+166,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+167,0,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+168,0,"wen_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+169,0,"w_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"w_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+171,0,"r1_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+172,0,"r1_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"r1_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+174,0,"r2_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+175,0,"r2_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"r2_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("mem", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+177+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("write_ff", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+209,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("execute_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+210,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+211,0,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("ex_if_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+212,0,"pc_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+213,0,"pc_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("id_ex_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+214,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+215,0,"pc_p4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+216,0,"rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+217,0,"rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+218,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+219,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+220,0,"alu_src",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+221,0,"mem_rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+222,0,"mem_wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"mem_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+224,0,"mem_signed",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+225,0,"is_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+226,0,"is_jump",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"is_jalr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+228,0,"wb_src",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+229,0,"rd_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+230,0,"rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("ex_mem_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+231,0,"pc_p4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+232,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+233,0,"addr_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+234,0,"mem_rd_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+235,0,"mem_wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+236,0,"mem_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+237,0,"mem_signed",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+238,0,"mem_wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+239,0,"wb_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+240,0,"rd_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+241,0,"rd_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->declBus(c+242,0,"alu_srcA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+243,0,"alu_srcB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+244,0,"alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+245,0,"pc_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+246,0,"pc_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+247,0,"addr_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("alu_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+248,0,"op_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+249,0,"srcA_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+250,0,"srcB_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+251,0,"result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("fetch_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+318,0,"I_MEM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+252,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("ex_if_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+255,0,"pc_src",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+256,0,"pc_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("if_id_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+257,0,"inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+258,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+259,0,"pc_p4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBus(c+260,0,"pc_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+261,0,"pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("i_reg_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+318,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+262,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+264,0,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+265,0,"pc_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+266,0,"inst_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+319,0,"NUM_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("memory_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+320,0,"D_MEM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+321,0,"D_MEM_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+267,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+268,0,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("ex_mem_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+269,0,"pc_p4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+270,0,"alu_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+271,0,"addr_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+272,0,"mem_rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+273,0,"mem_wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+274,0,"mem_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+275,0,"mem_signed",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+276,0,"mem_wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+277,0,"wb_src",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+278,0,"rd_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+279,0,"rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("mem_wb_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+280,0,"pc_p4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+281,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+282,0,"addr_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+283,0,"mem_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+284,0,"mem_rd_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+285,0,"mem_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+286,0,"mem_signed",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+287,0,"wb_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+288,0,"rd_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+289,0,"rd_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("sram_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+320,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+317,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+319,0,"NUM_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+321,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+290,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,0,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,0,"cenb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+293,0,"wenb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+294,0,"mask_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+295,0,"addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+296,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+297,0,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+298,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("writeback_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+299,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+300,0,"rstn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("mem_wb_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+301,0,"pc_p4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+302,0,"alu_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"addr_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+304,0,"mem_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+305,0,"mem_rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+306,0,"mem_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+307,0,"mem_signed",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+308,0,"wb_src",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+309,0,"rd_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+310,0,"rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("wb_id_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+311,0,"rd_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+312,0,"rd_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+313,0,"rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->declBus(c+314,0,"mem_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+315,0,"mem_data_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__rv_cpu_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__rv_cpu_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+317,0,"REG_FILE_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+318,0,"I_MEM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+320,0,"D_MEM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+322,0,"RF_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+323,0,"I_MEM_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+321,0,"D_MEM_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+316,(0x20U),32);
    bufp->fullIData(oldp+317,(0x20U),32);
    bufp->fullIData(oldp+318,(0x40U),32);
    bufp->fullIData(oldp+319,(4U),32);
    bufp->fullIData(oldp+320,(0x100U),32);
    bufp->fullIData(oldp+321,(8U),32);
    bufp->fullIData(oldp+322,(5U),32);
    bufp->fullIData(oldp+323,(6U),32);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.clk_i));
    bufp->fullBit(oldp+2,(vlSelfRef.rstn_i));
    bufp->fullBit(oldp+3,(vlSelfRef.riscv_en_i));
    bufp->fullBit(oldp+4,(vlSelfRef.rv_cpu__DOT__clk_i));
    bufp->fullBit(oldp+5,(vlSelfRef.rv_cpu__DOT__rstn_i));
    bufp->fullBit(oldp+6,(vlSelfRef.rv_cpu__DOT__riscv_en_i));
    bufp->fullCData(oldp+7,((0x7fU & (vlSelfRef.rv_cpu__DOT__id_ctl_w 
                                      >> 0xaU))),7);
    bufp->fullCData(oldp+8,((7U & (vlSelfRef.rv_cpu__DOT__id_ctl_w 
                                   >> 7U))),3);
    bufp->fullCData(oldp+9,((0x7fU & vlSelfRef.rv_cpu__DOT__id_ctl_w)),7);
    bufp->fullCData(oldp+10,((7U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                    >> 0x14U))),3);
    bufp->fullBit(oldp+11,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                  >> 0x13U))));
    bufp->fullBit(oldp+12,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                  >> 0x12U))));
    bufp->fullBit(oldp+13,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                  >> 0x11U))));
    bufp->fullCData(oldp+14,((3U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                    >> 0xfU))),2);
    bufp->fullCData(oldp+15,((0xfU & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                      >> 0xbU))),4);
    bufp->fullBit(oldp+16,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                  >> 0xaU))));
    bufp->fullBit(oldp+17,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                  >> 9U))));
    bufp->fullBit(oldp+18,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                  >> 8U))));
    bufp->fullCData(oldp+19,((0xfU & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                      >> 4U))),4);
    bufp->fullBit(oldp+20,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                  >> 3U))));
    bufp->fullBit(oldp+21,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                  >> 2U))));
    bufp->fullBit(oldp+22,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                  >> 1U))));
    bufp->fullBit(oldp+23,((1U & vlSelfRef.rv_cpu__DOT__ctl_id_w)));
    bufp->fullCData(oldp+24,((0x1fU & ((IData)(vlSelfRef.rv_cpu__DOT__id_hzd_w) 
                                       >> 5U))),5);
    bufp->fullCData(oldp+25,((0x1fU & (IData)(vlSelfRef.rv_cpu__DOT__id_hzd_w))),5);
    bufp->fullBit(oldp+26,((1U & (IData)((vlSelfRef.rv_cpu__DOT__ex_if_w 
                                          >> 0x20U)))));
    bufp->fullIData(oldp+27,((IData)(vlSelfRef.rv_cpu__DOT__ex_if_w)),32);
    bufp->fullBit(oldp+28,((1U & (IData)((vlSelfRef.rv_cpu__DOT__wb_id_w 
                                          >> 0x25U)))));
    bufp->fullCData(oldp+29,((0x1fU & (IData)((vlSelfRef.rv_cpu__DOT__wb_id_w 
                                               >> 0x20U)))),5);
    bufp->fullIData(oldp+30,((IData)(vlSelfRef.rv_cpu__DOT__wb_id_w)),32);
    bufp->fullIData(oldp+31,(vlSelfRef.rv_cpu__DOT__if_id_w[2U]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.rv_cpu__DOT__if_id_w[1U]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.rv_cpu__DOT__if_id_w[0U]),32);
    bufp->fullIData(oldp+34,(((vlSelfRef.rv_cpu__DOT__id_ex_w[5U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__id_ex_w[4U] 
                                         >> 0x17U))),32);
    bufp->fullIData(oldp+35,(((vlSelfRef.rv_cpu__DOT__id_ex_w[4U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__id_ex_w[3U] 
                                         >> 0x17U))),32);
    bufp->fullIData(oldp+36,(((vlSelfRef.rv_cpu__DOT__id_ex_w[3U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__id_ex_w[2U] 
                                         >> 0x17U))),32);
    bufp->fullIData(oldp+37,(((vlSelfRef.rv_cpu__DOT__id_ex_w[2U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__id_ex_w[1U] 
                                         >> 0x17U))),32);
    bufp->fullIData(oldp+38,(((vlSelfRef.rv_cpu__DOT__id_ex_w[1U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                         >> 0x17U))),32);
    bufp->fullCData(oldp+39,((0xfU & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                      >> 0x13U))),4);
    bufp->fullBit(oldp+40,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                  >> 0x12U))));
    bufp->fullBit(oldp+41,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                  >> 0x11U))));
    bufp->fullBit(oldp+42,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                  >> 0x10U))));
    bufp->fullCData(oldp+43,((0xfU & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                      >> 0xcU))),4);
    bufp->fullBit(oldp+44,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                  >> 0xbU))));
    bufp->fullBit(oldp+45,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                  >> 0xaU))));
    bufp->fullBit(oldp+46,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                  >> 9U))));
    bufp->fullBit(oldp+47,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                  >> 8U))));
    bufp->fullCData(oldp+48,((3U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                    >> 6U))),2);
    bufp->fullBit(oldp+49,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                  >> 5U))));
    bufp->fullCData(oldp+50,((0x1fU & vlSelfRef.rv_cpu__DOT__id_ex_w[0U])),5);
    bufp->fullIData(oldp+51,(((vlSelfRef.rv_cpu__DOT__ex_mem_w[4U] 
                               << 0x11U) | (vlSelfRef.rv_cpu__DOT__ex_mem_w[3U] 
                                            >> 0xfU))),32);
    bufp->fullIData(oldp+52,(((vlSelfRef.rv_cpu__DOT__ex_mem_w[3U] 
                               << 0x11U) | (vlSelfRef.rv_cpu__DOT__ex_mem_w[2U] 
                                            >> 0xfU))),32);
    bufp->fullIData(oldp+53,(((vlSelfRef.rv_cpu__DOT__ex_mem_w[2U] 
                               << 0x11U) | (vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] 
                                            >> 0xfU))),32);
    bufp->fullBit(oldp+54,((1U & (vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] 
                                  >> 0xeU))));
    bufp->fullBit(oldp+55,((1U & (vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] 
                                  >> 0xdU))));
    bufp->fullCData(oldp+56,((0xfU & (vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] 
                                      >> 9U))),4);
    bufp->fullBit(oldp+57,((1U & (vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] 
                                  >> 8U))));
    bufp->fullIData(oldp+58,(((vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] 
                               << 0x18U) | (vlSelfRef.rv_cpu__DOT__ex_mem_w[0U] 
                                            >> 8U))),32);
    bufp->fullCData(oldp+59,((3U & (vlSelfRef.rv_cpu__DOT__ex_mem_w[0U] 
                                    >> 6U))),2);
    bufp->fullBit(oldp+60,((1U & (vlSelfRef.rv_cpu__DOT__ex_mem_w[0U] 
                                  >> 5U))));
    bufp->fullCData(oldp+61,((0x1fU & vlSelfRef.rv_cpu__DOT__ex_mem_w[0U])),5);
    bufp->fullIData(oldp+62,(((vlSelfRef.rv_cpu__DOT__mem_wb_w[4U] 
                               << 0x12U) | (vlSelfRef.rv_cpu__DOT__mem_wb_w[3U] 
                                            >> 0xeU))),32);
    bufp->fullIData(oldp+63,(((vlSelfRef.rv_cpu__DOT__mem_wb_w[3U] 
                               << 0x12U) | (vlSelfRef.rv_cpu__DOT__mem_wb_w[2U] 
                                            >> 0xeU))),32);
    bufp->fullIData(oldp+64,(((vlSelfRef.rv_cpu__DOT__mem_wb_w[2U] 
                               << 0x12U) | (vlSelfRef.rv_cpu__DOT__mem_wb_w[1U] 
                                            >> 0xeU))),32);
    bufp->fullIData(oldp+65,(((vlSelfRef.rv_cpu__DOT__mem_wb_w[1U] 
                               << 0x12U) | (vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] 
                                            >> 0xeU))),32);
    bufp->fullBit(oldp+66,((1U & (vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] 
                                  >> 0xdU))));
    bufp->fullCData(oldp+67,((0xfU & (vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] 
                                      >> 9U))),4);
    bufp->fullBit(oldp+68,((1U & (vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] 
                                  >> 8U))));
    bufp->fullCData(oldp+69,((3U & (vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] 
                                    >> 6U))),2);
    bufp->fullBit(oldp+70,((1U & (vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] 
                                  >> 5U))));
    bufp->fullCData(oldp+71,((0x1fU & vlSelfRef.rv_cpu__DOT__mem_wb_w[0U])),5);
    bufp->fullBit(oldp+72,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__clk_i));
    bufp->fullCData(oldp+73,((0x7fU & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i 
                                       >> 0xaU))),7);
    bufp->fullCData(oldp+74,((7U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i 
                                    >> 7U))),3);
    bufp->fullCData(oldp+75,((0x7fU & vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i)),7);
    bufp->fullCData(oldp+76,((7U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                    >> 0x14U))),3);
    bufp->fullBit(oldp+77,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                  >> 0x13U))));
    bufp->fullBit(oldp+78,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                  >> 0x12U))));
    bufp->fullBit(oldp+79,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                  >> 0x11U))));
    bufp->fullCData(oldp+80,((3U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                    >> 0xfU))),2);
    bufp->fullCData(oldp+81,((0xfU & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                      >> 0xbU))),4);
    bufp->fullBit(oldp+82,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                  >> 0xaU))));
    bufp->fullBit(oldp+83,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                  >> 9U))));
    bufp->fullBit(oldp+84,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                  >> 8U))));
    bufp->fullCData(oldp+85,((0xfU & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                      >> 4U))),4);
    bufp->fullBit(oldp+86,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                  >> 3U))));
    bufp->fullBit(oldp+87,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                  >> 2U))));
    bufp->fullBit(oldp+88,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                  >> 1U))));
    bufp->fullBit(oldp+89,((1U & vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o)));
    bufp->fullCData(oldp+90,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next),4);
    bufp->fullCData(oldp+91,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode),7);
    bufp->fullCData(oldp+92,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3),3);
    bufp->fullCData(oldp+93,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct7),7);
    bufp->fullCData(oldp+94,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel),3);
    bufp->fullBit(oldp+95,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en));
    bufp->fullBit(oldp+96,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en));
    bufp->fullBit(oldp+97,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen));
    bufp->fullCData(oldp+98,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src),2);
    bufp->fullBit(oldp+99,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en));
    bufp->fullBit(oldp+100,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en));
    bufp->fullCData(oldp+101,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_mask),4);
    bufp->fullBit(oldp+102,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_signed));
    bufp->fullBit(oldp+103,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch));
    bufp->fullBit(oldp+104,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump));
    bufp->fullBit(oldp+105,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jalr));
    bufp->fullCData(oldp+106,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op),4);
    bufp->fullBit(oldp+107,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src));
    bufp->fullBit(oldp+108,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__clk_i));
    bufp->fullBit(oldp+109,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rstn_i));
    bufp->fullCData(oldp+110,((7U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                     >> 0x14U))),3);
    bufp->fullBit(oldp+111,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                   >> 0x13U))));
    bufp->fullBit(oldp+112,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                   >> 0x12U))));
    bufp->fullBit(oldp+113,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                   >> 0x11U))));
    bufp->fullCData(oldp+114,((3U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                     >> 0xfU))),2);
    bufp->fullCData(oldp+115,((0xfU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                       >> 0xbU))),4);
    bufp->fullBit(oldp+116,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                   >> 0xaU))));
    bufp->fullBit(oldp+117,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                   >> 9U))));
    bufp->fullBit(oldp+118,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                   >> 8U))));
    bufp->fullCData(oldp+119,((0xfU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                       >> 4U))),4);
    bufp->fullBit(oldp+120,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                   >> 3U))));
    bufp->fullBit(oldp+121,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                   >> 2U))));
    bufp->fullBit(oldp+122,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                   >> 1U))));
    bufp->fullBit(oldp+123,((1U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)));
    bufp->fullCData(oldp+124,((0x7fU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ctl_o 
                                        >> 0xaU))),7);
    bufp->fullCData(oldp+125,((7U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ctl_o 
                                     >> 7U))),3);
    bufp->fullCData(oldp+126,((0x7fU & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ctl_o)),7);
    bufp->fullCData(oldp+127,((0x1fU & ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_hzd_o) 
                                        >> 5U))),5);
    bufp->fullCData(oldp+128,((0x1fU & (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_hzd_o))),5);
    bufp->fullIData(oldp+129,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[2U]),32);
    bufp->fullIData(oldp+130,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[1U]),32);
    bufp->fullIData(oldp+131,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[0U]),32);
    bufp->fullBit(oldp+132,((1U & (IData)((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i 
                                           >> 0x25U)))));
    bufp->fullCData(oldp+133,((0x1fU & (IData)((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i 
                                                >> 0x20U)))),5);
    bufp->fullIData(oldp+134,((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i)),32);
    bufp->fullIData(oldp+135,(((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U] 
                                << 9U) | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U] 
                                          >> 0x17U))),32);
    bufp->fullIData(oldp+136,(((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U] 
                                << 9U) | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
                                          >> 0x17U))),32);
    bufp->fullIData(oldp+137,(((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
                                << 9U) | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U] 
                                          >> 0x17U))),32);
    bufp->fullIData(oldp+138,(((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U] 
                                << 9U) | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
                                          >> 0x17U))),32);
    bufp->fullIData(oldp+139,(((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
                                << 9U) | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                          >> 0x17U))),32);
    bufp->fullCData(oldp+140,((0xfU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                       >> 0x13U))),4);
    bufp->fullBit(oldp+141,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                   >> 0x12U))));
    bufp->fullBit(oldp+142,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                   >> 0x11U))));
    bufp->fullBit(oldp+143,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                   >> 0x10U))));
    bufp->fullCData(oldp+144,((0xfU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                       >> 0xcU))),4);
    bufp->fullBit(oldp+145,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                   >> 0xbU))));
    bufp->fullBit(oldp+146,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                   >> 0xaU))));
    bufp->fullBit(oldp+147,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                   >> 9U))));
    bufp->fullBit(oldp+148,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                   >> 8U))));
    bufp->fullCData(oldp+149,((3U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                     >> 6U))),2);
    bufp->fullBit(oldp+150,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                   >> 5U))));
    bufp->fullCData(oldp+151,((0x1fU & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U])),5);
    bufp->fullCData(oldp+152,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__opcode),7);
    bufp->fullIData(oldp+153,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i),32);
    bufp->fullCData(oldp+154,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs1_addr),5);
    bufp->fullCData(oldp+155,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs2_addr),5);
    bufp->fullCData(oldp+156,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__funct7),7);
    bufp->fullCData(oldp+157,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__funct3),3);
    bufp->fullSData(oldp+158,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm),12);
    bufp->fullCData(oldp+159,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__uimm),5);
    bufp->fullIData(oldp+160,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__upimm),20);
    bufp->fullSData(oldp+161,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__st_imm),12);
    bufp->fullSData(oldp+162,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__bta_imm),12);
    bufp->fullIData(oldp+163,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__jta_imm),20);
    bufp->fullIData(oldp+164,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm_next),32);
    bufp->fullCData(oldp+165,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rd_addr),5);
    bufp->fullBit(oldp+166,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__clk_i));
    bufp->fullBit(oldp+167,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i));
    bufp->fullBit(oldp+168,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__wen_i));
    bufp->fullIData(oldp+169,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_addr),32);
    bufp->fullIData(oldp+170,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_data),32);
    bufp->fullBit(oldp+171,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_en_i));
    bufp->fullIData(oldp+172,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_addr_i),32);
    bufp->fullIData(oldp+173,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o),32);
    bufp->fullBit(oldp+174,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_en_i));
    bufp->fullIData(oldp+175,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_addr_i),32);
    bufp->fullIData(oldp+176,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o),32);
    bufp->fullIData(oldp+177,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0]),32);
    bufp->fullIData(oldp+178,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[1]),32);
    bufp->fullIData(oldp+179,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[2]),32);
    bufp->fullIData(oldp+180,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[3]),32);
    bufp->fullIData(oldp+181,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[4]),32);
    bufp->fullIData(oldp+182,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[5]),32);
    bufp->fullIData(oldp+183,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[6]),32);
    bufp->fullIData(oldp+184,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[7]),32);
    bufp->fullIData(oldp+185,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[8]),32);
    bufp->fullIData(oldp+186,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[9]),32);
    bufp->fullIData(oldp+187,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[10]),32);
    bufp->fullIData(oldp+188,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[11]),32);
    bufp->fullIData(oldp+189,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[12]),32);
    bufp->fullIData(oldp+190,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[13]),32);
    bufp->fullIData(oldp+191,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[14]),32);
    bufp->fullIData(oldp+192,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[15]),32);
    bufp->fullIData(oldp+193,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[16]),32);
    bufp->fullIData(oldp+194,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[17]),32);
    bufp->fullIData(oldp+195,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[18]),32);
    bufp->fullIData(oldp+196,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[19]),32);
    bufp->fullIData(oldp+197,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[20]),32);
    bufp->fullIData(oldp+198,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[21]),32);
    bufp->fullIData(oldp+199,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[22]),32);
    bufp->fullIData(oldp+200,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[23]),32);
    bufp->fullIData(oldp+201,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[24]),32);
    bufp->fullIData(oldp+202,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[25]),32);
    bufp->fullIData(oldp+203,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[26]),32);
    bufp->fullIData(oldp+204,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[27]),32);
    bufp->fullIData(oldp+205,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[28]),32);
    bufp->fullIData(oldp+206,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[29]),32);
    bufp->fullIData(oldp+207,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[30]),32);
    bufp->fullIData(oldp+208,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[31]),32);
    bufp->fullIData(oldp+209,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+210,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__clk_i));
    bufp->fullBit(oldp+211,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__rstn_i));
    bufp->fullBit(oldp+212,((1U & (IData)((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_if_o 
                                           >> 0x20U)))));
    bufp->fullIData(oldp+213,((IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_if_o)),32);
    bufp->fullIData(oldp+214,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[5U] 
                                << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[4U] 
                                          >> 0x17U))),32);
    bufp->fullIData(oldp+215,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[4U] 
                                << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[3U] 
                                          >> 0x17U))),32);
    bufp->fullIData(oldp+216,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[3U] 
                                << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
                                          >> 0x17U))),32);
    bufp->fullIData(oldp+217,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
                                << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                                          >> 0x17U))),32);
    bufp->fullIData(oldp+218,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                                << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                          >> 0x17U))),32);
    bufp->fullCData(oldp+219,((0xfU & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                       >> 0x13U))),4);
    bufp->fullBit(oldp+220,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                   >> 0x12U))));
    bufp->fullBit(oldp+221,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                   >> 0x11U))));
    bufp->fullBit(oldp+222,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                   >> 0x10U))));
    bufp->fullCData(oldp+223,((0xfU & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                       >> 0xcU))),4);
    bufp->fullBit(oldp+224,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                   >> 0xbU))));
    bufp->fullBit(oldp+225,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                   >> 0xaU))));
    bufp->fullBit(oldp+226,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                   >> 9U))));
    bufp->fullBit(oldp+227,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                   >> 8U))));
    bufp->fullCData(oldp+228,((3U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                     >> 6U))),2);
    bufp->fullBit(oldp+229,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                   >> 5U))));
    bufp->fullCData(oldp+230,((0x1fU & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U])),5);
    bufp->fullIData(oldp+231,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[4U] 
                                << 0x11U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[3U] 
                                             >> 0xfU))),32);
    bufp->fullIData(oldp+232,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[3U] 
                                << 0x11U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[2U] 
                                             >> 0xfU))),32);
    bufp->fullIData(oldp+233,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[2U] 
                                << 0x11U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
                                             >> 0xfU))),32);
    bufp->fullBit(oldp+234,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
                                   >> 0xeU))));
    bufp->fullBit(oldp+235,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
                                   >> 0xdU))));
    bufp->fullCData(oldp+236,((0xfU & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
                                       >> 9U))),4);
    bufp->fullBit(oldp+237,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
                                   >> 8U))));
    bufp->fullIData(oldp+238,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
                                << 0x18U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U] 
                                             >> 8U))),32);
    bufp->fullCData(oldp+239,((3U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U] 
                                     >> 6U))),2);
    bufp->fullBit(oldp+240,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U] 
                                   >> 5U))));
    bufp->fullCData(oldp+241,((0x1fU & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U])),5);
    bufp->fullIData(oldp+242,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_srcA),32);
    bufp->fullIData(oldp+243,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_srcB),32);
    bufp->fullIData(oldp+244,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_result),32);
    bufp->fullBit(oldp+245,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__pc_src));
    bufp->fullIData(oldp+246,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__pc_addr),32);
    bufp->fullIData(oldp+247,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__addr_result),32);
    bufp->fullCData(oldp+248,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i),4);
    bufp->fullIData(oldp+249,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i),32);
    bufp->fullIData(oldp+250,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i),32);
    bufp->fullIData(oldp+251,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__result_o),32);
    bufp->fullBit(oldp+252,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__clk_i));
    bufp->fullBit(oldp+253,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__en_i));
    bufp->fullBit(oldp+254,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__rstn_i));
    bufp->fullBit(oldp+255,((1U & (IData)((vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__ex_if_i 
                                           >> 0x20U)))));
    bufp->fullIData(oldp+256,((IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__ex_if_i)),32);
    bufp->fullIData(oldp+257,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[2U]),32);
    bufp->fullIData(oldp+258,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[1U]),32);
    bufp->fullIData(oldp+259,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[0U]),32);
    bufp->fullIData(oldp+260,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_r),32);
    bufp->fullIData(oldp+261,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_next),32);
    bufp->fullBit(oldp+262,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__clk_i));
    bufp->fullBit(oldp+263,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__en_i));
    bufp->fullBit(oldp+264,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__rstn_i));
    bufp->fullIData(oldp+265,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__pc_i),32);
    bufp->fullIData(oldp+266,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__inst_o),32);
    bufp->fullBit(oldp+267,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__clk_i));
    bufp->fullBit(oldp+268,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__rstn_i));
    bufp->fullIData(oldp+269,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[4U] 
                                << 0x11U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[3U] 
                                             >> 0xfU))),32);
    bufp->fullIData(oldp+270,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[3U] 
                                << 0x11U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[2U] 
                                             >> 0xfU))),32);
    bufp->fullIData(oldp+271,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[2U] 
                                << 0x11U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                                             >> 0xfU))),32);
    bufp->fullBit(oldp+272,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                                   >> 0xeU))));
    bufp->fullBit(oldp+273,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                                   >> 0xdU))));
    bufp->fullCData(oldp+274,((0xfU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                                       >> 9U))),4);
    bufp->fullBit(oldp+275,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                                   >> 8U))));
    bufp->fullIData(oldp+276,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                                << 0x18U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U] 
                                             >> 8U))),32);
    bufp->fullCData(oldp+277,((3U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U] 
                                     >> 6U))),2);
    bufp->fullBit(oldp+278,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U] 
                                   >> 5U))));
    bufp->fullCData(oldp+279,((0x1fU & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U])),5);
    bufp->fullIData(oldp+280,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U] 
                                << 0x12U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U] 
                                             >> 0xeU))),32);
    bufp->fullIData(oldp+281,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U] 
                                << 0x12U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U] 
                                             >> 0xeU))),32);
    bufp->fullIData(oldp+282,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U] 
                                << 0x12U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
                                             >> 0xeU))),32);
    bufp->fullIData(oldp+283,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
                                << 0x12U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
                                             >> 0xeU))),32);
    bufp->fullBit(oldp+284,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
                                   >> 0xdU))));
    bufp->fullCData(oldp+285,((0xfU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
                                       >> 9U))),4);
    bufp->fullBit(oldp+286,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
                                   >> 8U))));
    bufp->fullCData(oldp+287,((3U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
                                     >> 6U))),2);
    bufp->fullBit(oldp+288,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
                                   >> 5U))));
    bufp->fullCData(oldp+289,((0x1fU & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U])),5);
    bufp->fullBit(oldp+290,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__clk_i));
    bufp->fullBit(oldp+291,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i));
    bufp->fullBit(oldp+292,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__cenb_i));
    bufp->fullBit(oldp+293,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__wenb_i));
    bufp->fullCData(oldp+294,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i),4);
    bufp->fullCData(oldp+295,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i),8);
    bufp->fullIData(oldp+296,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_i),32);
    bufp->fullIData(oldp+297,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o),32);
    bufp->fullIData(oldp+298,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i),32);
    bufp->fullBit(oldp+299,(vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__clk_i));
    bufp->fullBit(oldp+300,(vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__rstn_i));
    bufp->fullIData(oldp+301,(((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[4U] 
                                << 0x12U) | (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[3U] 
                                             >> 0xeU))),32);
    bufp->fullIData(oldp+302,(((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[3U] 
                                << 0x12U) | (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[2U] 
                                             >> 0xeU))),32);
    bufp->fullIData(oldp+303,(((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[2U] 
                                << 0x12U) | (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[1U] 
                                             >> 0xeU))),32);
    bufp->fullIData(oldp+304,(((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[1U] 
                                << 0x12U) | (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                             >> 0xeU))),32);
    bufp->fullBit(oldp+305,((1U & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                   >> 0xdU))));
    bufp->fullCData(oldp+306,((0xfU & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                       >> 9U))),4);
    bufp->fullBit(oldp+307,((1U & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                   >> 8U))));
    bufp->fullCData(oldp+308,((3U & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                     >> 6U))),2);
    bufp->fullBit(oldp+309,((1U & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                   >> 5U))));
    bufp->fullCData(oldp+310,((0x1fU & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U])),5);
    bufp->fullBit(oldp+311,((1U & (IData)((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o 
                                           >> 0x25U)))));
    bufp->fullCData(oldp+312,((0x1fU & (IData)((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o 
                                                >> 0x20U)))),5);
    bufp->fullIData(oldp+313,((IData)(vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o)),32);
    bufp->fullIData(oldp+314,(vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data),32);
    bufp->fullIData(oldp+315,(vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data_ext),32);
}
