#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createList(void) {
  LinkedList new_arr;
  new_arr.head = new_arr.tail = NULL;
  new_arr.length = 0;
  return new_arr;
};

int add_to_list(LinkedList *list, void *value) {
  Element *e = (Element *)malloc(sizeof(Element));
  int number = *(int *)value;
  e->value = number;
  e->next = NULL;
  if (list->length == 0)
    list->head = list->tail = e;
  else
    list->tail->next = list->tail = e;
  list->length++;
  return list->length;
  free(e);
};

void *get_first_element(LinkedList list) {
  int head = list.head->value;
  void *value = &head;
  return value;
};

void *get_last_element(LinkedList list) {
  int tail = list.tail->value;
  void *value = &tail;
  return value;
};
