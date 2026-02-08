#include "Graph.h"
#include <stdio.h>


int main(void){
  Graph graph1 = newGraph(1);

  freeGraph(&graph1);

  Graph graph2 = newGraph(3);

  addEdge(graph2, 1, 2);

  addEdge(graph2, 1, 3);


  FILE* outFile;

  Graph graph3 = newGraph(6);

  addEdge(graph3, 1, 2);

  addEdge(graph3, 1, 3);

  addEdge(graph3, 3, 4);

  addEdge(graph3, 2, 4);

  addEdge(graph3, 2, 5);

  addEdge(graph3, 2, 6);

  addEdge(graph3, 4, 5);

  addEdge(graph3, 5, 6);

  outFile = fopen("printGraphTest.txt", "w");

  printGraph(outFile, graph3);

  return 0;
}
