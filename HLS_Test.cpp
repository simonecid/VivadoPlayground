#include "HLS_Test.h"

#ifndef __SYNTHESIS__
#include <iostream>
#endif

void hls_main(
              unsigned int inVector1[ARRAY_SIZE],
              unsigned int inVector2[ARRAY_SIZE], 
              unsigned int outVector[ARRAY_SIZE]
             )
{
  #ifndef __SYNTHESIS__
  std::cout << "Summin' up stuff!" << std::endl;
  #endif
  sumLoop: for (unsigned int x = 0 ; x < ARRAY_SIZE ; x++)
  {
    outVector[x] = inVector1[x] + inVector2[x];
  }
}