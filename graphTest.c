#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int main(void){

  Graph testGraph = newGraph(5);

  addEdge(testGraph, 1, 2);
  addEdge(testGraph, 2, 4);
  addEdge(testGraph, 1, 3);
  addEdge(testGraph, 5, 4);

  FILE* outputFile = fopen("printTest.txt", "w");

  printGraph(outputFile, testGraph);

  freeGraph(&testGraph);

  return 0;
}
