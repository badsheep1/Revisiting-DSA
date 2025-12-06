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

  return 0;
}
