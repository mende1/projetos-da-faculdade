#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TMin INT_MIN
#define TMax INT_MAX

#include "btest.h"
#include "bits.h"

test_rec test_set[] = {

 {"bitXor", (funct_t) bitXor, (funct_t) test_bitXor, 2, "& ~", 14, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},

 {"allEvenBits", (funct_t) allEvenBits, (funct_t) test_allEvenBits, 1,
    "! ~ & ^ | + << >>", 12, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},  

 {"logicalShift", (funct_t) logicalShift, (funct_t) test_logicalShift,
   2, "! ~ & ^ | + << >>", 20, 2,
  {{TMin, TMax},{0,31},{TMin,TMax}}},

 {"logicalNeg", (funct_t) logicalNeg, (funct_t) test_logicalNeg, 1,
    "~ & ^ | + << >>", 12, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},

 {"tmax", (funct_t) tmax, (funct_t) test_tmax, 0, "! ~ & ^ | + << >>", 4, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},

 {"twosBits", (funct_t) twosBits, (funct_t) test_twosBits, 2,
    "! ~ & ^ | + << >>", 15, 3,
  {{TMin, TMax},{1,32},{TMin,TMax}}}, 

};
