#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Matrix testMatrix = newMatrix(3);

  freeMatrix(&testMatrix);

  return 0;
}
