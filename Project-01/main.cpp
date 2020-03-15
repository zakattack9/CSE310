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
  HEAP *heap = NULL;
  char c;
  int i, v, f, n, k; // parameters for heap fucntions
  int arrSize;       // holds size of array read in from "HEAPinput.txt"
  printf("Welcome to testing world");
  while (1)
  {
    c = nextCommand(&i, &v, &f, &n, &k);
    switch (c)
    {
    case 's':
    case 'S':
      printf("COMMAND: %c \n", c);
      exit(0);

    case 'c':
    case 'C':
      printf("COMMAND: %c %d\n", c, n);
      heap = Initialize(n);
      break;

    case 'r':
    case 'R':
      printf("COMMAND: %c \n", c);
      arrSize = loadArrSize();
      ELEMENT arr[arrSize];
      loadArrValues(arr);
      BuildHeap(heap, arr, arrSize);
      break;

    case 'w':
    case 'W':
      printf("COMMAND: %c \n", c);
      printHeap(heap);
      break;

    case 'i':
    case 'I':
      printf("COMMAND: %c %d %d \n", c, f, k);
      break;

    case 'd':
    case 'D':
      printf("COMMAND: %c %d \n", c, f);
      break;

    case 'k':
    case 'K':
      printf("COMMAND: %c %d %d %d \n", c, f, i, v);
      if (f != 2 && f != 1) {
        printf("Error: invalid flag value\n");
        break;
      }
      if (i <= 0 || i > heap->size) {
        printf("Error: invalid index\n");
        break;
      }

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