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

  printMatrix(stdout, testMatrix);

  changeEntry(testMatrix, 1, 3, 7.33);

  changeEntry(testMatrix, 1, 2, 9.0392);

  changeEntry(testMatrix, 2, 2, 1131.3);

  changeEntry(testMatrix, 3, 3, 3);

  changeEntry(testMatrix, 3, 2, 3);

  changeEntry(testMatrix, 3, 1, 3);

  printMatrix(stdout, testMatrix);

  assert(NZZ(testMatrix) == 9);

  makeZero(testMatrix);

  assert(NZZ(testMatrix) == 0);

  printMatrix(stdout, testMatrix);

  changeEntry(testMatrix, 1, 1, 1);
  changeEntry(testMatrix, 1, 2, 1);
  changeEntry(testMatrix, 1, 3, 1);

  changeEntry(testMatrix, 2, 1, 77);

  changeEntry(testMatrix, 2, 3, 1223);

  changeEntry(testMatrix, 3, 2, 83.2);

  Matrix clone = copy(testMatrix);

  printf("testMatrix: \n");

  printMatrix(stdout, testMatrix);

  printf("\nCopy:\n");

  printMatrix(stdout, clone);

  assert(NZZ(testMatrix) == NZZ(clone));

  Matrix trans = transpose(testMatrix);

  assert(NZZ(testMatrix) == NZZ(trans));

  printf("\nTransposed Matrix: \n");

  printMatrix(stdout, trans);

  freeMatrix(&testMatrix);

  freeMatrix(&clone);

  freeMatrix(&trans);

  Matrix baseMatrix = newMatrix(5);

  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      changeEntry(baseMatrix, i, j, i + j);
    }
  }

  Matrix scaled = scalarMult(2, baseMatrix);

  printf("Scalar Multiplication Test: \nBase Matrix:\n");

  printMatrix(stdout, baseMatrix);

  printf("\nScaled Matrix\n");

  printMatrix(stdout, scaled);

  Matrix A = newMatrix(3);
  Matrix B = newMatrix(3);

  printf("\nMatrix Summation: \n");

  changeEntry(A, 1, 1, 1);
  changeEntry(A, 1, 2, 2.51);
  changeEntry(A, 2, 2, 1231);
  changeEntry(A, 3, 1, 184.3);
  changeEntry(A, 3, 3, 67);

  printf("Matrix A:\n");

  printMatrix(stdout, A);

  changeEntry(B, 1, 1, 2);
  changeEntry(B, 1, 2, 0.32);
  changeEntry(B, 3, 1, 2);
  changeEntry(B, 2, 1, 1);

  printf("Matrix B:\n");

  printMatrix(stdout, B);

  printf("Summed Matrix:\n");

  Matrix summed = sum(A, B);

  printMatrix(stdout, summed);

  Matrix minuend = newMatrix(3);
  Matrix subtrahend = newMatrix(3);

  changeEntry(minuend, 1, 1, 231);
  changeEntry(minuend, 1, 2, 974);
  changeEntry(minuend, 3, 2, 32.53);

  changeEntry(minuend, 1, 3, 104.342);
  changeEntry(minuend, 2, 1, 88765);
  changeEntry(minuend, 3, 3, 213);

  changeEntry(subtrahend, 1, 1, 102);
  changeEntry(subtrahend, 1, 2, 111.2);
  changeEntry(subtrahend, 1, 3, 32.53);

  changeEntry(subtrahend, 1, 3, -104.342);
  changeEntry(subtrahend, 3, 1, 6.43);
  changeEntry(subtrahend, 3, 3, 213);

  printf("\nMinuend:\n");
  printMatrix(stdout, minuend);

  printf("\nSubtrahend\n");
  printMatrix(stdout, subtrahend);

  Matrix dif = diff(minuend, subtrahend);
  printf("\nDifference\n");
  printMatrix(stdout, dif);

  return 0;
}
