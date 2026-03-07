// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_RV_CPU_PKG_H_
#define VERILATED_VTOP_RV_CPU_PKG_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_rv_cpu_pkg final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ REG_FILE_DEPTH = 0x00000020U;
    static constexpr IData/*31:0*/ I_MEM_DEPTH = 0x00000040U;
    static constexpr IData/*31:0*/ D_MEM_DEPTH = 0x00000100U;
    static constexpr IData/*31:0*/ RF_ADDR_WIDTH = 5U;
    static constexpr IData/*31:0*/ I_MEM_ADDR_WIDTH = 6U;
    static constexpr IData/*31:0*/ D_MEM_ADDR_WIDTH = 8U;

    // CONSTRUCTORS
    Vtop_rv_cpu_pkg(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_rv_cpu_pkg();
    VL_UNCOPYABLE(Vtop_rv_cpu_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
