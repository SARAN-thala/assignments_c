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

void *getElementAt(LinkedList list, int index) {
  Element *ele = list.head;
  if (index >= list.length || index < 0)
    return NULL;
  for (int i = 1; i <= index; i++)
    ele = ele->next;
  return ele->value;
};

int indexOf(LinkedList list, void *element) {
  Element *ele = list.head;
  int count = 0;
  while (ele != NULL) {
    if (ele->value == element)
      return count;
    count++;
    ele = ele->next;
  }
  return -1;
};

void *deleteElementAt(LinkedList *list, int index) {
  void *deleted_data = 0;
  Element *temp = list->head;
  Element *previous = NULL;
  if (index < 0 || index >= list->length)
    return NULL;
  for (int i = 0; i < index; i++) {
    previous = temp;
    temp = temp->next;
  }
  deleted_data = temp->value;
  previous ? (previous->next = temp->next) : (list->head = list->head->next);
  temp == list->tail && (list->tail = previous);
  list->length--;
  return deleted_data;
};

int asArray(LinkedList list, void **array, int maxElements) {
  int counter = 0;
  Element *ele = list.head;
  while (counter <= maxElements && ele != NULL) {
    array[counter] = ele->value;
    counter++;
    ele = ele->next;
  }
  return counter;
};
