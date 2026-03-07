// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

// Parameter definitions for Vtop___024root
constexpr IData/*31:0*/ Vtop___024root::rv_cpu__DOT__fetch_stage__DOT__I_MEM_DEPTH;
constexpr IData/*31:0*/ Vtop___024root::rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__DEPTH;
constexpr IData/*31:0*/ Vtop___024root::rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__NUM_BYTES;
constexpr IData/*31:0*/ Vtop___024root::rv_cpu__DOT__decode_stage__DOT__RF_DEPTH;
constexpr IData/*31:0*/ Vtop___024root::rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__WIDTH;
constexpr IData/*31:0*/ Vtop___024root::rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__DEPTH;
constexpr IData/*31:0*/ Vtop___024root::rv_cpu__DOT__memory_stage__DOT__D_MEM_DEPTH;
constexpr IData/*31:0*/ Vtop___024root::rv_cpu__DOT__memory_stage__DOT__D_MEM_ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__DEPTH;
constexpr IData/*31:0*/ Vtop___024root::rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__WIDTH;
constexpr IData/*31:0*/ Vtop___024root::rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__NUM_BYTES;
constexpr IData/*31:0*/ Vtop___024root::rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__ADDR_WIDTH;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __Vm_mtaskstate_21(1U)
    , __Vm_mtaskstate_27(1U)
    , __Vm_mtaskstate_12(1U)
    , __Vm_mtaskstate_20(2U)
    , __Vm_mtaskstate_13(1U)
    , __Vm_mtaskstate_10(1U)
    , __Vm_mtaskstate_24(3U)
    , __Vm_mtaskstate_14(1U)
    , __Vm_mtaskstate_5(1U)
    , __Vm_mtaskstate_7(3U)
    , __Vm_mtaskstate_23(2U)
    , __Vm_mtaskstate_18(2U)
    , __Vm_mtaskstate_16(1U)
    , __Vm_mtaskstate_28(2U)
    , __Vm_mtaskstate_8(2U)
    , __Vm_mtaskstate_29(7U)
    , __Vm_mtaskstate_final__0nba(4U)
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
}
