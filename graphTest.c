#include "Graph.h"
#include <stdio.h>


int main(void){
  Graph graph1 = newGraph(1);

  freeGraph(&graph1);

  Graph graph2 = newGraph(3);

  addEdge(graph2, 1, 2);

  FILE* outFile;

  outFile = fopen("printGraphTest.txt", "a");

  printGraph(outFile, graph2);

   


  return 0;
}
