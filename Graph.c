#include "Graph.h"
#include "List.h"
#include <stdlib.h>
#include <stdio.h>

// Private Helper Function Prototype:

// Constructors-Destructors:
Graph newGraph(int n);
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
