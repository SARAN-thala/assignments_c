#include <stdio.h>
#include <assert.h>
#include "arrayUtil.h"

void test_create() {
  ArrayUtil a = create(sizeof(double), 3);
  assert(a.length == 3);
  assert(a.type_size == 8);
  ArrayUtil b = create(sizeof(int), 5);
  assert(b.length == 5);
  assert(b.type_size == 4);
  ArrayUtil c = create(sizeof(char), 2);
  assert(c.length == 2);
  assert(c.type_size == 1);
  assert(b.type_size == 4);
  ArrayUtil d = create(sizeof(float), 12);
  assert(d.length == 12);
  assert(d.type_size == 4);
  ArrayUtil e = create(sizeof(void), 22);
  assert(e.length == 22);
  assert(e.type_size == 1);
  dispose(a);
};

void test_are_equal() {
  ArrayUtil a = create(1, 3);
  ArrayUtil b = create(1, 3);
  assert(are_equal(a, b) == 1);
  assert(are_equal(b, a) == 1);
  assert(are_equal(b, b) == 1);
  assert(are_equal(a, a) == 1);
};

void test_resize() {
  ArrayUtil util = create(1, 3);
  int length;
  ArrayUtil new_arr = resize(util, length);
  assert(new_arr.length == length);
};

void test_findIndex() {
  ArrayUtil a1 = create(sizeof(int), 3);
  ArrayUtil a2 = create(sizeof(char), 5);
  ArrayUtil a3 = create(sizeof(float), 5);
  ArrayUtil a4 = create(sizeof(double), 2);
  int x = 3;
  int *num = (int *)a1.base;
  num[2] = 3;
  char y = 's';
  char *ch = (char *)a2.base;
  ch[4] = 's';
  float z = 20.000000;
  float *fl = (float *)a3.base;
  fl[3] = 20.000000;
  double w = 10.000000;
  double *dl = (double *)a4.base;
  dl[1] = 10.000000;
  assert(findIndex(a1, &x) == 2);
  assert(findIndex(a2, &y) == 4);
  assert(findIndex(a3, &z) == 3);
  assert(findIndex(a4, &w) == 1);
};

// void test_dispose() {
//   ArrayUtil e = create(sizeof(int), 22);
//   assert(e.length == 22);
//   assert(e.type_size == 4);
//   dispose(e);
//   assert(e.length == 0);
// }

// -------main fn----------------------------------------
int main() {
  test_create();
  test_are_equal();
  test_resize();
  test_findIndex();
  // test_dispose();
  return 0;
};
