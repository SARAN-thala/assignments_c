typedef struct node {
  void *value;
  struct node *next;
} Node;

typedef struct list {
  Node *head;
  Node *tail;
  int length;
} LinkedList;

typedef void (*ElementProcessor)(void *);
typedef int(MatchFunc)(void *, void *);
typedef void(ConvertFunc)(void *, void *, void *);
typedef void *(ReducerFunc)(void *, void *, void *);

LinkedList createList(void);

void print_list(LinkedList);

int add_to_list(LinkedList *, void *);

void *get_first_element(LinkedList list);

void *get_last_element(LinkedList list);

void forEach(LinkedList, ElementProcessor);

void *getElementAt(LinkedList, int);

int indexOf(LinkedList, void *);

void *deleteElementAt(LinkedList *, int);

int asArray(LinkedList, void **, int maxElements);

LinkedList filter(LinkedList, MatchFunc, void *);

LinkedList reverse(LinkedList);

LinkedList map(LinkedList, ConvertFunc, void *);

void *reduce(LinkedList, ReducerFunc, void *, void *);
