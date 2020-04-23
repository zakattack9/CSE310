#include <stdio.h>
#include <limits.h>
#include "graph.h"

void Initialize(GRAPH* G) {
  int v = G->v;
  ELEMENT* H = new ELEMENT[v + 1];
  for (int i = 1; i <= v; i++) {
    H[i].node = i;
  }
  G->H = H;
}

void Dijkstra(GRAPH* G, int s) {
  InitializeSingleSource(G, s);
}

void InitializeSingleSource(GRAPH* G, int s) {
  for (int i = 1; i <= G->v; i++) {
    G->H[i].d = INT_MAX;
    G->H[i].p = 0;
  }
  G->H[s].d = 0;
}

void Relax(int u, int v, int w) {
  // if (v.d > u.d ) {
  //   // + weight of u, v
  // }
}

void printGraph(GRAPH* G) {
  int v = G->v;
  int e = G->e;
  printf("%d %d\n", v, e);
  for (int i = 1; i <= v; i++) {
    printf("%d : ", i);
    LIST* A = G->A[i];
    while (A->next != NULL) {
      printf("(%d, %d); ", A->neighbor, A->weight);
      A = A->next;
    }
    printf("(%d, %d)\n", A->neighbor, A->weight);
  }
}