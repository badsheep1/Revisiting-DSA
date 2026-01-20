#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
// Data Structure 
typedef struct GraphObj{
  List* neighbors;
  int* colors;
  int* parents;
  int* distance;
  int order;
  int size;
  int recent;
}GraphObj;

// Constructors-Destructors

Graph newGraph(int n){

  // Initializing graphObj datatype.
  Graph graphObject = malloc(sizeof(struct GraphObj));

  // Initializing the fields of the object.
  graphObject->colors = malloc((n + 1) * sizeof(int));
  graphObject->parents = malloc((n + 1) * sizeof(int));
  graphObject->distance = malloc((n + 1) * sizeof(int));

  graphObject->neighbors = malloc((n + 1) * sizeof(List));

  //Initializing the 0th index for fields, despite not using them, to prevent unusual behavior if accidentally accessing them.
  graphObject->colors[0] = graphObject->parents[0] = NIL;
  graphObject->distance[0] = INF;
  graphObject->neighbors[0] = NULL;
  // Initializing all neighbors array elements with ListObj
  for(int i = 1; i < (n + 2); i++){
    graphObject->neighbors[i] = newList();
  }

  graphObject->order = n; // Setting the order, the number of vertices equal to n.

  // size and recent ought to be determined later with manipulation functions are initialized as NIl.
  graphObject->size = NIL;
  graphObject->recent = NIL;

  return graphObject;
}
void freeGraph(Graph* pG){
  Graph handle = *pG;

  // Freeing the memory allocated to these arrays.
  free(handle->colors);
  free(handle->parents);
  free(handle->distance);

  // Freeing the List elements in the List Array.
  for(int i = 1; i < (getSize(handle) + 2); i++){
    freeList(&handle->neighbors[i]);
  }
  // Freeing the GraphObj itself.
  free(handle); 
}

//Access Functions
int getOrder(Graph G);
int getSize(Graph G);
int getSource(Graph G);
int getParent(Graph G, int u);
int getDist(Graph G, int u);
void getPath(List L, Graph G, int u);

//Manipulation Procedures
void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);

//Other Operations
void printGraph(FILE* out, Graph G);
