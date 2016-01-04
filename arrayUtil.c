#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arrayUtil.h"

Arr create(int type_size,int length){
    Arr *new_arr=(Arr *)calloc(length,type_size);
    new_arr->type_size = type_size;
    new_arr->length = length;
    new_arr->base = new_arr;
    printf("Array base: %ld\n", new_arr->base);
    return *new_arr;
}

int are_equal(Arr a,Arr b) {
  if(a.length != b.length && a.type_size != b.type_size)
    return 0;
  // for (size_t i = 0; i < a.length; i++) {
  //   if(a.base[i] != b.base[i])
  //     return 0;
  // }
  return 1;
}
