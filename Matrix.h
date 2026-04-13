#include "List.h"
typedef struct matrixObj *Matrix;

// Constructor and Deconstructor
Matrix newMatrix(int n);

void freeMatrix(Matrix *M);

// Access Functions
int size(Matrix M);

int NZZ(Matrix M);

int equals(Matrix A, Matrix B);

// Manipulation Procedures
void makeZero(Matrix M);

void changeEntry(Matrix M, int i, int j, double x);

// Matrix Arithmetic Operations
Matrix copy(Matrix A);

Matrix transpose(Matrix A);

Matrix scalarMult(double x, Matrix A);

Matrix sum(Matrix A, Matrix B);

Matrix diff(Matrix A, Matrix B);

Matrix product(Matrix A, Matrix B);

// Other Functions
void printMatrix(FILE *out, Matrix A);
