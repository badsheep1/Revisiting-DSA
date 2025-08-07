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

  if(length(testList) == 0){
    printf("New List is correctly empty.\n");
  }
  else{
    printf("New List is not empty.\n");
  }

  if(index(testList) == UNDEFINED){
    printf("New List's cursor is correctly undefined.\n");
  }
  else{
    printf("New List's cursor is incorrectly defined.\n");
  }

  
  return 0;
}
