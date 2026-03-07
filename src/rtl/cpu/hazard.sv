import rv_cpu_pkg::id_hzd_s;
module hazard
#(

) (
    // clk, rst
    input logic     clk_i,
    input logic     rstn_i,

    // ID to Hazard Detection Interface
    input id_hzd_s id_hzd_i,

    // Hazard Detection to Control Interface
    output logic stall_o,
    output logic flush_o
);
    // ======================== //
    //       HAZARD DETECTION
    // ======================== //
    /**
     *  The main functions handled by the hazard detection unit are:
     *  1. Detect data hazards and generate stall signals for the pipeline registers
     *  2. Detect control hazards and generate flush signals for the pipeline registers
     *
     *  For this project, we will only implement data hazard detection for load-use hazards (i.e. when an instruction tries to use a register that is being loaded from memory in the previous instruction)
     *  We will not implement control hazard detection (i.e. for branches and jumps) since we are assuming a simple static branch predictor that always predicts not taken (and thus does not require any flushing)
     */

    // ======================== //
    //        Variables
    // ======================== //
    // no vars?

endmodule
