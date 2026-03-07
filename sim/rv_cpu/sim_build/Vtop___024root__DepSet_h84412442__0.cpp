// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__fetch_stage__DOT__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__rstn_i)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__fetch_stage__DOT__rstn_i__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(3U, ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(4U, ((~ (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rstn_i)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__rstn_i__0)));
    vlSelfRef.__VactTriggered.setBit(5U, ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(6U, ((~ (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i__0)));
    vlSelfRef.__VactTriggered.setBit(7U, ((IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__execute_stage__DOT__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(8U, ((~ (IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__rstn_i)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__execute_stage__DOT__rstn_i__0)));
    vlSelfRef.__VactTriggered.setBit(9U, ((IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(0xaU, ((~ (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__rstn_i)) 
                                            & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__rstn_i__0)));
    vlSelfRef.__VactTriggered.setBit(0xbU, ((IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__clk_i) 
                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(0xcU, ((~ (IData)(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i)) 
                                            & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i__0)));
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
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vtop___024root____Vthread__nba__s0__t0(void* voidSelf, bool even_cycle);
void Vtop___024root____Vthread__nba__s0__t1(void* voidSelf, bool even_cycle);
void Vtop___024root____Vthread__nba__s0__t2(void* voidSelf, bool even_cycle);
void Vtop___024root____Vthread__nba__s0__t3(void* voidSelf, bool even_cycle);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->__Vm_even_cycle__nba = !vlSymsp->__Vm_even_cycle__nba;
    vlSymsp->__Vm_threadPoolp->workerp(0)->addTask(&Vtop___024root____Vthread__nba__s0__t0, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSymsp->__Vm_threadPoolp->workerp(1)->addTask(&Vtop___024root____Vthread__nba__s0__t1, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSymsp->__Vm_threadPoolp->workerp(2)->addTask(&Vtop___024root____Vthread__nba__s0__t2, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    Vtop___024root____Vthread__nba__s0__t3(vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSelf->__Vm_mtaskstate_final__0nba.waitUntilUpstreamDone(vlSymsp->__Vm_even_cycle__nba);
    Verilated::mtaskId(0);
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 0;
    Verilated::mtaskId(taskId);
    if ((0x60ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x180ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 1;
    Verilated::mtaskId(taskId);
    if ((0x1800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 2;
    Verilated::mtaskId(taskId);
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x18ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 3;
    Verilated::mtaskId(taskId);
    if ((0x600ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 4;
    Verilated::mtaskId(taskId);
    if ((0x1800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__6(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_sequent__TOP__7(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 5;
    Verilated::mtaskId(taskId);
    if ((0x18ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__7(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_sequent__TOP__8(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 6;
    Verilated::mtaskId(taskId);
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__8(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_sequent__TOP__9(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__10(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 7;
    Verilated::mtaskId(taskId);
    if ((0x1800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((0x180ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__10(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_sequent__TOP__11(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 8;
    Verilated::mtaskId(taskId);
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__11(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask9(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 9;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_sequent__TOP__12(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__2(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask10(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask10\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 10;
    Verilated::mtaskId(taskId);
    if ((0x1800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__12(vlSelf);
    }
    if ((0x1e00ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__2(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__3(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask11(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 11;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__3(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__4(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask12(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask12\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 12;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__4(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__5(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask13(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask13\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 13;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__5(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__6(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask14(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask14\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 14;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__6(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__7(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask15(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask15\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 15;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__7(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__8(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask16(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask16\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 16;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__8(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__9(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask17(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask17\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 17;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__9(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__10(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask18(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask18\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 18;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__10(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__11(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask19(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask19\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 19;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__11(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__12(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask20(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask20\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 20;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__12(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_sequent__TOP__13(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__14(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask21(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask21\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 21;
    Verilated::mtaskId(taskId);
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__13(vlSelf);
    }
    if ((0x60ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__14(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_sequent__TOP__15(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask22(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask22\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 22;
    Verilated::mtaskId(taskId);
    if ((0x60ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__15(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__13(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask23(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask23\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 23;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__13(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_sequent__TOP__16(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__14(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask24(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask24\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 24;
    Verilated::mtaskId(taskId);
    if ((0x60ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__16(vlSelf);
    }
    if ((0x78ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__14(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__15(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask25(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask25\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 25;
    Verilated::mtaskId(taskId);
    if ((0x78ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__15(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__16(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask26(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask26\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 26;
    Verilated::mtaskId(taskId);
    if ((0x78ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__16(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__17(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask27(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask27\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 27;
    Verilated::mtaskId(taskId);
    if ((0x1e00ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__17(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__18(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__19(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask28(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask28\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 28;
    Verilated::mtaskId(taskId);
    if ((0x78ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__18(vlSelf);
    }
    if ((0x7bULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__19(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root___nba_comb__TOP__20(Vtop___024root* vlSelf);

void Vtop___024root__nba_mtask29(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__nba_mtask29\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    static constexpr unsigned taskId = 29;
    Verilated::mtaskId(taskId);
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__20(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtop___024root____Vthread__nba__s0__t0(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vthread__nba__s0__t0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__nba_mtask2(vlSelf);
    vlSelf->__Vm_mtaskstate_5.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_8.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_21.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask21(vlSelf);
    vlSelf->__Vm_mtaskstate_23.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_24.signalUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask22(vlSelf);
    vlSelf->__Vm_mtaskstate_27.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask27(vlSelf);
    vlSelf->__Vm_mtaskstate_12.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask12(vlSelf);
    vlSelf->__Vm_mtaskstate_29.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_20.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask20(vlSelf);
    vlSelf->__Vm_mtaskstate_29.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_13.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask13(vlSelf);
    vlSelf->__Vm_mtaskstate_29.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void Vtop___024root____Vthread__nba__s0__t1(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vthread__nba__s0__t1\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__nba_mtask6(vlSelf);
    vlSelf->__Vm_mtaskstate_8.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_21.signalUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask4(vlSelf);
    vlSelf->__Vm_mtaskstate_7.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_10.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask10(vlSelf);
    vlSelf->__Vm_mtaskstate_27.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_24.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask24(vlSelf);
    Vtop___024root__nba_mtask26(vlSelf);
    vlSelf->__Vm_mtaskstate_28.signalUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask25(vlSelf);
    vlSelf->__Vm_mtaskstate_28.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_14.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask14(vlSelf);
    vlSelf->__Vm_mtaskstate_29.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void Vtop___024root____Vthread__nba__s0__t2(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vthread__nba__s0__t2\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__nba_mtask0(vlSelf);
    vlSelf->__Vm_mtaskstate_24.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_5.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask5(vlSelf);
    vlSelf->__Vm_mtaskstate_24.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_7.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask7(vlSelf);
    vlSelf->__Vm_mtaskstate_23.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask23(vlSelf);
    vlSelf->__Vm_mtaskstate_29.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_18.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask18(vlSelf);
    vlSelf->__Vm_mtaskstate_29.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_16.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask16(vlSelf);
    vlSelf->__Vm_mtaskstate_29.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_28.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask28(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}

void Vtop___024root____Vthread__nba__s0__t3(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vthread__nba__s0__t3\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__nba_mtask3(vlSelf);
    vlSelf->__Vm_mtaskstate_7.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_10.signalUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask1(vlSelf);
    vlSelf->__Vm_mtaskstate_7.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_8.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask8(vlSelf);
    vlSelf->__Vm_mtaskstate_23.signalUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask11(vlSelf);
    vlSelf->__Vm_mtaskstate_12.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_13.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_14.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_16.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_18.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_20.signalUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask9(vlSelf);
    vlSelf->__Vm_mtaskstate_18.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_20.signalUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask15(vlSelf);
    Vtop___024root__nba_mtask19(vlSelf);
    Vtop___024root__nba_mtask17(vlSelf);
    vlSelf->__Vm_mtaskstate_29.waitUntilUpstreamDone(even_cycle);
    Vtop___024root__nba_mtask29(vlSelf);
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}
