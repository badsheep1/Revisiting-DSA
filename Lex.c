#include <stdio.h>
#include <stdlib.h>
#include "List.h"

#define MAX_LENGTH 1000

int main(int argc, char *argv[]){
  
  if(argc != 3){
    fprintf(stderr, "Error: arguement mismatch.\n"
            "Usage: %s <input-file> <output-file> ", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE* inputFile = fopen(argv[1], "r");
  FILE* outputFile = fopen(argv[2], "w");

  int n = 0;
  char * stringBuffer = malloc(MAX_LENGTH * sizeof(char));

  while(fgets(stringBuffer, MAX_LENGTH, inputFile) != NULL){
    
  }




  return 0;
}
