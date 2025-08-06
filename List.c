#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// Defining Data Structures

struct NodeObj{
  int data;
  Node prev;
  Node next;
};
struct ListObj{
  int size;
  int index;
  Node cursor;
  Node front;
  Node back;
};

// Constructors and Deconstructors:

List newList(void){
  List infant = malloc(sizeof(struct ListObj));
  if(infant == NULL){
    fprintf(stderr, "Error: Memory Allocation failed in newList().");
    exit(EXIT_FAILURE);
  }
  
  infant->size = 0;
  infant->index = UNDEFINED;
  infant->cursor = NULL;
  infant->cursor = infant->front = infant->back = NULL;
  return infant;
}

void freeList(List *pL){
  ;
}

// Access Functions
int length(List L){ 
  
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  return L->size;
}

int index(List L){

  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  return L->index;
}

int front(List L){

  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }
  
  return L->front->data;
}

int back(List L){

  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  return L->back->data;
}

int get(List L){
  
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  if(L->cursor == NULL){
    fprintf(stderr, "Error: List cursor is undefined.");
    exit(EXIT_FAILURE);
  }

  return L->cursor->data;

}

bool equals(List A, List B){
  
  if(A == NULL || B == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  if(length(A) != length(B)){
    return ERROR;
  }

  return SUCCESS;

}

//Manipulation Procedures
void clear(List L){
    
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  while(length(L)){
    deleteFront(L);
  }

}

void set(List L, int x){
  
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }
  
  if(L->cursor == NULL){
    fprintf(stderr, "Error: List Cursor is undefined.");
    exit(EXIT_FAILURE);
  }

  L->cursor->data = x;
  
}

void moveFront(List L){
  
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }
  
  L->index = 0; // Sets the index to 0, the front of the list.
  L->cursor = L->front;
}
void moveBack(List L){

  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }
  
  L->index = L->size - 1; // Sets the index to (n-1) back of the list.
  L->cursor = L->back; 
}

void moveNext(List L){
  
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }
  
  if(L->cursor != NULL){
    L->cursor = L->cursor->next;
  }
}

void movePrev(List L){
  
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  if(L->cursor != NULL){
    fprintf(stderr, "Error: Cursor is undefined.");
  }

  L->cursor = L->cursor->prev;
  L->index--;
}
 
void prepback(List L, int x){

  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  Node newNode = malloc(sizeof(struct NodeObj));
  if(newNode == NULL){
    fprintf(stderr, "Error: Memory Allocation error for new Node.");
    exit(EXIT_FAILURE);
  }

  newNode->data = x;

  if(L->size == 0){
    L->front = L->back = newNode;
    newNode->prev = newNode->next = NULL;
  }
  else{
    newNode->prev = NULL;
    newNode->next = L->front;
    L->front->prev = newNode;
    L->front = newNode;
  }
  
  if(L->index != UNDEFINED){
    L->index++;
  }

  }

void appback(List L, int x){

  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  Node newNode = malloc(sizeof(struct NodeObj));
  if(newNode == NULL){
    fprintf(stderr, "Error: Memory Allocation error for new Node.");
    exit(EXIT_FAILURE);
  }

  newNode->data = x;

  if(L->size == 0){
    L->front = L->back = newNode;
    newNode->prev = newNode->next = NULL;
  }
  else{
    newNode->next = NULL;
    newNode->prev = L->back;
    L->back->next = newNode;
    L->back = newNode;
  }
  
  }

void insertBefore(List L, int x){
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  if(L->cursor == NULL){
    fprintf(stderr, "Error: Cursor is undefined.");
    exit(EXIT_FAILURE);
  }
  
  L->index++;
  

}

void deleteFront(List L){
  
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  if(length(L) == 0){
    fprintf(stderr, "Error: List does not have a front to delete.");
    exit(EXIT_FAILURE);
  }
  
  Node tempCursor = L->front; // Creates a temporary pointer to point at the front node.

  L->front = L->front->next;
  L->size--;
  free(tempCursor);
 
  if(index(L) != UNDEFINED){ // If the cursor is undefined, do nothing, otherwise:

    if(index(L) == 0){ // Check if the cursor is pointed to the front of the list.
      L->cursor = NULL; // Set the cursor to NULl and undefine it.
      L->index = UNDEFINED;
    }
    else{
      L->index--;
    }

  }

}

void deleteBack(List L){
  
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  if(length(L) == 0){
    fprintf(stderr, "Error: List does not have a front to delete.");
    exit(EXIT_FAILURE);
  }
  
  Node tempCursor = L->back; // Creates a temporary pointer to point at the front node.
  L->back = L->back->prev;
  L->size--;
  free(tempCursor);

  if( index(L) != UNDEFINED && index(L) == (length(L) - 1)){
    L->cursor = NULL; // Set the cursor to NULl and undefine it.
    L->index = UNDEFINED;
  }

}

void delete(List L){

  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  if(length(L) == 0){
    fprintf(stderr, "Error: List is empty.");
    exit(EXIT_FAILURE);
  }

  if(index(L) == UNDEFINED){
    fprintf(stderr, "Error: The cursor is undefined.");
    exit(EXIT_FAILURE);
  }
  
  if(index(L) == 0){
    deleteFront(L);
  }
  else if(index(L) == length(L) - 1){
    deleteBack(L);
  }
  else{
    L->cursor->prev->next = L->cursor->next;
    L->cursor->next->prev = L->cursor->prev;
    free(L->cursor);
    L->cursor = NULL;
    L->index = UNDEFINED;
    L->size--;
  }

}


void printList(FILE* out, List L){
  



}

