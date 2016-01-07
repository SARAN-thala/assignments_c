#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayUtil.h"

ArrayUtil create(int type_size, int length) {
  ArrayUtil new_arr;
  new_arr.type_size = type_size;
  new_arr.length = length;
  new_arr.base = calloc(length, type_size);
  return new_arr;
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
  ArrayUtil new_arr;
  new_arr.base = realloc(util.base, need_length);
  new_arr.length = length;
  return new_arr;
};

int findIndex(ArrayUtil util, void *element) {
  void *base = util.base;
  for (size_t i = 0; i < util.length; i++) {
    if (memcmp(base + (util.type_size * i), element, util.type_size) == 0)
      return i;
  }
  return -1;
};

void dispose(ArrayUtil util) {
  free(util.base);
  util.base = NULL;
};

void *findFirst(ArrayUtil util, MatchFunc *match, void *hint) {
  void *array = util.base;
  void *element;
  for (size_t i = 0; i < util.length; i++) {
    element = &(array[i * util.type_size]);
    if (match(hint, element))
      return element;
  }
  return 0;
}

void *findLast(ArrayUtil util, MatchFunc *match, void *hint) {
  void *array = util.base;
  void *element;
  for (int i = (util.length - 1); i >= 0; i--) {
    element = &(array[i * util.type_size]);
    if (match(hint, element))
      return element;
  }
  return 0;
}

int count(ArrayUtil util, MatchFunc *match, void *hint) {
  int counter = 0;
  void *array = util.base;
  void *element;
  for (size_t i = 0; i < util.length; i++) {
    element = &(array[i * util.type_size]);
    if (match(hint, element))
      counter++;
  }
  return counter;
}

int filter(ArrayUtil util, MatchFunc *match, void *hint, void **destination,
           int maxItems) {
  int count = 0;
  void *base;
  for (int i = 0; i < util.length; i++) {
    base = util.base + (i * util.type_size);
    if (count < maxItems) {
      if (match(hint, base)) {
        memcpy(*destination + (count * util.type_size), base, util.type_size);
        count++;
      }
    }
  }
  return count;
};
