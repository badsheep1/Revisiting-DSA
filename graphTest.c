#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int main(void){

  Graph testGraph = newGraph(5);

  addArc(testGraph, 1, 2);
  addArc(testGraph, 2, 4);
  addArc(testGraph, 1, 3);
  addArc(testGraph, 5, 4);

  FILE* outputFile = fopen("printTest.txt", "w");

  printGraph(outputFile, testGraph);

  freeGraph(&testGraph);

  return 0;
}
