#include "Graph.h"
#include "List.h"
#include <stdlib.h>
#include <stdio.h>

// Private Helper Function Prototype
static void insertAdj(Graph G, int u, int v);
static void Visit(Graph G, int vertex, int *time);

// Data Structure  
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
    exit(EXIT_FAILURE);
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
    newBorn->parent[i] = NIL; 
    newBorn->discover[i] = newBorn->finish[i] = UNDEF; 
  }

  return newBorn;
}

void freeGraph(Graph* pG){

  Graph Handle = *pG;

  if(Handle == NULL){
    fprintf(stderr, "Graph Error: freeGraph was passed a NULL graphObj.\n");
    exit(EXIT_FAILURE);
  }
 
  free(Handle->parent);
  free(Handle->color);
  free(Handle->discover);
  free(Handle->finish);

  for(int i = 1; i <= getOrder(Handle); i++){
    freeList(&Handle->neighbor[i]);
  }

  free(Handle->neighbor);

  free(Handle);

}

//Access Functions
int getOrder(Graph G){
  if(G == NULL){
    fprintf(stderr, "Graph Error: getOrder was passed a Null graphObj.\n");
    exit(EXIT_FAILURE);
  }

  return G->order;
}

int getSize(Graph G){
  if(G == NULL){
    fprintf(stderr, "Graph Error: getSize was passed a Null graphObj.\n");
    exit(EXIT_FAILURE);
  }

  return G->size;
}

int getParent(Graph G, int u){
  if(G == NULL){
    fprintf(stderr, "Graph Error: getParent was passed a Null graphObj.\n");
    exit(EXIT_FAILURE);
  }

  if((u < 1) || (u > getOrder(G))){
    fprintf(stderr, 
            "\033[31mGraph Error: getParent was passed an out of range u value.\n"
            "Parameter Passed: u = %d\n"
            "Pre-requisite : 1 <= u <= %d\033[0m\n", u, getOrder(G));
    exit(EXIT_FAILURE);
  }

  return G->parent[u]; 
}

int getDiscover(Graph G, int u){
if(G == NULL){
    fprintf(stderr, "Graph Error: getDiscover was passed a Null graphObj.\n");
    exit(EXIT_FAILURE);
  }

  if((u < 1) || (u > getOrder(G))){
    fprintf(stderr, 
            "\033[31mGraph Error: getDiscover was passed an out of range u value.\n"
            "Parameter Passed: u = %d\n"
            "Pre-requisite : 1 <= u <= %d\033[0m\n", u, getOrder(G));
    exit(EXIT_FAILURE);
  }

  return G->discover[u];
}
int getFinish(Graph G, int u){
if(G == NULL){
    fprintf(stderr, "Graph Error: getFinish was passed a Null graphObj.\n");
    exit(EXIT_FAILURE);
  }

  if((u < 1) || (u > getOrder(G))){
    fprintf(stderr, 
            "\033[31mGraph Error: getFinish was passed an out of range u value.\n"
            "Parameter Passed: u = %d\n"
            "Pre-requisite : 1 <= u <= %d\033[0m\n", u, getOrder(G));
    exit(EXIT_FAILURE);
  }

  return G->finish[u];

}

//Manipulation Procedures
void addArc(Graph G, int u, int v){

  if(G == NULL){
    fprintf(stderr, "\033[31mGraph Error: addArc was passed a NULL GraphObj.\033[0m\n");
    exit(EXIT_FAILURE);
  }

  if((u < 1) || (u > getOrder(G))){
    fprintf(stderr,
            "\033[31mGraph Error: addArc was passed an out of range u parameter\n"
            "Parameter Passed: u = %d\n"
            "Pre-requisite: 1 <= u <= %d\033[0m\n", u, getOrder(G));
  }

  if((v < 1) || (v > getOrder(G))){
    fprintf(stderr,
            "\033[31mGraph Error: addArc was passed an out of range v parameter\n"
            "Parameter Passed: v = %d\n"
            "Pre-requisite: 1 <= v <= %d\033[0m\n", v, getOrder(G));
  }

  insertAdj(G, u, v);

  G->size++;
}

void addEdge(Graph G, int u, int v){
  if(G == NULL){
    fprintf(stderr, "\033[31mGraph Error: addEdge was passed a NULL GraphObj.\033[0m\n");
    exit(EXIT_FAILURE);
  }

  if((u < 1) || (u > getOrder(G))){
    fprintf(stderr,
            "\033[31mGraph Error: addEdge was passed an out of range u parameter\n"
            "Parameter Passed: u = %d\n"
            "Pre-requisite: 1 <= u <= %d\033[0m\n", u, getOrder(G));
  }

  if((v < 1) || (v > getOrder(G))){
    fprintf(stderr,
            "\033[31mGraph Error: addEdge was passed an out of range v parameter\n"
            "Parameter Passed: v = %d\n"
            "Pre-requisite: 1 <= v <= %d\033[0m\n", v, getOrder(G));
  }

  insertAdj(G, u, v);
  insertAdj(G, v, u);

  G->size++;
}

void DFS(Graph G, List S){

  if(G == NULL){
    fprintf(stderr, "\033[31mGraph Error: DFS was passed a NULL GraphObj.\033[0m\n");
    exit(EXIT_FAILURE);
  }

  if(S == NULL){
    fprintf(stderr, "\033[31mGraph Error: DFS was passed a NULL ListObj.\033[0m\n");
    exit(EXIT_FAILURE);
  }

  if(length(S) != getOrder(G)){
    fprintf(stderr, "\033[31mGraph Error: DFS pre-condition length(S) == n was not met."
            "length(S) = %d while n = %d\033[0m\n", length(S), getOrder(G));
    exit(EXIT_FAILURE);
  }

  int time = 0;

  moveFront(S);
  int targetVertex;
  while(listIndex(S) != UNDEFINED){
    targetVertex = get(S);
    if(G->color[targetVertex] == WHITE){
      Visit(G, targetVertex, &time);
    }
    else{
      moveNext(G);
    }
  }


}

//Other Operations
Graph transpose(Graph G);
Graph copyGraph(Graph G);

void printGraph(FILE* out, Graph G){

  if(G == NULL){
    fprintf(stderr, "\033[31mGraph Error: printGraph was passed a NULL GraphObj.\033[0m\n");
    exit(EXIT_FAILURE);
  }

  if(out == NULL){
    fprintf(stderr, "\033[31mGraph Error: printGraph was passed a NULL FILE.\033[0m\n");
    exit(EXIT_FAILURE);
  }

  for(int i = 1; i <= getOrder(G); i++){
    fprintf(out, "%d: ", i);
    printList(out, G->neighbor[i]);
    fprintf(out, "\n");
  }

}

//Private helper function definition: 
static void insertAdj(Graph G, int u, int v){
  List Handle = G->neighbor[u];

  if(length(Handle) == 0){
    append(Handle, v);
  }
  else{
    moveFront(Handle);
    while(listIndex(Handle) != UNDEFINED){
      if(v <= get(Handle)){
        insertBefore(Handle, v);
        break;
      }
      else{
        if(listIndex(Handle) == length(Handle) - 1){
          if(v >= get(Handle)){
            insertAfter(Handle, v);
          }
          else{
            insertBefore(Handle, v);
          }
          break;
        }
        moveNext(Handle);
      }
    }
  }
}

static void Visit(Graph G, int vertex, int *time){
  *time++; // Increments the timer each function call.

  if(G->color[vertex] == WHITE){
    G->color[vertex] = GREY;
    G->discover = *time;

    List adjHandle = G->neighbor[vertex];
    moveFront(adjHandle);
    while(listIndex(adjHandle) != UNDEFINED){
      int nextNeighbor = get(adjHandle);
      Visit(G, nextNeighbor, time);
    }

    G->color[vertex] = BLACK;
    G->finish[vertex] = *time;

  }

}
