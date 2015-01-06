#include <stdio.h>
#include <stdlib.h>
#include "llstack.h"

void PrintStack(llStackT *llStackP);

int main(void)
{
  llStackT s1;
  s1.size = 0;
  char e1, e2, e3;
  e1 = 'A';
  e2 = 'B';
  e3 = 'X';

  LLStackPush(&s1, e1);
  LLStackPush(&s1, e2);
  LLStackPop(&s1);
  LLStackPush(&s1, e3);
  LLStackPush(&s1, e3);

  PrintStack(&s1);

  exit(0);
}

void PrintStack(llStackT *llStackP)
{
  while(!LLStackIsEmpty(llStackP))
  {
    printf("%c", LLStackPop(llStackP));
  }
  printf("\n");
}
