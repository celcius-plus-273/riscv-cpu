module axi_mem_test
    import rv_cpu_pkg::*;
(
    // clk, rst
    input logic clk_i,
    input logic rstn_i,

    // EX/MEM Interface
    input ex_mem_s ex_mem_i, // Execute to Memory pipeline register (reg)

    // MEM/WB Interface (output reg)
    output mem_wb_s mem_wb_o // Memory to Writeback pipeline register (reg)
);
    // ============================== //
    //    AXI4 Lite Bus Instance
    // ============================== //
    axi4_lite_if axi_lite_bus (.*); // AXI4-Lite bus
    mem_hzd_s mem_hzd_o; // memory hazard output

    // ============================== //
    //       Pipe Mem Instance
    // ============================== //
    pipe_mem #(
        .D_MEM_DEPTH(D_MEM_DEPTH)
    ) pipe_mem_inst (
        .clk_i(clk_i),
        .rstn_i(rstn_i),
        .ex_mem_i(ex_mem_i),
        .mem_wb_o(mem_wb_o),
        .mem_hzd_o(mem_hzd_o),
        .axl_if(axi_lite_bus.master)
    );

    // ============================== //
    //        D Cache Instance
    // ============================== //
    d_cache #(
        .D_CACHE_DEPTH(D_MEM_DEPTH),
        .D_CACHE_AX_DELAY(D_MEM_AX_DELAY) // 2 cycle delay for AXI transactions
    ) d_cache_inst (
        .clk_i(clk_i),
        .rstn_i(rstn_i),
        .axl_if(axi_lite_bus.slave)
    );

endmodule
