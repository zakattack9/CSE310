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

int main()
{
  // variables for the parser...
  HEAP *heap;
  char c;
  int i, v, f, n, k; // parameters for heap fucntions
  int arrSize;       // holds size of array read in from "HEAPinput.txt"
  printf("Welcome to testing world");
  while (1)
  {
    c = nextCommand(&i, &v, &f, &n, &k);
    printf("THIS IS CHAR %c\n", c);
    switch (c)
    {
    case 's':
    case 'S':
      printf("COMMAND: %c.\n", c);
      exit(0);

    case 'c':
    case 'C':
      heap = Initialize(n);
      break;

    case 'r':
    case 'R':
      arrSize = loadArrSize();
      ELEMENT arr[arrSize];
      loadArrValues(arr);
      BuildHeap(heap, arr, arrSize);
      // printf("SIZE OF ARR %d\n", heap->size);
      // for (int i = 0; i <= n + 1; i++) {
      //   printf("HEAP %d = %d\n", i, heap->H[i].key);
      // }
      break;

    case 'w':
    case 'W':
      break;

    case 'i':
    case 'I':
      break;

    case 'd':
    case 'D':
      break;

    case 'k':
    case 'K':
      printf("COMMAND: %c %d %d %d.\n", c, i, v, f);
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

  if (file.is_open())
  {
    file >> num; // read in and ignore size of array
    int index = 0;
    while (file >> num)
    {
      ELEMENT el;
      el.key = num;
      arr[index++] = el;
    }
    file.close();
  }
}