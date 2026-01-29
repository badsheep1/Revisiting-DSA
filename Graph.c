#include "Graph.h"
#include "List.h"
#include <stdlib.h>
#include <stdio.h>

// Private Helper Function Prototype:

// Helper function for inserting a vertex's label in an adjacent list, sorted chronologically.
static void adjInsert(List L, int label);


// Data Structure 
typedef struct GraphObj{
  List* neighbors;
  int* colors;
  int* parents;
  int* distance;
  int order;
  int size;
  int source;
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

  //Initializing the 0th listIndex for fields, despite not using them, to prevent unusual behavior if accidentally accessing them.
  graphObject->colors[0] = graphObject->parents[0] = NIL;
  graphObject->distance[0] = INF;
  graphObject->neighbors[0] = NULL;
  // Initializing all neighbors array elements with ListObj
  for(int i = 1; i <= n; i++){
    graphObject->neighbors[i] = newList();
  }

  graphObject->order = n; // Setting the order, the number of vertices equal to n.

  // size and source ought to be determined later with manipulation functions are initialized as NIl.
  graphObject->size = NIL;
  graphObject->source = NIL;

  return graphObject;
}
void freeGraph(Graph* pG){
  Graph handle = *pG;

  // Freeing the memory allocated to these arrays.
  free(handle->colors);
  free(handle->parents);
  free(handle->distance);

  // Freeing the List elements in the List Array.
  for(int i = 1; i <= getOrder(handle); i++){
    freeList(&(handle->neighbors[i]));
    handle->neighbors[i] = NULL;
  }
  // Freeing the array of Lists pointer
  free(handle->neighbors);
  free(handle);
  *pG = NULL;
  }
 
//Access Functions
int getOrder(Graph G){
  if(G == NULL){
    fprintf(stderr, "Graph Error: getOrder is passed null GraphObj.\n");
    exit(EXIT_FAILURE);
  }

  return G->order;
}
int getSize(Graph G){
  if(G == NULL){
    fprintf(stderr, "Graph Error: getSize is passed null GraphObj.\n");
    exit(EXIT_FAILURE);
  }

  return G->size;
}

int getSource(Graph G){
  if(G == NULL){
    fprintf(stderr, "Graph Error: getSource is passed a null GraphObj.\n");
    exit(EXIT_FAILURE);
  }

  return G->source;
}


int getParent(Graph G, int u){
if(G == NULL){
    fprintf(stderr, "Graph Error: getParent is passed null GraphObj.\n");
  }
if(u <= 0 || u > getOrder(G)){
    fprintf(stderr, "Graph Error: getParent is passed an listIndex out of range.\n");
    exit(EXIT_FAILURE);
  }
return G->parents[u];

}
int getDist(Graph G, int u){
if(G == NULL){
    fprintf(stderr, "Graph Error: getDist is passed null GraphObj.\n");
  }
if(u <= 0 || u > getOrder(G)){
    fprintf(stderr, "Graph Error: getDist is passed an listIndex out of range.\n");
    exit(EXIT_FAILURE);
  }
  return G->distance[u];
}
void getPath(List L, Graph G, int u);

//Manipulation Procedures
void makeNull(Graph G);
void addEdge(Graph G, int u, int v){
  if(G == NULL){
    fprintf(stderr, "Graph Error: addEdge is passed a null GraphObj.\n");
    exit(EXIT_FAILURE);
  }

  if( u < 1 || u > getOrder(G)){
    fprintf(stderr, "Graph Error: addEdge is passed an out of range u parameter.\n");
    exit(EXIT_FAILURE);
  }

  if( v < 1 || v > getOrder(G)){
    fprintf(stderr, "Graph Error: addEdge is passed an out of range v parameter.\n");
    exit(EXIT_FAILURE);
  }

  List uNeighbors = G->neighbors[u];
  List vNeighbors = G->neighbors[v];

  adjInsert(uNeighbors, v);
  adjInsert(vNeighbors, u);
}
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);

//Other Operations
void printGraph(FILE* out, Graph G);

//Private Helper Function

static void adjInsert(List L, int label){
  
  if(length(L) == 0){
    append(L, label);
  }
  else{
    moveFront(L);
    while(listIndex(L) != UNDEFINED){
      if(listIndex(L) == length(L) - 1){
        if(get(L) > label){
          insertBefore(L, label);
        }
        else{
          insertAfter(L, label);
        }
      }
      
      if(get(L) < label){
        moveNext(L);
      }
      else{
        insertBefore(L, label);
      }
    }
  }
}
