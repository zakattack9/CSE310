#include <stdio.h>
#include <limits.h>
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
    printf("Error: array size exceeds heap capacity\n");
    return;
  }

  // max-heapify the element array first
  for (int i = n / 2; i >= 1; i--) {
    MaxHeapify(A, n, i);
  }

  // copy array into heap (index-one based array)
  for (int i = 1; i <= n; i++) {
    heap->H[i] = A[i];
  }
  heap->size = n;
}

void Insert(HEAP* heap, int flag, int k)
{
  if (heap->size + 1 > heap->capacity) {
    printf("Error: exceeds heap capacity");
  } else {
    heap->size++;
    int i = heap->size;
    heap->H[i].key = INT_MIN;
    IncreaseKey(heap, flag, i, k);
  }
}

int DeleteMax(HEAP* heap, int flag)
{
  printf("Before delete max operation:\n");
  if (flag == 2) printHeap(heap); // print heap before

  if (heap->size < 1) {
    printf("Error: heap empty\n");
  } else {
    int max = heap->H[1].key;
    heap->H[1].key = heap->H[heap->size].key;
    heap->size--;
    MaxHeapify(heap->H, heap->size, 1);

    printf("After delete max operation:\n");
    if (flag == 2) printHeap(heap); // print heap after
    return max;
  }

}

void IncreaseKey(HEAP* heap, int flag, int index, int value)
{
  printf("Before increase key operation:\n");
  if (flag == 2) printHeap(heap); // print heap before

  if (value < heap->H[index].key) {
    printf("Error: new key is smaller than current key\n");
  } else {
    heap->H[index].key = value;
    while(index > 1 && heap->H[Parent(index)].key < heap->H[index].key) {
      // swap key and its parent
      ELEMENT temp = heap->H[index];
      heap->H[index] = heap->H[Parent(index)];
      heap->H[Parent(index)] = temp;
      index = Parent(index);
    }
  }

  printf("After increase key operation:\n");
  if (flag == 2) printHeap(heap); // print heap after
}

void printHeap(HEAP* heap)
{
  printf("Capacity = %d\n", heap->capacity);
  printf("Size = %d\n", heap->size);
  for (int i = 1; i <= heap->size; i++) {
    printf("%d\n", heap->H[i].key);
  }
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
void MaxHeapify(ELEMENT A[], int n, int i)
{
  int largest = i; // index of largest element in subtree
  int left = Left(i);
  int right = Right(i);

  // check if left child is larger than element at index i
  if (left <= n && A[left].key > A[largest].key) {
    largest = left;
  }
  
  // check if right child is larger than element at index i
  if (right <= n && A[right].key > A[largest].key) {
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