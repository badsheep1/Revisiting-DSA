#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
// This is to test the functions defined in List.c

int main(){

// Testing the constructor:
  List testList = newList();
       
  // Test case for the initialization conditions:
  
  assert(testList != NULL && "newList() failed to create a List instance. \n");

  assert(length(testList) == 0 && "newList() did not initialize list size to 0. \n");

  assert(index(testList) == UNDEFINED && "newList() failed to set cursor to UNDEFINED. \n");
  
  printf("All newList() tests passed.\n");

  freeList(&testList);

  assert(testList == NULL);

  printf("All freeList() tests passed. \n");

  List accessList = newList();
  
  prepend(accessList, 6);

  assert(front(accessList) == 6);
 
  prepend(accessList, 3);
  prepend(accessList, 66);
  prepend(accessList, 67);
  prepend(accessList, 69);
  prepend(accessList, 32);


  assert(back(accessList) == 6);

  moveFront(accessList);
  assert(index(accessList) == 0);
  
  moveNext(accessList);

  assert(index(accessList) == 1 && get(accessList) == 69);

  moveNext(accessList);

  assert(index(accessList) == 2 && get(accessList) == 67);

  printf("All access function tests passed. \n");

  return 0;
}
