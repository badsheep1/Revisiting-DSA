#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

#define BUFFER_LEN 128

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
  Graph tGraph = transpose(DFS_Graph);
  DFS(tGraph, DFS_List);

  int nSCC = 0;

  List *listArray = malloc(sizeof(List));
  listArray[0] = NULL;

  List arrayHandle = NULL;
  moveFront(DFS_List);
  while(listIndex(DFS_List) != UNDEFINED){
    int targetVertex = get(DFS_List);
    if(getParent(tGraph, targetVertex) == NIL){
      nSCC++;
      listArray = realloc(listArray, (nSCC + 1) * sizeof(List));
      listArray[nSCC] = newList();
      arrayHandle = listArray[nSCC];
    }
    append(arrayHandle, targetVertex); 
    moveNext(DFS_List);
  }

  fprintf(outputFile, "Adjacency Representation of G:\n");
  printGraph(outputFile, DFS_Graph);
  fprintf(outputFile, "\nG contains %d strongly connected components:\n", nSCC);

  for(int i = 1; i <= nSCC; i++){
    fprintf(outputFile, "Component %d: ", i);
    printList(outputFile,listArray[i]);
    fprintf(outputFile, "\n");
  }



  fclose(inputFile);
  fclose(outputFile);

  return 0;
}
