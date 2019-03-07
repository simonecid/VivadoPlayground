#include "HLS_Test.h"
#include <iostream>
#include <assert.h>

int main(int argc, char const *argv[])
{
  unsigned int array1[ARRAY_SIZE];
  unsigned int array2[ARRAY_SIZE];
  unsigned int array3[ARRAY_SIZE];
  unsigned int array3_truth[ARRAY_SIZE];

  for (unsigned int a = 0; a < ARRAY_SIZE; a++)
  {
    array1[a] = a;
    array2[a] = a;
    array3_truth[a] = array1[a] + array2[a];
  }

  hls_main(array1, array2, array3);

  for (unsigned int a = 0; a < ARRAY_SIZE; a++)
  {
    assert(array3_truth[a] == array3[a]);
  }

}