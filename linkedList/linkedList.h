typedef struct linkedList {
  struct element *head;
  struct element *tail;
  int length;
} LinkedList;

typedef struct element {
  int value;
  struct element *next;
} Element;

LinkedList createList(void);

int add_to_list(LinkedList *, void *);
