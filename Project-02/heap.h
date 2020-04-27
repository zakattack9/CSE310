#ifndef _HEAP_H_
#define _HEAP_H_
#include "graph.h"

// MAIN HEAP FUNCTIONS
void BuildHeap(ELEMENT* H, int n);
ELEMENT DeleteMin(ELEMENT* H, int* size);
void DecreaseKey(ELEMENT* H, int index);
void printHeap(ELEMENT* H, int size);

// HELPER HEAP FUNCTIONS
int Parent(int i);
int Left(int i);
int Right(int i);
void MinHeapify(ELEMENT A[], int n, int i);

#endif