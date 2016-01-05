#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayUtil.h"

ArrayUtil create(int type_size, int length) {
  ArrayUtil *new_arr = (ArrayUtil *)calloc(length, type_size);
  new_arr->type_size = type_size;
  new_arr->length = length;
  new_arr->base = new_arr;
  return *new_arr;
};

int are_equal(ArrayUtil a, ArrayUtil b) {
  int length = a.length > b.length ? a.length : b.length;
  int compare = memcmp(a.base, b.base, length);
  if (a.length == b.length && a.type_size == b.type_size && compare == 0) {
    return 1;
  }
  return 0;
};

ArrayUtil resize(ArrayUtil util, int length) {
  int need_length = util.type_size * length;
  ArrayUtil *new_arr = realloc(util.base, need_length);
  new_arr->length = length;
  return *new_arr;
};

int findIndex(ArrayUtil util, void *element) {
  void *base = util.base;
  for (size_t i = 0; i < util.length; i++) {
    if (memcmp(base, element, util.type_size) == 0) {
      return i;
    }
    base = base + util.type_size;
  }
  // for (size_t i = 0; i < util.length; i++) {
  //   if (((char *)util.base)[i] == *((char *)element))
  //     return i;
  // }
  // for (size_t i = 0; i < util.length; i++) {
  //   if (((double *)util.base)[i] == *((double *)element))
  //     return i;
  // }
  return -1;
};

void dispose(ArrayUtil util) {
  free(util.base);
  util.base = NULL;
};
