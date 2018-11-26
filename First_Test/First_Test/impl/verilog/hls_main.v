// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="hls_main,hls_ip_2018_2,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7k160tfbg484-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=5.790000,HLS_SYN_LAT=0,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=1,HLS_SYN_FF=0,HLS_SYN_LUT=0,HLS_VERSION=2018_2}" *)

module hls_main (
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        v1,
        v2,
        v3,
        ap_return
);


input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [7:0] v1;
input  [7:0] v2;
input  [7:0] v3;
output  [7:0] ap_return;

wire  signed [7:0] grp_fu_34_p3;

hls_main_mac_mulabkb #(
    .ID( 1 ),
    .NUM_STAGE( 1 ),
    .din0_WIDTH( 8 ),
    .din1_WIDTH( 8 ),
    .din2_WIDTH( 8 ),
    .dout_WIDTH( 8 ))
hls_main_mac_mulabkb_U1(
    .din0(v3),
    .din1(v2),
    .din2(v1),
    .dout(grp_fu_34_p3)
);

assign ap_done = ap_start;

assign ap_idle = 1'b1;

assign ap_ready = ap_start;

assign ap_return = grp_fu_34_p3;

endmodule //hls_main
