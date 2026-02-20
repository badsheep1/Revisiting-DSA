#include "Graph.h" 
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

typedef enum{
  GRAPH_EXPAND,
  GRAPH_QUERY
}State;

int main(int argc, char *argv[]){

  if(argc != 3){
    fprintf(stderr, "Error: arguement mismatch.\n" 
            "Usage: %s <input-file> <output-file> ", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE* inputFile = fopen(argv[1], "r");
  FILE* outputFile = fopen(argv[2], "w");

  char inputBuffer[BUFFER_SIZE];

  fgets(inputBuffer, BUFFER_SIZE, inputFile);

  int graphOrder;
  sscanf(inputBuffer, "%d", &graphOrder); // Reads the first line of the input, saves the value as the Order of the graph.
 
  Graph pathGraph = newGraph(graphOrder);
 
  int vertexA, vertexB; 

  State phase = GRAPH_EXPAND;

  List path = newList();

  while(fgets(inputBuffer, BUFFER_SIZE, inputFile)){
    sscanf(inputBuffer, "%d %d", &vertexA, &vertexB);
    printGraph(outputFile, pathGraph);

    switch(phase){
      case GRAPH_EXPAND:
        if((vertexA == 0) || (vertexB == 0)){
          phase = GRAPH_QUERY;
          printGraph(outputFile, pathGraph);
        }
        else{
          addEdge(pathGraph, vertexA, vertexB);
        }
        break;
      case GRAPH_QUERY: 
        if((vertexA == 0) || (vertexB == 0)){
          continue;
        }
        else{
          BFS(pathGraph, vertexA);
          getPath(path, pathGraph, vertexB);
          fprintf(outputFile, "The distance from %d to %d is ", vertexA, vertexB);

          moveFront(path);
          if(get(path) == INF){
            fprintf(outputFile, "infinity\nNo %d-%d path exists\n", vertexA, vertexB);
          }
          else{
            fprintf(outputFile, "%d\nA shortest %d-%d path is: ",(length(path) - 1), vertexA, vertexB);
            printList(outputFile, path);
            fprintf(outputFile, "\n");
          }
        }
        break;
    }
  } 

  freeGraph(&pathGraph);

  return 0;
}
