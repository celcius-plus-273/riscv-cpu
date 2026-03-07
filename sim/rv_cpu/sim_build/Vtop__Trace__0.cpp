// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk_i));
    bufp->chgBit(oldp+1,(vlSelfRef.rstn_i));
    bufp->chgBit(oldp+2,(vlSelfRef.riscv_en_i));
    bufp->chgBit(oldp+3,(vlSelfRef.rv_cpu__DOT__clk_i));
    bufp->chgBit(oldp+4,(vlSelfRef.rv_cpu__DOT__rstn_i));
    bufp->chgBit(oldp+5,(vlSelfRef.rv_cpu__DOT__riscv_en_i));
    bufp->chgCData(oldp+6,((0x7fU & (vlSelfRef.rv_cpu__DOT__id_ctl_w 
                                     >> 0xaU))),7);
    bufp->chgCData(oldp+7,((7U & (vlSelfRef.rv_cpu__DOT__id_ctl_w 
                                  >> 7U))),3);
    bufp->chgCData(oldp+8,((0x7fU & vlSelfRef.rv_cpu__DOT__id_ctl_w)),7);
    bufp->chgCData(oldp+9,((7U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                  >> 0x14U))),3);
    bufp->chgBit(oldp+10,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                 >> 0x13U))));
    bufp->chgBit(oldp+11,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                 >> 0x12U))));
    bufp->chgBit(oldp+12,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                 >> 0x11U))));
    bufp->chgCData(oldp+13,((3U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                   >> 0xfU))),2);
    bufp->chgCData(oldp+14,((0xfU & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                     >> 0xbU))),4);
    bufp->chgBit(oldp+15,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                 >> 0xaU))));
    bufp->chgBit(oldp+16,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                 >> 9U))));
    bufp->chgBit(oldp+17,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                 >> 8U))));
    bufp->chgCData(oldp+18,((0xfU & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                     >> 4U))),4);
    bufp->chgBit(oldp+19,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                 >> 3U))));
    bufp->chgBit(oldp+20,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                 >> 2U))));
    bufp->chgBit(oldp+21,((1U & (vlSelfRef.rv_cpu__DOT__ctl_id_w 
                                 >> 1U))));
    bufp->chgBit(oldp+22,((1U & vlSelfRef.rv_cpu__DOT__ctl_id_w)));
    bufp->chgCData(oldp+23,((0x1fU & ((IData)(vlSelfRef.rv_cpu__DOT__id_hzd_w) 
                                      >> 5U))),5);
    bufp->chgCData(oldp+24,((0x1fU & (IData)(vlSelfRef.rv_cpu__DOT__id_hzd_w))),5);
    bufp->chgBit(oldp+25,((1U & (IData)((vlSelfRef.rv_cpu__DOT__ex_if_w 
                                         >> 0x20U)))));
    bufp->chgIData(oldp+26,((IData)(vlSelfRef.rv_cpu__DOT__ex_if_w)),32);
    bufp->chgBit(oldp+27,((1U & (IData)((vlSelfRef.rv_cpu__DOT__wb_id_w 
                                         >> 0x25U)))));
    bufp->chgCData(oldp+28,((0x1fU & (IData)((vlSelfRef.rv_cpu__DOT__wb_id_w 
                                              >> 0x20U)))),5);
    bufp->chgIData(oldp+29,((IData)(vlSelfRef.rv_cpu__DOT__wb_id_w)),32);
    bufp->chgIData(oldp+30,(vlSelfRef.rv_cpu__DOT__if_id_w[2U]),32);
    bufp->chgIData(oldp+31,(vlSelfRef.rv_cpu__DOT__if_id_w[1U]),32);
    bufp->chgIData(oldp+32,(vlSelfRef.rv_cpu__DOT__if_id_w[0U]),32);
    bufp->chgIData(oldp+33,(((vlSelfRef.rv_cpu__DOT__id_ex_w[5U] 
                              << 9U) | (vlSelfRef.rv_cpu__DOT__id_ex_w[4U] 
                                        >> 0x17U))),32);
    bufp->chgIData(oldp+34,(((vlSelfRef.rv_cpu__DOT__id_ex_w[4U] 
                              << 9U) | (vlSelfRef.rv_cpu__DOT__id_ex_w[3U] 
                                        >> 0x17U))),32);
    bufp->chgIData(oldp+35,(((vlSelfRef.rv_cpu__DOT__id_ex_w[3U] 
                              << 9U) | (vlSelfRef.rv_cpu__DOT__id_ex_w[2U] 
                                        >> 0x17U))),32);
    bufp->chgIData(oldp+36,(((vlSelfRef.rv_cpu__DOT__id_ex_w[2U] 
                              << 9U) | (vlSelfRef.rv_cpu__DOT__id_ex_w[1U] 
                                        >> 0x17U))),32);
    bufp->chgIData(oldp+37,(((vlSelfRef.rv_cpu__DOT__id_ex_w[1U] 
                              << 9U) | (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                        >> 0x17U))),32);
    bufp->chgCData(oldp+38,((0xfU & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                     >> 0x13U))),4);
    bufp->chgBit(oldp+39,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                 >> 0x12U))));
    bufp->chgBit(oldp+40,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                 >> 0x11U))));
    bufp->chgBit(oldp+41,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                 >> 0x10U))));
    bufp->chgCData(oldp+42,((0xfU & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                     >> 0xcU))),4);
    bufp->chgBit(oldp+43,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                 >> 0xbU))));
    bufp->chgBit(oldp+44,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                 >> 0xaU))));
    bufp->chgBit(oldp+45,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                 >> 9U))));
    bufp->chgBit(oldp+46,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                 >> 8U))));
    bufp->chgCData(oldp+47,((3U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                   >> 6U))),2);
    bufp->chgBit(oldp+48,((1U & (vlSelfRef.rv_cpu__DOT__id_ex_w[0U] 
                                 >> 5U))));
    bufp->chgCData(oldp+49,((0x1fU & vlSelfRef.rv_cpu__DOT__id_ex_w[0U])),5);
    bufp->chgIData(oldp+50,(((vlSelfRef.rv_cpu__DOT__ex_mem_w[4U] 
                              << 0x11U) | (vlSelfRef.rv_cpu__DOT__ex_mem_w[3U] 
                                           >> 0xfU))),32);
    bufp->chgIData(oldp+51,(((vlSelfRef.rv_cpu__DOT__ex_mem_w[3U] 
                              << 0x11U) | (vlSelfRef.rv_cpu__DOT__ex_mem_w[2U] 
                                           >> 0xfU))),32);
    bufp->chgIData(oldp+52,(((vlSelfRef.rv_cpu__DOT__ex_mem_w[2U] 
                              << 0x11U) | (vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] 
                                           >> 0xfU))),32);
    bufp->chgBit(oldp+53,((1U & (vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] 
                                 >> 0xeU))));
    bufp->chgBit(oldp+54,((1U & (vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] 
                                 >> 0xdU))));
    bufp->chgCData(oldp+55,((0xfU & (vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] 
                                     >> 9U))),4);
    bufp->chgBit(oldp+56,((1U & (vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] 
                                 >> 8U))));
    bufp->chgIData(oldp+57,(((vlSelfRef.rv_cpu__DOT__ex_mem_w[1U] 
                              << 0x18U) | (vlSelfRef.rv_cpu__DOT__ex_mem_w[0U] 
                                           >> 8U))),32);
    bufp->chgCData(oldp+58,((3U & (vlSelfRef.rv_cpu__DOT__ex_mem_w[0U] 
                                   >> 6U))),2);
    bufp->chgBit(oldp+59,((1U & (vlSelfRef.rv_cpu__DOT__ex_mem_w[0U] 
                                 >> 5U))));
    bufp->chgCData(oldp+60,((0x1fU & vlSelfRef.rv_cpu__DOT__ex_mem_w[0U])),5);
    bufp->chgIData(oldp+61,(((vlSelfRef.rv_cpu__DOT__mem_wb_w[4U] 
                              << 0x12U) | (vlSelfRef.rv_cpu__DOT__mem_wb_w[3U] 
                                           >> 0xeU))),32);
    bufp->chgIData(oldp+62,(((vlSelfRef.rv_cpu__DOT__mem_wb_w[3U] 
                              << 0x12U) | (vlSelfRef.rv_cpu__DOT__mem_wb_w[2U] 
                                           >> 0xeU))),32);
    bufp->chgIData(oldp+63,(((vlSelfRef.rv_cpu__DOT__mem_wb_w[2U] 
                              << 0x12U) | (vlSelfRef.rv_cpu__DOT__mem_wb_w[1U] 
                                           >> 0xeU))),32);
    bufp->chgIData(oldp+64,(((vlSelfRef.rv_cpu__DOT__mem_wb_w[1U] 
                              << 0x12U) | (vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] 
                                           >> 0xeU))),32);
    bufp->chgBit(oldp+65,((1U & (vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] 
                                 >> 0xdU))));
    bufp->chgCData(oldp+66,((0xfU & (vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] 
                                     >> 9U))),4);
    bufp->chgBit(oldp+67,((1U & (vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] 
                                 >> 8U))));
    bufp->chgCData(oldp+68,((3U & (vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] 
                                   >> 6U))),2);
    bufp->chgBit(oldp+69,((1U & (vlSelfRef.rv_cpu__DOT__mem_wb_w[0U] 
                                 >> 5U))));
    bufp->chgCData(oldp+70,((0x1fU & vlSelfRef.rv_cpu__DOT__mem_wb_w[0U])),5);
    bufp->chgBit(oldp+71,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__clk_i));
    bufp->chgCData(oldp+72,((0x7fU & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i 
                                      >> 0xaU))),7);
    bufp->chgCData(oldp+73,((7U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i 
                                   >> 7U))),3);
    bufp->chgCData(oldp+74,((0x7fU & vlSelfRef.rv_cpu__DOT__control_stage__DOT__id_ctl_i)),7);
    bufp->chgCData(oldp+75,((7U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                   >> 0x14U))),3);
    bufp->chgBit(oldp+76,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                 >> 0x13U))));
    bufp->chgBit(oldp+77,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                 >> 0x12U))));
    bufp->chgBit(oldp+78,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                 >> 0x11U))));
    bufp->chgCData(oldp+79,((3U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                   >> 0xfU))),2);
    bufp->chgCData(oldp+80,((0xfU & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                     >> 0xbU))),4);
    bufp->chgBit(oldp+81,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                 >> 0xaU))));
    bufp->chgBit(oldp+82,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                 >> 9U))));
    bufp->chgBit(oldp+83,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                 >> 8U))));
    bufp->chgCData(oldp+84,((0xfU & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                     >> 4U))),4);
    bufp->chgBit(oldp+85,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                 >> 3U))));
    bufp->chgBit(oldp+86,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                 >> 2U))));
    bufp->chgBit(oldp+87,((1U & (vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o 
                                 >> 1U))));
    bufp->chgBit(oldp+88,((1U & vlSelfRef.rv_cpu__DOT__control_stage__DOT__ctl_id_o)));
    bufp->chgCData(oldp+89,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__inst_next),4);
    bufp->chgCData(oldp+90,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__opcode),7);
    bufp->chgCData(oldp+91,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct3),3);
    bufp->chgCData(oldp+92,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__funct7),7);
    bufp->chgCData(oldp+93,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__imm_sel),3);
    bufp->chgBit(oldp+94,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__r1_en));
    bufp->chgBit(oldp+95,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__r2_en));
    bufp->chgBit(oldp+96,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__rd_wen));
    bufp->chgCData(oldp+97,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__wb_src),2);
    bufp->chgBit(oldp+98,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_rd_en));
    bufp->chgBit(oldp+99,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_wr_en));
    bufp->chgCData(oldp+100,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_mask),4);
    bufp->chgBit(oldp+101,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__mem_signed));
    bufp->chgBit(oldp+102,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_branch));
    bufp->chgBit(oldp+103,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jump));
    bufp->chgBit(oldp+104,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__is_jalr));
    bufp->chgCData(oldp+105,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_op),4);
    bufp->chgBit(oldp+106,(vlSelfRef.rv_cpu__DOT__control_stage__DOT__alu_src));
    bufp->chgBit(oldp+107,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__clk_i));
    bufp->chgBit(oldp+108,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rstn_i));
    bufp->chgCData(oldp+109,((7U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                    >> 0x14U))),3);
    bufp->chgBit(oldp+110,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                  >> 0x13U))));
    bufp->chgBit(oldp+111,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                  >> 0x12U))));
    bufp->chgBit(oldp+112,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                  >> 0x11U))));
    bufp->chgCData(oldp+113,((3U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                    >> 0xfU))),2);
    bufp->chgCData(oldp+114,((0xfU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                      >> 0xbU))),4);
    bufp->chgBit(oldp+115,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                  >> 0xaU))));
    bufp->chgBit(oldp+116,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                  >> 9U))));
    bufp->chgBit(oldp+117,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                  >> 8U))));
    bufp->chgCData(oldp+118,((0xfU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                      >> 4U))),4);
    bufp->chgBit(oldp+119,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                  >> 3U))));
    bufp->chgBit(oldp+120,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                  >> 2U))));
    bufp->chgBit(oldp+121,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i 
                                  >> 1U))));
    bufp->chgBit(oldp+122,((1U & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__ctl_id_i)));
    bufp->chgCData(oldp+123,((0x7fU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ctl_o 
                                       >> 0xaU))),7);
    bufp->chgCData(oldp+124,((7U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ctl_o 
                                    >> 7U))),3);
    bufp->chgCData(oldp+125,((0x7fU & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ctl_o)),7);
    bufp->chgCData(oldp+126,((0x1fU & ((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_hzd_o) 
                                       >> 5U))),5);
    bufp->chgCData(oldp+127,((0x1fU & (IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_hzd_o))),5);
    bufp->chgIData(oldp+128,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[2U]),32);
    bufp->chgIData(oldp+129,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[1U]),32);
    bufp->chgIData(oldp+130,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__if_id_i[0U]),32);
    bufp->chgBit(oldp+131,((1U & (IData)((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i 
                                          >> 0x25U)))));
    bufp->chgCData(oldp+132,((0x1fU & (IData)((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i 
                                               >> 0x20U)))),5);
    bufp->chgIData(oldp+133,((IData)(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__wb_id_i)),32);
    bufp->chgIData(oldp+134,(((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[5U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U] 
                                         >> 0x17U))),32);
    bufp->chgIData(oldp+135,(((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[4U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
                                         >> 0x17U))),32);
    bufp->chgIData(oldp+136,(((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[3U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U] 
                                         >> 0x17U))),32);
    bufp->chgIData(oldp+137,(((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[2U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
                                         >> 0x17U))),32);
    bufp->chgIData(oldp+138,(((vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[1U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                         >> 0x17U))),32);
    bufp->chgCData(oldp+139,((0xfU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                      >> 0x13U))),4);
    bufp->chgBit(oldp+140,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                  >> 0x12U))));
    bufp->chgBit(oldp+141,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                  >> 0x11U))));
    bufp->chgBit(oldp+142,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                  >> 0x10U))));
    bufp->chgCData(oldp+143,((0xfU & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                      >> 0xcU))),4);
    bufp->chgBit(oldp+144,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                  >> 0xbU))));
    bufp->chgBit(oldp+145,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                  >> 0xaU))));
    bufp->chgBit(oldp+146,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                  >> 9U))));
    bufp->chgBit(oldp+147,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                  >> 8U))));
    bufp->chgCData(oldp+148,((3U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                    >> 6U))),2);
    bufp->chgBit(oldp+149,((1U & (vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U] 
                                  >> 5U))));
    bufp->chgCData(oldp+150,((0x1fU & vlSelfRef.rv_cpu__DOT__decode_stage__DOT__id_ex_o[0U])),5);
    bufp->chgCData(oldp+151,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__opcode),7);
    bufp->chgIData(oldp+152,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__inst_i),32);
    bufp->chgCData(oldp+153,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs1_addr),5);
    bufp->chgCData(oldp+154,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rs2_addr),5);
    bufp->chgCData(oldp+155,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__funct7),7);
    bufp->chgCData(oldp+156,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__funct3),3);
    bufp->chgSData(oldp+157,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm),12);
    bufp->chgCData(oldp+158,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__uimm),5);
    bufp->chgIData(oldp+159,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__upimm),20);
    bufp->chgSData(oldp+160,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__st_imm),12);
    bufp->chgSData(oldp+161,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__bta_imm),12);
    bufp->chgIData(oldp+162,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__jta_imm),20);
    bufp->chgIData(oldp+163,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__imm_next),32);
    bufp->chgCData(oldp+164,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__rd_addr),5);
    bufp->chgBit(oldp+165,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__clk_i));
    bufp->chgBit(oldp+166,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__rstn_i));
    bufp->chgBit(oldp+167,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__wen_i));
    bufp->chgIData(oldp+168,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_addr),32);
    bufp->chgIData(oldp+169,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__w_data),32);
    bufp->chgBit(oldp+170,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_en_i));
    bufp->chgIData(oldp+171,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_addr_i),32);
    bufp->chgIData(oldp+172,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r1_data_o),32);
    bufp->chgBit(oldp+173,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_en_i));
    bufp->chgIData(oldp+174,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_addr_i),32);
    bufp->chgIData(oldp+175,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__r2_data_o),32);
    bufp->chgIData(oldp+176,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[0]),32);
    bufp->chgIData(oldp+177,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[1]),32);
    bufp->chgIData(oldp+178,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[2]),32);
    bufp->chgIData(oldp+179,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[3]),32);
    bufp->chgIData(oldp+180,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[4]),32);
    bufp->chgIData(oldp+181,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[5]),32);
    bufp->chgIData(oldp+182,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[6]),32);
    bufp->chgIData(oldp+183,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[7]),32);
    bufp->chgIData(oldp+184,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[8]),32);
    bufp->chgIData(oldp+185,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[9]),32);
    bufp->chgIData(oldp+186,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[10]),32);
    bufp->chgIData(oldp+187,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[11]),32);
    bufp->chgIData(oldp+188,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[12]),32);
    bufp->chgIData(oldp+189,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[13]),32);
    bufp->chgIData(oldp+190,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[14]),32);
    bufp->chgIData(oldp+191,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[15]),32);
    bufp->chgIData(oldp+192,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[16]),32);
    bufp->chgIData(oldp+193,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[17]),32);
    bufp->chgIData(oldp+194,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[18]),32);
    bufp->chgIData(oldp+195,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[19]),32);
    bufp->chgIData(oldp+196,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[20]),32);
    bufp->chgIData(oldp+197,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[21]),32);
    bufp->chgIData(oldp+198,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[22]),32);
    bufp->chgIData(oldp+199,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[23]),32);
    bufp->chgIData(oldp+200,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[24]),32);
    bufp->chgIData(oldp+201,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[25]),32);
    bufp->chgIData(oldp+202,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[26]),32);
    bufp->chgIData(oldp+203,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[27]),32);
    bufp->chgIData(oldp+204,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[28]),32);
    bufp->chgIData(oldp+205,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[29]),32);
    bufp->chgIData(oldp+206,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[30]),32);
    bufp->chgIData(oldp+207,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__mem[31]),32);
    bufp->chgIData(oldp+208,(vlSelfRef.rv_cpu__DOT__decode_stage__DOT__reg_file_inst__DOT__write_ff__DOT__unnamedblk1__DOT__i),32);
    bufp->chgBit(oldp+209,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__clk_i));
    bufp->chgBit(oldp+210,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__rstn_i));
    bufp->chgBit(oldp+211,((1U & (IData)((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_if_o 
                                          >> 0x20U)))));
    bufp->chgIData(oldp+212,((IData)(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_if_o)),32);
    bufp->chgIData(oldp+213,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[5U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[4U] 
                                         >> 0x17U))),32);
    bufp->chgIData(oldp+214,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[4U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[3U] 
                                         >> 0x17U))),32);
    bufp->chgIData(oldp+215,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[3U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
                                         >> 0x17U))),32);
    bufp->chgIData(oldp+216,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[2U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                                         >> 0x17U))),32);
    bufp->chgIData(oldp+217,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[1U] 
                               << 9U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                         >> 0x17U))),32);
    bufp->chgCData(oldp+218,((0xfU & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                      >> 0x13U))),4);
    bufp->chgBit(oldp+219,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                  >> 0x12U))));
    bufp->chgBit(oldp+220,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                  >> 0x11U))));
    bufp->chgBit(oldp+221,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                  >> 0x10U))));
    bufp->chgCData(oldp+222,((0xfU & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                      >> 0xcU))),4);
    bufp->chgBit(oldp+223,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                  >> 0xbU))));
    bufp->chgBit(oldp+224,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                  >> 0xaU))));
    bufp->chgBit(oldp+225,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                  >> 9U))));
    bufp->chgBit(oldp+226,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                  >> 8U))));
    bufp->chgCData(oldp+227,((3U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                    >> 6U))),2);
    bufp->chgBit(oldp+228,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U] 
                                  >> 5U))));
    bufp->chgCData(oldp+229,((0x1fU & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__id_ex_i[0U])),5);
    bufp->chgIData(oldp+230,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[4U] 
                               << 0x11U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[3U] 
                                            >> 0xfU))),32);
    bufp->chgIData(oldp+231,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[3U] 
                               << 0x11U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[2U] 
                                            >> 0xfU))),32);
    bufp->chgIData(oldp+232,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[2U] 
                               << 0x11U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
                                            >> 0xfU))),32);
    bufp->chgBit(oldp+233,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
                                  >> 0xeU))));
    bufp->chgBit(oldp+234,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
                                  >> 0xdU))));
    bufp->chgCData(oldp+235,((0xfU & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
                                      >> 9U))),4);
    bufp->chgBit(oldp+236,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
                                  >> 8U))));
    bufp->chgIData(oldp+237,(((vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[1U] 
                               << 0x18U) | (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U] 
                                            >> 8U))),32);
    bufp->chgCData(oldp+238,((3U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U] 
                                    >> 6U))),2);
    bufp->chgBit(oldp+239,((1U & (vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U] 
                                  >> 5U))));
    bufp->chgCData(oldp+240,((0x1fU & vlSelfRef.rv_cpu__DOT__execute_stage__DOT__ex_mem_o[0U])),5);
    bufp->chgIData(oldp+241,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_srcA),32);
    bufp->chgIData(oldp+242,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_srcB),32);
    bufp->chgIData(oldp+243,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_result),32);
    bufp->chgBit(oldp+244,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__pc_src));
    bufp->chgIData(oldp+245,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__pc_addr),32);
    bufp->chgIData(oldp+246,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__addr_result),32);
    bufp->chgCData(oldp+247,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__op_i),4);
    bufp->chgIData(oldp+248,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcA_i),32);
    bufp->chgIData(oldp+249,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__srcB_i),32);
    bufp->chgIData(oldp+250,(vlSelfRef.rv_cpu__DOT__execute_stage__DOT__alu_inst__DOT__result_o),32);
    bufp->chgBit(oldp+251,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__clk_i));
    bufp->chgBit(oldp+252,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__en_i));
    bufp->chgBit(oldp+253,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__rstn_i));
    bufp->chgBit(oldp+254,((1U & (IData)((vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__ex_if_i 
                                          >> 0x20U)))));
    bufp->chgIData(oldp+255,((IData)(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__ex_if_i)),32);
    bufp->chgIData(oldp+256,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[2U]),32);
    bufp->chgIData(oldp+257,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[1U]),32);
    bufp->chgIData(oldp+258,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__if_id_o[0U]),32);
    bufp->chgIData(oldp+259,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_r),32);
    bufp->chgIData(oldp+260,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__pc_next),32);
    bufp->chgBit(oldp+261,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__clk_i));
    bufp->chgBit(oldp+262,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__en_i));
    bufp->chgBit(oldp+263,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__rstn_i));
    bufp->chgIData(oldp+264,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__pc_i),32);
    bufp->chgIData(oldp+265,(vlSelfRef.rv_cpu__DOT__fetch_stage__DOT__i_reg_inst__DOT__inst_o),32);
    bufp->chgBit(oldp+266,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__clk_i));
    bufp->chgBit(oldp+267,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__rstn_i));
    bufp->chgIData(oldp+268,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[4U] 
                               << 0x11U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[3U] 
                                            >> 0xfU))),32);
    bufp->chgIData(oldp+269,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[3U] 
                               << 0x11U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[2U] 
                                            >> 0xfU))),32);
    bufp->chgIData(oldp+270,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[2U] 
                               << 0x11U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                                            >> 0xfU))),32);
    bufp->chgBit(oldp+271,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                                  >> 0xeU))));
    bufp->chgBit(oldp+272,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                                  >> 0xdU))));
    bufp->chgCData(oldp+273,((0xfU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                                      >> 9U))),4);
    bufp->chgBit(oldp+274,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                                  >> 8U))));
    bufp->chgIData(oldp+275,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[1U] 
                               << 0x18U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U] 
                                            >> 8U))),32);
    bufp->chgCData(oldp+276,((3U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U] 
                                    >> 6U))),2);
    bufp->chgBit(oldp+277,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U] 
                                  >> 5U))));
    bufp->chgCData(oldp+278,((0x1fU & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__ex_mem_i[0U])),5);
    bufp->chgIData(oldp+279,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[4U] 
                               << 0x12U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U] 
                                            >> 0xeU))),32);
    bufp->chgIData(oldp+280,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[3U] 
                               << 0x12U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U] 
                                            >> 0xeU))),32);
    bufp->chgIData(oldp+281,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[2U] 
                               << 0x12U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
                                            >> 0xeU))),32);
    bufp->chgIData(oldp+282,(((vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[1U] 
                               << 0x12U) | (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
                                            >> 0xeU))),32);
    bufp->chgBit(oldp+283,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
                                  >> 0xdU))));
    bufp->chgCData(oldp+284,((0xfU & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
                                      >> 9U))),4);
    bufp->chgBit(oldp+285,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
                                  >> 8U))));
    bufp->chgCData(oldp+286,((3U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
                                    >> 6U))),2);
    bufp->chgBit(oldp+287,((1U & (vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U] 
                                  >> 5U))));
    bufp->chgCData(oldp+288,((0x1fU & vlSelfRef.rv_cpu__DOT__memory_stage__DOT__mem_wb_o[0U])),5);
    bufp->chgBit(oldp+289,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__clk_i));
    bufp->chgBit(oldp+290,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__rstn_i));
    bufp->chgBit(oldp+291,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__cenb_i));
    bufp->chgBit(oldp+292,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__wenb_i));
    bufp->chgCData(oldp+293,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__mask_i),4);
    bufp->chgCData(oldp+294,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__addr_i),8);
    bufp->chgIData(oldp+295,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_i),32);
    bufp->chgIData(oldp+296,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__data_o),32);
    bufp->chgIData(oldp+297,(vlSelfRef.rv_cpu__DOT__memory_stage__DOT__sram_inst__DOT__i),32);
    bufp->chgBit(oldp+298,(vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__clk_i));
    bufp->chgBit(oldp+299,(vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__rstn_i));
    bufp->chgIData(oldp+300,(((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[4U] 
                               << 0x12U) | (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[3U] 
                                            >> 0xeU))),32);
    bufp->chgIData(oldp+301,(((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[3U] 
                               << 0x12U) | (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[2U] 
                                            >> 0xeU))),32);
    bufp->chgIData(oldp+302,(((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[2U] 
                               << 0x12U) | (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[1U] 
                                            >> 0xeU))),32);
    bufp->chgIData(oldp+303,(((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[1U] 
                               << 0x12U) | (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                            >> 0xeU))),32);
    bufp->chgBit(oldp+304,((1U & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                  >> 0xdU))));
    bufp->chgCData(oldp+305,((0xfU & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                      >> 9U))),4);
    bufp->chgBit(oldp+306,((1U & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                  >> 8U))));
    bufp->chgCData(oldp+307,((3U & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                    >> 6U))),2);
    bufp->chgBit(oldp+308,((1U & (vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U] 
                                  >> 5U))));
    bufp->chgCData(oldp+309,((0x1fU & vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_wb_i[0U])),5);
    bufp->chgBit(oldp+310,((1U & (IData)((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o 
                                          >> 0x25U)))));
    bufp->chgCData(oldp+311,((0x1fU & (IData)((vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o 
                                               >> 0x20U)))),5);
    bufp->chgIData(oldp+312,((IData)(vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__wb_id_o)),32);
    bufp->chgIData(oldp+313,(vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data),32);
    bufp->chgIData(oldp+314,(vlSelfRef.rv_cpu__DOT__writeback_stage__DOT__mem_data_ext),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
