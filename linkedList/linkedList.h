typedef struct node {
  void *value;
  struct node *next;
} Node;

typedef struct list {
  Node *head;
  Node *tail;
  int length;
} LinkedList;

LinkedList createList(void);

void print_list(LinkedList);

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

typedef void(ConvertFunc)(void *hint, void *sourceItem, void *destinationItem);

LinkedList map(LinkedList, ConvertFunc, void *);
