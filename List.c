#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Defining Data Structures

typedef struct NodeObj{
  int data;
  Node prev;
  Node next;
} NodeObj;

// Typedef pointer to node.
typedef NodeObj* Node;

typedef struct ListObj{
  int size;
  int index;
  Node cursor;
  Node front;
  Node back;
} ListObj;

// Constructors and Deconstructors:


// newList(void)
// Pre-conditions: N/A
// Post-conditions: N/A

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
// There are no Post-Conditions for Access Functions.

// length(List L)
// Pre-Conditions: List Exists
int length(List L){ 
  
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  return L->size;
}

// index(List L)
// Pre-Condition: List Exists
int index(List L){

  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  return L->index;
}

// front(List L)
// Pre-condition: List Exists
int front(List L){

  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }
  
  return L->front->data;
}

//  back(List L)
//  Pre-Condition: List Exists
int back(List L){

  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  return L->back->data;
}

//  get(List L)
//  Pre-Condition: List Exists, List is not empty, List cursor is pointing at something
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

//  equals(List A, List B)
//  Pre-Conditions: List A and List B both exist.
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
//Pre-Conditions: List Exists.
//Post-Conditions: Removes all nodes from the list.
void clear(List L){
    
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  while(length(L)){
    deleteFront(L);
  }

}

//Pre-Conditions: List Exists, List is not-empty, List Cursor is not pointing to NULL.
//Post-Conditions: List node selected by the cursor has its data over-written.
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

//Pre-Conditions: List Exists, List is not empty.
//Post-Conditions: List cursor points at the node at the front, the index is changed to 0.
void moveFront(List L){
  
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }
 
  // If List is non-empty, it moves the cursor to the front. Otherwise it does nothing.
  if(length(L) > 0){
    L->index = 0; // Sets the index to 0, the front of the list.
    L->cursor = L->front;
  }

}

//Pre-Conditions: List Exists, List is not empty.
//Post-Conditions: List cursor points to the node at the end, the index is changed to (list's size - 1).
void moveBack(List L){

  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }

  if(length(L) > 0){ 
    L->index = L->size - 1; // Sets the index to (n-1) back of the list.
    L->cursor = L->back; 
  }

}

//Pre-Conditions: List Exists, Cursor must exist and not defined at the back of the List.
//Post-Conditions: Cursor traverses to the next node, index is incremented to reflect this. Otherwise cursor becomes undefined.
void moveNext(List L){
  
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }
  
  if(L->cursor != NULL){
    if(L->index != length(L)--){
      L->cursor = L->cursor->next;
      L->index++;
    }
  }

}

//Pre-Conditions: List Exists, Cursor should exist and not defined at the front of the List.
//Post-Conditions: Cursor tranverses to the previous node, index is decremented to reflect this. Otherwise cursor becomes undefined.
void movePrev(List L){
  
  if(L == NULL){
    fprintf(stderr, "Error: List parameter is NULL.");
    exit(EXIT_FAILURE);
  }
  if(L->cursor != NULL){
    if(L->index != 0){
      L->cursor = L->cursor->prev;
      L->index--;
    }
  }
  
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

