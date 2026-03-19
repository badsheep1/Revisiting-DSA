#include<stdbool.h>
#include<stdio.h>

#define SUCCESS 1
#define ERROR 0
#define UNDEFINED -1

// Data Structure Declarations
typedef struct ListObj* List;

// Constructors - Deconstructors
List newList(void);

void freeList(List* pL);

// Access Functions

int length(List L);

int listIndex(List L);

void* front(List L);

void* back(List L);

void* get(List L);

// Manipulation procedures

void clear(List L);

void set(List L, void* x);

void moveFront(List L);

void moveBack(List L);

void movePrev(List L);


void moveNext(List L);

void prepend(List L, void* x);

void append(List L, void* x);

void insertBefore(List L, void* x);

void insertAfter(List L, void* x);

void deleteFront(List L);

void deleteBack(List L);

void delete(List L);


