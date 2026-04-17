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

void rowClone(Matrix M, int rowIndex, List row);

Matrix newMatrix(int n) {
  Matrix child = malloc(sizeof(matrixObj));
  child->size = n;
  child->nnz = 0;

  child->matrixArray = calloc(n + 1, sizeof(List));

  for (int i = 1; i <= n; i++) {
    child->matrixArray[i] = newList();
  }

  return child;
}

void freeMatrix(Matrix *pM) {
  for (int i = 1; i <= size(*pM); i++) {
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

int NZZ(Matrix M) {
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
  for (int i = 1; i <= size(M); i++) {
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

  /* Setting x = 0, deletes NZZ entries, or does nothing to zero entries */
  if (x == 0) {

    while (listIndex(rowHandle) != UNDEFINED) {
      Entry cursor = (Entry)get(rowHandle);
      if (cursor->column == j) {
        delete(rowHandle);
        M->nnz--;
        break;
      } else if (cursor->column < j) {
        moveNext(rowHandle);
      } else {
        break; // Column is not in this sparse matrix, do nothing.
      }
    }

  }
  /* Non-zero entry either edits existing entries, or creates new ones */
  else {
    // Empty NNZ list, add new entry anywhere
    if (listIndex(rowHandle) == UNDEFINED) {
      Entry E = newEntry(j, x);
      append(rowHandle, E);
      M->nnz++;
    } else {

      while (listIndex(rowHandle) != UNDEFINED) {
        Entry cursor = (Entry)get(rowHandle);
        if (j ==
            cursor
                ->column) { // NNZ at this column already exists, edit the entry
          cursor->value = x;
          break;
        } else if (j < cursor->column) {
          Entry E = newEntry(j, x);
          insertBefore(rowHandle, E);
          M->nnz++;
          break;
        } else {
          if (listIndex(rowHandle) == (length(rowHandle) - 1)) { // Questionable
            Entry E = newEntry(j, x);
            insertAfter(rowHandle, E);
            M->nnz++;
            break;
          } else {
            moveNext(rowHandle);
          }
        }
      }
    }
  }
}

// Matrix Arithmetic Operations
Matrix copy(Matrix A) {

  Matrix clone = newMatrix(size(A));

  for (int i = 1; i <= size(A); i++) {
    List rowHandle = A->matrixArray[i];
    if (length(rowHandle) > 0) {
      moveFront(rowHandle);
      while (listIndex(rowHandle) != UNDEFINED) {
        Entry currentEntry = (Entry)get(rowHandle);
        changeEntry(clone, i, currentEntry->column, currentEntry->value);
        moveNext(rowHandle);
      }
    }
  }

  return clone;
}

Matrix transpose(Matrix A) {
  Matrix trans = newMatrix(size(A));

  for (int i = 1; i <= size(A); i++) {
    List currentRow = A->matrixArray[i];
    moveFront(currentRow);
    while (listIndex(currentRow) != UNDEFINED) {
      Entry currentEntry = (Entry)get(currentRow);
      changeEntry(trans, currentEntry->column, i, currentEntry->value);
      moveNext(currentRow);
    }
  }
  return trans;
}

Matrix scalarMult(double x, Matrix A) {
  Matrix scale = newMatrix(size(A));
  for (int i = 1; i <= size(A); i++) {
    List currentRow = A->matrixArray[i];
    moveFront(currentRow);
    while (listIndex(currentRow) != UNDEFINED) {
      Entry currentEntry = (Entry)get(currentRow);
      changeEntry(scale, i, currentEntry->column, x * currentEntry->value);
      moveNext(currentRow);
    }
  }
  return scale;
}

Matrix sum(Matrix A, Matrix B) {
  Matrix sum = newMatrix(size(A));
  for (int i = 1; i <= size(A); i++) {
    List rowA = A->matrixArray[i];
    List rowB = B->matrixArray[i];

    moveFront(rowA);
    moveFront(rowB);
    while (listIndex(rowA) != UNDEFINED || listIndex(rowB) != UNDEFINED) {
      if (listIndex(rowA) != UNDEFINED && listIndex(rowB) == UNDEFINED) {
        Entry entryA = (Entry)get(rowA);
        changeEntry(sum, i, entryA->column, entryA->value);
        moveNext(rowA);
      } else if (listIndex(rowA) == UNDEFINED && listIndex(rowB) != UNDEFINED) {
        Entry entryB = (Entry)get(rowB);
        changeEntry(sum, i, entryB->column, entryB->value);
        moveNext(rowB);
      } else {
        Entry entryA = (Entry)get(rowA);
        Entry entryB = (Entry)get(rowB);
        if (entryA->column == entryB->column) {
          changeEntry(sum, i, entryA->column, (entryA->value + entryB->value));
          moveNext(rowA);
          moveNext(rowB);
        } else if (entryA->column < entryB->column) {
          changeEntry(sum, i, entryA->column, entryA->value);
          moveNext(rowA);
        } else if (entryA->column > entryB->column) {
          changeEntry(sum, i, entryB->column, entryB->value);
          moveNext(rowB);
        }
      }
    }
  }
  return sum;
}

Matrix diff(Matrix A, Matrix B);

Matrix product(Matrix A, Matrix B);

// Other Matrix Operations
void printMatrix(FILE *out, Matrix A) {
  if (A == NULL) {
    fprintf(stderr,
            "Matrix Error: printMatrix is passed an invalid matrixObj.\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i <= size(A); i++) {
    List rowHandle = A->matrixArray[i];
    if (length(rowHandle) > 0) {
      fprintf(out, "%d: ", i);

      moveFront(rowHandle);
      while (listIndex(rowHandle) != UNDEFINED) {
        Entry cursor = (Entry)get(rowHandle);
        fprintf(out, "(%d, %f) ", cursor->column, cursor->value);
        moveNext(rowHandle);
      }
    }
    fprintf(out, "\n");
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

void rowClone(Matrix M, int rowIndex, List row) {
  if (M == NULL) {
    fprintf(stderr,
            "Matrix Error: listClone is passed an invalid M matrixObj,\n");
    exit(EXIT_FAILURE);
  }
  if (row == NULL) {
    fprintf(stderr,
            "Matrix Error: listClone is passed an invalid row ListObj,\n");
    exit(EXIT_FAILURE);
  }

  moveFront(row);
  while (listIndex(row) != UNDEFINED) {
    Entry currentEntry = (Entry)get(row);
    changeEntry(M, rowIndex, currentEntry->column, currentEntry->value);
    moveNext(row);
  }
}
