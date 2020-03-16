#ifndef _HEAP_H_
#define _HEAP_H_

struct ELEMENT {
  int key;
};

struct HEAP {
  int capacity;
  int size;
  ELEMENT* H;
};

// MAIN HEAP FUNCTIONS
HEAP* Initialize(int n);
void BuildHeap(HEAP* heap, ELEMENT A[], int n);
void Insert(HEAP* heap, int flag, int k);
int DeleteMax(HEAP* heap, int flag);
void IncreaseKey(HEAP* heap, int flag, int index, int value);
void printHeap(HEAP* heap);

// HELPER HEAP FUNCTIONS
int Parent(int i);
int Left(int i);
int Right(int i);
void MaxHeapify(ELEMENT A[], int n, int i);
void ExpandHeapCapacity(HEAP* heap, int newCapacity);

#endif