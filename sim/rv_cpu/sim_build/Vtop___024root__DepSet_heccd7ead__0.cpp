// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*3:0*/, 512> Vtop__ConstPool__TABLE_h482a7531_0;

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__pc_i 
        = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_r;
    vlSelfRef.rv_cpu__DOT__riscv_en_i = vlSelfRef.riscv_en_i;
    vlSelfRef.rv_cpu__DOT__ex_mem_w[0U] = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U];
    vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U];
    vlSelfRef.rv_cpu__DOT__ex_mem_w[2U] = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[2U];
    vlSelfRef.rv_cpu__DOT__ex_mem_w[3U] = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[3U];
    vlSelfRef.rv_cpu__DOT__ex_mem_w[4U] = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[4U];
    vlSelfRef.rv_cpu__DOT__rstn_i = vlSelfRef.rstn_i;
    vlSelfRef.rv_cpu__DOT__clk_i = vlSelfRef.clk_i;
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
        = ((0x3fffU & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U]) 
           | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o 
              << 0xeU));
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
        = ((0xffffc000U & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U]) 
           | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o 
              >> 0x12U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
        = ((0x7fffffU & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U]) 
           | ((IData)((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o)) 
                        << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o)))) 
              << 0x17U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U] 
        = (((IData)((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o)) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o)))) 
            >> 9U) | ((IData)(((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o)) 
                                 << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o))) 
                               >> 0x20U)) << 0x17U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
        = ((0xff800000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U]) 
           | ((IData)(((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o)) 
                         << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o))) 
                       >> 0x20U)) >> 9U));
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[2U] 
        = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__inst_o;
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__en_i = vlSelfRef.rv_cpu__DOT__riscv_en_i;
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U] 
        = vlSelfRef.rv_cpu__DOT__ex_mem_w[0U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
        = vlSelfRef.rv_cpu__DOT__ex_mem_w[1U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[2U] 
        = vlSelfRef.rv_cpu__DOT__ex_mem_w[2U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[3U] 
        = vlSelfRef.rv_cpu__DOT__ex_mem_w[3U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[4U] 
        = vlSelfRef.rv_cpu__DOT__ex_mem_w[4U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__rstn_i 
        = vlSelfRef.rv_cpu__DOT__rstn_i;
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__rstn_i 
        = vlSelfRef.rv_cpu__DOT__rstn_i;
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__rstn_i 
        = vlSelfRef.rv_cpu__DOT__rstn_i;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rstn_i 
        = vlSelfRef.rv_cpu__DOT__rstn_i;
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__rstn_i 
        = vlSelfRef.rv_cpu__DOT__rstn_i;
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__clk_i 
        = vlSelfRef.rv_cpu__DOT__clk_i;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__clk_i 
        = vlSelfRef.rv_cpu__DOT__clk_i;
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__clk_i 
        = vlSelfRef.rv_cpu__DOT__clk_i;
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__clk_i 
        = vlSelfRef.rv_cpu__DOT__clk_i;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__clk_i 
        = vlSelfRef.rv_cpu__DOT__clk_i;
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__clk_i 
        = vlSelfRef.rv_cpu__DOT__clk_i;
    vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U];
    vlSelfRef.rv_cpu__DOT__mem_wb_w[1U] = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U];
    vlSelfRef.rv_cpu__DOT__mem_wb_w[2U] = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U];
    vlSelfRef.rv_cpu__DOT__mem_wb_w[3U] = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U];
    vlSelfRef.rv_cpu__DOT__mem_wb_w[4U] = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U];
    vlSelfRef.rv_cpu__DOT__id_ex_w[0U] = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U];
    vlSelfRef.rv_cpu__DOT__id_ex_w[1U] = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U];
    vlSelfRef.rv_cpu__DOT__id_ex_w[2U] = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U];
    vlSelfRef.rv_cpu__DOT__id_ex_w[3U] = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U];
    vlSelfRef.rv_cpu__DOT__id_ex_w[4U] = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U];
    vlSelfRef.rv_cpu__DOT__id_ex_w[5U] = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U];
    vlSelfRef.rv_cpu__DOT__if_id_w[0U] = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[0U];
    vlSelfRef.rv_cpu__DOT__if_id_w[1U] = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[1U];
    vlSelfRef.rv_cpu__DOT__if_id_w[2U] = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[2U];
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__en_i 
        = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__en_i;
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i 
        = (0xfU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                   >> 9U));
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i 
        = (0xffU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[2U] 
                    >> 0xfU));
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_i 
        = ((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
            << 0x18U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U] 
                         >> 8U));
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__wenb_i 
        = (1U & (~ (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                    >> 0xdU)));
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__rstn_i 
        = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__rstn_i;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i 
        = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rstn_i;
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i 
        = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__rstn_i;
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__clk_i 
        = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__clk_i;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__clk_i 
        = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__clk_i;
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__clk_i 
        = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__clk_i;
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
        = vlSelfRef.rv_cpu__DOT__mem_wb_w[0U];
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[1U] 
        = vlSelfRef.rv_cpu__DOT__mem_wb_w[1U];
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[2U] 
        = vlSelfRef.rv_cpu__DOT__mem_wb_w[2U];
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[3U] 
        = vlSelfRef.rv_cpu__DOT__mem_wb_w[3U];
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[4U] 
        = vlSelfRef.rv_cpu__DOT__mem_wb_w[4U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
        = vlSelfRef.rv_cpu__DOT__id_ex_w[0U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
        = vlSelfRef.rv_cpu__DOT__id_ex_w[1U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
        = vlSelfRef.rv_cpu__DOT__id_ex_w[2U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[3U] 
        = vlSelfRef.rv_cpu__DOT__id_ex_w[3U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[4U] 
        = vlSelfRef.rv_cpu__DOT__id_ex_w[4U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[5U] 
        = vlSelfRef.rv_cpu__DOT__id_ex_w[5U];
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[0U] 
        = vlSelfRef.rv_cpu__DOT__if_id_w[0U];
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[1U] 
        = vlSelfRef.rv_cpu__DOT__if_id_w[1U];
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[2U] 
        = vlSelfRef.rv_cpu__DOT__if_id_w[2U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__cenb_i 
        = ((~ (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
               >> 0xeU)) & (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__wenb_i));
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o 
        = ((0xffffffffULL & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o) 
           | ((QData)((IData)((0x3fU & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U]))) 
              << 0x20U));
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data 
        = ((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[1U] 
            << 0x12U) | (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                         >> 0xeU));
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i 
        = (0xfU & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                   >> 0x13U));
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_srcA 
        = ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[3U] 
            << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
                      >> 0x17U));
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_srcB 
        = ((0x40000U & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U])
            ? ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                          >> 0x17U)) : ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
                                         << 9U) | (
                                                   vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                                                   >> 0x17U)));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
        = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[2U];
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data_ext 
        = ((IData)((0x2100U == (0x2100U & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U])))
            ? ((1U == (0xfU & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                               >> 9U))) ? (((- (IData)(
                                                       (1U 
                                                        & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data 
                                                           >> 7U)))) 
                                            << 8U) 
                                           | (0xffU 
                                              & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data))
                : ((3U == (0xfU & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                   >> 9U))) ? (((- (IData)(
                                                           (1U 
                                                            & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data 
                                                               >> 0xfU)))) 
                                                << 0x10U) 
                                               | (0xffffU 
                                                  & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data))
                    : ((0xfU == (0xfU & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                         >> 9U))) ? vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data
                        : 0U))) : ((IData)((0x2000U 
                                            == (0x2100U 
                                                & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U])))
                                    ? ((1U == (0xfU 
                                               & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                                  >> 9U)))
                                        ? (0xffU & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data)
                                        : ((3U == (0xfU 
                                                   & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                                      >> 9U)))
                                            ? (0xffffU 
                                               & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data)
                                            : ((0xfU 
                                                == 
                                                (0xfU 
                                                 & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                                    >> 9U)))
                                                ? vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data
                                                : 0U)))
                                    : vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data));
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o 
        = ((0x3f00000000ULL & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o) 
           | (IData)((IData)(((0x80U & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U])
                               ? ((0x40U & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U])
                                   ? ((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[3U] 
                                       << 0x12U) | 
                                      (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[2U] 
                                       >> 0xeU)) : 
                                  ((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[4U] 
                                    << 0x12U) | (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[3U] 
                                                 >> 0xeU)))
                               : ((0x40U & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U])
                                   ? vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data_ext
                                   : ((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[3U] 
                                       << 0x12U) | 
                                      (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[2U] 
                                       >> 0xeU)))))));
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
        = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_srcA;
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i 
        = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_srcB;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rd_addr 
        = (0x1fU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                    >> 7U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__st_imm 
        = ((0xfe0U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                      >> 0x14U)) | (0x1fU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                                             >> 7U)));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__bta_imm 
        = (((0x800U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                       >> 0x14U)) | (0x400U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                                               << 3U))) 
           | ((0x3f0U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                         >> 0x15U)) | (0xfU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                                               >> 8U))));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__jta_imm 
        = ((0x80000U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                        >> 0xcU)) | ((0x7f800U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                                                  >> 1U)) 
                                     | ((0x400U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                                                   >> 0xaU)) 
                                        | (0x3ffU & 
                                           (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                                            >> 0x15U)))));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm = 
        (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
         >> 0x14U);
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__uimm 
        = (0x1fU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                    >> 0x14U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__upimm 
        = (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
           >> 0xcU);
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs1_addr 
        = (0x1fU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                    >> 0xfU));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs2_addr 
        = (0x1fU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                    >> 0x14U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__opcode 
        = (0x7fU & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i);
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__funct3 
        = (7U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                 >> 0xcU));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__funct7 
        = (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
           >> 0x19U);
    vlSelfRef.rv_cpu__DOT__wb_id_w = vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o;
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__result_o 
        = ((8U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
            ? ((4U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                ? 0U : ((2U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                         ? 0U : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                                  ? (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                                     & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)
                                  : (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                                     | vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i))))
            : ((4U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                ? ((2U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                    ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                        ? VL_SHIFTRS_III(32,32,5, vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i, 
                                         (0x1fU & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i))
                        : (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                           >> (0x1fU & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)))
                    : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                        ? (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                           ^ vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)
                        : ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                            < vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)
                            ? 1U : 0U))) : ((2U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                                             ? ((1U 
                                                 & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                                                 ? 
                                                (VL_LTS_III(32, vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i, vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)
                                                  ? 1U
                                                  : 0U)
                                                 : 
                                                (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                                                 << 
                                                 (0x1fU 
                                                  & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)))
                                             : ((1U 
                                                 & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                                                 ? 
                                                (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                                                 - vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)
                                                 : 
                                                (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                                                 + vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)))));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_addr_i 
        = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs1_addr;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_addr_i 
        = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs2_addr;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_hzd_o 
        = (((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs1_addr) 
            << 5U) | (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs2_addr));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ctl_o 
        = (((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__opcode) 
            << 0xaU) | (((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__funct3) 
                         << 7U) | (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__funct7)));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i 
        = vlSelfRef.rv_cpu__DOT__wb_id_w;
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_result 
        = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__result_o;
    vlSelfRef.rv_cpu__DOT__id_hzd_w = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_hzd_o;
    vlSelfRef.rv_cpu__DOT__id_ctl_w = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ctl_o;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__wen_i 
        = (1U & (IData)((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i 
                         >> 0x25U)));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_addr 
        = (0x1fU & (IData)((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i 
                            >> 0x20U)));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_data 
        = (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i);
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__pc_src 
        = (1U & (((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                   >> 0xaU) & (~ (0U != vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_result))) 
                 | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                    >> 9U)));
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__addr_result 
        = (((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[5U] 
             << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[4U] 
                       >> 0x17U)) + ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                                      << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                                >> 0x17U)));
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__pc_addr 
        = ((0x100U & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U])
            ? vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_result
            : vlSelfRef.rv_cpu__DOT__execute_stage__DOT__addr_result);
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i 
        = vlSelfRef.rv_cpu__DOT__id_ctl_w;
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_if_o 
        = (((QData)((IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__pc_src)) 
            << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__pc_addr)));
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct7 
        = (0x7fU & vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i);
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3 
        = (7U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i 
                 >> 7U));
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode 
        = (0x7fU & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i 
                    >> 0xaU));
    vlSelfRef.rv_cpu__DOT__ex_if_w = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_if_o;
    __Vtableidx1 = (((((0x37U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                       << 8U) | (((0x17U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                                  << 7U) | ((0x6fU 
                                             == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                                            << 6U))) 
                     | (((0x63U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                         << 5U) | ((0x23U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                                   << 4U))) | ((((0x67U 
                                                  == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                                                 << 3U) 
                                                | ((3U 
                                                    == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                                                   << 2U)) 
                                               | (((0x13U 
                                                    == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                                                   << 1U) 
                                                  | (0x33U 
                                                     == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)))));
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next 
        = Vtop__ConstPool__TABLE_h482a7531_0[__Vtableidx1];
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__ex_if_i 
        = vlSelfRef.rv_cpu__DOT__ex_if_w;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jalr = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_signed = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_mask = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jalr = 1U;
                }
                if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_mask 
                        = ((0U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                            ? 1U : ((1U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                     ? 3U : ((2U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                              ? 0xfU
                                              : 0U)));
                }
            }
        } else if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_mask 
                    = ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                        ? ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                            ? 0U : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                     ? 3U : 1U)) : 
                       ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                         ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                             ? 0U : 0xfU) : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                              ? 3U : 1U)));
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_signed 
                        = ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3) 
                                     >> 2U))) && ((1U 
                                                   & (~ 
                                                      ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3) 
                                                       >> 1U))) 
                                                  || (1U 
                                                      & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3)))));
                }
            }
        }
    }
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op = 0xfU;
    if ((8U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op = 0U;
                }
            } else {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op = 0U;
            }
        } else {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src 
                = (1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                            >> 1U)));
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op = 0U;
            } else if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 2U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 1U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 6U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op = 0U;
            } else {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 3U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 3U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op = 0xaU;
            }
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen 
                = (1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                            >> 1U)));
        }
    } else {
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 1U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen = 1U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 3U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op = 0U;
                } else {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 5U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op 
                        = ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                            ? ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                ? 4U : 3U) : ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                               ? 0xfU
                                               : 1U));
                }
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en = 1U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en = 1U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch = 1U;
                }
            } else {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 1U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en = 1U;
                if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en = 1U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 4U;
                } else {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen = 1U;
                }
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op = 0U;
            }
            if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 2U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 1U;
                }
                if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en = 1U;
                }
            }
        } else {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 1U;
                if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 1U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 1U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op = 0U;
                } else {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel 
                        = (((1U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3)) 
                            | (5U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3)))
                            ? 2U : 1U);
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op 
                        = ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                            ? ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                    ? 9U : 8U) : ((1U 
                                                   & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                                   ? 
                                                  ((0x20U 
                                                    & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct7))
                                                    ? 7U
                                                    : 6U)
                                                   : 5U))
                            : ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                    ? 4U : 3U) : ((1U 
                                                   & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                                   ? 2U
                                                   : 0U)));
                }
            } else {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 0U;
                }
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op 
                    = ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                        ? ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                            ? ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                    ? 9U : 8U) : ((1U 
                                                   & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                                   ? 
                                                  ((0x20U 
                                                    & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct7))
                                                    ? 7U
                                                    : 6U)
                                                   : 5U))
                            : ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                    ? 4U : 3U) : ((1U 
                                                   & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                                   ? 2U
                                                   : 
                                                  ((0x20U 
                                                    & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct7))
                                                    ? 1U
                                                    : 0U))))
                        : 0U);
            }
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en 
                = ((1U & ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                          >> 1U)) || (1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)));
            if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                          >> 1U)))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en 
                    = (1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next));
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 0U;
                }
            }
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen 
                = ((1U & ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                          >> 1U)) || (1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)));
        }
        if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en = 1U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en = 0U;
            }
        }
    }
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_next 
        = ((1U & (IData)((vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__ex_if_i 
                          >> 0x20U))) ? (IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__ex_if_i)
            : ((IData)(4U) + vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_r));
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
        = (((((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel) 
              << 0x14U) | (((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en) 
                            << 0x13U) | (((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en) 
                                          << 0x12U) 
                                         | ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen) 
                                            << 0x11U)))) 
            | (((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src) 
                << 0xfU) | ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op) 
                            << 0xbU))) | ((((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src) 
                                            << 0xaU) 
                                           | (((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en) 
                                               << 9U) 
                                              | ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en) 
                                                 << 8U))) 
                                          | (((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_mask) 
                                              << 4U) 
                                             | ((((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_signed) 
                                                  << 3U) 
                                                 | ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch) 
                                                    << 2U)) 
                                                | (((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump) 
                                                    << 1U) 
                                                   | (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jalr))))));
    vlSelfRef.rv_cpu__DOT__ctl_id_w = vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
        = vlSelfRef.rv_cpu__DOT__ctl_id_w;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_en_i 
        = (1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                 >> 0x13U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_en_i 
        = (1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                 >> 0x12U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm_next 
        = ((0x400000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
            ? ((0x200000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
                ? ((0x100000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
                    ? 0U : (((- (IData)((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__jta_imm 
                                               >> 0x13U)))) 
                             << 0x15U) | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__jta_imm 
                                          << 1U))) : 
               ((0x100000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
                 ? (((- (IData)((1U & ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__bta_imm) 
                                       >> 0xbU)))) 
                     << 0xdU) | ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__bta_imm) 
                                 << 1U)) : (((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__st_imm) 
                                                            >> 0xbU)))) 
                                             << 0xcU) 
                                            | (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__st_imm))))
            : ((0x200000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
                ? ((0x100000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
                    ? (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__upimm 
                       << 0xcU) : (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__uimm))
                : ((0x100000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
                    ? (((- (IData)((1U & ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm) 
                                          >> 0xbU)))) 
                        << 0xcU) | (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm))
                    : 0U)));
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i)))) {
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 1U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 2U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 3U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 4U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 5U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 6U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 7U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 8U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 9U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0xaU;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0xbU;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0xcU;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0xdU;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0xeU;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0xfU;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x10U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x11U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x12U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x13U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x14U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x15U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x16U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x17U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x18U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x19U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x1aU;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x1bU;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x1cU;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x1dU;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x1eU;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x1fU;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0x20U;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__rstn_i) {
        vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
            = ((0x7fffU & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U]) 
               | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__addr_result 
                  << 0xfU));
        vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[2U] 
            = ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__addr_result 
                >> 0x11U) | ((IData)((((QData)((IData)(
                                                       ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[4U] 
                                                         << 9U) 
                                                        | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[3U] 
                                                           >> 0x17U)))) 
                                       << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_result)))) 
                             << 0xfU));
        vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[3U] 
            = (((IData)((((QData)((IData)(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[4U] 
                                            << 9U) 
                                           | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[3U] 
                                              >> 0x17U)))) 
                          << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_result)))) 
                >> 0x11U) | ((IData)(((((QData)((IData)(
                                                        ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[4U] 
                                                          << 9U) 
                                                         | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[3U] 
                                                            >> 0x17U)))) 
                                        << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_result))) 
                                      >> 0x20U)) << 0xfU));
        vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[4U] 
            = ((IData)(((((QData)((IData)(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[4U] 
                                            << 9U) 
                                           | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[3U] 
                                              >> 0x17U)))) 
                          << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_result))) 
                        >> 0x20U)) >> 0x11U);
        vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U] 
            = ((0x3fU & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U]) 
               | ((IData)((((QData)((IData)((0x7fU 
                                             & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                                >> 0xbU)))) 
                            << 0x22U) | (((QData)((IData)(
                                                          ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
                                                            << 9U) 
                                                           | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                                                              >> 0x17U)))) 
                                          << 2U) | (QData)((IData)(
                                                                   (3U 
                                                                    & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                                                       >> 6U))))))) 
                  << 6U));
        vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
            = ((0xffff8000U & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U]) 
               | (((IData)((((QData)((IData)((0x7fU 
                                              & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                                 >> 0xbU)))) 
                             << 0x22U) | (((QData)((IData)(
                                                           ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
                                                             << 9U) 
                                                            | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                                                               >> 0x17U)))) 
                                           << 2U) | (QData)((IData)(
                                                                    (3U 
                                                                     & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                                                        >> 6U))))))) 
                   >> 0x1aU) | ((IData)(((((QData)((IData)(
                                                           (0x7fU 
                                                            & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                                               >> 0xbU)))) 
                                           << 0x22U) 
                                          | (((QData)((IData)(
                                                              ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
                                                                << 9U) 
                                                               | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                                                                  >> 0x17U)))) 
                                              << 2U) 
                                             | (QData)((IData)(
                                                               (3U 
                                                                & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                                                   >> 6U)))))) 
                                         >> 0x20U)) 
                                << 6U)));
        vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U] 
            = ((0xffffffc0U & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U]) 
               | (0x3fU & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U]));
    } else {
        vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U] = 0U;
        vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] = 0U;
        vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[2U] = 0U;
        vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[3U] = 0U;
        vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[4U] = 0U;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0;
    __VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0 = 0;
    CData/*7:0*/ __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0;
    __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0 = 0;
    IData/*31:0*/ __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0;
    __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0 = 0;
    CData/*7:0*/ __VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1;
    __VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1 = 0;
    CData/*7:0*/ __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1;
    __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1 = 0;
    IData/*31:0*/ __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1;
    __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1 = 0;
    CData/*7:0*/ __VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2;
    __VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2 = 0;
    CData/*7:0*/ __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2;
    __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2 = 0;
    IData/*31:0*/ __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2;
    __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2 = 0;
    CData/*7:0*/ __VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3;
    __VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3 = 0;
    CData/*7:0*/ __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3;
    __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3 = 0;
    IData/*31:0*/ __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3;
    __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3 = 0;
    CData/*7:0*/ __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v4;
    __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v4 = 0;
    // Body
    if (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i) {
        if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__cenb_i)))) {
            if (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__wenb_i) {
                vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i = 0U;
                vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i = 1U;
                vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i = 2U;
                vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i = 3U;
                vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i = 4U;
            } else {
                vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i = 0U;
                if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i))) {
                    __VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0 
                        = (0xffU & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_i);
                    __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0 
                        = (0xffU & VL_SHIFTR_III(8,8,32, (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i), 2U));
                    __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0 = 0U;
                    __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0 
                        = ((0xffffff00U & __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0) 
                           | (IData)(__VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0));
                    vlSelfRef.__VdlyCommitQueuerv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array.enqueue(__VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0, 0xffU, (IData)(__VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v0));
                }
                vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i = 1U;
                if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i))) {
                    __VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1 
                        = (0xffU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_i 
                                    >> 8U));
                    __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1 
                        = (0xffU & VL_SHIFTR_III(8,8,32, (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i), 2U));
                    __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1 = 0U;
                    __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1 
                        = ((0xffff00ffU & __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1) 
                           | ((IData)(__VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1) 
                              << 8U));
                    vlSelfRef.__VdlyCommitQueuerv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array.enqueue(__VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1, 0xff00U, (IData)(__VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v1));
                }
                vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i = 2U;
                if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i))) {
                    __VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2 
                        = (0xffU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_i 
                                    >> 0x10U));
                    __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2 
                        = (0xffU & VL_SHIFTR_III(8,8,32, (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i), 2U));
                    __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2 = 0U;
                    __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2 
                        = ((0xff00ffffU & __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2) 
                           | ((IData)(__VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2) 
                              << 0x10U));
                    vlSelfRef.__VdlyCommitQueuerv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array.enqueue(__VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2, 0xff0000U, (IData)(__VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v2));
                }
                vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i = 3U;
                if ((8U & (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i))) {
                    __VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3 
                        = (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_i 
                           >> 0x18U);
                    __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3 
                        = (0xffU & VL_SHIFTR_III(8,8,32, (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i), 2U));
                    __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3 = 0U;
                    __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3 
                        = ((0xffffffU & __VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3) 
                           | ((IData)(__VdlyVal__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3) 
                              << 0x18U));
                    vlSelfRef.__VdlyCommitQueuerv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array.enqueue(__VdlyElem__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3, 0xff000000U, (IData)(__VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v3));
                }
                vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i = 4U;
            }
        }
    } else {
        vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i = 0U;
        while (VL_GTS_III(32, 0x100U, vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i)) {
            __VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v4 
                = (0xffU & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i);
            vlSelfRef.__VdlyCommitQueuerv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array.enqueue(0U, 0xffffffffU, (IData)(__VdlyDim0__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array__v4));
            vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i 
                = ((IData)(1U) + vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i);
        }
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__inst_o 
        = ((IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__rstn_i)
            ? ((IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__en_i)
                ? vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__mem
               [(0x3fU & (vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__pc_i 
                          >> 2U))] : vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__inst_o)
            : 0U);
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rstn_i) {
        vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
            = ((0x7fffffU & vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U]) 
               | ((IData)((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[0U])))) 
                  << 0x17U));
        vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U] 
            = (((IData)((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[1U])) 
                          << 0x20U) | (QData)((IData)(
                                                      vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[0U])))) 
                >> 9U) | ((IData)(((((QData)((IData)(
                                                     vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[0U]))) 
                                   >> 0x20U)) << 0x17U));
        vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U] 
            = ((IData)(((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[1U])) 
                          << 0x20U) | (QData)((IData)(
                                                      vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[0U]))) 
                        >> 0x20U)) >> 9U);
        vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
            = (0xff800000U | vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U]);
        vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U] = 0xffffffffU;
        vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U] 
            = (0x7fffffU | vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U]);
        vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
            = ((0x1ffU & vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U]) 
               | ((IData)((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm_next)) 
                            << 0xeU) | (QData)((IData)(
                                                       (0x3fffU 
                                                        & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                                           >> 1U)))))) 
                  << 9U));
        vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
            = ((0xff800000U & vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U]) 
               | (((IData)((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm_next)) 
                             << 0xeU) | (QData)((IData)(
                                                        (0x3fffU 
                                                         & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                                            >> 1U)))))) 
                   >> 0x17U) | ((IData)(((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm_next)) 
                                           << 0xeU) 
                                          | (QData)((IData)(
                                                            (0x3fffU 
                                                             & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                                                >> 1U))))) 
                                         >> 0x20U)) 
                                << 9U)));
        vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
            = (0xfffffe00U | vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U]);
        vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
            = (0x7fffffU | vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U]);
        vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
            = ((0xffffff00U & vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U]) 
               | ((0xc0U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                            >> 9U)) | ((0x20U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                                 >> 0xcU)) 
                                       | (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rd_addr))));
        vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
            = (0xffU | vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U]);
    } else {
        vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
            = (0x7fffffU & vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U]);
        vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U] = 0U;
        vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U] = 0U;
        vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
            = (0xff800000U | vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U]);
        vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U] = 0xffffffffU;
        vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U] 
            = (0x7fffffU | vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U]);
        vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
            = (0x1ffU & vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U]);
        vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
            = (0xff800000U & vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U]);
        vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
            = (0xfffffe00U | vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U]);
        vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
            = (0x7fffffU | vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U]);
        vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
            = (0xffffff00U & vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U]);
        vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
            = (0xffU | vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U]);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<5>/*141:0*/ __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o;
    VL_ZERO_W(142, __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o);
    VlWide<5>/*141:0*/ __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o;
    VL_ZERO_W(142, __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o);
    VlWide<5>/*159:0*/ __Vtemp_5;
    // Body
    if (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__rstn_i) {
        __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
            = ((0x3fffU & __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U]) 
               | ((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[2U] 
                   << 0x1fU) | (0x7fffc000U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                                               >> 1U))));
        __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U] 
            = ((0x3fffU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[2U] 
                           >> 1U)) | ((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[3U] 
                                       << 0x1fU) | 
                                      (0x7fffc000U 
                                       & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[2U] 
                                          >> 1U))));
        __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U] 
            = ((0x3fffU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[3U] 
                           >> 1U)) | ((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[4U] 
                                       << 0x1fU) | 
                                      (0x7fffc000U 
                                       & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[3U] 
                                          >> 1U))));
        __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U] 
            = (0x3fffU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[4U] 
                          >> 1U));
        __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
            = (0xffffc000U | (0x3fffU & __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U]));
        __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U] = 0xffffffffU;
        __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U] = 0xffffffffU;
        __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U] = 0x3fffU;
        __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
            = ((0xffffc000U & __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U]) 
               | ((0x2000U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                              >> 1U)) | ((0x1f00U & 
                                          vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U]) 
                                         | (0xffU & 
                                            vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U]))));
        __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
            = (0x3fffU | __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U]);
    } else {
        __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
            = (0x3fffU & __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U]);
        __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U] = 0U;
        __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U] = 0U;
        __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U] = 0U;
        __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
            = (0xffffc000U | (0x3fffU & __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U]));
        __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U] = 0xffffffffU;
        __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U] = 0xffffffffU;
        __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U] = 0x3fffU;
        __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
            = (0xffffc000U & __Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U]);
        __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
            = (0x3fffU | __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U]);
    }
    __Vtemp_5[1U] = ((__Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
                      & __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U]) 
                     | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
                        & (~ __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U])));
    __Vtemp_5[2U] = ((__Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U] 
                      & __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U]) 
                     | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U] 
                        & (~ __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U])));
    __Vtemp_5[3U] = ((__Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U] 
                      & __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U]) 
                     | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U] 
                        & (~ __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U])));
    __Vtemp_5[4U] = ((__Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U] 
                      & __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U]) 
                     | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U] 
                        & (~ __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U])));
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
        = ((__Vdly__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
            & __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U]) 
           | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
              & (~ __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U])));
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
        = __Vtemp_5[1U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U] 
        = __Vtemp_5[2U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U] 
        = __Vtemp_5[3U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U] 
        = __Vtemp_5[4U];
    __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] = 0U;
    __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] = 0U;
    __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U] = 0U;
    __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U] = 0U;
    __VdlyMask__rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U] = 0U;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i) {
        if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__cenb_i)))) {
            if (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__wenb_i) {
                if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i))) {
                    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o 
                        = ((0xffffff00U & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o) 
                           | (0xffU & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array
                              [(0xffU & VL_SHIFTR_III(8,8,32, (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i), 2U))]));
                }
                if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i))) {
                    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o 
                        = ((0xffff00ffU & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o) 
                           | (0xff00U & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array
                              [(0xffU & VL_SHIFTR_III(8,8,32, (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i), 2U))]));
                }
                if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i))) {
                    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o 
                        = ((0xff00ffffU & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o) 
                           | (0xff0000U & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array
                              [(0xffU & VL_SHIFTR_III(8,8,32, (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i), 2U))]));
                }
                if ((8U & (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i))) {
                    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o 
                        = ((0xffffffU & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o) 
                           | (0xff000000U & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array
                              [(0xffU & VL_SHIFTR_III(8,8,32, (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i), 2U))]));
                }
            }
        }
    } else {
        vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o = 0U;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<6>/*191:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[1U] = ((vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
                      & vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U]) 
                     | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
                        & (~ vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U])));
    __Vtemp_1[2U] = ((vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U] 
                      & vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U]) 
                     | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U] 
                        & (~ vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U])));
    __Vtemp_1[3U] = ((vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
                      & vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U]) 
                     | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
                        & (~ vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U])));
    __Vtemp_1[4U] = ((vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U] 
                      & vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U]) 
                     | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U] 
                        & (~ vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U])));
    __Vtemp_1[5U] = ((vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U] 
                      & vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U]) 
                     | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U] 
                        & (~ vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U])));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
        = ((vlSelfRef.__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
            & vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U]) 
           | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
              & (~ vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U])));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
        = __Vtemp_1[1U];
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U] 
        = __Vtemp_1[2U];
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
        = __Vtemp_1[3U];
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U] 
        = __Vtemp_1[4U];
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U] 
        = __Vtemp_1[5U];
    vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] = 0U;
    vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] = 0U;
    vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U] = 0U;
    vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] = 0U;
    vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U] = 0U;
    vlSelfRef.__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U] = 0U;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vdly__rv_cpu__DOT__fetch_stage__DOT__if_id_o;
    VL_ZERO_W(96, __Vdly__rv_cpu__DOT__fetch_stage__DOT__if_id_o);
    VlWide<3>/*95:0*/ __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o;
    VL_ZERO_W(96, __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o);
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vdly__rv_cpu__DOT__fetch_stage__DOT__if_id_o[0U] 
        = (IData)(((IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__rstn_i)
                    ? (((QData)((IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_r)) 
                        << 0x20U) | (QData)((IData)(
                                                    ((IData)(4U) 
                                                     + vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_r))))
                    : 0ULL));
    __Vdly__rv_cpu__DOT__fetch_stage__DOT__if_id_o[1U] 
        = (IData)((((IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__rstn_i)
                     ? (((QData)((IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_r)) 
                         << 0x20U) | (QData)((IData)(
                                                     ((IData)(4U) 
                                                      + vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_r))))
                     : 0ULL) >> 0x20U));
    __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o[0U] = 0xffffffffU;
    __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o[1U] = 0xffffffffU;
    __Vtemp_1[1U] = ((__Vdly__rv_cpu__DOT__fetch_stage__DOT__if_id_o[1U] 
                      & __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o[1U]) 
                     | (vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[1U] 
                        & (~ __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o[1U])));
    __Vtemp_1[2U] = ((__Vdly__rv_cpu__DOT__fetch_stage__DOT__if_id_o[2U] 
                      & __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o[2U]) 
                     | (vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[2U] 
                        & (~ __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o[2U])));
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[0U] 
        = ((__Vdly__rv_cpu__DOT__fetch_stage__DOT__if_id_o[0U] 
            & __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o[0U]) 
           | (vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[0U] 
              & (~ __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o[0U])));
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[1U] 
        = __Vtemp_1[1U];
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[2U] 
        = __Vtemp_1[2U];
    __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o[0U] = 0U;
    __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o[1U] = 0U;
    __VdlyMask__rv_cpu__DOT__fetch_stage__DOT__if_id_o[2U] = 0U;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__9(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlyCommitQueuerv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array.commit(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array);
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__10(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__10\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__ex_mem_w[0U] = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U];
    vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U];
    vlSelfRef.rv_cpu__DOT__ex_mem_w[2U] = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[2U];
    vlSelfRef.rv_cpu__DOT__ex_mem_w[3U] = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[3U];
    vlSelfRef.rv_cpu__DOT__ex_mem_w[4U] = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[4U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U] 
        = vlSelfRef.rv_cpu__DOT__ex_mem_w[0U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
        = vlSelfRef.rv_cpu__DOT__ex_mem_w[1U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[2U] 
        = vlSelfRef.rv_cpu__DOT__ex_mem_w[2U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[3U] 
        = vlSelfRef.rv_cpu__DOT__ex_mem_w[3U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[4U] 
        = vlSelfRef.rv_cpu__DOT__ex_mem_w[4U];
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i 
        = (0xfU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                   >> 9U));
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i 
        = (0xffU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[2U] 
                    >> 0xfU));
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_i 
        = ((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
            << 0x18U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U] 
                         >> 8U));
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__wenb_i 
        = (1U & (~ (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                    >> 0xdU)));
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__cenb_i 
        = ((~ (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
               >> 0xeU)) & (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__wenb_i));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__11(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[2U] 
        = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__inst_o;
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__if_id_w[0U] = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[0U];
    vlSelfRef.rv_cpu__DOT__if_id_w[1U] = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[1U];
    vlSelfRef.rv_cpu__DOT__if_id_w[2U] = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[2U];
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[0U] 
        = vlSelfRef.rv_cpu__DOT__if_id_w[0U];
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[1U] 
        = vlSelfRef.rv_cpu__DOT__if_id_w[1U];
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[2U] 
        = vlSelfRef.rv_cpu__DOT__if_id_w[2U];
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
        = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[2U];
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__opcode 
        = (0x7fU & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i);
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__funct3 
        = (7U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                 >> 0xcU));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__funct7 
        = (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
           >> 0x19U);
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ctl_o 
        = (((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__opcode) 
            << 0xaU) | (((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__funct3) 
                         << 7U) | (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__funct7)));
    vlSelfRef.rv_cpu__DOT__id_ctl_w = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ctl_o;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i 
        = vlSelfRef.rv_cpu__DOT__id_ctl_w;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode 
        = (0x7fU & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i 
                    >> 0xaU));
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__jta_imm 
        = ((0x80000U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                        >> 0xcU)) | ((0x7f800U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                                                  >> 1U)) 
                                     | ((0x400U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                                                   >> 0xaU)) 
                                        | (0x3ffU & 
                                           (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                                            >> 0x15U)))));
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct7 
        = (0x7fU & vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i);
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3 
        = (7U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i 
                 >> 7U));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__12(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__12\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
        = ((0x3fffU & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U]) 
           | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o 
              << 0xeU));
    vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
        = ((0xffffc000U & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U]) 
           | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o 
              >> 0x12U));
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U];
    vlSelfRef.rv_cpu__DOT__mem_wb_w[1U] = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U];
    vlSelfRef.rv_cpu__DOT__mem_wb_w[2U] = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U];
    vlSelfRef.rv_cpu__DOT__mem_wb_w[3U] = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U];
    vlSelfRef.rv_cpu__DOT__mem_wb_w[4U] = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U];
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
        = vlSelfRef.rv_cpu__DOT__mem_wb_w[0U];
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[1U] 
        = vlSelfRef.rv_cpu__DOT__mem_wb_w[1U];
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[2U] 
        = vlSelfRef.rv_cpu__DOT__mem_wb_w[2U];
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[3U] 
        = vlSelfRef.rv_cpu__DOT__mem_wb_w[3U];
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[4U] 
        = vlSelfRef.rv_cpu__DOT__mem_wb_w[4U];
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o 
        = ((0xffffffffULL & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o) 
           | ((QData)((IData)((0x3fU & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U]))) 
              << 0x20U));
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data 
        = ((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[1U] 
            << 0x12U) | (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                         >> 0xeU));
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data_ext 
        = ((IData)((0x2100U == (0x2100U & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U])))
            ? ((1U == (0xfU & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                               >> 9U))) ? (((- (IData)(
                                                       (1U 
                                                        & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data 
                                                           >> 7U)))) 
                                            << 8U) 
                                           | (0xffU 
                                              & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data))
                : ((3U == (0xfU & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                   >> 9U))) ? (((- (IData)(
                                                           (1U 
                                                            & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data 
                                                               >> 0xfU)))) 
                                                << 0x10U) 
                                               | (0xffffU 
                                                  & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data))
                    : ((0xfU == (0xfU & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                         >> 9U))) ? vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data
                        : 0U))) : ((IData)((0x2000U 
                                            == (0x2100U 
                                                & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U])))
                                    ? ((1U == (0xfU 
                                               & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                                  >> 9U)))
                                        ? (0xffU & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data)
                                        : ((3U == (0xfU 
                                                   & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                                      >> 9U)))
                                            ? (0xffffU 
                                               & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data)
                                            : ((0xfU 
                                                == 
                                                (0xfU 
                                                 & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                                    >> 9U)))
                                                ? vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data
                                                : 0U)))
                                    : vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data));
    vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o 
        = ((0x3f00000000ULL & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o) 
           | (IData)((IData)(((0x80U & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U])
                               ? ((0x40U & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U])
                                   ? ((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[3U] 
                                       << 0x12U) | 
                                      (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[2U] 
                                       >> 0xeU)) : 
                                  ((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[4U] 
                                    << 0x12U) | (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[3U] 
                                                 >> 0xeU)))
                               : ((0x40U & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U])
                                   ? vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data_ext
                                   : ((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[3U] 
                                       << 0x12U) | 
                                      (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[2U] 
                                       >> 0xeU)))))));
    vlSelfRef.rv_cpu__DOT__wb_id_w = vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i 
        = vlSelfRef.rv_cpu__DOT__wb_id_w;
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((((0x37U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                       << 8U) | (((0x17U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                                  << 7U) | ((0x6fU 
                                             == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                                            << 6U))) 
                     | (((0x63U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                         << 5U) | ((0x23U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                                   << 4U))) | ((((0x67U 
                                                  == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                                                 << 3U) 
                                                | ((3U 
                                                    == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                                                   << 2U)) 
                                               | (((0x13U 
                                                    == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)) 
                                                   << 1U) 
                                                  | (0x33U 
                                                     == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode)))));
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next 
        = Vtop__ConstPool__TABLE_h482a7531_0[__Vtableidx1];
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jalr = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jalr = 1U;
                }
            }
        }
    }
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 0U;
    if ((8U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 0U;
                }
            } else {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 0U;
            }
        } else if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 0U;
        } else if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 1U;
        }
    } else if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 1U;
            }
        }
    } else if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                         >> 1U)))) {
        if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump = 0U;
        }
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en = 0U;
    if ((8U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en = 0U;
                }
            } else {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en = 0U;
            }
        } else {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src 
                = (1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                            >> 1U)));
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en = 0U;
            }
        }
    } else if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en = 1U;
            }
        } else {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 1U;
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en = 1U;
        }
    } else {
        if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 1U;
        } else if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src = 0U;
        }
        vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en 
            = ((1U & ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                      >> 1U)) || (1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)));
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen = 0U;
    if ((8U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen = 0U;
                }
            } else {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen = 0U;
            }
        } else {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en = 0U;
            }
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen 
                = (1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                            >> 1U)));
        }
    } else if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en = 1U;
            }
            if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen = 1U;
            }
        } else {
            if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen = 1U;
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                      >> 1U)))) {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en 
                = (1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next));
        }
        vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen 
            = ((1U & ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                      >> 1U)) || (1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)));
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 0U;
    if ((8U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 0U;
                }
            } else {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 0U;
            }
        } else if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en = 0U;
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 0U;
        } else {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src 
                = ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                    ? 2U : 3U);
        }
    } else {
        if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en = 1U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en = 0U;
            }
        }
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 2U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 1U;
            }
        } else if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src = 0U;
        }
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en = 0U;
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch = 0U;
    if ((8U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en = 0U;
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch = 0U;
                }
            } else {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en = 0U;
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch = 0U;
            }
        } else if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en = 0U;
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en = 1U;
            }
        }
        if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch = 1U;
            }
        }
    } else if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                         >> 1U)))) {
        if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en = 0U;
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch = 0U;
        }
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__9(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 0U;
    if ((8U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 0U;
                }
            } else {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 0U;
            }
        } else {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel 
                = ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                    ? 0U : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                             ? 6U : 3U));
        }
    } else if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel 
            = ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                    ? 3U : 5U) : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                                   ? 4U : 1U));
    } else if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel 
            = ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                ? 1U : (((1U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3)) 
                         | (5U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3)))
                         ? 2U : 1U));
    } else if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
        vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel = 0U;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__10(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__10\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_signed = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_signed 
                        = ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3) 
                                     >> 2U))) && ((1U 
                                                   & (~ 
                                                      ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3) 
                                                       >> 1U))) 
                                                  || (1U 
                                                      & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3)))));
                }
            }
        }
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__11(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_mask = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((1U & (~ ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_mask 
                        = ((0U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                            ? 1U : ((1U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                     ? 3U : ((2U == (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                              ? 0xfU
                                              : 0U)));
                }
            }
        } else if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_mask 
                    = ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                        ? ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                            ? 0U : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                     ? 3U : 1U)) : 
                       ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                         ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                             ? 0U : 0xfU) : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                              ? 3U : 1U)));
            }
        }
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__12(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__12\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op = 0xfU;
    if ((8U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
        if ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
            if ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))) {
                if ((1U & (~ (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next)))) {
                    vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op = 0U;
                }
            } else {
                vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op = 0U;
            }
        } else {
            vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op 
                = ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                    ? 0U : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                             ? 0U : 0xaU));
        }
    } else {
        vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op 
            = ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                ? ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                    ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                        ? 0U : ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                 ? ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                     ? 4U : 3U) : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                                    ? 0xfU
                                                    : 1U)))
                    : 0U) : ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                              ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                                  ? 0U : ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                           ? ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                                   ? 9U
                                                   : 8U)
                                               : ((1U 
                                                   & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                                   ? 
                                                  ((0x20U 
                                                    & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct7))
                                                    ? 7U
                                                    : 6U)
                                                   : 5U))
                                           : ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                                   ? 4U
                                                   : 3U)
                                               : ((1U 
                                                   & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                                   ? 2U
                                                   : 0U))))
                              : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next))
                                  ? ((4U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                      ? ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                          ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                              ? 9U : 8U)
                                          : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                              ? ((0x20U 
                                                  & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct7))
                                                  ? 7U
                                                  : 6U)
                                              : 5U))
                                      : ((2U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                          ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                              ? 4U : 3U)
                                          : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3))
                                              ? 2U : 
                                             ((0x20U 
                                               & (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct7))
                                               ? 1U
                                               : 0U))))
                                  : 0U)));
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__13(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__13\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_r = 
        ((IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__rstn_i)
          ? ((IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__en_i)
              ? vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_next
              : vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_r)
          : 0U);
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__pc_i 
        = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_r;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__14(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__14\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i) {
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o 
            = ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_en_i)
                ? vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem
               [(0x1fU & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_addr_i)]
                : vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o);
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o 
            = ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_en_i)
                ? vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem
               [(0x1fU & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_addr_i)]
                : vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o);
    } else {
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o = 0U;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__15(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__15\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0;
    __VdlyVal__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0 = 0;
    CData/*4:0*/ __VdlyDim0__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0;
    __VdlyDim0__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0;
    __VdlySet__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v1;
    __VdlySet__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v1 = 0;
    // Body
    __VdlySet__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0 = 0U;
    __VdlySet__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v1 = 0U;
    if (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i) {
        if ((0U != vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_addr)) {
            __VdlyVal__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0 
                = ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__wen_i)
                    ? vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_data
                    : vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem
                   [(0x1fU & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_addr)]);
            __VdlyDim0__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0 
                = (0x1fU & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_addr);
            __VdlySet__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0 = 1U;
        }
    } else {
        __VdlySet__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v1 = 1U;
    }
    if (__VdlySet__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0) {
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[__VdlyDim0__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0] 
            = __VdlyVal__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v0;
    }
    if (__VdlySet__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem__v1) {
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[1U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[2U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[3U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[4U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[5U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[6U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[7U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[8U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[9U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0xaU] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0xbU] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0xcU] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0xdU] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0xeU] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0xfU] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x10U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x11U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x12U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x13U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x14U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x15U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x16U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x17U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x18U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x19U] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x1aU] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x1bU] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x1cU] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x1dU] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x1eU] = 0U;
        vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0x1fU] = 0U;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__13(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__13\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rd_addr 
        = (0x1fU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                    >> 7U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__st_imm 
        = ((0xfe0U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                      >> 0x14U)) | (0x1fU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                                             >> 7U)));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__bta_imm 
        = (((0x800U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                       >> 0x14U)) | (0x400U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                                               << 3U))) 
           | ((0x3f0U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                         >> 0x15U)) | (0xfU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                                               >> 8U))));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm = 
        (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
         >> 0x14U);
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__uimm 
        = (0x1fU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                    >> 0x14U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__upimm 
        = (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
           >> 0xcU);
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs1_addr 
        = (0x1fU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                    >> 0xfU));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs2_addr 
        = (0x1fU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i 
                    >> 0x14U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_addr_i 
        = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs1_addr;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_addr_i 
        = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs2_addr;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_hzd_o 
        = (((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs1_addr) 
            << 5U) | (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs2_addr));
    vlSelfRef.rv_cpu__DOT__id_hzd_w = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_hzd_o;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__16(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__16\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
        = ((0x7fffffU & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U]) 
           | ((IData)((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o)) 
                        << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o)))) 
              << 0x17U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U] 
        = (((IData)((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o)) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o)))) 
            >> 9U) | ((IData)(((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o)) 
                                 << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o))) 
                               >> 0x20U)) << 0x17U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
        = ((0xff800000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U]) 
           | ((IData)(((((QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o)) 
                         << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o))) 
                       >> 0x20U)) >> 9U));
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__14(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__14\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__id_ex_w[0U] = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U];
    vlSelfRef.rv_cpu__DOT__id_ex_w[1U] = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U];
    vlSelfRef.rv_cpu__DOT__id_ex_w[2U] = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U];
    vlSelfRef.rv_cpu__DOT__id_ex_w[3U] = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U];
    vlSelfRef.rv_cpu__DOT__id_ex_w[4U] = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U];
    vlSelfRef.rv_cpu__DOT__id_ex_w[5U] = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
        = vlSelfRef.rv_cpu__DOT__id_ex_w[0U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
        = vlSelfRef.rv_cpu__DOT__id_ex_w[1U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
        = vlSelfRef.rv_cpu__DOT__id_ex_w[2U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[3U] 
        = vlSelfRef.rv_cpu__DOT__id_ex_w[3U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[4U] 
        = vlSelfRef.rv_cpu__DOT__id_ex_w[4U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[5U] 
        = vlSelfRef.rv_cpu__DOT__id_ex_w[5U];
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i 
        = (0xfU & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                   >> 0x13U));
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_srcA 
        = ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[3U] 
            << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
                      >> 0x17U));
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_srcB 
        = ((0x40000U & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U])
            ? ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                          >> 0x17U)) : ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
                                         << 9U) | (
                                                   vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                                                   >> 0x17U)));
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
        = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_srcA;
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i 
        = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_srcB;
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__result_o 
        = ((8U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
            ? ((4U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                ? 0U : ((2U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                         ? 0U : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                                  ? (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                                     & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)
                                  : (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                                     | vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i))))
            : ((4U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                ? ((2U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                    ? ((1U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                        ? VL_SHIFTRS_III(32,32,5, vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i, 
                                         (0x1fU & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i))
                        : (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                           >> (0x1fU & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)))
                    : ((1U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                        ? (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                           ^ vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)
                        : ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                            < vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)
                            ? 1U : 0U))) : ((2U & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                                             ? ((1U 
                                                 & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                                                 ? 
                                                (VL_LTS_III(32, vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i, vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)
                                                  ? 1U
                                                  : 0U)
                                                 : 
                                                (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                                                 << 
                                                 (0x1fU 
                                                  & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)))
                                             : ((1U 
                                                 & (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i))
                                                 ? 
                                                (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                                                 - vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)
                                                 : 
                                                (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i 
                                                 + vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i)))));
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_result 
        = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__result_o;
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__15(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__15\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__pc_src 
        = (1U & (((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                   >> 0xaU) & (~ (0U != vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_result))) 
                 | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                    >> 9U)));
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__16(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__16\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__addr_result 
        = (((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[5U] 
             << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[4U] 
                       >> 0x17U)) + ((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                                      << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                                >> 0x17U)));
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__pc_addr 
        = ((0x100U & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U])
            ? vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_result
            : vlSelfRef.rv_cpu__DOT__execute_stage__DOT__addr_result);
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__17(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__17\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__wen_i 
        = (1U & (IData)((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i 
                         >> 0x25U)));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_addr 
        = (0x1fU & (IData)((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i 
                            >> 0x20U)));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_data 
        = (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i);
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__18(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__18\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_if_o 
        = (((QData)((IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__pc_src)) 
            << 0x20U) | (QData)((IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__pc_addr)));
    vlSelfRef.rv_cpu__DOT__ex_if_w = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_if_o;
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__ex_if_i 
        = vlSelfRef.rv_cpu__DOT__ex_if_w;
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__19(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__19\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_next 
        = ((1U & (IData)((vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__ex_if_i 
                          >> 0x20U))) ? (IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__ex_if_i)
            : ((IData)(4U) + vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_r));
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__20(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__20\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
        = (((((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel) 
              << 0x14U) | (((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en) 
                            << 0x13U) | (((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en) 
                                          << 0x12U) 
                                         | ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen) 
                                            << 0x11U)))) 
            | (((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src) 
                << 0xfU) | ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op) 
                            << 0xbU))) | ((((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src) 
                                            << 0xaU) 
                                           | (((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en) 
                                               << 9U) 
                                              | ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en) 
                                                 << 8U))) 
                                          | (((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_mask) 
                                              << 4U) 
                                             | ((((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_signed) 
                                                  << 3U) 
                                                 | ((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch) 
                                                    << 2U)) 
                                                | (((IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump) 
                                                    << 1U) 
                                                   | (IData)(vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jalr))))));
    vlSelfRef.rv_cpu__DOT__ctl_id_w = vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
        = vlSelfRef.rv_cpu__DOT__ctl_id_w;
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_en_i 
        = (1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                 >> 0x13U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_en_i 
        = (1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                 >> 0x12U));
    vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm_next 
        = ((0x400000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
            ? ((0x200000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
                ? ((0x100000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
                    ? 0U : (((- (IData)((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__jta_imm 
                                               >> 0x13U)))) 
                             << 0x15U) | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__jta_imm 
                                          << 1U))) : 
               ((0x100000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
                 ? (((- (IData)((1U & ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__bta_imm) 
                                       >> 0xbU)))) 
                     << 0xdU) | ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__bta_imm) 
                                 << 1U)) : (((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__st_imm) 
                                                            >> 0xbU)))) 
                                             << 0xcU) 
                                            | (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__st_imm))))
            : ((0x200000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
                ? ((0x100000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
                    ? (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__upimm 
                       << 0xcU) : (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__uimm))
                : ((0x100000U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)
                    ? (((- (IData)((1U & ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm) 
                                          >> 0xbU)))) 
                        << 0xcU) | (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm))
                    : 0U)));
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<13> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/kh-g14/projects/riscv-cpu/src/rtl/rv_cpu.sv", 2, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/kh-g14/projects/riscv-cpu/src/rtl/rv_cpu.sv", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/kh-g14/projects/riscv-cpu/src/rtl/rv_cpu.sv", 2, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk_i & 0xfeU)))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.rstn_i & 0xfeU)))) {
        Verilated::overWidthError("rstn_i");}
    if (VL_UNLIKELY(((vlSelfRef.riscv_en_i & 0xfeU)))) {
        Verilated::overWidthError("riscv_en_i");}
}
#endif  // VL_DEBUG
