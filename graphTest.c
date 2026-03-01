#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int main(void){

  Graph testGraph = newGraph(8);

  // Graph Test provided in the instructions.
  addArc(testGraph, 1, 2); 
  addArc(testGraph, 2, 5); 
  addArc(testGraph, 2, 6);
  addArc(testGraph, 5, 1);
  addArc(testGraph, 5, 6);

  addArc(testGraph, 6, 7);
  addArc(testGraph, 7, 6);
  addArc(testGraph, 7, 8);
  addArc(testGraph, 8, 8);

  addArc(testGraph, 2, 3);
  addArc(testGraph, 3, 4);
  addArc(testGraph, 4, 3);
  addArc(testGraph, 3, 7);
  addArc(testGraph, 4, 8);

  FILE* outputFile = fopen("printTest.txt", "w");
  FILE* outputFile2 = fopen("printTest2.txt", "w");


  List el = newList();
  for(int i = 1; i <= 8; i++){
    append(el, i);
  }

  List le = copyList(el);

  DFS(testGraph, el);

  Graph clone = copyGraph(testGraph);

  assert(getOrder(testGraph) == getOrder(clone));

  DFS(clone, le);

  for(int i = 1; i <= getOrder(testGraph); i++){
    assert(getParent(testGraph, i) == getParent(clone, i));
    assert(getDiscover(testGraph, i) == getDiscover(clone, i));
    assert(getFinish(testGraph, i) == getFinish(clone, i));
  }

  assert(getSize(testGraph) == getSize(clone));

  Graph transGraph = transpose(testGraph);

  printGraph(outputFile, testGraph);
  printGraph(outputFile2, transGraph); 

  assert(getOrder(testGraph) == getOrder(testGraph));
  assert(getSize(testGraph) == getSize(transGraph));

  freeGraph(&testGraph);
  freeGraph(&clone);
  freeGraph(&transGraph);

  freeList(&el);
  freeList(&le);

  

  return 0;
}
