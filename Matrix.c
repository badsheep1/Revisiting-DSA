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

// Entry helper function prototypes:
Entry newEntry(int col, double val);
void freeEntry(Entry *pE);

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

  free((*pM)->matrixArray);

  free(*pM);
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

  if (x == 0) {

    while (listIndex(rowHandle) != UNDEFINED) {
      Entry cursor = (Entry)get(rowHandle);
      if (cursor->column == j) {
        delete(rowHandle);
      } else if (cursor->column > j) {
        break;
      } else {
        moveNext(rowHandle);
      }
    }

  } else {

    if (listIndex(rowHandle) == UNDEFINED) {
      // No non-zero entries in this row:
      if (x != 0) {
        Entry E = newEntry(j, x);
        append(rowHandle, E);
      }
    } else {

      while (listIndex(rowHandle) != UNDEFINED) {

        Entry cursor = (Entry)get(rowHandle);
        if (j == cursor->column) {
          cursor->value = x;
          break;
        } else if (j < cursor->column) {
          Entry E = newEntry(j, x);
          insertBefore(rowHandle, E);
          break;
        } else {
          if (listIndex(rowHandle) == (length(rowHandle) - 1)) {
            Entry E = newEntry(j, x);
            insertAfter(rowHandle, E);
            break;
          } else {
            moveNext(rowHandle);
          }
        }
      }
    }
  }
}

// Helper Functions:
Entry newEntry(int col, double val) {
  Entry child = malloc(sizeof(matrixEntry));
  child->column = col;
  child->value = val;

  return child;
}

void freeEntry(Entry *pE) {
  if ((pE != NULL) && (*pE != NULL)) {
    free(*pE);
    *pE = NULL;
  }
}
