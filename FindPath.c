#include "Graph.h" 
#include <stdio.h>



int main(int argc, char *argv[]){

  if(argc != 3){
    fprintf(stderr, "Error: arguement mismatch.\n" 
            "Usage: %s <input-file> <output-file> ", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE* inputFile = fopen(argv[1], "r");
  FILE* outputFile = fopen(argv[2], "w");


  

  return 0;
}
