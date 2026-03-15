interface mem_dcache_if
#(
    parameter ADDR_W = 32,
    parameter DATA_W = 32
);
    logic                   rd_en;
    logic                   wr_en;
    logic                   stall;
    logic [ADDR_W-1:0]      addr;
    logic [DATA_W-1:0]      wr_data;
    logic [(DATA_W/8)-1:0]  wr_strb;
    logic [DATA_W-1:0]      rd_data;

    modport master (output rd_en, wr_en, addr, wr_data, wr_strb,
                    input  stall, rd_data);

    modport slave (input  rd_en, wr_en, addr, wr_data, wr_strb,
                    output stall, rd_data);

endinterface //mem_dcache_if
