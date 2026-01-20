#include "Graph.h"
#include "List.h"

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
  for(int i = 1; i < (n + 1); i++){
    graphObject->neighbors[i] = newList();
  }

  graphObject->order = n; 

  return graphConstruction;
}
void freeGraph(Graph* pG);

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
