#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "heap.h"

using namespace std;

string fileName = "HEAPinput.txt";
int loadArrSize();
void loadArrValues(ELEMENT arr[]);
void cleanup(HEAP* heap, ELEMENT* arr);
bool heapExists(HEAP* heap);
bool heapEmpty(HEAP* heap);
bool validHeapCapacity(int n);
bool validFlag(int flag);
bool validIndex(HEAP* heap, int index);

int main()
{
  // variables for the parser...
  HEAP* heap = NULL;
  ELEMENT* arr = NULL;
  char c;
  int i, v, f, n; // parameters for heap fucntions
  int arrSize; // holds size of array read in from "HEAPinput.txt"
  int deletedMax; // holds max key deleted from heap
  while (1)
  {
    c = nextCommand(&i, &v, &f, &n);
    switch (c)
    {
    case 's':
    case 'S':
      printf("COMMAND: %c\n", c);
      cleanup(heap, arr);

      exit(0);

    case 'c':
    case 'C':
      printf("COMMAND: %c %d\n", c, n);
      if (!validHeapCapacity(n)) break;

      heap = Initialize(n);
      break;

    case 'r':
    case 'R':
      printf("COMMAND: %c\n", c);
      if (!heapExists(heap)) break;

      arrSize = loadArrSize();
      arr = new ELEMENT[arrSize + 1]; // array starts at index 1
      loadArrValues(arr);
      BuildHeap(heap, arr, arrSize);
      break;

    case 'w':
    case 'W':
      printf("COMMAND: %c\n", c);
      if (!heapExists(heap)) break;

      printHeap(heap);
      break;

    case 'i':
    case 'I':
      printf("COMMAND: %c %d %d\n", c, f, v);
      if (!heapExists(heap)) break;
      if (!validFlag(f)) break;

      Insert(heap, f, v);
      break;

    case 'd':
    case 'D':
      printf("COMMAND: %c %d\n", c, f);
      if (!heapExists(heap)) break;
      if (heapEmpty(heap)) break;
      if (!validFlag(f)) break;

      deletedMax = DeleteMax(heap, f);
      printf("Deleted max = %d\n", deletedMax);
      break;

    case 'k':
    case 'K':
      printf("COMMAND: %c %d %d %d\n", c, f, i, v);
      if (!heapExists(heap)) break;
      if (!validFlag(f)) break;
      if (!validIndex(heap, i)) break;

      IncreaseKey(heap, f, i, v);
      break;

    default:
      break;
    }
  }
  exit(0);
}

int loadArrSize()
{
  int size = 0;
  ifstream file;
  file.open(fileName);

  if (file.is_open())
  {
    file >> size;
    file.close();
  }
 
  return size;
}

void loadArrValues(ELEMENT arr[])
{
  int num;
  ifstream file;
  file.open(fileName);

  if (file.is_open()) {
    file >> num; // read in and ignore size of array
    int index = 1;
    while (file >> num)
    {
      ELEMENT el;
      el.key = num;
      arr[index++] = el;
    }
    file.close();
  }
}

bool heapExists(HEAP* heap)
{
  if (heap == NULL) {
    printf("Error: heap not initialized\n");
    return false;
  }
  return true;
}

bool heapEmpty(HEAP* heap)
{
  if (heap->size < 1) {
    printf("Error: heap empty\n");
    return true;
  }
  return false;
}

bool validHeapCapacity(int n)
{
  if (n < 0) {
    printf("Error: invalid heap capacity\n");
    return false;
  }
  return true;
}

bool validFlag(int flag)
{
  if (flag != 2 && flag != 1) {
    printf("Error: invalid flag value\n");
    return false;
  }
  return true;
}

bool validIndex(HEAP* heap, int index)
{
  if (index <= 0 || index > heap->size) {
    printf("Error: invalid index\n");
    return false;
  }
  return true;
}

void cleanup(HEAP* heap, ELEMENT* arr)
{
  if (arr != NULL) {
    delete[] arr;
    arr = NULL;
  }
  if (heap != NULL) {
    if (heap->H != NULL) {
      delete[] heap->H;
      heap->H = NULL;
    }
    delete heap;
    heap = NULL;
  }
}