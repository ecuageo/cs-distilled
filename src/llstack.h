#ifndef _LL_Stack
#define _LL_Stack

typedef struct llStackElementT {
  char value;
  struct llStackElementT *next;
} llStackElementT;

typedef struct llStackT {
  int size;
  struct llStackElementT *top;
} llStackT;

int LLStackIsEmpty(llStackT *llStackP);
void LLStackPush(llStackT *llStackP, char element);
char LLStackPop(llStackT *llStackP);
#endif
