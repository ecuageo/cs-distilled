#include <stdlib.h>
#include <stdio.h>
#include "llstack.h"

/*
typedef struct {
  int size;
  llStackElementT *top;
} llStackT;
*/

int LLStackIsEmpty(llStackT *llStackP)
{
  return llStackP->size == 0;
}

void LLStackPush(llStackT *llStackP, char value)
{
  llStackElementT *newElementP;
  newElementP = (llStackElementT *)malloc(sizeof(llStackElementT));

  if (newElementP == NULL) 
  {
    printf("No available memory to add to the stack\n");
    exit(1);
  }

  if (llStackP->size > 0)
  {
    newElementP->next = llStackP->top;
  }

  llStackP->top = newElementP;
  newElementP->value = value;
  llStackP->size += 1;
}

char LLStackPop(llStackT *llStackP)
{
  char popped = llStackP->top->value;
  llStackElementT *oldTop = llStackP->top;
  llStackP->top = oldTop->next;
  free(oldTop);
  llStackP->size -= 1;
  return popped;
}

