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
    printf("Error: array size exceeds heap capacity\n");
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
  return 2 * i + 1;
}

// return index of right child node
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