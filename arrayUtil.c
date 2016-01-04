#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arrayUtil.h"

Arr create(int type_size,int length){
    Arr new_arr;
    new_arr.type_size = type_size;
    new_arr.length = length;
    new_arr.base = calloc(length,type_size);
    return new_arr;
}

// int are_equal(Arr a,Arr b) {
//   if(a.length != b.length)
//     return 0;
//   for (size_t i = 0; i < a.length; i++) {
//     if(a.base[i]!=b.base[i])
//       return 0;
//   }
//   return 1;
// }
