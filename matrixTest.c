#include "Matrix.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Matrix testMatrix = newMatrix(3);

  assert(size(testMatrix) == 3);
  assert(NZZ(testMatrix) == 0);

  changeEntry(testMatrix, 1, 1, 2.5);

  changeEntry(testMatrix, 1, 3, 5.1);

  changeEntry(testMatrix, 2, 3, 63.92);

  printMatrix(stdout, testMatrix);

  changeEntry(testMatrix, 2, 1, 3);

  printMatrix(stdout, testMatrix);

  assert(NZZ(testMatrix) == 4);

  changeEntry(testMatrix, 1, 1, 3.326);

  assert(NZZ(testMatrix) == 4);

  printMatrix(stdout, testMatrix);

  changeEntry(testMatrix, 1, 2, 0);

  assert(NZZ(testMatrix) == 4);

  changeEntry(testMatrix, 1, 3, 0);

  assert(NZZ(testMatrix) == 3);

  freeMatrix(&testMatrix);

  return 0;
}
