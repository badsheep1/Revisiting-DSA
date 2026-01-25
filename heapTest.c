#include "List.h"
#include <stdlib.h>


int main(void){

  int n = 5;

  List *listArray = malloc((n + 1) * sizeof(List));
  listArray[0] = NULL;

  for (int i = 1; i <= n; i++){
    listArray[i] = newList();
  }

  for (int i = 1; i<= n; i++){
    freeList(&listArray[i]);
  }

  free(listArray);
  listArray = NULL;

  return 0;
}
