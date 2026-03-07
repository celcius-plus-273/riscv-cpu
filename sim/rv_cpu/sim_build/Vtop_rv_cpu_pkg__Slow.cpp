// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_rv_cpu_pkg.h"

// Parameter definitions for Vtop_rv_cpu_pkg
constexpr IData/*31:0*/ Vtop_rv_cpu_pkg::REG_FILE_DEPTH;
constexpr IData/*31:0*/ Vtop_rv_cpu_pkg::I_MEM_DEPTH;
constexpr IData/*31:0*/ Vtop_rv_cpu_pkg::D_MEM_DEPTH;
constexpr IData/*31:0*/ Vtop_rv_cpu_pkg::RF_ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop_rv_cpu_pkg::I_MEM_ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop_rv_cpu_pkg::D_MEM_ADDR_WIDTH;


void Vtop_rv_cpu_pkg___ctor_var_reset(Vtop_rv_cpu_pkg* vlSelf);

Vtop_rv_cpu_pkg::Vtop_rv_cpu_pkg(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_rv_cpu_pkg___ctor_var_reset(this);
}

void Vtop_rv_cpu_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_rv_cpu_pkg::~Vtop_rv_cpu_pkg() {
}
