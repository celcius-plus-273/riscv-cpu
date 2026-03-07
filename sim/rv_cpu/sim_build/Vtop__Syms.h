// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"
#include "Vtop___024unit.h"
#include "Vtop_rv_cpu_pkg.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MULTI-THREADING
    VlThreadPool* __Vm_threadPoolp;
    bool __Vm_even_cycle__ico = false;
    bool __Vm_even_cycle__act = false;
    bool __Vm_even_cycle__nba = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;
    Vtop_rv_cpu_pkg                TOP__rv_cpu_pkg;

    // SCOPE NAMES
    VerilatedScope __Vscope_TOP;
    VerilatedScope __Vscope_rv_cpu;
    VerilatedScope __Vscope_rv_cpu__control_stage;
    VerilatedScope __Vscope_rv_cpu__decode_stage;
    VerilatedScope __Vscope_rv_cpu__decode_stage__reg_file_inst;
    VerilatedScope __Vscope_rv_cpu__decode_stage__reg_file_inst__write_ff;
    VerilatedScope __Vscope_rv_cpu__decode_stage__reg_file_inst__write_ff__unnamedblk1;
    VerilatedScope __Vscope_rv_cpu__execute_stage;
    VerilatedScope __Vscope_rv_cpu__execute_stage__alu_inst;
    VerilatedScope __Vscope_rv_cpu__fetch_stage;
    VerilatedScope __Vscope_rv_cpu__fetch_stage__i_reg_inst;
    VerilatedScope __Vscope_rv_cpu__memory_stage;
    VerilatedScope __Vscope_rv_cpu__memory_stage__sram_inst;
    VerilatedScope __Vscope_rv_cpu__writeback_stage;
    VerilatedScope __Vscope_rv_cpu_pkg;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
