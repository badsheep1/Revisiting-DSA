#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Defining Data Structures

//Node Object
typedef struct NodeObj{
  int data;
  struct NodeObj* prev;
  struct NodeObj* next;
} NodeObj;

typedef NodeObj* Node;

Node newNode(int data){ 
  Node infant = malloc(sizeof(NodeObj));
  if(infant == NULL){
    printf("Error: Memory allocation failed for newNode().");
    return NULL;
  }
  infant->data = data;
  infant->prev = infant->next = NULL;
  return infant;
}

void freeNode(Node* pN){
  if(pN != NULL && *pN != NULL){
    free(*pN);
    *pN = NULL;
  }
}

//List Object

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
    printf("Error: Memory Allocation failed in newList().");
    return NULL;
  }
  
  infant->size = 0;
  infant->index = UNDEFINED;
  infant->cursor = NULL;
  infant->cursor = infant->front = infant->back = NULL;
  return infant;
}

void freeList(List *pL){

  if(pL != NULL && *pL != NULL){
    free(*pL);
    *pL = NULL;
  }

}


// Access Functions
// There are no Post-Conditions for Access Functions.

// length(List L)
// Pre-Conditions: List Exists
int length(List L){ 
  
  if(L == NULL){
    printf("Error: List parameter is NULL.");
    return ERROR;
  }

  return L->size;
}

// index(List L)
// Pre-Condition: List Exists
int index(List L){

  if(L == NULL){
    printf("Error: List parameter is NULL.");
    return ERROR;
  }

  return L->index;
}

// front(List L)
// Pre-condition: List Exists
int front(List L){

  if(L == NULL){
    printf("Error: List parameter is NULL.");
    return ERROR;
  }
  
  return L->front->data;
}

//  back(List L)
//  Pre-Condition: List Exists
int back(List L){

  if(L == NULL){
    printf("Error: List parameter is NULL.");
    return ERROR;
  }

  return L->back->data;
}

//  get(List L)
//  Pre-Condition: List Exists, List is not empty, List cursor is pointing at something
int get(List L){
  
  if(L == NULL){
    printf("Error: List parameter is NULL.");
    return ERROR;
  }

  if(L->cursor == NULL){
    printf("Error: List cursor is undefined.");
    return ERROR;
  }

  return L->cursor->data;

}

//  equals(List A, List B)
//  Pre-Conditions: List A and List B both exist.
bool equals(List A, List B){
  
  if(A == NULL || B == NULL){
    printf("Error: List parameter is NULL.");
    return ERROR;
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
    printf("Error: List parameter is NULL.");
    return NULL;
  }

  while(length(L)){
    deleteFront(L);
  }

}

//Pre-Conditions: List Exists, List is not-empty, List Cursor is not pointing to NULL.
//Post-Conditions: List node selected by the cursor has its data over-written.
void set(List L, int x){
  
  if(L == NULL){
    printf("Error: List parameter is NULL.");
    return;
  }
  
  if(L->cursor == NULL){
    printf("Error: List Cursor is undefined.");
    return;
  }

  L->cursor->data = x;
  
}

//Pre-Conditions: List Exists, List is not empty.
//Post-Conditions: List cursor points at the node at the front, the index is changed to 0.
void moveFront(List L){
  
  if(L == NULL){
    printf("Error: List parameter is NULL.");
    return NULL;
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
    printf("Error: List parameter is NULL.");
    return NULL;
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
    printf("Error: List parameter is NULL.");
    return NULL;
  }
  
  if(L->cursor != NULL){
    if(L->index != length(L)--){
      L->cursor = L->cursor->next;
      L->index++;
    }
    else{
      L->cursor = NULL;
      L->index = UNDEFINED;
    }
  }

}

//Pre-Conditions: List Exists, Cursor should exist and not defined at the front of the List.
//Post-Conditions: Cursor tranverses to the previous node, index is decremented to reflect this. Otherwise cursor becomes undefined.
void movePrev(List L){
  
  if(L == NULL){
    printf("Error: List parameter is NULL.");
    return NULL;
  }
  if(L->cursor != NULL){
    if(L->index != 0){
      L->cursor = L->cursor->prev;
      L->index--;
    }
    else{
      L->cursor = NULL;
      L->index = UNDEFINED;
    }
  }
  
}

//Pre-Conditions: List Exists
//Post-Conditions: New Node is created and inserted at the front. Size increments by one. If cursor is defined, index should be incremented.
void prepend(List L, int x){
  if(L == NULL){
    printf("Error: List parameter is NULL in prepback().");
    return NULL;
  }

  Node preNode = newNode(x);

  if(L->size == 0){
    L->front = L->back = preNode;
  }
  else{
    preNode->next = L->front;
    L->front->prev = preNode;
    L->front = preNode;
  }
  
  if(L->index != UNDEFINED){
    L->index++;
  }

}

//Pre-Conditions: List Exists.
//Post-Conditions: New Node is created and inserted at the end. Size increments by one. Index remains constant.
void append(List L, int x){

  if(L == NULL){
    printf("Error: List parameter is NULL.");
    return NULL;
  }

  Node appNode = newNode(x);
  
  if(L->size == 0){
    L->front = L->back = appNode;
  }
  else{
    newNode->prev = L->back;
    L->back->next = newNode;
    L->back = newNode;
  }
  
}

void insertBefore(List L, int x){
  if(L == NULL){
    printf("Error: List parameter is NULL for insertBefore().");
    return NULL;
  }

  if(length(L) == 0){
    printf("Error: Cursor is undefined for insertBefore().");
    return NULL;
  }

  Node nodeLink = newNode(x);
  nodeLink->prev = L->cursor->prev;
  nodeLink->next = L->cursor;
  L->cursor->prev = nodeLink;
  
  L->index++;
  
}

void insertAfter(List L, int x){
  if(L == NULL){
    printf("Error: List parameter is NULL for insertAfter().");
    return NULL;
  }

  if(length(L) == 0){
    printf("Error: Cursor is undefined for insertAfter().");
    return NULL;
  }

  Node nodeLink = newNode(x);
  nodeLink->prev = L->cursor;
  nodeLink->next = L->cursor->next;
  L->cursor->next = nodeLink;
   
}

void deleteFront(List L){
  
  if(L == NULL){
    printf("Error: List parameter is NULL for deleteFront().");
    return NULL;
  }

  if(length(L) == 0){
    printf("Error: List is empty for deleteFront().");
    return NULL;
  }
  
  Node tempCursor = L->front; // Creates a temporary pointer to point at the front node.

  L->front = L->front->next;
  L->size--;
  freeNode(&tempCursor);
 
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
    printf("Error: List parameter is NULL for deleteBack().");
    return; 
  }

  if(length(L) == 0){
    printf("Error: Empty List for deleteBack().");
    return; 
  }
  
  Node tempCursor = L->back; // Creates a temporary pointer to point at the front node.
  L->back = L->back->prev;
  L->size--;
  freeNode(&tempCursor);

  if( index(L) != UNDEFINED && index(L) == (length(L) - 1)){
    L->cursor = NULL; // Set the cursor to NULl and undefine it.
    L->index = UNDEFINED;
  }

}

void delete(List L){

  if(L == NULL){
    printf("Error: List parameter is NULL for delete().");
    return NULL;
  }

  if(length(L) == 0){
    printf("Error: Empty List for delete().");
    return NULL;
  }

  if(index(L) == UNDEFINED){
    printf("Error: The cursor is undefined for delete().");
    return NULL;
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

    freeNode(&L->cursor);
    L->cursor = NULL;
    L->index = UNDEFINED;
    L->size--;
  }

}

//Other Operations

void printList(FILE* out, List L){
  if(L == NULL){
    printf("Error: The list parameter is not valid for printList().");
    return;
  }

  if(out == NULL){
    printf("Error: The file parameter is not valid for printList().");
    return;
  }

  int placeHolder = index(L);
  moveFront(L);

  while(index(L) != UNDEFINED){
    fprintf(out, "%d ", get(L));
    moveNext(L);
  }

  moveFront(L);
  while(index(L) != placeHolder){
    moveNext(L);
  }

}

List copyList(List L){
  if(L == NULL){
    printf("Error: List parameter is not valid for copyList().");
    return NULL;
  }

  List cloneList = newList();

  int indexMark = index(L);
  moveFront(L);

  while(index(L) < size(L)--){
    append(cloneList, get(L));
    moveNext(L);
  }
  cloneList->cursor = NULL;
  cloneList->index = UNDEFINED;

  moveFront(L);
  while(index(L) < indexMark){
    moveNext(L);
  }

}


