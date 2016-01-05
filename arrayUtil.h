typedef struct {
  int type_size;
  void *base;
  int length;
} ArrayUtil;

ArrayUtil create(int type_size, int length);
int are_equal(ArrayUtil a, ArrayUtil b);
ArrayUtil resize(ArrayUtil util, int length);
int findIndex(ArrayUtil util, void *element);
