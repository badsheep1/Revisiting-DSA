#include "Graph.h"
#include "List.h"
#include <stdlib.h>
#include <stdio.h>

// Private Helper Function Prototype:
typedef struct GraphObj{
  List *neighbor;
  int *parent;
  int *color;
  int *discover;
  int *finish;
  int order;
  int size;
}GraphObj;
// Constructors-Destructors:

Graph newGraph(int n){
  if(n < 1){
    fprintf(stderr, "Graph Error: newGraph is passed an invalid n parameter.\n");
    exit(EXIT_FAILURE):
  }

  Graph newBorn = malloc(sizeof(GraphObj));
  newBorn->order = n;
  newBorn->size = NIL;

  //allocating memory for these arrays.
  newBorn->neighbor = malloc((n + 1) * sizeof(List));
  newBorn->parent = malloc((n + 1) * sizeof(int));
  newBorn->color = malloc((n + 1) * sizeof(int));
  newBorn->discover = malloc((n + 1) * sizeof(int));
  newBorn->finish = malloc((n + 1) * sizeof(int));

  //setting zero index to some invalid value, will not be accessing these indices.
  newBorn->neighbor[0] = NULL;
  newBorn->parent[0] = newBorn->discover[0] = newBorn->finish[0] = newBorn->color[0] = NIL; 
  
  for(int i = 1; i <= n; i++){
    newBorn->neighbor[i] = newList();
    newBorn->color[i] = WHITE;
    newBorn->parent[0] = newBorn->discover[0] = newBorn->finish[0] = NIL; 
  }
}
void freeGraph(Graph* pG);

//Access Functions
int getOrder(Graph G);
int getSize(Graph G);
int getParent(Graph G, int u);
int getDiscover(Graph G, int u);
int getFinish(Graph G, int u);

//Manipulation Procedures
void addArc(Graph G, int u, int v);
void addEdge(Graph G, int u, int v);
void DFS(Graph G, List S);

//Other Operations
Graph transpose(Graph G);
Graph copyGraph(Graph G);
void printGraph(FILE* out, Graph G);
