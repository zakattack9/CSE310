#include <stdio.h>
#include <math.h>
#include "heap.h"

// MAIN HEAP FUNCTIONS
HEAP* Initialize(int n)
{
  HEAP* heap = new HEAP;
  heap->capacity = n;
  heap->size = 0;
  heap->H = new ELEMENT[n];
  return heap;
}

void BuildHeap(HEAP* heap, ELEMENT A[], int n)
{
  // add check to see if HEAP is null
  if (n > heap->capacity) {
    printf("Array size is larger than heap capacity\n");
    return;
  }

  // max-heapify the element array first
  for (int i = (n / 2) - 1; i >= 0; i--) {
    MaxHeapify(A, n, i);
  }

  // copy array into heap (index-one based array)
  for (int i = 1; i <= n; i++) {
    heap->H[i] = A[i - 1];
  }
  heap->size = n;
}

void Insert(HEAP* heap, int flag, int k)
{
  heap->size++;
  
}

int DeleteMax(HEAP* heap, int flag)
{

}

void IncreaseKey(HEAP* heap, int flag, int index, int value)
{

}

void printHeap(HEAP* heap)
{

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
  return 2 * i + 1;
}

// return iindex of right child node
int Right(int i)
{
  return 2 * i + 2;
}

// organizes array into a max heap starting at a specific index
// arrays are zero-index based
void MaxHeapify(ELEMENT A[], int n, int i)
{
  int largest = i; // index of largest element in subtree
  int left = Left(i);
  int right = Right(i);

  // check if left child is larger than element at index i
  if (left < n && A[left].key > A[largest].key) {
    largest = left;
  }
  
  // check if right child is larger than element at index i
  if (right < n && A[right].key > A[largest].key) {
    largest = right;
  }

  if (largest != i) {
    // swaps element at index i with larger child node
    ELEMENT temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;
    // recursively call max-heapify to float element at i down tree 
    MaxHeapify(A, n, largest);
  }
}

void PrintHeap(HEAP* heap, int flag)
{

}