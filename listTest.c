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

  List accesslist = newList();
  
  prepend(accesslist, 6);

  assert(front(accesslist) == 6);
 
  prepend(accesslist, 3);
  prepend(accesslist, 66);
  prepend(accesslist, 67);
  prepend(accesslist, 69);
  prepend(accesslist, 32);


  assert(back(accesslist) == 6);

  moveFront(accesslist);
  assert(index(accesslist) == 0);
  
  moveNext(accesslist);

  assert(index(accesslist) == 1 && get(accesslist) == 69);

  moveNext(accesslist);

  assert(index(accesslist) == 2 && get(accesslist) == 67);

  moveBack(accesslist);

  assert(index(accesslist) == 5 && get(accesslist) == 6);

  movePrev(accesslist);

  assert(index(accesslist) == 4 && get(accesslist) == 3);

  movePrev(accesslist);

  assert(index(accesslist) == 3 && get(accesslist) == 66);

  List accesslist2 = newList();

  append(accesslist2, 32);
  append(accesslist2, 69);
  append(accesslist2, 67);
  append(accesslist2, 66);
  append(accesslist2, 3);
  append(accesslist2, 6);

  int index1, index2;
  index1 = index(accesslist);
  index2 = index(accesslist2);

  assert(equals(accesslist, accesslist2));

  assert(index1 == index(accesslist) && index2 == index(accesslist2));

  printf("all access function tests passed. \n");

  clear(accesslist);
  clear(accesslist2);

  assert(length(accesslist) == 0 && index(accesslist) == UNDEFINED);

  assert(length(accesslist2) == 0 && index(accesslist2) == UNDEFINED);
  
  freeList(&accesslist);
  freeList(&accesslist2);

  assert(accesslist == NULL && accesslist2 == NULL);

  List manipulationlist = newList();

  for(int i = 0; i < 10; i++){
    append(manipulationlist, i);
  }

  assert(length(manipulationlist) == 10);

  moveFront(manipulationlist);

  for(int i = 0; i < 10; i++){
    assert(get(manipulationlist) == i); 
    assert(index(manipulationlist) == i);
    moveNext(manipulationlist);
  }

  moveBack(manipulationlist);
  
  for(int i = 9; i == 0; i--){
    assert(get(manipulationlist) == i);
    assert(index(manipulationlist) == i);
    movePrev(manipulationlist);
  }

  moveFront(manipulationlist);
  moveNext(manipulationlist);
  moveNext(manipulationlist);

  set(manipulationlist, 100);
  moveNext(manipulationlist); 
  moveNext(manipulationlist);
  set(manipulationlist, 99);

moveFront(manipulationlist);

  for(int i = 0; i < 10; i++){
    if(i == 2){
      assert(get(manipulationlist) == 100);
    }
    else if(i == 4){
      assert(get(manipulationlist) == 99);
    }
    else{
      assert(get(manipulationlist) == i);
    }
    moveNext(manipulationlist);
  }

  moveBack(manipulationlist);

  insertBefore(manipulationlist, 0);

  assert(index(manipulationlist) == 10);

  assert(length(manipulationlist) == 11);

  movePrev(manipulationlist);

  assert(get(manipulationlist) == 0);

  movePrev(manipulationlist);

  assert(get(manipulationlist) == 8);

  moveFront(manipulationlist);
  
  insertAfter(manipulationlist, 55);

  assert(index(manipulationlist) == 0);

  moveNext(manipulationlist);
  assert(get(manipulationlist) == 55);

  moveNext(manipulationlist);

  assert(get(manipulationlist) == 1);

  List anotherList = newList();

  append(anotherList, 1);
  append(anotherList, 79);
  
  moveFront(anotherList);
  insertAfter(anotherList, 412);
 
  clear(manipulationlist);

  assert(index(manipulationlist) == UNDEFINED && length(manipulationlist) == 0);

  for(int i = 1; i <= 10; i++){
    append(manipulationlist, i);
  }

  moveFront(manipulationlist);

  assert(get(manipulationlist) == 1);
  moveNext(manipulationlist);
  assert(get(manipulationlist) == 2);
  moveNext(manipulationlist);
  assert(get(manipulationlist) == 3);

  delete(manipulationlist);

  assert(index(manipulationlist) == UNDEFINED && length(manipulationlist) == 9);

  moveFront(manipulationlist);

  moveNext(manipulationlist);
  moveNext(manipulationlist);

  assert(get(manipulationlist) == 4);

  assert(index(manipulationlist) == 2);

  // deleteFront(manipulationlist);
  //
  // assert(index(manipulationlist) == 1);
  //
  // moveFront(manipulationlist);
  //
  // assert(get(manipulationlist) == 2);
  //
  


  printf("All manipulation function tests have passed.\n");

  
  return 0;
}
