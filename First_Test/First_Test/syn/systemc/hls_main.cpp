// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "hls_main.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic hls_main::ap_const_logic_1 = sc_dt::Log_1;
const bool hls_main::ap_const_boolean_1 = true;
const sc_logic hls_main::ap_const_logic_0 = sc_dt::Log_0;

hls_main::hls_main(sc_module_name name) : sc_module(name), mVcdFile(0) {
    hls_main_mac_mulabkb_U1 = new hls_main_mac_mulabkb<1,1,8,8,8,8>("hls_main_mac_mulabkb_U1");
    hls_main_mac_mulabkb_U1->din0(v3);
    hls_main_mac_mulabkb_U1->din1(v2);
    hls_main_mac_mulabkb_U1->din2(v1);
    hls_main_mac_mulabkb_U1->dout(grp_fu_34_p3);

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_start );

    SC_METHOD(thread_ap_idle);

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_start );

    SC_METHOD(thread_ap_return);
    sensitive << ( ap_start );
    sensitive << ( grp_fu_34_p3 );

    SC_THREAD(thread_hdltv_gen);
    sensitive << ( ap_virtual_clock.pos() );

    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "hls_main_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT__
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, v1, "(port)v1");
    sc_trace(mVcdFile, v2, "(port)v2");
    sc_trace(mVcdFile, v3, "(port)v3");
    sc_trace(mVcdFile, ap_return, "(port)ap_return");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, grp_fu_34_p3, "grp_fu_34_p3");
#endif

    }
    mHdltvinHandle.open("hls_main.hdltvin.dat");
    mHdltvoutHandle.open("hls_main.hdltvout.dat");
}

hls_main::~hls_main() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    mHdltvinHandle << "] " << endl;
    mHdltvoutHandle << "] " << endl;
    mHdltvinHandle.close();
    mHdltvoutHandle.close();
    delete hls_main_mac_mulabkb_U1;
}

void hls_main::thread_ap_done() {
    ap_done = ap_start.read();
}

void hls_main::thread_ap_idle() {
    ap_idle = ap_const_logic_1;
}

void hls_main::thread_ap_ready() {
    ap_ready = ap_start.read();
}

void hls_main::thread_ap_return() {
    ap_return = grp_fu_34_p3.read();
}

void hls_main::thread_hdltv_gen() {
    const char* dump_tv = std::getenv("AP_WRITE_TV");
    if (!(dump_tv && string(dump_tv) == "on")) return;

    wait();

    mHdltvinHandle << "[ " << endl;
    mHdltvoutHandle << "[ " << endl;
    int ap_cycleNo = 0;
    while (1) {
        wait();
        const char* mComma = ap_cycleNo == 0 ? " " : ", " ;
        mHdltvinHandle << mComma << "{"  <<  " \"ap_start\" :  \"" << ap_start.read() << "\" ";
        mHdltvoutHandle << mComma << "{"  <<  " \"ap_done\" :  \"" << ap_done.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_idle\" :  \"" << ap_idle.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_ready\" :  \"" << ap_ready.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"v1\" :  \"" << v1.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"v2\" :  \"" << v2.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"v3\" :  \"" << v3.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_return\" :  \"" << ap_return.read() << "\" ";
        mHdltvinHandle << "}" << std::endl;
        mHdltvoutHandle << "}" << std::endl;
        ap_cycleNo++;
    }
}

}
