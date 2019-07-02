#include "HLS_Test.h"

#ifndef __SYNTHESIS__
#include <iostream>
#endif

void hls_null_algo(
              const unsigned char inData[N_INPUTS],
              unsigned char outData[N_INPUTS]
             )
{
  #pragma HLS pipeline 
  #pragma HLS array_partition variable=inData dim=0 complete
  #pragma HLS array_partition variable=outData dim=0 complete
  #pragma HLS interface ap_none port=inData
  #pragma HLS interface ap_none port=outData
  #pragma HLS interface ap_ctrl_none port=return

  #pragma HLS latency min=5 max=5

  copyData: for (unsigned int idx = 0 ; idx < N_INPUTS ; idx++)
  {
    outData[idx] = inData[idx];
  }

}