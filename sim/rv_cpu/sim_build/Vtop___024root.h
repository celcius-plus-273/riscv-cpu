// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"
class Vtop_rv_cpu_pkg;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop_rv_cpu_pkg* __PVT__rv_cpu_pkg;

    // DESIGN SPECIFIC STATE
    IData/*31:0*/ rv_cpu__DOT__execute_stage__DOT__alu_result;
    VlWide<6>/*182:0*/ rv_cpu__DOT__execute_stage__DOT__id_ex_i;
    IData/*31:0*/ rv_cpu__DOT__execute_stage__DOT__addr_result;
    CData/*0:0*/ rv_cpu__DOT__execute_stage__DOT__rstn_i;
    IData/*31:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i;
    VlWide<5>/*142:0*/ rv_cpu__DOT__execute_stage__DOT__ex_mem_o;
    VlWide<5>/*142:0*/ rv_cpu__DOT__ex_mem_w;
    VlUnpacked<IData/*31:0*/, 256> rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array;
    CData/*0:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__cenb_i;
    CData/*0:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__wenb_i;
    CData/*3:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i;
    CData/*7:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i;
    CData/*0:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i;
    IData/*31:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i;
    IData/*31:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_i;
    VlNBACommitQueue<VlUnpacked<IData/*31:0*/, 256>, true, IData/*31:0*/, 1> __VdlyCommitQueuerv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array;
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VlWide<5>/*142:0*/ rv_cpu__DOT__memory_stage__DOT__ex_mem_i;
        CData/*0:0*/ rv_cpu__DOT__memory_stage__DOT__rstn_i;
        VlWide<5>/*141:0*/ rv_cpu__DOT__memory_stage__DOT__mem_wb_o;
        IData/*31:0*/ rv_cpu__DOT__writeback_stage__DOT__mem_data;
        IData/*31:0*/ rv_cpu__DOT__writeback_stage__DOT__mem_data_ext;
        QData/*37:0*/ rv_cpu__DOT__wb_id_w;
        VlWide<5>/*141:0*/ rv_cpu__DOT__mem_wb_w;
        VlWide<5>/*141:0*/ rv_cpu__DOT__writeback_stage__DOT__mem_wb_i;
        QData/*37:0*/ rv_cpu__DOT__writeback_stage__DOT__wb_id_o;
        QData/*37:0*/ rv_cpu__DOT__decode_stage__DOT__wb_id_i;
        CData/*0:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__wen_i;
        IData/*31:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_addr;
        IData/*31:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_data;
        VlUnpacked<IData/*31:0*/, 32> rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem;
        CData/*0:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i;
        CData/*0:0*/ rv_cpu__DOT__fetch_stage__DOT__en_i;
        CData/*0:0*/ rv_cpu__DOT__fetch_stage__DOT__rstn_i;
        IData/*31:0*/ rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__pc_i;
        IData/*31:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o;
        IData/*31:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o;
        CData/*3:0*/ rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i;
        IData/*31:0*/ rv_cpu__DOT__execute_stage__DOT__alu_srcA;
        IData/*31:0*/ rv_cpu__DOT__execute_stage__DOT__alu_srcB;
        IData/*31:0*/ rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i;
        IData/*31:0*/ rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i;
        IData/*31:0*/ rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__result_o;
        VlWide<6>/*182:0*/ rv_cpu__DOT__id_ex_w;
        VlWide<6>/*182:0*/ rv_cpu__DOT__decode_stage__DOT__id_ex_o;
        VlWide<6>/*182:0*/ __Vdly__rv_cpu__DOT__decode_stage__DOT__id_ex_o;
        VlWide<6>/*182:0*/ __VdlyMask__rv_cpu__DOT__decode_stage__DOT__id_ex_o;
        CData/*0:0*/ rv_cpu__DOT__decode_stage__DOT__rstn_i;
        CData/*0:0*/ rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__en_i;
        CData/*0:0*/ rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__rstn_i;
        VlUnpacked<IData/*31:0*/, 64> rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__mem;
        IData/*31:0*/ rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__inst_o;
        VlWide<3>/*95:0*/ rv_cpu__DOT__decode_stage__DOT__if_id_i;
        CData/*6:0*/ rv_cpu__DOT__decode_stage__DOT__opcode;
        CData/*6:0*/ rv_cpu__DOT__decode_stage__DOT__funct7;
        CData/*2:0*/ rv_cpu__DOT__decode_stage__DOT__funct3;
        IData/*16:0*/ rv_cpu__DOT__id_ctl_w;
        IData/*16:0*/ rv_cpu__DOT__decode_stage__DOT__id_ctl_o;
        VlWide<3>/*95:0*/ rv_cpu__DOT__if_id_w;
        CData/*6:0*/ rv_cpu__DOT__control_stage__DOT__opcode;
        VlWide<3>/*95:0*/ rv_cpu__DOT__fetch_stage__DOT__if_id_o;
        IData/*16:0*/ rv_cpu__DOT__control_stage__DOT__id_ctl_i;
        IData/*31:0*/ rv_cpu__DOT__decode_stage__DOT__inst_i;
        IData/*19:0*/ rv_cpu__DOT__decode_stage__DOT__jta_imm;
        CData/*0:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_en_i;
        CData/*0:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_en_i;
        IData/*31:0*/ rv_cpu__DOT__fetch_stage__DOT__pc_next;
        IData/*31:0*/ rv_cpu__DOT__fetch_stage__DOT__pc_r;
        QData/*32:0*/ rv_cpu__DOT__ex_if_w;
        QData/*32:0*/ rv_cpu__DOT__fetch_stage__DOT__ex_if_i;
        QData/*32:0*/ rv_cpu__DOT__execute_stage__DOT__ex_if_o;
        IData/*31:0*/ rv_cpu__DOT__execute_stage__DOT__pc_addr;
        CData/*0:0*/ rv_cpu__DOT__execute_stage__DOT__pc_src;
        IData/*31:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o;
        CData/*4:0*/ rv_cpu__DOT__decode_stage__DOT__uimm;
        SData/*11:0*/ rv_cpu__DOT__decode_stage__DOT__imm;
        SData/*11:0*/ rv_cpu__DOT__decode_stage__DOT__st_imm;
        SData/*11:0*/ rv_cpu__DOT__decode_stage__DOT__bta_imm;
        IData/*19:0*/ rv_cpu__DOT__decode_stage__DOT__upimm;
        CData/*4:0*/ rv_cpu__DOT__decode_stage__DOT__rs1_addr;
        CData/*4:0*/ rv_cpu__DOT__decode_stage__DOT__rs2_addr;
    };
    struct {
        SData/*9:0*/ rv_cpu__DOT__id_hzd_w;
        SData/*9:0*/ rv_cpu__DOT__decode_stage__DOT__id_hzd_o;
        IData/*31:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_addr_i;
        IData/*31:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_addr_i;
        CData/*4:0*/ rv_cpu__DOT__decode_stage__DOT__rd_addr;
        IData/*22:0*/ rv_cpu__DOT__decode_stage__DOT__ctl_id_i;
        IData/*31:0*/ rv_cpu__DOT__decode_stage__DOT__imm_next;
        IData/*22:0*/ rv_cpu__DOT__ctl_id_w;
        IData/*22:0*/ rv_cpu__DOT__control_stage__DOT__ctl_id_o;
        CData/*0:0*/ rv_cpu__DOT__control_stage__DOT__r1_en;
        CData/*0:0*/ rv_cpu__DOT__control_stage__DOT__alu_src;
        CData/*0:0*/ rv_cpu__DOT__control_stage__DOT__is_jump;
        CData/*0:0*/ rv_cpu__DOT__control_stage__DOT__is_jalr;
        CData/*1:0*/ rv_cpu__DOT__control_stage__DOT__wb_src;
        CData/*0:0*/ rv_cpu__DOT__control_stage__DOT__mem_rd_en;
        CData/*0:0*/ rv_cpu__DOT__control_stage__DOT__r2_en;
        CData/*0:0*/ rv_cpu__DOT__control_stage__DOT__rd_wen;
        CData/*2:0*/ rv_cpu__DOT__control_stage__DOT__imm_sel;
        CData/*0:0*/ rv_cpu__DOT__control_stage__DOT__mem_wr_en;
        CData/*0:0*/ rv_cpu__DOT__control_stage__DOT__is_branch;
        CData/*3:0*/ rv_cpu__DOT__control_stage__DOT__mem_mask;
        CData/*0:0*/ rv_cpu__DOT__control_stage__DOT__mem_signed;
        CData/*3:0*/ rv_cpu__DOT__control_stage__DOT__alu_op;
        CData/*6:0*/ rv_cpu__DOT__control_stage__DOT__funct7;
        CData/*2:0*/ rv_cpu__DOT__control_stage__DOT__funct3;
        CData/*3:0*/ rv_cpu__DOT__control_stage__DOT__inst_next;
        CData/*0:0*/ rv_cpu__DOT__fetch_stage__DOT__clk_i;
        CData/*0:0*/ rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__clk_i;
        CData/*0:0*/ rv_cpu__DOT__decode_stage__DOT__clk_i;
        CData/*0:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__clk_i;
        CData/*0:0*/ rv_cpu__DOT__execute_stage__DOT__clk_i;
        CData/*0:0*/ rv_cpu__DOT__memory_stage__DOT__clk_i;
        CData/*0:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__clk_i;
        VL_IN8(clk_i,0,0);
        VL_IN8(rstn_i,0,0);
        VL_IN8(riscv_en_i,0,0);
        CData/*0:0*/ rv_cpu__DOT__clk_i;
        CData/*0:0*/ rv_cpu__DOT__rstn_i;
        CData/*0:0*/ rv_cpu__DOT__riscv_en_i;
        CData/*0:0*/ rv_cpu__DOT__control_stage__DOT__clk_i;
        CData/*0:0*/ rv_cpu__DOT__writeback_stage__DOT__clk_i;
        CData/*0:0*/ rv_cpu__DOT__writeback_stage__DOT__rstn_i;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__fetch_stage__DOT__clk_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__fetch_stage__DOT__rstn_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__clk_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__clk_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__rstn_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__clk_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__execute_stage__DOT__clk_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__execute_stage__DOT__rstn_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__clk_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__rstn_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__clk_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i__0;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ __VactIterCount;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<13> __VactTriggered;
    VlTriggerVec<13> __VnbaTriggered;
    VlMTaskVertex __Vm_mtaskstate_21;
    VlMTaskVertex __Vm_mtaskstate_27;
    VlMTaskVertex __Vm_mtaskstate_12;
    VlMTaskVertex __Vm_mtaskstate_20;
    VlMTaskVertex __Vm_mtaskstate_13;
    VlMTaskVertex __Vm_mtaskstate_10;
    VlMTaskVertex __Vm_mtaskstate_24;
    VlMTaskVertex __Vm_mtaskstate_14;
    VlMTaskVertex __Vm_mtaskstate_5;
    VlMTaskVertex __Vm_mtaskstate_7;
    VlMTaskVertex __Vm_mtaskstate_23;
    VlMTaskVertex __Vm_mtaskstate_18;
    VlMTaskVertex __Vm_mtaskstate_16;
    VlMTaskVertex __Vm_mtaskstate_28;
    VlMTaskVertex __Vm_mtaskstate_8;
    VlMTaskVertex __Vm_mtaskstate_29;
    VlMTaskVertex __Vm_mtaskstate_final__0nba;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ rv_cpu__DOT__fetch_stage__DOT__I_MEM_DEPTH = 0x00000040U;
    static constexpr IData/*31:0*/ rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__DEPTH = 0x00000040U;
    static constexpr IData/*31:0*/ rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__NUM_BYTES = 4U;
    static constexpr IData/*31:0*/ rv_cpu__DOT__decode_stage__DOT__RF_DEPTH = 0x00000020U;
    static constexpr IData/*31:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__DEPTH = 0x00000020U;
    static constexpr IData/*31:0*/ rv_cpu__DOT__memory_stage__DOT__D_MEM_DEPTH = 0x00000100U;
    static constexpr IData/*31:0*/ rv_cpu__DOT__memory_stage__DOT__D_MEM_ADDR_WIDTH = 8U;
    static constexpr IData/*31:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__DEPTH = 0x00000100U;
    static constexpr IData/*31:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__NUM_BYTES = 4U;
    static constexpr IData/*31:0*/ rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__ADDR_WIDTH = 8U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
