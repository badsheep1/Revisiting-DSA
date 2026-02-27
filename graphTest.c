#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int main(void){

  Graph testGraph = newGraph(8);

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

  //FILE* outputFile = fopen("printTest.txt", "w");


  List el = newList();
  for(int i = 1; i <= 8; i++){
    append(el, i);
  }

  DFS(testGraph, el);

  //printGraph(outputFile, testGraph);
  
  for(int i = 1; i <= 8; i++){
    printf("%d:\t%d\t%d\n", i, getDiscover(testGraph, i), getFinish(testGraph, i));
  }

  freeGraph(&testGraph);

  return 0;
}
