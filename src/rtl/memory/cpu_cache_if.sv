interface cpu_cache_if
#(
    parameter ADDR_W = 32,
    parameter DATA_W = 32
);
    logic                   rd_en;
    logic                   wr_en;
    logic                   stall;
    logic [(DATA_W/8)-1:0]  mask;
    logic [ADDR_W-1:0]      addr;
    logic [DATA_W-1:0]      wr_data;
    logic [DATA_W-1:0]      rd_data;

    modport master (output rd_en, wr_en, addr, wr_data, mask,
                    input  stall, rd_data);

    modport slave (input  rd_en, wr_en, addr, wr_data, mask,
                    output stall, rd_data);

endinterface
