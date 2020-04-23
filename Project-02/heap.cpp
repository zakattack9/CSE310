#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "heap.h"

// MAIN HEAP FUNCTIONS

// void BuildHeap(HEAP* heap, ELEMENT A[], int n)
// {
//   if (n > heap->capacity) {
//     printf("Error: array size exceeds heap capacity\n");
//     return;
//   }

//   // max-heapify the element array first
//   for (int i = n / 2; i >= 1; i--) {
//     MinHeapify(A, n, i);
//   }

//   // copy max-heapified array into heap (index-one based array)
//   for (int i = 1; i <= n; i++) {
//     heap->H[i] = A[i];
//   }
//   heap->size = n;
// }

// int DeleteMin(HEAP* heap, int flag)
// {
//   if (flag == 2) {
//     printf("Before delete max operation:\n");
//     printHeap(heap);
//   }

//   int min = heap->H[1].key; // max of heap is the root of heap tree
//   heap->H[1].key = heap->H[heap->size].key; // set root of heap to last element
//   heap->size--;
//   MinHeapify(heap->H, heap->size, 1); // max heapify starting at root

//   if (flag == 2) {
//     printf("After delete max operation:\n");
//     printHeap(heap);
//   }
  
//   return min;
// }

// void printHeap(HEAP* heap)
// {
//   printf("Capacity = %d\n", heap->capacity);
//   printf("Size = %d\n", heap->size);
//   for (int i = 1; i <= heap->size; i++) {
//     printf("%d\n", heap->H[i].key);
//   }
// }

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
// void MinHeapify(ELEMENT A[], int n, int i)
// {
//   int smallest = i; // index of smallest element in subtree
//   int left = Left(i);
//   int right = Right(i);

//   // check if left child is larger than element at index i
//   if (left <= n && A[left].key < A[smallest].key) {
//     smallest = left;
//   }
  
//   // check if right child is larger than element at index i
//   if (right <= n && A[right].key < A[smallest].key) {
//     smallest = right;
//   }

//   if (smallest != i) {
//     // swaps element at index i with larger child node
//     ELEMENT temp = A[i];
//     A[i] = A[smallest];
//     A[smallest] = temp;
//     // recursively call max-heapify to float element at i down tree 
//     MinHeapify(A, n, smallest);
//   }
// }
