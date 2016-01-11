#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createList(void) {
  LinkedList new_arr;
  new_arr.head = new_arr.tail = NULL;
  new_arr.length = 0;
  return new_arr;
};

int add_to_list(LinkedList *linkedList, void *value) {
  Element *e = (Element *)malloc(sizeof(Element));
  int number = *(int *)value;
  e->value = number;
  e->next = NULL;
  if (linkedList->length == 0)
    linkedList->head = linkedList->tail = e;
  else
    linkedList->tail->next = linkedList->tail = e;
  linkedList->length++;
  return linkedList->length;
  free(e);
};
