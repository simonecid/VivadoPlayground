// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _hls_main_HH_
#define _hls_main_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "hls_main_mac_mulabkb.h"

namespace ap_rtl {

struct hls_main : public sc_module {
    // Port declarations 8
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_in< sc_lv<8> > v1;
    sc_in< sc_lv<8> > v2;
    sc_in< sc_lv<8> > v3;
    sc_out< sc_lv<8> > ap_return;
    // Port declarations for the virtual clock. 
    sc_in_clk ap_virtual_clock;


    // Module declarations
    hls_main(sc_module_name name);
    SC_HAS_PROCESS(hls_main);

    ~hls_main();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    hls_main_mac_mulabkb<1,1,8,8,8,8>* hls_main_mac_mulabkb_U1;
    sc_signal< sc_lv<8> > grp_fu_34_p3;
    static const sc_logic ap_const_logic_1;
    static const bool ap_const_boolean_1;
    static const sc_logic ap_const_logic_0;
    // Thread declarations
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_ap_return();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif
