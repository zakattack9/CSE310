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
  ELEMENT* S = new ELEMENT[G->v + 1];
  while (size >= 1) {
    ELEMENT u = DeleteMin(G->H, &size);
    S[u.node] = u;
    LIST* uAdj = G->A[u.node]; // adjacency linked list for vertex u
    if (uAdj == NULL) continue; // handles node without neighbors
    do {
      int vIndex = FindAdjacentVertex(G->H, uAdj->neighbor, size);
      Relax(G->H, u, vIndex, uAdj->weight);
      uAdj = uAdj->next;
    } while (uAdj != NULL);
  }
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
  if (v == 0) return;
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
  if (H[t].d == INT_MAX || H[t].d < 0) {
    printf("Error: node %d not reachable from node %d\n", t, s);
  } else if (flag == 1) {
    int length = H[t].d;
    printf("LENGTH: %d\n", length);
  } else if (flag == 0) {
    string path = "";
    ELEMENT node;
    for (node = H[t]; node.d != 0; node = H[node.p]) {
      string nodeStr = ", " + to_string(node.node);
      path.insert(0, nodeStr); // prepends to start of string
    }
    printf("PATH: %d%s\n", node.node, path.c_str());
  }
}

void printGraph(GRAPH* G) {
  int v = G->v;
  int e = G->e;
  printf("%d %d\n", v, e);
  for (int i = 1; i <= v; i++) {
    printf("%d : ", i);
    if (G->A[i] == NULL) { // handles node without neighbors
      printf("\n");
      continue;
    }
    LIST* A = G->A[i];
    while (A->next != NULL) {
      printf("(%d, %d); ", A->neighbor, A->weight);
      A = A->next;
    }
    printf("(%d, %d)\n", A->neighbor, A->weight);
  }
}