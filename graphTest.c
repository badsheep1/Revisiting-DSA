#include "Graph.h"


int main(void){
  Graph graph1 = newGraph(5);

  freeGraph(&graph1);

  return 0;
}
