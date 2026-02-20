#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 128

int main(int argc, char* argv[]){

  FILE* inputFile = fopen(argv[1], "r");
  FILE* outputFile = fopen(argv[2], "w");

  char buffer[BUFFER_SIZE];

  fgets(buffer, BUFFER_SIZE, inputFile);

  int vertexA, vertexB;
  while(fgets(buffer, BUFFER_SIZE, inputFile)){
    sscanf(buffer, "%d %d", &vertexA, &vertexB);
    fprintf(outputFile, "%d %d\n", vertexA, vertexB);
  }

  fclose(inputFile);
  fclose(outputFile);

  return 0;
}
