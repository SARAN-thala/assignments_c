typedef struct arr {
  int type_size;
  void * base;
  int length;
} Arr;

Arr create(int type_size,int length);
