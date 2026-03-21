#include <stdlib.h>
#include <stdio.h>
#include "List.h"


struct testObj{
  int data;
  struct testObj* nodePointer;
};

int main(void){
  List testList = newList();

  int* integer = malloc(sizeof(int));
  *integer = 1;

  append(testList, integer);

  append(testList, &"string1");

  struct testObj testInstance;
  testInstance.data = 5;
  testInstance.nodePointer = NULL;

  append(testList, &testInstance);

  moveFront(testList);

  freeList(&testList);
  return 0;
}
