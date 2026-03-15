interface axi4_lite_if
#(
    parameter ADDR_W = 32,
    parameter DATA_W = 32
);
    // Write address
    logic [ADDR_W-1:0]    aw_addr;
    logic [2:0]           aw_prot;
    logic                 aw_vld;
    logic                 aw_rdy;
    // Write data
    logic [DATA_W-1:0]    w_data;
    logic [DATA_W/8-1:0]  w_strb;
    logic                 w_vld;
    logic                 w_rdy;
    // Write response
    logic [1:0]           b_resp;
    logic                 b_vld;
    logic                 b_rdy;
    // Read address
    logic [ADDR_W-1:0]    ar_addr;
    logic [2:0]           ar_prot;
    logic                 ar_vld;
    logic                 ar_rdy;
    // Read data
    logic [DATA_W-1:0]    r_data;
    logic [1:0]           r_resp;
    logic                 r_vld;
    logic                 r_rdy;

    modport master (output  aw_addr, aw_prot, aw_vld, w_data, w_strb, w_vld,
                            b_rdy, ar_addr, ar_prot, ar_vld, r_rdy,
                    input  aw_rdy, w_rdy, b_resp, b_vld, ar_rdy, r_data, r_resp, r_vld);

    modport slave  (input  aw_addr, aw_prot, aw_vld, w_data, w_strb, w_vld,
                            b_rdy, ar_addr, ar_prot, ar_vld, r_rdy,
                    output aw_rdy, w_rdy, b_resp, b_vld, ar_rdy, r_data, r_resp, r_vld);
endinterface
