#ifndef COMMON_H
#include "common.h"
#endif

/*
 * Helper function
 * Prints the binary representation of integer x
 */
void print_binary(int x) {
  int i;
  // start at MSB and go backwards (decrement)
  for (i = 31; i >= 0; --i) {
    // print the i-th bit (0 or 1)
    printf("%d", (x >> i) & 1);
    // add space for readability
    if (i % 8 == 0) printf(" ");
    if (i % 4 == 0) printf(" ");
  }
  printf("\n");
}
