#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void PrintStack(stackT *stackP);

int main(void)
{
  stackT s1;
  stackElementT e1, e2, e3;
  e1 = 'A';
  e2 = 'B';
  e3 = 'X';

  StackInit(&s1, 5);
  StackPush(&s1, e1);
  StackPush(&s1, e2);
  StackPop(&s1);
  StackPush(&s1, e3);
  StackPush(&s1, e3);

  PrintStack(&s1);

  StackDestroy(&s1);
  exit(0);
}

void PrintStack(stackT *stackP)
{
  for (int i = 0; i <= stackP->top; ++i)
  {
    printf("%c", stackP->contents[i]);
  }
  printf("\n");
}
