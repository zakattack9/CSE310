#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "heap.h"
#include "graph.h"

using namespace std;

string fileName = "Ginput.txt";
void loadGraph(GRAPH* graph);
void buildAdjacencyList(GRAPH* graph, ifstream &file);
bool graphExists(GRAPH* graph);
bool validFlag(int flag);
bool validNodes(int v, int s, int t);
bool validArgs(int v, int s, int t, int f);
void cleanup(GRAPH* graph, ELEMENT* computedNodes);

int main()
{
  GRAPH* graph = NULL;
  ELEMENT* computedNodes = NULL;
  char c; // holds last command inputted by user
  int s, t, f; // parameters for graph fucntions
  while (1)
  {
    c = nextCommand(&s, &t, &f);
    switch (c)
    {
    case 's':
    case 'S':
      printf("COMMAND: %c\n", c);
      cleanup(graph, computedNodes);
      exit(0);

    case 'r':
    case 'R':
      printf("COMMAND: %c\n", c);
      
      graph = new GRAPH;
      loadGraph(graph);
      break;

    case 'w':
    case 'W':
      printf("COMMAND: %c\n", c);
      if (!graphExists(graph)) break;

      printGraph(graph);
      break;

    case 'f':
    case 'F':
      printf("COMMAND: %c %d %d %d\n", c, s, t, f);
      if (!graphExists(graph)) break;
      if (!validArgs(graph->v, s, t, f)) break;

      Initialize(graph);
      computedNodes = Dijkstra(graph, s);
      printPath(computedNodes, s, t, f);
      break;

    default:
      break;
    }
  }
  exit(0);
}

void loadGraph(GRAPH* graph) {
  int v, e; // # vertices and # edges 
  ifstream file;
  file.open(fileName);
  file >> v >> e; // read in first two lines of file, v and e respectively

  graph->v = v;
  graph->e = e;
  graph->H = NULL;
  graph->A = new LIST*[v + 1]; // index starts at 1
  // set all vertices in adjacency list as null
  for (int i = 1; i <= v; i++) {
    graph->A[i] = NULL;
  }
  // build adjacency list values
  buildAdjacencyList(graph, file);
  file.close();
}

void buildAdjacencyList(GRAPH* graph, ifstream &file) {
  int u, v, w; // neighbor vertex (v) and weight (w) of vertex u
  while (file >> u >> v >> w) {
    // create temporary vertex adjacency list
    LIST* temp = new LIST;
    temp->neighbor = v;
    temp->weight = w;
    temp->next = NULL;

    if (graph->A[u] == NULL) {
      // if adjacency list for vertex is empty, set as head
      graph->A[u] = temp;
    } else {
      // if adjacency list for vertex is not empty, insert at head
      temp->next = graph->A[u];
      graph->A[u] = temp;
    }
  }
}

bool graphExists(GRAPH* graph) {
  if (graph == NULL) {
    printf("Error: graph not initialized\n");
    return false;
  }
  return true;
}

bool validFlag(int flag) {
  if (flag != 0 && flag != 1) {
    printf("Error: invalid flag value\n");
    return false;
  }
  return true;
}

bool validNodes(int v, int s, int t) {
  if (s < 1 || t < 1 || s > v || t > v) {
    printf("Error: one or more invalid nodes\n");
    return false;
  }
  return true;
}

bool validArgs(int v, int s, int t, int f) {
  bool valid = true;
  if (!validNodes(v, s, t)) valid = false;
  if (!validFlag(f)) valid = false;
  return valid;
}

void cleanup(GRAPH* graph, ELEMENT* computedNodes) {
  if (graph != NULL) {
    // delete min-heap
    if (graph->H != NULL) {
      delete[] graph->H;
      graph->H = NULL;
    }

    // delete linked lists in adjacency list
    for (int i = 1; i <= graph->v; i++) {
      do {
        LIST* next = graph->A[i]->next;
        delete graph->A[i];
        graph->A[i] = next;
      } while(graph->A[i] != NULL);
    }

    // delete adjacency list
    delete[] graph->A;
    graph->A = NULL;

    // delete graph struct
    delete graph;
    graph = NULL;
  }

  if (computedNodes != NULL) {
    // delete computed nodes from Dijkstra's
    delete[] computedNodes;
    computedNodes = NULL;
  }
}