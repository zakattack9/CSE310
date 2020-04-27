#include <stdio.h>
#include <limits.h>
#include <string>
#include "graph.h"
#include "heap.h"

using namespace std;

void Initialize(GRAPH* G) {
  int v = G->v;
  G->H = new ELEMENT[v + 1];
  for (int i = 1; i <= v; i++) {
    G->H[i].node = i;
  }
}

ELEMENT* Dijkstra(GRAPH* G, int s) {
  int size = G->v;
  InitializeSingleSource(G, s, size);
  printf("INITIALIZED SINGLE SOURCE\n");
  ELEMENT* S = new ELEMENT[G->v + 1];
  while (size != 0) {
    ELEMENT u = DeleteMin(G->H, &size);
    printf("EXTRACTED NODE %d\n", u.node);
    S[u.node] = u;
    LIST* uAdj = G->A[u.node]; // adjacency linked list for vertex u
    do {
      int vIndex = FindAdjacentVertex(G->H, uAdj->neighbor, size);
      printf("INDEX OF V: %d", vIndex);
      // Relax(G->H, u, vIndex, uAdj->weight);
      // printf("RELAXED NODES %d %d\n", u.node, G->H[vIndex].node);
      uAdj = uAdj->next;
    } while (uAdj->next != NULL);
  }
  printf("FINISHED DIJKSTRAS\n");
  return S;
}

void InitializeSingleSource(GRAPH* G, int s, int size) {
  for (int i = 1; i <= G->v; i++) {
    G->H[i].d = INT_MAX;
    G->H[i].p = 0;
  }
  G->H[s].d = 0;
  BuildHeap(G->H, size);
}

void Relax(ELEMENT* H, ELEMENT u, int v, int w) {
  if (H[v].d > u.d + w) {
    H[v].d = u.d + w;
    H[v].p = u.node;
    DecreaseKey(H, v);
  }
}

int FindAdjacentVertex(ELEMENT* H, int v, int size) {
  for (int i = 1; i <= size; i++) {
    if (H[i].node == v) {
      return i;
    }
  }
  return 0;
}

void printPath(ELEMENT* H, int s, int t, int flag) {
  if (flag == 1) {
    int length = H[t].d;
    printf("LENGTH: %d", length);
  } else if (flag == 0) {
    string path = "";
    ELEMENT node = H[t];
    while (node.d != 0) {
      string nodeStr = ", " + to_string(node.node);
      path.insert(0, nodeStr);
      node = H[node.p];
    }
    // path.insert(0, to_string(node.node));
    printf("%d%s\n", node.node, path.c_str());
  }
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