#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "heap.h"

// MAIN HEAP FUNCTIONS

void BuildHeap(ELEMENT* H, int n)
{
  // max-heapify the element array first
  for (int i = n / 2; i >= 1; i--) {
    MinHeapify(H, n, i);
  }
}

ELEMENT DeleteMin(ELEMENT* H, int* size)
{
  ELEMENT min = H[1]; // max of heap is the root of heap tree
  H[1] = H[*size]; // set root of heap to last element
  *size = *size - 1;
  MinHeapify(H, *size, 1); // max heapify starting at root
  return min;
}

void DecreaseKey(ELEMENT* H, int index)
{
  while(index > 1 && H[Parent(index)].d > H[index].d) {
    // swap key and its parent
    ELEMENT temp = H[index];
    H[index] = H[Parent(index)];
    H[Parent(index)] = temp;
    index = Parent(index);
  }
}

void printHeap(ELEMENT* H, int size)
{
  for (int i = 1; i <= size; i++) {
    printf("%d ", H[i].node);
  }
  printf("\n");
}

// HELPER HEAP FUNCTIONS
// returns index of parent node
int Parent(int i)
{
  return floor(i / 2);
}

// returns index of left child node
int Left(int i)
{
  return 2 * i;
}

// return index of right child node
int Right(int i)
{
  return 2 * i + 1;
}

// organizes array into a max heap starting at a specific index
void MinHeapify(ELEMENT A[], int n, int i)
{
  int smallest = i; // index of smallest element in subtree
  int left = Left(i);
  int right = Right(i);

  // check if left child is smaller than element at index i
  if (left <= n && A[left].d < A[smallest].d) {
    smallest = left;
  }
  
  // check if right child is smaller than element at index i
  if (right <= n && A[right].d < A[smallest].d) {
    smallest = right;
  }

  if (smallest != i) {
    // swaps element at index i with smaller child node
    ELEMENT temp = A[i];
    A[i] = A[smallest];
    A[smallest] = temp;
    // recursively call min-heapify to float element at i down tree 
    MinHeapify(A, n, smallest);
  }
}
