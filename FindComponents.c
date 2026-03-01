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
 
  char readBuffer[BUFFER_LEN];

  int graphOrder;

  fgets(readBuffer, BUFFER_LEN, inputFile);

  sscanf(readBuffer, "%d", &graphOrder);

  printf("%d", graphOrder);

  // while(fgets(readBuffer, BUFFER_LEN, inputFile)){
  //
  // }


  fclose(inputFile);
  fclose(outputFile);

  return 0;
}
