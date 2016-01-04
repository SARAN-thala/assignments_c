#include <stdio.h>
#include <assert.h>
#include "arrayUtil.h"
int main() {
  Arr arr1 = create(4,5);
  Arr arr2 = create(4,5);
  // printf("The new Arr length is : %d\n", arr1.length);
  // printf("The new Arr type_size is : %d\n", arr1.type_size);
  // printf("The new Arr base is : %p\n", (int *)arr1.base);
  // int a[]={1,2,3};
  // int b[]={1,2,3};
  assert(are_equal(arr1,arr2)==1);
  return 0;
}
