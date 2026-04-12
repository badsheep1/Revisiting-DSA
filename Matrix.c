#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct matrixObj {
  List *matrixArray;
  int size;
  int nnz;
} matrixObj;

typedef struct matrixEntry {
  int column;
  double value;
} matrixEntry;

typedef matrixEntry *Entry;

Matrix newMatrix(int n) {
  Matrix child = malloc(sizeof(matrixObj));
  child->size = n;
  child->nnz = 0;

  child->matrixArray = malloc(n * sizeof(List));

  for (int i = 0; i < n; i++) {
    child->matrixArray[i] = newList();
  }

  return child;
}

void freeMatrix(Matrix *pM) {
  for (int i = 0; i < size(*pM); i++) {
    freeList(&((*pM)->matrixArray[i]));
  }

  free(pM);
  *pM = NULL;
}

int size(Matrix M) {
  if (M == NULL) {
    fprintf(stderr, "Matrix Error: size() is passed a Null MatrixObj.\n");
    exit(EXIT_FAILURE);
  }

  return M->size;
}

int NNZ(Matrix M) {
  if (M == NULL) {
    fprintf(stderr, "Matrix Error: NZZ() is passed a Null MatrixObj.\n");
    exit(EXIT_FAILURE);
  }

  return M->nnz;
}

// Manipulation Procedures
void makeZero(Matrix M) {
  if (M == NULL) {
    fprintf(stderr, "Matrix Error: makeZero is passed a null MatrixObj.\n");
    exit(EXIT_FAILURE);
  }

  List Handle;
  for (int i = 0; i < size(M); i++) {
    Handle = M->matrixArray[i];
    clear(Handle);
  }
  M->nnz = 0;
}

void changeEntry(Matrix M, int i, int j, double x) {
  if (M == NULL) {
    fprintf(stderr, "Matrix Error: changeEntry is passed a null MatrixObj.\n");
    exit(EXIT_FAILURE);
  }

  if (!((i >= 1) && (i <= size(M)))) {
    fprintf(
        stderr,
        "Matrix Error: changeEntry is passed an out of range i parameter.\n");
    exit(EXIT_FAILURE);
  }

  if (!((j >= 1) && (j <= size(M)))) {
    fprintf(
        stderr,
        "Matrix Error: changeEntry is passed an out of range j parameter.\n");
    exit(EXIT_FAILURE);
  }

  List rowHandle = M->matrixArray[i];

  moveFront(rowHandle);
  if (listIndex(rowHandle) == UNDEFINED) {
    if (x != 0) {
      Entry newEntry = malloc(sizeof(struct matrixEntry));
      newEntry->column = j;
      newEntry->value = x;
      append(rowHandle, &newEntry);
    }
  } else {

    Entry colHandle = (Entry *)get(rowHandle);
  }
}
