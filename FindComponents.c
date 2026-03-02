#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

#define BUFFER_LEN 128

enum componentSM{
  LIST_INIT, LIST_INTAKE, LIST_FINISH;
}

int main(int argc, char* argv[]){
  // Arguement check
  if(argc != 3){
    fprintf(stderr, "\033[31mFindComponents is passed invalid number of arguments."
            "Expected 2 arguements, received only %d\033[0m\n", (argc - 1));
    exit(EXIT_FAILURE);
  }

  FILE *inputFile, *outputFile;
  inputFile = fopen(argv[1], "r");
  outputFile = fopen(argv[2], "w");

  if(inputFile == NULL){
    fprintf(stderr, "\033[31m FindComponents is passed a NULL input file.\033[0m\n");
    exit(EXIT_FAILURE);
  }

  if(outputFile == NULL){
    fprintf(stderr, "\033[31m FindComponents is passed a NULL output file.\033[0m\n");
    exit(EXIT_FAILURE);
  }
 
  char readBuffer[BUFFER_LEN]; // Buffer storing lines being read from the input file.
 
  int graphOrder; // Reads the first line, saves the value as the order we pass when creating a graph object.

  fgets(readBuffer, BUFFER_LEN, inputFile);
  sscanf(readBuffer, "%d", &graphOrder);

  Graph DFS_Graph = newGraph(graphOrder);

  int u, v; 
  while(fgets(readBuffer, BUFFER_LEN, inputFile)){
    sscanf(readBuffer, "%d %d", &u, &v);

    if((u != 0) && (v != 0)){
      addArc(DFS_Graph, u, v);
    }
    else{
      break;
    }

  } 

  // Creates the list of the vertices we want to explore in order.
  List DFS_List = newList();
  for(int i = 1; i <= graphOrder; i++){
    append(DFS_List, i);
  }

  DFS(DFS_Graph, DFS_List);
  Graph tGraph = transposed(DFS_Graph);
  DFS(tGraph, DFS_Lists);

  List SCC_List = newList();

  componentSM state = LIST_INIT:

  moveFront(DFS_Lists);
  while(listIndex(DFS_Lists) != UNDEFINED){
    int vertexCursor = get(DFS_Lists);
    
    if((getFinish(DFS_Lists, vertexVursor) - getDiscover(DFS_Lists, vertexCursor) == 1) && (length(SCC_List) != 0)){
      append(SCC_LIST, NIL);
    }

    append(SCC_LIST, vertexCursor);
    moveNext(DFS_LISTS):
  }

  fprintf(outputFile, "Adjacency Representation of G:\n");
  printGraph(outputFile, DFS_Graph);

  fclose(inputFile);
  fclose(outputFile);

  return 0;
}
