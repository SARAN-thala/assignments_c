typedef struct {
  int type_size;
  void *base;
  int length;
} ArrayUtil;

typedef int(MatchFunc)(void *, void *);
typedef void(ConvertFunc)(void *, void *, void *);
typedef void(OperationFunc)(void *, void *);

ArrayUtil create(int type_size, int length);
int are_equal(ArrayUtil a, ArrayUtil b);
ArrayUtil resize(ArrayUtil util, int length);
int findIndex(ArrayUtil util, void *element);
void dispose(ArrayUtil util);
void *findFirst(ArrayUtil util, MatchFunc *, void *hint);
void *findLast(ArrayUtil util, MatchFunc *, void *hint);
int count(ArrayUtil util, MatchFunc *match, void *hint);
int filter(ArrayUtil util, MatchFunc *match, void *hint, void **destination,
           int maxItems);
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc *convert,
         void *hint);
void forEach(ArrayUtil util, OperationFunc *operation, void *hint);
