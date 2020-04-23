#ifndef _HEAP_H_
#define _HEAP_H_

// MAIN HEAP FUNCTIONS
// void BuildHeap(HEAP* heap, ELEMENT A[], int n);
// int DeleteMin(HEAP* heap, int flag);
// void printHeap(HEAP* heap);

// HELPER HEAP FUNCTIONS
int Parent(int i);
int Left(int i);
int Right(int i);
void MinHeapify(ELEMENT A[], int n, int i);

#endif