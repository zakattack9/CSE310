#include <stdio.h>
#include "util.h"

int nextCommand(int* s, int* t, int* f)
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
    if (c == 'f' || c == 'F')
    {
      scanf("%d", s);
      scanf("%d", t);
      scanf("%d", f);
      break;
    }
    printf("Invalid Command\n");
  }
  return c;
}