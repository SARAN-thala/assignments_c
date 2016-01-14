typedef struct element {
  void *value;
  struct element *next;
} Element;

typedef struct list {
  Element *head;
  Element *tail;
  int length;
} LinkedList;

LinkedList createList(void);

int add_to_list(LinkedList *, void *);

void *get_first_element(LinkedList list);

void *get_last_element(LinkedList list);

typedef void (*ElementProcessor)(void *);

void forEach(LinkedList, ElementProcessor);

void *getElementAt(LinkedList, int);

int indexOf(LinkedList, void *);

void *deleteElementAt(LinkedList *, int);

int asArray(LinkedList, void **, int maxElements);

typedef int(MatchFunc)(void *, void *);

LinkedList filter(LinkedList, MatchFunc, void *);

LinkedList reverse(LinkedList);
