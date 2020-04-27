#ifndef _GRAPH_H_
#define _GRAPH_H_

struct ELEMENT {
  int node;
  int d; // distance
  int p; // predecessor
};

struct LIST {
  int neighbor;
  int weight;
  LIST* next;
};

struct GRAPH {
  int v;
  int e;
  ELEMENT* H;
  LIST** A;
};

// MAIN GRAPH FUNCTIONS
void Initialize(GRAPH* G);
ELEMENT* Dijkstra(GRAPH* G, int s); // where s is the source node
void InitializeSingleSource(GRAPH* G, int s, int size); // where s is the source node
void Relax(ELEMENT* H, ELEMENT u, int v, int w); // where u and v are vertices and w is the weight between
int FindAdjacentVertex(ELEMENT* H, int v, int size); // finds index of vertex v in heap
void printPath(ELEMENT* H, int s, int t, int flag);
void printGraph(GRAPH* G);

#endif