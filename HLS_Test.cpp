#include "HLS_Test.h"

#include <ap_int.h>

#ifndef __SYNTHESIS__
#include <iostream>
#endif

void hls_delay(
              const ap_uint<64> inData[N_INPUTS],
              ap_uint<64> outData[N_INPUTS]
             )
{
  #pragma HLS pipeline 
  #pragma HLS array_partition variable=inData dim=0 complete
  #pragma HLS array_partition variable=outData dim=0 complete
  #pragma HLS interface ap_none port=inData
  #pragma HLS interface ap_none port=outData
  #pragma HLS interface ap_ctrl_none port=return

  // #pragma HLS latency min=1 max=1

  copyData: for (unsigned int idx = 0 ; idx < N_INPUTS ; idx++)
  {
    outData[idx] = inData[idx];
  }

}