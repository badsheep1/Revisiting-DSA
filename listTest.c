#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
// This is to test the functions defined in List.c

int main(){

// Testing the constructor:
  List testList = newList();
       
  // Test case for the initialization conditions:
  
  assert(testList != NULL); 

  assert(length(testList) == 0);

  assert(index(testList) == UNDEFINED);
  
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

  moveBack(accessList);

  assert(index(accessList) == 5 && get(accessList) == 6);

  movePrev(accessList);

  assert(index(accessList) == 4 && get(accessList) == 3);

  movePrev(accessList);

  assert(index(accessList) == 3 && get(accessList) == 66);

  List accessList2 = newList();

  append(accessList2, 32);
  append(accessList2, 69);
  append(accessList2, 67);
  append(accessList2, 66);
  append(accessList2, 3);
  append(accessList2, 6);
  assert(equals(accessList, accessList2));

  printf("All access function tests passed. \n");

  return 0;
}
