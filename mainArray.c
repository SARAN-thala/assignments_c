#include <stdio.h>
#include <assert.h>
#include "arrayUtil.h"
int main() {
  Arr arr1 = create(4,5);
  printf("The new Arr length is : %d\n", arr1.length);
  printf("The new Arr type_size is : %d\n", arr1.type_size);
  printf("The new Arr base is : %d\n", (*(int *)arr1.base));
  // int a[]={1,2,3};
  // int b[]={1,2,3};
  // int are_equal(int a,int b);
  return 0;
}
