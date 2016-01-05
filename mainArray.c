#include <stdio.h>
#include <assert.h>
#include "arrayUtil.h"

void test_are_equal(ArrayUtil a, ArrayUtil b) {
  assert(are_equal(a, b) == 1);
  assert(are_equal(b, a) == 1);
  assert(are_equal(b, b) == 1);
  assert(are_equal(a, a) == 1);
};

void test_resize(ArrayUtil util, int length) {
  ArrayUtil new_arr = resize(util, length);
  assert(new_arr.length == length);
};

void test_find_index(ArrayUtil util, void *element){

};

int main() {
  ArrayUtil arr1 = create(4, 3);
  ArrayUtil arr2 = create(4, 3);
  // printf("The new Arr length is : %d\n", arr1.length);
  // printf("The new Arr type_size is : %d\n", arr1.type_size);
  // printf("The new Arr base is : %d\n", *(int *)arr1.base);
  test_are_equal(arr1, arr2);
  test_resize(arr1, 12);
  test_resize(arr2, 18);
  return 0;
};
