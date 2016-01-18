#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedList.h"

void test_empty_create_list() {
  LinkedList list = createList();
  assert(list.length == 0);
  assert(list.head == NULL);
  assert(list.tail == NULL);
};

void test_add_to_list_int() {
  LinkedList list = createList();
  int value = 3;
  assert(add_to_list(&list, &value) == 1);
  assert(add_to_list(&list, &value) != 0);
};

void test_add_to_list_float() {
  LinkedList list = createList();
  float value = 1.023;
  assert(add_to_list(&list, &value) == 1);
  assert(add_to_list(&list, &value) != 0);
};

void test_add_to_list_double() {
  LinkedList list = createList();
  double value = 1.03;
  assert(add_to_list(&list, &value) == 1);
  assert(add_to_list(&list, &value) != 0);
};

void test_add_to_list_char() {
  LinkedList list = createList();
  char value = 's';
  assert(add_to_list(&list, &value) == 1);
  assert(add_to_list(&list, &value) != 0);
};

void test_add_to_list_string() {
  LinkedList list = createList();
  char value[] = "saran";
  assert(add_to_list(&list, &value) == 1);
  assert(add_to_list(&list, &value) != 0);
};

void test_get_first_element_int() {
  LinkedList list = createList();
  int value = 4;
  int value1 = 3;
  int value2 = 7;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  assert(4 == *(int *)get_first_element(list));
};

void test_get_first_element_float() {
  LinkedList list = createList();
  float value = 4.302;
  float value1 = 3.211;
  float value2 = 7.02;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  assert(value == *(float *)get_first_element(list));
};

void test_get_first_element_double() {
  LinkedList list = createList();
  double value = 4.302;
  double value1 = 3.211;
  double value2 = 7.02;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  assert(4.302 == *(double *)get_first_element(list));
};

void test_get_first_element_char() {
  LinkedList list = createList();
  char value = 'S';
  char value1 = 'A';
  char value2 = 'X';
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  assert('S' == *(char *)get_first_element(list));
};

void test_get_first_element_string() {
  LinkedList list = createList();
  char value[] = "The";
  char value1[] = "World";
  char value2[] = "Beautiful";
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  assert(value == (char *)get_first_element(list));
};

void test_get_last_element_int() {
  LinkedList list = createList();
  int value = 4;
  int value1 = 3;
  int value2 = 7;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  assert(7 == *(int *)get_last_element(list));
};

void test_get_last_element_float() {
  LinkedList list = createList();
  float value = 4.302;
  float value1 = 3.211;
  float value2 = 7.02;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  assert(value2 == *(float *)get_last_element(list));
};

void test_get_last_element_double() {
  LinkedList list = createList();
  double value = 4.302;
  double value1 = 3.211;
  double value2 = 7.02;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  assert(7.02 == *(double *)get_last_element(list));
};

void test_get_last_element_char() {
  LinkedList list = createList();
  char value = 'S';
  char value1 = 'A';
  char value2 = 'X';
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  assert('X' == *(char *)get_last_element(list));
};

void test_get_last_element_string() {
  LinkedList list = createList();
  char value[] = "The";
  char value1[] = "World";
  char value2[] = "Beautiful";
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  assert(value2 == (char *)get_last_element(list));
};

void increment(void *ele) {
  (*(int *)ele) += 1;
  //
};

void increment_float(void *ele) {
  (*(float *)ele) += 1;
  //
};

void increment_double(void *ele) {
  (*(double *)ele) += 1;
  //
};

void square(void *ele) {
  (*(int *)ele *= (*(int *)ele));
  //
};
void square_float(void *ele) {
  (*(float *)ele *= (*(float *)ele));
  //
};
void square_double(void *ele) {
  (*(double *)ele *= (*(double *)ele));
  //
};

void test_for_each_increment() {
  LinkedList list = createList();
  int value = 3, value1 = 5, value2 = 7;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  forEach(list, increment);
  assert(4 == *(int *)list.head->value);
  assert(8 == *(int *)list.tail->value);
};

void test_for_each_increment_float() {
  LinkedList list = createList();
  float value = 3.2, value1 = 5.21, value2 = 7.01;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  forEach(list, increment_float);
  assert(value == *(float *)list.head->value);
  assert(value2 == *(float *)list.tail->value);
};

void test_for_each_increment_double() {
  LinkedList list = createList();
  double value = 3.223, value1 = 5.21, value2 = 7.01;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  forEach(list, increment_double);
  assert(4.223 == *(double *)list.head->value);
  assert(8.01 == *(double *)list.tail->value);
};

void test_for_each_square() {
  LinkedList list = createList();
  int value = 3, value1 = 5, value2 = 7;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  forEach(list, square);
  assert(9 == *(int *)list.head->value);
  assert(49 == *(int *)list.tail->value);
};

void test_for_each_square_float() {
  LinkedList list = createList();
  float value = 3.2, value1 = 5.1, value2 = 7.4;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  forEach(list, square_float);
  assert(value == *(float *)list.head->value);
  assert(value2 == *(float *)list.tail->value);
};

void test_for_each_square_double() {
  LinkedList list = createList();
  double value = 3.2, value1 = 5.1, value2 = 7.4;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  forEach(list, square_double);
  assert(value == *(double *)list.head->value);
  assert(value2 == *(double *)list.tail->value);
};

void test_get_element_at_int() {
  LinkedList list = createList();
  int val1 = 2, val2 = 3, val3 = 4;
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  assert(4 == *(int *)getElementAt(list, 2));
  assert(2 == *(int *)getElementAt(list, 0));
  assert(NULL == (int *)getElementAt(list, 3));
  assert(NULL == (int *)getElementAt(list, -1));
};

void test_get_element_at_float() {
  LinkedList list = createList();
  float val1 = 2.23, val2 = 3.11, val3 = 4.02;
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  assert(val3 == *(float *)getElementAt(list, 2));
  assert(val1 == *(float *)getElementAt(list, 0));
  assert(NULL == (float *)getElementAt(list, 3));
  assert(NULL == (float *)getElementAt(list, -1));
};

void test_get_element_at_double() {
  LinkedList list = createList();
  double val1 = 2.23, val2 = 3.11, val3 = 4.02;
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  assert(4.02 == *(double *)getElementAt(list, 2));
  assert(2.23 == *(double *)getElementAt(list, 0));
  assert(NULL == (double *)getElementAt(list, 3));
  assert(NULL == (double *)getElementAt(list, -1));
};

void test_get_element_at_char() {
  LinkedList list = createList();
  char val1 = 'S', val2 = 'A', val3 = 'Q';
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  assert('Q' == *(char *)getElementAt(list, 2));
  assert('S' == *(char *)getElementAt(list, 0));
  assert(NULL == (char *)getElementAt(list, 3));
  assert(NULL == (char *)getElementAt(list, -1));
};

void test_get_element_at_string() {
  LinkedList list = createList();
  char val1[] = "The", val2[] = "World", val3[] = "Beautiful";
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  assert(val3 == (char *)getElementAt(list, 2));
  assert(val1 == (char *)getElementAt(list, 0));
  assert(NULL == (char *)getElementAt(list, 3));
  assert(NULL == (char *)getElementAt(list, -1));
};

void test_index_of_int() {
  LinkedList list = createList();
  int val1 = 2, val2 = 3, val3 = 4, val4 = 6;
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  assert(0 == indexOf(list, &val1));
  assert(2 == indexOf(list, &val3));
  assert(-1 == indexOf(list, &val4));
};

void test_index_of_float() {
  LinkedList list = createList();
  float val1 = 2.231, val2 = 3.028, val3 = 4.89, val4 = 6.21;
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  assert(0 == indexOf(list, &val1));
  assert(2 == indexOf(list, &val3));
  assert(-1 == indexOf(list, &val4));
};

void test_index_of_double() {
  LinkedList list = createList();
  double val1 = 2.231, val2 = 3.028, val3 = 4.89, val4 = 6.21;
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  assert(0 == indexOf(list, &val1));
  assert(2 == indexOf(list, &val3));
  assert(-1 == indexOf(list, &val4));
};

void test_index_of_char() {
  LinkedList list = createList();
  char val1 = 'A', val2 = 'S', val3 = 'W', val4 = 'Z';
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  assert(0 == indexOf(list, &val1));
  assert(2 == indexOf(list, &val3));
  assert(-1 == indexOf(list, &val4));
};

void test_index_of_string() {
  LinkedList list = createList();
  char val1[] = "The", val2[] = "boy", val3[] = "so", val4[] = "cool";
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  assert(0 == indexOf(list, &val1));
  assert(2 == indexOf(list, &val3));
  assert(-1 == indexOf(list, &val4));
};

void test_delete_element_at() {
  LinkedList list = createList();
  int val1 = 2, val2 = 3, val3 = 4, val4 = 5;
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  add_to_list(&list, &val4);
  assert(&val2 == deleteElementAt(&list, 1));
  assert(list.head->value == &val1);
  assert(list.tail->value == &val4);
  LinkedList array = createList();
  int value1 = 2, value2 = 3, value3 = 4, value4 = 5;
  add_to_list(&array, &value1);
  add_to_list(&array, &value2);
  add_to_list(&array, &value3);
  add_to_list(&array, &value4);
  assert(&value4 == deleteElementAt(&array, 3));
  assert(array.head->value == &value1);
  assert(array.tail->value == &value3);
};

void test_delete_element_at_float() {
  LinkedList list = createList();
  float val1 = 2.12, val2 = 3.34, val3 = 4.89, val4 = 5.33;
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  add_to_list(&list, &val4);
  assert(&val2 == deleteElementAt(&list, 1));
  assert(list.head->value == &val1);
  assert(list.tail->value == &val4);
  LinkedList array = createList();
  float value1 = 2.12, value2 = 3.34, value3 = 4.89, value4 = 5.33;
  add_to_list(&array, &value1);
  add_to_list(&array, &value2);
  add_to_list(&array, &value3);
  add_to_list(&array, &value4);
  assert(&value4 == deleteElementAt(&array, 3));
  assert(array.head->value == &value1);
  assert(array.tail->value == &value3);
};

void test_delete_element_at_char() {
  LinkedList list = createList();
  char val1 = 'A', val2 = 'S', val3 = 'Q', val4 = 'W';
  add_to_list(&list, &val1);
  add_to_list(&list, &val2);
  add_to_list(&list, &val3);
  add_to_list(&list, &val4);
  assert(&val2 == deleteElementAt(&list, 1));
  assert(list.head->value == &val1);
  assert(list.tail->value == &val4);
  LinkedList array = createList();
  char value1 = 'A', value2 = 'S', value3 = 'Q', value4 = 'W';
  add_to_list(&array, &value1);
  add_to_list(&array, &value2);
  add_to_list(&array, &value3);
  add_to_list(&array, &value4);
  assert(&value4 == deleteElementAt(&array, 3));
  assert(array.head->value == &value1);
  assert(array.tail->value == &value3);
};

void test_as_array() {
  LinkedList list = createList();
  int arr[5] = {2, 3, 9, 6, 1};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list, &arr[i]);
  }
  void *arr_ads = (void *)calloc(2, 8);
  int count = asArray(list, arr_ads, 2);
  for (size_t i = 0; i < count; i++) {
    assert(**(int **)arr_ads == arr[i]);
    arr_ads += 8;
  }
};

void test_as_array_double() {
  LinkedList list = createList();
  double arr[5] = {2.21, 3.223, 9.434, 6.54, 1.5454};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list, &arr[i]);
  }
  void *arr_ads = (void *)calloc(2, 8);
  double count = asArray(list, arr_ads, 2);
  for (size_t i = 0; i < count; i++) {
    assert(**(double **)arr_ads == arr[i]);
    arr_ads += 8;
  }
};

void test_as_array_char() {
  LinkedList list = createList();
  char arr[5] = {'S', 'A', 'R', 'A', 'N'};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list, &arr[i]);
  }
  void *arr_ads = (void *)calloc(2, 8);
  char count = asArray(list, arr_ads, 2);
  for (size_t i = 0; i < count; i++) {
    assert(**(char **)arr_ads == arr[i]);
    arr_ads += 8;
  }
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

void test_filter_isEven() {
  LinkedList list = createList();
  int arr[7] = {2, 3, 4, 6, 1, 12, 45};
  for (size_t i = 0; i < 7; i++) {
    add_to_list(&list, &arr[i]);
  }
  LinkedList output = filter(list, &isEven, NULL);
  int *index1 = getElementAt(output, 1);
  int *index2 = getElementAt(output, 2);
  assert(*(int *)output.head->value == 2);
  assert(*index1 == 4);
  assert(*index2 == 6);
  assert(*(int *)output.tail->value == 12);
};

void test_filter_is_divisible() {
  int hint = 3;
  LinkedList list = createList();
  int arr[7] = {2, 3, 4, 6, 1, 12, 45};
  for (size_t i = 0; i < 7; i++) {
    add_to_list(&list, &arr[i]);
  }
  LinkedList output = filter(list, &isDivisible, &hint);
  int *index1 = getElementAt(output, 1);
  int *index2 = getElementAt(output, 2);
  assert(*(int *)output.head->value == 3);
  assert(*index1 == 6);
  assert(*index2 == 12);
  assert(*(int *)output.tail->value == 45);
};

void test_reverse() {
  LinkedList list = createList();
  int arr[7] = {2, 3, 4, 6, 1, 12, 45};
  for (size_t i = 0; i < 7; i++) {
    add_to_list(&list, &arr[i]);
  }
  LinkedList res = reverse(list);
  int *index1 = getElementAt(res, 1);
  int *index2 = getElementAt(res, 2);
  int *index5 = getElementAt(res, 5);
  assert(*(int *)res.head->value == 45);
  assert(*index1 == 12);
  assert(*index2 == 1);
  assert(*index5 == 3);
  assert(*(int *)res.tail->value == 2);
};

void test_reverse_double() {
  LinkedList list = createList();
  double arr[7] = {2.21, 3.212, 4.87, 6.34, 1.435, 12.43, 45.22};
  for (size_t i = 0; i < 7; i++) {
    add_to_list(&list, &arr[i]);
  }
  LinkedList res = reverse(list);
  double *index1 = getElementAt(res, 1);
  double *index2 = getElementAt(res, 2);
  double *index5 = getElementAt(res, 5);
  assert(*(double *)res.head->value == 45.22);
  assert(*index1 == 12.43);
  assert(*index2 == 1.435);
  assert(*index5 == 3.212);
  assert(*(double *)res.tail->value == 2.21);
};

void increment_by_1(void *hint, void *sourceItem, void *destinationItem) {
  int a = *(int *)sourceItem;
  *(int *)destinationItem = a + 1;
};

void test_map_increment() {
  LinkedList list = createList();
  int arr[7] = {2, 3, 4, 6, 1, 12, 45};
  for (size_t i = 0; i < 7; i++) {
    add_to_list(&list, &arr[i]);
  }
  LinkedList output = map(list, &increment_by_1, NULL);
  int *index1 = getElementAt(output, 1);
  int *index2 = getElementAt(output, 2);
  assert(*(int *)output.head->value == 3);
  assert(*index1 == 4);
  assert(*index2 == 5);
  assert(*(int *)output.tail->value == 46);
};

void *largest(void *hint, void *previousItem, void *item) {
  if (*((char *)previousItem) > *((char *)item))
    return previousItem;
  return item;
};

void test_reduce_largest() {
  int *x;
  int initialValue = 0;
  LinkedList list = createList();
  int arr[7] = {2, 3, 4, 6, 1, 62, 45};
  for (size_t i = 0; i < 7; i++) {
    add_to_list(&list, &arr[i]);
  }
  int result = *(int *)reduce(list, &largest, &x, &initialValue);
  assert(result == 62);
};
