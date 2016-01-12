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
  e->value = value;
  e->next = NULL;
  if (list->length == 0)
    list->head = list->tail = e;
  else
    list->tail = list->tail->next = e;
  list->length++;
  return list->length;
  free(e);
};

void *get_first_element(LinkedList list) {
  return list.head->value;
  //
};

void *get_last_element(LinkedList list) {
  return list.tail->value;
  //
};

void forEach(LinkedList list, ElementProcessor e) {
  Element *ele = list.head;
  while (ele != NULL) {
    e(ele->value);
    ele = ele->next;
  }
};
