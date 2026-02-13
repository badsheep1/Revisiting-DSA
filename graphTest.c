#include "Graph.h"
#include <stdio.h>
#include <assert.h>


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

  assert(getOrder(graph3) == 6);

  outFile = fopen("printGraphTest.txt", "w");

  printGraph(outFile, graph3);

  BFS(graph3, 1);

  assert(getSource(graph3) == 1);

  assert(getDist(graph3, 1) == 0);

  assert(getDist(graph3, 2) == 1);

  assert(getDist(graph3, 3) == 1);

  assert(getDist(graph3, 4) == 2);

  assert(getDist(graph3, 5) == 2);

  assert(getDist(graph3, 6) == 2);

  assert(getParent(graph3, 1) == NIL);

  assert(getParent(graph3, 2) == 1);

  assert(getParent(graph3, 3) == 1);
  
  assert(getParent(graph3, 4) == 2);

  assert(getParent(graph3, 5) == 2);

  assert(getParent(graph3, 6) == 2);

  List path1 = newList();

  getPath(path1, graph3, 3);

  assert(length(path1) == 2);

  moveFront(path1);

  assert(get(path1) == 1);

  moveNext(path1);

  assert(get(path1) == 3);
  return 0;
}
