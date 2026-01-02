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
  char** stringArray = NULL;

  while(fgets(stringBuffer, MAX_LENGTH, inputFile) != NULL){

    n++; //Incrementing the n counter.
    
    char** tempArray = realloc(stringArray, n * sizeof(char*));

    if(tempArray == NULL){
      fprintf(stderr, "Error: memory reallocation failed. \n");
      exit(EXIT_FAILURE);
    }

    stringArray = tempArray;


    stringArray[n - 1] = malloc(strlen(stringBuffer) + 1);
    strcpy(stringArray[n - 1], stringBuffer);
  }

  List hand = newList();

  for(int i = 0; i < n; i++){
    
    if(length(hand) == 0){
      append(hand, i);
      continue;
    } 
    else{
      moveFront(hand);
    }

    while(length(hand) < (i + 1)){
      if(strcmp(stringArray[i], stringArray[get(hand)]) > 0){
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
    
  }

  moveFront(hand);

  while(listIndex(hand) != UNDEFINED){
    fputs(stringArray[get(hand)], outputFile);
    moveNext(hand);
  }

  fclose(inputFile);
  fclose(outputFile);

  free(stringBuffer);
  freeList(&hand);

  for(int i = 0; i < n; i++){
    free(stringArray[i]);
  }

  free(stringArray);

  return 0;
}
