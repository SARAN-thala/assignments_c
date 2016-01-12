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
