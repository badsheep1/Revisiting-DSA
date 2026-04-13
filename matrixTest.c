#include "Matrix.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Matrix testMatrix = newMatrix(3);

  assert(size(testMatrix) == 3);
  assert(NZZ(testMatrix) == 0);

  freeMatrix(&testMatrix);

  return 0;
}
