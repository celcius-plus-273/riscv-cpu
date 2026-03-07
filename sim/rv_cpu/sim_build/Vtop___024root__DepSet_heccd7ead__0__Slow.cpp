// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__fetch_stage__DOT__clk_i__0 
        = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__fetch_stage__DOT__rstn_i__0 
        = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__rstn_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__clk_i__0 
        = vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__clk_i__0 
        = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__rstn_i__0 
        = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rstn_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__clk_i__0 
        = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i__0 
        = vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__execute_stage__DOT__clk_i__0 
        = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__execute_stage__DOT__rstn_i__0 
        = vlSelfRef.rv_cpu__DOT__execute_stage__DOT__rstn_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__clk_i__0 
        = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__rstn_i__0 
        = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__rstn_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__clk_i__0 
        = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i__0 
        = vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/kh-g14/projects/riscv-cpu/src/rtl/rv_cpu.sv", 2, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*3:0*/, 512> Vtop__ConstPool__TABLE_h482a7531_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
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
    vlSelfRef.rv_cpu__DOT__control_stage__DOT__clk_i 
        = vlSelfRef.rv_cpu__DOT__clk_i;
    vlSelfRef.rv_cpu__DOT__execute_stage__DOT__clk_i 
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

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge rv_cpu.fetch_stage.clk_i)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge rv_cpu.fetch_stage.rstn_i)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge rv_cpu.fetch_stage.i_reg_inst.clk_i)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge rv_cpu.decode_stage.clk_i)\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(negedge rv_cpu.decode_stage.rstn_i)\n");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @(posedge rv_cpu.decode_stage.reg_file_inst.clk_i)\n");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @(negedge rv_cpu.decode_stage.reg_file_inst.rstn_i)\n");
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @(posedge rv_cpu.execute_stage.clk_i)\n");
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @(negedge rv_cpu.execute_stage.rstn_i)\n");
    }
    if ((0x200ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 9 is active: @(posedge rv_cpu.memory_stage.clk_i)\n");
    }
    if ((0x400ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 10 is active: @(negedge rv_cpu.memory_stage.rstn_i)\n");
    }
    if ((0x800ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 11 is active: @(posedge rv_cpu.memory_stage.sram_inst.clk_i)\n");
    }
    if ((0x1000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 12 is active: @(negedge rv_cpu.memory_stage.sram_inst.rstn_i)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge rv_cpu.fetch_stage.clk_i)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge rv_cpu.fetch_stage.rstn_i)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge rv_cpu.fetch_stage.i_reg_inst.clk_i)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge rv_cpu.decode_stage.clk_i)\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(negedge rv_cpu.decode_stage.rstn_i)\n");
    }
    if ((0x20ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @(posedge rv_cpu.decode_stage.reg_file_inst.clk_i)\n");
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @(negedge rv_cpu.decode_stage.reg_file_inst.rstn_i)\n");
    }
    if ((0x80ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @(posedge rv_cpu.execute_stage.clk_i)\n");
    }
    if ((0x100ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @(negedge rv_cpu.execute_stage.rstn_i)\n");
    }
    if ((0x200ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 9 is active: @(posedge rv_cpu.memory_stage.clk_i)\n");
    }
    if ((0x400ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 10 is active: @(negedge rv_cpu.memory_stage.rstn_i)\n");
    }
    if ((0x800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 11 is active: @(posedge rv_cpu.memory_stage.sram_inst.clk_i)\n");
    }
    if ((0x1000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 12 is active: @(negedge rv_cpu.memory_stage.sram_inst.rstn_i)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11908517815223722933ull);
    vlSelf->rstn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13254468488862703655ull);
    vlSelf->riscv_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 130412068927183594ull);
    vlSelf->rv_cpu__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3418910723777869639ull);
    vlSelf->rv_cpu__DOT__rstn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18116251669238247439ull);
    vlSelf->rv_cpu__DOT__riscv_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16456221573290219562ull);
    vlSelf->rv_cpu__DOT__id_ctl_w = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11641304427760204560ull);
    vlSelf->rv_cpu__DOT__ctl_id_w = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 3595907333960361329ull);
    vlSelf->rv_cpu__DOT__id_hzd_w = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 18303414301060394971ull);
    vlSelf->rv_cpu__DOT__ex_if_w = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 10167839519019326776ull);
    vlSelf->rv_cpu__DOT__wb_id_w = VL_SCOPED_RAND_RESET_Q(38, __VscopeHash, 7267064481190568004ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->rv_cpu__DOT__if_id_w, __VscopeHash, 3272975691462106467ull);
    VL_SCOPED_RAND_RESET_W(183, vlSelf->rv_cpu__DOT__id_ex_w, __VscopeHash, 17895578531904666432ull);
    VL_SCOPED_RAND_RESET_W(143, vlSelf->rv_cpu__DOT__ex_mem_w, __VscopeHash, 16844288102170461393ull);
    VL_SCOPED_RAND_RESET_W(142, vlSelf->rv_cpu__DOT__mem_wb_w, __VscopeHash, 16945461785146766176ull);
    vlSelf->rv_cpu__DOT__fetch_stage__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14708992844643255888ull);
    vlSelf->rv_cpu__DOT__fetch_stage__DOT__en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1011948792126111672ull);
    vlSelf->rv_cpu__DOT__fetch_stage__DOT__rstn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11919922405723009526ull);
    vlSelf->rv_cpu__DOT__fetch_stage__DOT__ex_if_i = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 7158974608817525952ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->rv_cpu__DOT__fetch_stage__DOT__if_id_o, __VscopeHash, 8343275035169880169ull);
    vlSelf->rv_cpu__DOT__fetch_stage__DOT__pc_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16246936919860754452ull);
    vlSelf->rv_cpu__DOT__fetch_stage__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15576746343612525179ull);
    vlSelf->rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17968322070445774155ull);
    vlSelf->rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4737746035074048274ull);
    vlSelf->rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__rstn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14921123846408978096ull);
    vlSelf->rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__pc_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18176517348464841695ull);
    vlSelf->rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__inst_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1313612252634274529ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15507806593216704318ull);
    }
    vlSelf->rv_cpu__DOT__decode_stage__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13215402605908186425ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__rstn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12348588995843181031ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__ctl_id_i = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 16761034692849971073ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__id_ctl_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 5332669595235780877ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__id_hzd_o = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 6789986253946516047ull);
    VL_SCOPED_RAND_RESET_W(96, vlSelf->rv_cpu__DOT__decode_stage__DOT__if_id_i, __VscopeHash, 16296764565450533793ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__wb_id_i = VL_SCOPED_RAND_RESET_Q(38, __VscopeHash, 18205667506451017866ull);
    VL_SCOPED_RAND_RESET_W(183, vlSelf->rv_cpu__DOT__decode_stage__DOT__id_ex_o, __VscopeHash, 17649479200792505472ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 8901456065985638067ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__inst_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8039858138716717936ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__rs1_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13094736945194184624ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__rs2_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12839520834897620210ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__funct7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 3955317077050195333ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9356654830348546570ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__imm = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 9958600026647650189ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__uimm = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3664470281405112790ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__upimm = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 11376624327138187001ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__st_imm = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 18180204453425035153ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__bta_imm = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 3386880088765311975ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__jta_imm = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 17040123769577184274ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__imm_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11105639266070824486ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16720783197891976370ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10090455447612083687ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2882987393091043973ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__wen_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16591726548922499471ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16952526781092517154ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14764061151314551356ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1227968064378957197ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_addr_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17752605110699312061ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13672526943314386969ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12027780774215715835ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_addr_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4102106749148591602ull);
    vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18005807130773923957ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1258220818636120958ull);
    }
    vlSelf->rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->rv_cpu__DOT__control_stage__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15483424581793484440ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__id_ctl_i = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11577981525144626598ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__ctl_id_o = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 1779849926917880132ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__inst_next = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12431581597622728411ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 16809909354488322250ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7256540924519183641ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__funct7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 10063195736936167679ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__imm_sel = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1296303535340136125ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__r1_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14605197940573473144ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__r2_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1981529246613967203ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__rd_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7970811533146821735ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__wb_src = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15102589095322339651ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__mem_rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5782852076694193688ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__mem_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 341274658847293811ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__mem_mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18422884013982470323ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__mem_signed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10564962009416504509ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__is_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8869868186423833896ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__is_jump = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3906307375935097165ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__is_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12901930138575067385ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__alu_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 236165912811482643ull);
    vlSelf->rv_cpu__DOT__control_stage__DOT__alu_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4755937577578732641ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13434430335207983127ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__rstn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 221356217857958169ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__ex_if_o = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 6688027936224373291ull);
    VL_SCOPED_RAND_RESET_W(183, vlSelf->rv_cpu__DOT__execute_stage__DOT__id_ex_i, __VscopeHash, 9470361697420568798ull);
    VL_SCOPED_RAND_RESET_W(143, vlSelf->rv_cpu__DOT__execute_stage__DOT__ex_mem_o, __VscopeHash, 749317368704325392ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__alu_srcA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13318224437485117173ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__alu_srcB = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16482677655964845113ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17383598984190606565ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__pc_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4127836611379559019ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__pc_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10940988766303537410ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__addr_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15483097568240182081ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3622545127535820831ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 572149544707823655ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17788324937712227634ull);
    vlSelf->rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__result_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8594932028533411573ull);
    vlSelf->rv_cpu__DOT__memory_stage__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8694643723378482680ull);
    vlSelf->rv_cpu__DOT__memory_stage__DOT__rstn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 617833515030776697ull);
    VL_SCOPED_RAND_RESET_W(143, vlSelf->rv_cpu__DOT__memory_stage__DOT__ex_mem_i, __VscopeHash, 12998177769377773364ull);
    VL_SCOPED_RAND_RESET_W(142, vlSelf->rv_cpu__DOT__memory_stage__DOT__mem_wb_o, __VscopeHash, 14993007770221285457ull);
    vlSelf->rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15643196402436335576ull);
    vlSelf->rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14372744072961219143ull);
    vlSelf->rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__cenb_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3954640443584577908ull);
    vlSelf->rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__wenb_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3357864354987840732ull);
    vlSelf->rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8755733735870806035ull);
    vlSelf->rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4600145972060161970ull);
    vlSelf->rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7147958175601233693ull);
    vlSelf->rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3990970407140150605ull);
    vlSelf->rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9770013189242121463ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11436247932767430846ull);
    }
    vlSelf->rv_cpu__DOT__writeback_stage__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17444799682113643932ull);
    vlSelf->rv_cpu__DOT__writeback_stage__DOT__rstn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12519852780925651480ull);
    VL_SCOPED_RAND_RESET_W(142, vlSelf->rv_cpu__DOT__writeback_stage__DOT__mem_wb_i, __VscopeHash, 9459229324584905321ull);
    vlSelf->rv_cpu__DOT__writeback_stage__DOT__wb_id_o = VL_SCOPED_RAND_RESET_Q(38, __VscopeHash, 2827469710341856483ull);
    vlSelf->rv_cpu__DOT__writeback_stage__DOT__mem_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9876113120328571275ull);
    vlSelf->rv_cpu__DOT__writeback_stage__DOT__mem_data_ext = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6695979669767959762ull);
    VL_SCOPED_RAND_RESET_W(183, vlSelf->__Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o, __VscopeHash, 15064466578309285552ull);
    VL_SCOPED_RAND_RESET_W(183, vlSelf->__VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o, __VscopeHash, 5158116263261943563ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__fetch_stage__DOT__clk_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11056562803924979527ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__fetch_stage__DOT__rstn_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 857729358787312564ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__clk_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17007299930959152642ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__clk_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18058562424973089201ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__rstn_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17061215336048741390ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__clk_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10298244815283725912ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13003397382573023550ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__execute_stage__DOT__clk_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9836164100172136047ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__execute_stage__DOT__rstn_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6420218667334516084ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__clk_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14453449816802151990ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__rstn_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1858485037903540106ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__clk_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17646004588815670353ull);
    vlSelf->__Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8722644855253795284ull);
}
