#include <stdio.h>
#include "omp.h"

int main() {
  int A = 0;
  omp_set_num_threads(4);

#pragma omp parallel reduction(+:A)
  {
    int ID = omp_get_thread_num();
    A += ID;
    printf("A on rank %d: %d  -->  %d \n", ID, A - ID, A);
  }
  

  printf("A:  %d (expected: 10)\n", A);

  return 0;
}
