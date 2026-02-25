#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int main(void){

  Graph testGraph = newGraph(5);

  getParent(testGraph, 6);

  freeGraph(&testGraph);

  return 0;
}
