#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "arrayUtil.h"

void test_create() {
  ArrayUtil a = create(sizeof(double), 3);
  double array[] = {3.122, 4.3121, 1.2211};
  a.base = array;
  assert(a.length == 3);
  assert(a.type_size == 8);

  ArrayUtil b = create(sizeof(int), 5);
  int arr[] = {3, 4, 1, 7, 8};
  b.base = arr;
  assert(b.length == 5);
  assert(b.type_size == 4);

  ArrayUtil c = create(sizeof(char), 2);
  char ar[] = {'a', 'b'};
  c.base = ar;
  assert(c.length == 2);
  assert(c.type_size == 1);

  ArrayUtil d = create(sizeof(float), 4);
  float arr1[] = {3.122, 4.3121, 1.2211, 2.00};
  d.base = arr1;
  assert(d.length == 4);
  assert(d.type_size == 4);

  ArrayUtil e = create(sizeof(void), 22);
  assert(e.length == 22);
  assert(e.type_size == 1);
};

void test_are_equal() {
  ArrayUtil a = create(sizeof(int), 3);
  ArrayUtil b = create(sizeof(float), 3);
  ArrayUtil c = create(sizeof(char), 3);
  ArrayUtil d = create(sizeof(double), 3);
  assert(are_equal(a, b) == 1);
  assert(are_equal(b, a) == 1);
  assert(are_equal(b, b) == 1);
  assert(are_equal(a, a) == 1);
  assert(are_equal(a, c) == 0);
  assert(are_equal(a, d) == 0);
  assert(are_equal(c, d) == 0);
};

void test_resize() {
  int length;
  ArrayUtil util = create(sizeof(int), 3);
  ArrayUtil util1 = create(sizeof(char), 4);
  ArrayUtil util2 = create(sizeof(float), 6);
  ArrayUtil util3 = create(sizeof(double), 5);
  ArrayUtil new_arr = resize(util, 10);
  assert(new_arr.length == 10);
  ArrayUtil new_arr1 = resize(util1, 20);
  assert(new_arr1.length == 20);
  ArrayUtil new_arr2 = resize(util2, 12);
  assert(new_arr2.length == 12);
  ArrayUtil new_arr3 = resize(util3, 22);
  assert(new_arr3.length == 22);
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

int isEven(void *hint, void *item) {
  return (*(int *)item % 2) ? 0 : 1;
  //
};

int isDivisible(void *hint, void *item) {
  int *numberPtr = (int *)item;
  int *hintPtr = (int *)hint;
  return *numberPtr % *hintPtr ? 0 : 1;
};

void test_find_first_is_even() {
  ArrayUtil array = create(sizeof(int), 6);
  int arr[] = {3, 4, 1, 7, 8, 9}, x, *result;
  array.base = arr;
  result = (int *)findFirst(array, &isEven, &x);
  assert(*result == 4);
}

void test_find_first_is_divisible() {
  ArrayUtil array = create(sizeof(int), 6);
  int arr[] = {2, 4, 6, 7, 8, 9}, x = 3, *result;
  array.base = arr;
  result = (int *)findFirst(array, &isDivisible, &x);
  assert(*result == 6);
}

void test_find_last_is_even() {
  ArrayUtil array = create(sizeof(int), 6);
  int arr[] = {3, 4, 1, 7, 8, 9}, x, *result;
  array.base = arr;
  result = (int *)findLast(array, &isEven, &x);
  assert(*result == 8);
};

void test_find_last_is_divisible() {
  ArrayUtil array = create(sizeof(int), 6);
  int arr[] = {2, 4, 6, 7, 8, 9}, x = 3, *result;
  array.base = arr;
  result = (int *)findLast(array, &isDivisible, &x);
  assert(*result == 9);
}

void test_count_is_even() {
  ArrayUtil array = create(sizeof(int), 6);
  int arr[] = {3, 4, 1, 7, 8, 9}, x, result;
  array.base = arr;
  result = count(array, &isEven, &x);
  assert(result == 2);
};

void test_count_is_divisible() {
  ArrayUtil array = create(sizeof(int), 6);
  int arr[] = {3, 4, 6, 7, 8, 9}, x = 3, result;
  array.base = arr;
  result = count(array, &isDivisible, &x);
  assert(result == 3);
};

void test_filter_returns_only_even_numbers() {
  int x;
  int maxItems = 5;
  ArrayUtil array = create(sizeof(int), 5);
  int base[] = {1, 22, 66, 46, 96};
  // int *base = (int *)array.base;
  array.base = base;
  ArrayUtil dest = create(sizeof(int), maxItems);
  assert(filter(array, &isEven, &x, &dest.base, maxItems) == 4);
  int *result = (int *)dest.base;
  assert(result[0] == 22);
  assert(result[1] == 66);
  assert(result[2] == 46);
  assert(result[3] == 96);
};
void test_filter_is_divisible() {
  int x = 3;
  int maxItems = 5;
  ArrayUtil array = create(sizeof(int), 5);
  int base[] = {1, 22, 66, 46, 96};
  array.base = base;
  ArrayUtil dest = create(sizeof(int), maxItems);
  assert(filter(array, &isDivisible, &x, &dest.base, maxItems) == 2);
  int *result = (int *)dest.base;
  assert(result[0] == 66);
  assert(result[1] == 96);
};

void increment(void *hint, void *sourceItem, void *destinationItem) {
  int a = *(int *)sourceItem;
  *(int *)destinationItem = a + 1;
};

void test_map_increment() {
  int x;
  ArrayUtil array = create(sizeof(int), 5);
  int arr[] = {1, 2, 3, 4, 5};
  array.base = arr;
  ArrayUtil dest = create(sizeof(int), 5);
  map(array, dest, &increment, &x);
  int *result = (int *)dest.base;
  assert(result[0] == 2);
  assert(result[1] == 3);
  assert(result[2] == 4);
  assert(result[3] == 5);
  assert(result[4] == 6);
};

void square(void *hint, void *item) {
  int *result = (int *)item;
  *result = (*result) * (*result);
};

void test_forEach_square() {
  int *x;
  ArrayUtil array = create(sizeof(int), 5);
  int arr[] = {1, 2, 3, 4, 5};
  array.base = arr;
  forEach(array, square, &x);
  int *result = (int *)array.base;
  assert(result[0] == 1);
  assert(result[1] == 4);
  assert(result[2] == 9);
  assert(result[3] == 16);
  assert(result[4] == 25);
};

void *largest(void *hint, void *previousItem, void *item) {
  if (*((char *)previousItem) > *((char *)item))
    return previousItem;
  return item;
};

void test_reduce_largest() {
  int *x;
  int intialValue = 0;
  ArrayUtil array = create(sizeof(int), 5);
  int arr[] = {1, 2, 3, 4, 5};
  array.base = arr;
  int value = *(int *)reduce(array, &largest, &x, &intialValue);
  assert(value == 5);
};
