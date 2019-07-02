#include "HLS_Test.h"

#ifndef __SYNTHESIS__
#include <iostream>
#endif

void hls_main(
              unsigned int inData[PHI_SIZE][ETA_SIZE],
              // unsigned int inVector2[ARRAY_SIZE], 
              // unsigned int inVector3[ARRAY_SIZE], 
              // unsigned int inVector4[ARRAY_SIZE], 
              // unsigned int outVector[ARRAY_SIZE]
              unsigned int outData[ETA_SIZE]
             )
{
  #pragma HLS pipeline 
  #pragma HLS array_partition variable=inData dim=0 complete
  #pragma HLS array_partition variable=outData dim=0 complete
  static unsigned int clockCounter = 0;
  unsigned int lClockCounter = clockCounter;
  static unsigned int caloGrid_BRAM[PHI_SIZE][ETA_SIZE];
  #pragma HLS array_partition variable=caloGrid_BRAM dim=2 complete
  //#pragma HLS resource variable=caloGrid_BRAM core=RAM_2P_BRAM
  static unsigned int caloGrid_FF[PHI_SIZE][ETA_SIZE];
  #pragma HLS array_partition variable=caloGrid_FF dim=0 complete

  clockCounter = (clockCounter == PHI_SIZE - 1) ? 0 : clockCounter + 1;

  if (lClockCounter == 0)
  {
    copyToFF: for (unsigned int phi = 0 ; phi < PHI_SIZE ; phi++)
    {
      for (unsigned int eta = 0 ; eta < ETA_SIZE ; eta++)
      {
        caloGrid_FF[phi][eta] = inData[phi][eta];
      }
    }
  }

  replaceInBRAM:for (unsigned int eta = 0 ; eta < ETA_SIZE ; eta++)
  {
    outData[eta] = caloGrid_BRAM[lClockCounter][eta];
    caloGrid_BRAM[lClockCounter][eta] = caloGrid_FF[lClockCounter][eta];
  }

}