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
void Dijkstra(GRAPH* G, int s); // where s is the source node
void InitializeSingleSource(GRAPH* G, int s); // where s is the source node
void Relax(int u, int v, int w); // where u and v are vertices and w is the weight between
int Weight(int u, int v); // returns weight between vertices u and v
void printGraph(GRAPH* G);

#endif