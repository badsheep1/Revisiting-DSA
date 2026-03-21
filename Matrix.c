#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"

typedef struct matrixObj{
  List* matrixArray;
  int size;
  int nnz;
}matrixObj;

Matrix newMatrix(int n){
  Matrix child = malloc(sizeof(matrixObj));
  child->size = n;
  child->nnz = 0;

  child->matrixArray = malloc(n * sizeof(List));

  for(int i = 0; i < n; i++){
    child->matrixArray[i] = newList();
  }

  return child;
}

void freeMatrix(Matrix* pM){
  for(int i = 0; i < size(*pM); i++){
    freeList(&((*pM)->matrixArray[i]));
  }

  free(pM);
  *pM = NULL;
}

int size(Matrix M){
  if(M == NULL){
    fprintf(stderr, "Matrix Error: size() is passed a Null MatrixObj.\n");
    exit(EXIT_FAILURE);
  }

  return M->size;
}

int NNZ(Matrix M){
  if(M == NULL){
    fprintf(stderr, "Matrix Error: NZZ() is passed a Null MatrixObj.\n");
    exit(EXIT_FAILURE);
  }

  return M->nnz;
}
