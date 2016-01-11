#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedList.h"

void test_empty_create_list() {
  LinkedList array = createList();
  assert(array.length == 0);
  assert(array.head == NULL);
  assert(array.tail == NULL);
};

void test_add_to_list() {
  LinkedList array = createList();
  int value = 3;
  assert(add_to_list(&array, &value) == 1);
  assert(add_to_list(&array, &value) != 0);
};
