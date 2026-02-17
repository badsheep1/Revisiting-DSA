#include "Graph.h" 
#include <stdio.h>

#define HEADER_LEN 1
#define TOKEN_LEN 2
#define EOF -1

int main(int argc, char *argv[]){

  if(argc != 3){
    fprintf(stderr, "Error: arguement mismatch.\n" 
            "Usage: %s <input-file> <output-file> ", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE* inputFile = fopen(argv[1], "r");
  FILE* outputFile = fopen(argv[2], "w");

  char inputBuffer[HEADER_LEN];

  fgets(inputBuffer, TOKEN_LEN, inputFile);

  int graphOrder;
  sscanf(inputBuffer, "%d", &graphOrder); // Reads the first line of the input, saves the value as the Order of the graph.
 
  Graph pathGraph = newGraph(graphOrder);
 
  int vertex1, vertex2; 
  while(fgets(inputBuffer, HEADER_LEN, inputFile)){
    sscanf(inputBuffer, "%d, %d", &vertex1, &vertex2);

    if(vertex1 && vertex2 == 0){
      break; // Input File Terminates
    } 
    else{
      addEdge(pathGraph, vertex1, vertex2); 
    }
  }
  

  freeGraph(&pathGraph);

  return 0;
}
