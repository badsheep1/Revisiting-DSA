#include <stdlib.h>
#include <stdio.h>


typedef struct obj1{
  int data;
}dataObj;

typedef struct obj2{
  char string[128];
}stringObj;

typedef struct nodeObj{
  void* obj;
  struct nodeObj* next;
  struct nodeObj* prev;
}nodeObj;

typedef nodeObj* Node;

typedef struct listObj{
  Node front;
  Node end;
  Node cursor;
}listObj;


Node newNode(void* obj);

Node newNode(void* obj){
  Node child = malloc(sizeof(nodeObj));
  child->next = NULL;
  child->prev = NULL;
  child->obj = obj;

  return child;
}



int main(void){


  return 0;
}
