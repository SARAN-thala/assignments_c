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

void test_add_to_list() {
  LinkedList list = createList();
  int value = 3;
  assert(add_to_list(&list, &value) == 1);
  assert(add_to_list(&list, &value) != 0);
};

void test_get_first_element() {
  LinkedList list = createList();
  int value = 4;
  int value1 = 3;
  int value2 = 7;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  assert(4 == *(int *)get_first_element(list));
};

void test_get_last_element() {
  LinkedList list = createList();
  int value = 4;
  int value1 = 3;
  int value2 = 7;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  assert(7 == *(int *)get_last_element(list));
};

void increment(void *ele) {
  (*(int *)ele) += 1;
  //
};

void test_for_each() {
  LinkedList list = createList();
  int value = 3, value1 = 5, value2 = 7;
  add_to_list(&list, &value);
  add_to_list(&list, &value1);
  add_to_list(&list, &value2);
  forEach(list, increment);
  assert(4 == *(int *)list.head->value);
  assert(8 == *(int *)list.tail->value);
};

void test_get_element_at() {
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

void test_index_of() {
  LinkedList list = createList();
  int val1 = 2, val2 = 3, val3 = 4, val4 = 6;
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
  assert(&value1 == deleteElementAt(&array, 0));
  assert(array.head->value == &value2);
  assert(array.tail->value == &value4);
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
