#include <stdio.h>
#include "util.h"

int nextCommand(int* i, int* v, int* f, int* n)
{
  char c;
  while (1)
  {
    scanf("%c", &c);
    if (c == ' ' || c == '\t' || c == '\n')
    {
      continue;
    }
    if (c == 's' || c == 'S' || c == 'r' || c == 'R' || c == 'w' || c == 'W')
    {
      break;
    }
    if (c == 'c' || c == 'C')
    {
      scanf("%d", n);
      break;
    }
    if (c == 'i' || c == 'I')
    {
      scanf("%d", f);
      scanf("%d", v);
      break;
    }
    if (c == 'd' || c == 'D')
    {
      scanf("%d", f);
      break;
    }
    if (c == 'k' || c == 'K')
    {
      scanf("%d", f);
      scanf("%d", i);
      scanf("%d", v);
      break;
    }
    printf("Invalid Command\n");
  }
  return c;
}