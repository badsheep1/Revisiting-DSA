#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  char* stringBuffer = malloc(MAX_LENGTH * sizeof(char));
  char** stringArray = malloc(sizeof(char*));

  while(fgets(stringBuffer, MAX_LENGTH, inputFile) != NULL){
    if(n != 0) {
      char** tempArray = realloc(stringArray, (n + 1) * sizeof(char*));

      if(tempArray == NULL){
        fprintf(stderr, "Error: memory reallocation failed. \n");
        exit(EXIT_FAILURE);
      }

      stringArray = tempArray;
    }

    stringArray[n] = malloc(strlen(stringBuffer) + 1);
    strcpy(stringArray[n], stringBuffer);
    n++; 
  }

  List hand = newList();

  for(int i = 0; i < n; i++){
    
    if(length(hand) == 0){
      append(hand, i);
    } 
    else{
      moveFront(hand);

    }

    if(strcmp(stringArray[i],get(hand)) > 0){
      if(listIndex(hand) == length(hand) - 1){
        insertAfter(hand, i);
      }
      else{
        moveNext(hand);
      }
    }
    else{
      insertBefore(hand, i);
    }

  }





  for(int i = 0; i < n; i++){
    fputs(stringArray[i], outputFile);
    fputc('\n', outputFile);
  }

  fclose(inputFile);
  fclose(outputFile);


  return 0;
}
