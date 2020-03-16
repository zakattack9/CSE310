#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "heap.h"

// MAIN HEAP FUNCTIONS
HEAP* Initialize(int n)
{
  HEAP* heap = new HEAP; // allocate memory for heap object
  heap->capacity = n;
  heap->size = 0;
  heap->H = new ELEMENT[n + 1]; // heap starts at index 1
  return heap;
}

void BuildHeap(HEAP* heap, ELEMENT A[], int n)
{
  if (n > heap->capacity) {
    printf("Error: array size exceeds heap capacity\n");
    return;
  }

  // max-heapify the element array first
  for (int i = n / 2; i >= 1; i--) {
    MaxHeapify(A, n, i);
  }

  // copy max-heapified array into heap (index-one based array)
  for (int i = 1; i <= n; i++) {
    heap->H[i] = A[i];
  }
  heap->size = n;
}

void Insert(HEAP* heap, int flag, int v)
{
  // if (heap->size + 1 > heap->capacity) {
  //   printf("Error: exceeds heap capacity");
  // }

  if (flag == 2) {
    printf("Before insert operation:\n");
    printHeap(heap);
  }

  heap->size++;
  int height = ceil(log2(heap->size)); // calculate height of heap
  int newCapacity = pow(2, height); // increase heap capacity by power of 2
  if (newCapacity > heap->capacity) {
    ExpandHeapCapacity(heap, newCapacity);
    heap->capacity = newCapacity;
  }

  // set last element in heap to an arbitrarily small number
  int i = heap->size;
  heap->H[i].key = INT_MIN;
  IncreaseKey(heap, 1, i, v);

  if (flag == 2) {
    printf("After insert operation:\n");
    printHeap(heap);
  }
}

int DeleteMax(HEAP* heap, int flag)
{
  if (flag == 2) {
    printf("Before delete max operation:\n");
    printHeap(heap);
  }

  int max = heap->H[1].key; // max of heap is the root of heap tree
  heap->H[1].key = heap->H[heap->size].key; // set root of heap to last element
  heap->size--;
  MaxHeapify(heap->H, heap->size, 1); // max heapify starting at root

  if (flag == 2) {
    printf("After delete max operation:\n");
    printHeap(heap);
  }
  
  return max;
}

void IncreaseKey(HEAP* heap, int flag, int index, int value)
{

  if (value < heap->H[index].key) {
    printf("Error: new key is smaller than current key\n");
  } else {
    if (flag == 2) {
      printf("Before increase key operation:\n");
      printHeap(heap);
    }

    heap->H[index].key = value; // set to key to new value at index
    while(index > 1 && heap->H[Parent(index)].key < heap->H[index].key) {
      // swap key and its parent
      ELEMENT temp = heap->H[index];
      heap->H[index] = heap->H[Parent(index)];
      heap->H[Parent(index)] = temp;
      index = Parent(index);
    }

    if (flag == 2) {
      printf("After increase key operation:\n");
      printHeap(heap);
    }
  }
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

// increases capacity of heap and deallocates memory for old heap array
void ExpandHeapCapacity(HEAP* heap, int newCapacity)
{
  ELEMENT* oldHeap = heap->H;
  heap->H = new ELEMENT[newCapacity]; // create new heap array with newCapacity
  // copy elements of old heap array to new heap array
  for (int i = 1; i <= heap->capacity; i++) {
    heap->H[i].key = oldHeap[i].key;
  }

  if (oldHeap != NULL) {
    // deallocate memory of old heap array
    delete[] oldHeap;
    oldHeap = NULL;
  }
}