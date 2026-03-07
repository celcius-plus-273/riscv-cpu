// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop___024unit.h"
#include "Vtop_rv_cpu_pkg.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_rv_cpu);
    __Vhier.remove(0, &__Vscope_rv_cpu_pkg);
    __Vhier.remove(&__Vscope_rv_cpu, &__Vscope_rv_cpu__control_stage);
    __Vhier.remove(&__Vscope_rv_cpu, &__Vscope_rv_cpu__decode_stage);
    __Vhier.remove(&__Vscope_rv_cpu, &__Vscope_rv_cpu__execute_stage);
    __Vhier.remove(&__Vscope_rv_cpu, &__Vscope_rv_cpu__fetch_stage);
    __Vhier.remove(&__Vscope_rv_cpu, &__Vscope_rv_cpu__memory_stage);
    __Vhier.remove(&__Vscope_rv_cpu, &__Vscope_rv_cpu__writeback_stage);
    __Vhier.remove(&__Vscope_rv_cpu__decode_stage, &__Vscope_rv_cpu__decode_stage__reg_file_inst);
    __Vhier.remove(&__Vscope_rv_cpu__decode_stage__reg_file_inst, &__Vscope_rv_cpu__decode_stage__reg_file_inst__write_ff);
    __Vhier.remove(&__Vscope_rv_cpu__decode_stage__reg_file_inst__write_ff, &__Vscope_rv_cpu__decode_stage__reg_file_inst__write_ff__unnamedblk1);
    __Vhier.remove(&__Vscope_rv_cpu__execute_stage, &__Vscope_rv_cpu__execute_stage__alu_inst);
    __Vhier.remove(&__Vscope_rv_cpu__fetch_stage, &__Vscope_rv_cpu__fetch_stage__i_reg_inst);
    __Vhier.remove(&__Vscope_rv_cpu__memory_stage, &__Vscope_rv_cpu__memory_stage__sram_inst);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_threadPoolp{static_cast<VlThreadPool*>(contextp->threadPoolp())}
    // Setup module instances
    , TOP{this, namep}
    , TOP__rv_cpu_pkg{this, Verilated::catName(namep, "rv_cpu_pkg")}
{
        // Check resources
        Verilated::stackCheck(363);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-11);
    // Setup each module's pointers to their submodules
    TOP.__PVT__rv_cpu_pkg = &TOP__rv_cpu_pkg;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__rv_cpu_pkg.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_rv_cpu.configure(this, name(), "rv_cpu", "rv_cpu", "rv_cpu", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_rv_cpu__control_stage.configure(this, name(), "rv_cpu.control_stage", "control_stage", "control", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_rv_cpu__decode_stage.configure(this, name(), "rv_cpu.decode_stage", "decode_stage", "pipe_id", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_rv_cpu__decode_stage__reg_file_inst.configure(this, name(), "rv_cpu.decode_stage.reg_file_inst", "reg_file_inst", "reg_file", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_rv_cpu__decode_stage__reg_file_inst__write_ff.configure(this, name(), "rv_cpu.decode_stage.reg_file_inst.write_ff", "write_ff", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_rv_cpu__decode_stage__reg_file_inst__write_ff__unnamedblk1.configure(this, name(), "rv_cpu.decode_stage.reg_file_inst.write_ff.unnamedblk1", "unnamedblk1", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_rv_cpu__execute_stage.configure(this, name(), "rv_cpu.execute_stage", "execute_stage", "pipe_ex", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_rv_cpu__execute_stage__alu_inst.configure(this, name(), "rv_cpu.execute_stage.alu_inst", "alu_inst", "alu", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_rv_cpu__fetch_stage.configure(this, name(), "rv_cpu.fetch_stage", "fetch_stage", "pipe_if", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_rv_cpu__fetch_stage__i_reg_inst.configure(this, name(), "rv_cpu.fetch_stage.i_reg_inst", "i_reg_inst", "i_reg", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_rv_cpu__memory_stage.configure(this, name(), "rv_cpu.memory_stage", "memory_stage", "pipe_mem", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_rv_cpu__memory_stage__sram_inst.configure(this, name(), "rv_cpu.memory_stage.sram_inst", "sram_inst", "sram_rw_dff", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_rv_cpu__writeback_stage.configure(this, name(), "rv_cpu.writeback_stage", "writeback_stage", "pipe_wb", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_rv_cpu_pkg.configure(this, name(), "rv_cpu_pkg", "rv_cpu_pkg", "rv_cpu_pkg", -9, VerilatedScope::SCOPE_PACKAGE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_rv_cpu);
    __Vhier.add(0, &__Vscope_rv_cpu_pkg);
    __Vhier.add(&__Vscope_rv_cpu, &__Vscope_rv_cpu__control_stage);
    __Vhier.add(&__Vscope_rv_cpu, &__Vscope_rv_cpu__decode_stage);
    __Vhier.add(&__Vscope_rv_cpu, &__Vscope_rv_cpu__execute_stage);
    __Vhier.add(&__Vscope_rv_cpu, &__Vscope_rv_cpu__fetch_stage);
    __Vhier.add(&__Vscope_rv_cpu, &__Vscope_rv_cpu__memory_stage);
    __Vhier.add(&__Vscope_rv_cpu, &__Vscope_rv_cpu__writeback_stage);
    __Vhier.add(&__Vscope_rv_cpu__decode_stage, &__Vscope_rv_cpu__decode_stage__reg_file_inst);
    __Vhier.add(&__Vscope_rv_cpu__decode_stage__reg_file_inst, &__Vscope_rv_cpu__decode_stage__reg_file_inst__write_ff);
    __Vhier.add(&__Vscope_rv_cpu__decode_stage__reg_file_inst__write_ff, &__Vscope_rv_cpu__decode_stage__reg_file_inst__write_ff__unnamedblk1);
    __Vhier.add(&__Vscope_rv_cpu__execute_stage, &__Vscope_rv_cpu__execute_stage__alu_inst);
    __Vhier.add(&__Vscope_rv_cpu__fetch_stage, &__Vscope_rv_cpu__fetch_stage__i_reg_inst);
    __Vhier.add(&__Vscope_rv_cpu__memory_stage, &__Vscope_rv_cpu__memory_stage__sram_inst);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk_i", &(TOP.clk_i), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"riscv_en_i", &(TOP.riscv_en_i), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"rstn_i", &(TOP.rstn_i), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu.varInsert(__Vfinal,"clk_i", &(TOP.rv_cpu__DOT__clk_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu.varInsert(__Vfinal,"ctl_id_w", &(TOP.rv_cpu__DOT__ctl_id_w), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,22,0);
        __Vscope_rv_cpu.varInsert(__Vfinal,"ex_if_w", &(TOP.rv_cpu__DOT__ex_if_w), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,32,0);
        __Vscope_rv_cpu.varInsert(__Vfinal,"ex_mem_w", &(TOP.rv_cpu__DOT__ex_mem_w), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,142,0);
        __Vscope_rv_cpu.varInsert(__Vfinal,"id_ctl_w", &(TOP.rv_cpu__DOT__id_ctl_w), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,16,0);
        __Vscope_rv_cpu.varInsert(__Vfinal,"id_ex_w", &(TOP.rv_cpu__DOT__id_ex_w), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,182,0);
        __Vscope_rv_cpu.varInsert(__Vfinal,"id_hzd_w", &(TOP.rv_cpu__DOT__id_hzd_w), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,9,0);
        __Vscope_rv_cpu.varInsert(__Vfinal,"if_id_w", &(TOP.rv_cpu__DOT__if_id_w), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,95,0);
        __Vscope_rv_cpu.varInsert(__Vfinal,"mem_wb_w", &(TOP.rv_cpu__DOT__mem_wb_w), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,141,0);
        __Vscope_rv_cpu.varInsert(__Vfinal,"riscv_en_i", &(TOP.rv_cpu__DOT__riscv_en_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu.varInsert(__Vfinal,"rstn_i", &(TOP.rv_cpu__DOT__rstn_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu.varInsert(__Vfinal,"wb_id_w", &(TOP.rv_cpu__DOT__wb_id_w), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,37,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"alu_op", &(TOP.rv_cpu__DOT__control_stage__DOT__alu_op), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"alu_src", &(TOP.rv_cpu__DOT__control_stage__DOT__alu_src), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"clk_i", &(TOP.rv_cpu__DOT__control_stage__DOT__clk_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"ctl_id_o", &(TOP.rv_cpu__DOT__control_stage__DOT__ctl_id_o), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,22,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"funct3", &(TOP.rv_cpu__DOT__control_stage__DOT__funct3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"funct7", &(TOP.rv_cpu__DOT__control_stage__DOT__funct7), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"id_ctl_i", &(TOP.rv_cpu__DOT__control_stage__DOT__id_ctl_i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,16,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"imm_sel", &(TOP.rv_cpu__DOT__control_stage__DOT__imm_sel), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"inst_next", &(TOP.rv_cpu__DOT__control_stage__DOT__inst_next), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"is_branch", &(TOP.rv_cpu__DOT__control_stage__DOT__is_branch), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"is_jalr", &(TOP.rv_cpu__DOT__control_stage__DOT__is_jalr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"is_jump", &(TOP.rv_cpu__DOT__control_stage__DOT__is_jump), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"mem_mask", &(TOP.rv_cpu__DOT__control_stage__DOT__mem_mask), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"mem_rd_en", &(TOP.rv_cpu__DOT__control_stage__DOT__mem_rd_en), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"mem_signed", &(TOP.rv_cpu__DOT__control_stage__DOT__mem_signed), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"mem_wr_en", &(TOP.rv_cpu__DOT__control_stage__DOT__mem_wr_en), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"opcode", &(TOP.rv_cpu__DOT__control_stage__DOT__opcode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"r1_en", &(TOP.rv_cpu__DOT__control_stage__DOT__r1_en), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"r2_en", &(TOP.rv_cpu__DOT__control_stage__DOT__r2_en), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"rd_wen", &(TOP.rv_cpu__DOT__control_stage__DOT__rd_wen), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__control_stage.varInsert(__Vfinal,"wb_src", &(TOP.rv_cpu__DOT__control_stage__DOT__wb_src), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"RF_DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP.rv_cpu__DOT__decode_stage__DOT__RF_DEPTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"bta_imm", &(TOP.rv_cpu__DOT__decode_stage__DOT__bta_imm), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,11,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"clk_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__clk_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"ctl_id_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__ctl_id_i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,22,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"funct3", &(TOP.rv_cpu__DOT__decode_stage__DOT__funct3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"funct7", &(TOP.rv_cpu__DOT__decode_stage__DOT__funct7), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"id_ctl_o", &(TOP.rv_cpu__DOT__decode_stage__DOT__id_ctl_o), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,16,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"id_ex_o", &(TOP.rv_cpu__DOT__decode_stage__DOT__id_ex_o), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,182,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"id_hzd_o", &(TOP.rv_cpu__DOT__decode_stage__DOT__id_hzd_o), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,9,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"if_id_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__if_id_i), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,95,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"imm", &(TOP.rv_cpu__DOT__decode_stage__DOT__imm), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,11,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"imm_next", &(TOP.rv_cpu__DOT__decode_stage__DOT__imm_next), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"inst_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__inst_i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"jta_imm", &(TOP.rv_cpu__DOT__decode_stage__DOT__jta_imm), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,19,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"opcode", &(TOP.rv_cpu__DOT__decode_stage__DOT__opcode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"rd_addr", &(TOP.rv_cpu__DOT__decode_stage__DOT__rd_addr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"rs1_addr", &(TOP.rv_cpu__DOT__decode_stage__DOT__rs1_addr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"rs2_addr", &(TOP.rv_cpu__DOT__decode_stage__DOT__rs2_addr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"rstn_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__rstn_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"st_imm", &(TOP.rv_cpu__DOT__decode_stage__DOT__st_imm), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,11,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"uimm", &(TOP.rv_cpu__DOT__decode_stage__DOT__uimm), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"upimm", &(TOP.rv_cpu__DOT__decode_stage__DOT__upimm), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,19,0);
        __Vscope_rv_cpu__decode_stage.varInsert(__Vfinal,"wb_id_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__wb_id_i), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,37,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__DEPTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"clk_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__clk_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"mem", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,31 ,31,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"r1_addr_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_addr_i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"r1_data_o", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"r1_en_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_en_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"r2_addr_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_addr_i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"r2_data_o", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"r2_en_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_en_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"rstn_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"w_addr", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_addr), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"w_data", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst.varInsert(__Vfinal,"wen_i", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__wen_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__decode_stage__reg_file_inst__write_ff__unnamedblk1.varInsert(__Vfinal,"i", &(TOP.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_rv_cpu__execute_stage.varInsert(__Vfinal,"addr_result", &(TOP.rv_cpu__DOT__execute_stage__DOT__addr_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__execute_stage.varInsert(__Vfinal,"alu_result", &(TOP.rv_cpu__DOT__execute_stage__DOT__alu_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__execute_stage.varInsert(__Vfinal,"alu_srcA", &(TOP.rv_cpu__DOT__execute_stage__DOT__alu_srcA), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__execute_stage.varInsert(__Vfinal,"alu_srcB", &(TOP.rv_cpu__DOT__execute_stage__DOT__alu_srcB), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__execute_stage.varInsert(__Vfinal,"clk_i", &(TOP.rv_cpu__DOT__execute_stage__DOT__clk_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__execute_stage.varInsert(__Vfinal,"ex_if_o", &(TOP.rv_cpu__DOT__execute_stage__DOT__ex_if_o), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,32,0);
        __Vscope_rv_cpu__execute_stage.varInsert(__Vfinal,"ex_mem_o", &(TOP.rv_cpu__DOT__execute_stage__DOT__ex_mem_o), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,142,0);
        __Vscope_rv_cpu__execute_stage.varInsert(__Vfinal,"id_ex_i", &(TOP.rv_cpu__DOT__execute_stage__DOT__id_ex_i), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,182,0);
        __Vscope_rv_cpu__execute_stage.varInsert(__Vfinal,"pc_addr", &(TOP.rv_cpu__DOT__execute_stage__DOT__pc_addr), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__execute_stage.varInsert(__Vfinal,"pc_src", &(TOP.rv_cpu__DOT__execute_stage__DOT__pc_src), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__execute_stage.varInsert(__Vfinal,"rstn_i", &(TOP.rv_cpu__DOT__execute_stage__DOT__rstn_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__execute_stage__alu_inst.varInsert(__Vfinal,"op_i", &(TOP.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_rv_cpu__execute_stage__alu_inst.varInsert(__Vfinal,"result_o", &(TOP.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__result_o), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__execute_stage__alu_inst.varInsert(__Vfinal,"srcA_i", &(TOP.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__execute_stage__alu_inst.varInsert(__Vfinal,"srcB_i", &(TOP.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__fetch_stage.varInsert(__Vfinal,"I_MEM_DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP.rv_cpu__DOT__fetch_stage__DOT__I_MEM_DEPTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__fetch_stage.varInsert(__Vfinal,"clk_i", &(TOP.rv_cpu__DOT__fetch_stage__DOT__clk_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__fetch_stage.varInsert(__Vfinal,"en_i", &(TOP.rv_cpu__DOT__fetch_stage__DOT__en_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__fetch_stage.varInsert(__Vfinal,"ex_if_i", &(TOP.rv_cpu__DOT__fetch_stage__DOT__ex_if_i), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,32,0);
        __Vscope_rv_cpu__fetch_stage.varInsert(__Vfinal,"if_id_o", &(TOP.rv_cpu__DOT__fetch_stage__DOT__if_id_o), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,95,0);
        __Vscope_rv_cpu__fetch_stage.varInsert(__Vfinal,"pc_next", &(TOP.rv_cpu__DOT__fetch_stage__DOT__pc_next), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__fetch_stage.varInsert(__Vfinal,"pc_r", &(TOP.rv_cpu__DOT__fetch_stage__DOT__pc_r), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__fetch_stage.varInsert(__Vfinal,"rstn_i", &(TOP.rv_cpu__DOT__fetch_stage__DOT__rstn_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__fetch_stage__i_reg_inst.varInsert(__Vfinal,"DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__DEPTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__fetch_stage__i_reg_inst.varInsert(__Vfinal,"NUM_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__NUM_BYTES))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__fetch_stage__i_reg_inst.varInsert(__Vfinal,"clk_i", &(TOP.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__clk_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__fetch_stage__i_reg_inst.varInsert(__Vfinal,"en_i", &(TOP.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__en_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__fetch_stage__i_reg_inst.varInsert(__Vfinal,"inst_o", &(TOP.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__inst_o), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__fetch_stage__i_reg_inst.varInsert(__Vfinal,"mem", &(TOP.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__mem), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,63 ,31,0);
        __Vscope_rv_cpu__fetch_stage__i_reg_inst.varInsert(__Vfinal,"pc_i", &(TOP.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__pc_i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__fetch_stage__i_reg_inst.varInsert(__Vfinal,"rstn_i", &(TOP.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__rstn_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__memory_stage.varInsert(__Vfinal,"D_MEM_ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.rv_cpu__DOT__memory_stage__DOT__D_MEM_ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__memory_stage.varInsert(__Vfinal,"D_MEM_DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP.rv_cpu__DOT__memory_stage__DOT__D_MEM_DEPTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__memory_stage.varInsert(__Vfinal,"clk_i", &(TOP.rv_cpu__DOT__memory_stage__DOT__clk_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__memory_stage.varInsert(__Vfinal,"ex_mem_i", &(TOP.rv_cpu__DOT__memory_stage__DOT__ex_mem_i), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,142,0);
        __Vscope_rv_cpu__memory_stage.varInsert(__Vfinal,"mem_wb_o", &(TOP.rv_cpu__DOT__memory_stage__DOT__mem_wb_o), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,141,0);
        __Vscope_rv_cpu__memory_stage.varInsert(__Vfinal,"rstn_i", &(TOP.rv_cpu__DOT__memory_stage__DOT__rstn_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__DEPTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"NUM_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__NUM_BYTES))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"addr_i", &(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"cenb_i", &(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__cenb_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"clk_i", &(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__clk_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"data_i", &(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"data_o", &(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"i", &(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"mask_i", &(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"mem_array", &(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mem_array), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,255 ,31,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"rstn_i", &(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__memory_stage__sram_inst.varInsert(__Vfinal,"wenb_i", &(TOP.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__wenb_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__writeback_stage.varInsert(__Vfinal,"clk_i", &(TOP.rv_cpu__DOT__writeback_stage__DOT__clk_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__writeback_stage.varInsert(__Vfinal,"mem_data", &(TOP.rv_cpu__DOT__writeback_stage__DOT__mem_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__writeback_stage.varInsert(__Vfinal,"mem_data_ext", &(TOP.rv_cpu__DOT__writeback_stage__DOT__mem_data_ext), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu__writeback_stage.varInsert(__Vfinal,"mem_wb_i", &(TOP.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,141,0);
        __Vscope_rv_cpu__writeback_stage.varInsert(__Vfinal,"rstn_i", &(TOP.rv_cpu__DOT__writeback_stage__DOT__rstn_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_rv_cpu__writeback_stage.varInsert(__Vfinal,"wb_id_o", &(TOP.rv_cpu__DOT__writeback_stage__DOT__wb_id_o), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,37,0);
        __Vscope_rv_cpu_pkg.varInsert(__Vfinal,"D_MEM_ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__rv_cpu_pkg.D_MEM_ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu_pkg.varInsert(__Vfinal,"D_MEM_DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP__rv_cpu_pkg.D_MEM_DEPTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu_pkg.varInsert(__Vfinal,"I_MEM_ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__rv_cpu_pkg.I_MEM_ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu_pkg.varInsert(__Vfinal,"I_MEM_DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP__rv_cpu_pkg.I_MEM_DEPTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu_pkg.varInsert(__Vfinal,"REG_FILE_DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP__rv_cpu_pkg.REG_FILE_DEPTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_rv_cpu_pkg.varInsert(__Vfinal,"RF_ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__rv_cpu_pkg.RF_ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
    }
}
