#include <string.h>
#include <stdio.h>
#include "queue.h"

int main(void)
{
  queueT queue;
  Create(&queue, 5);

  char name[] = "George South";
  int length = strlen(name);

  for (int i = 0; i < length; ++i)
  {
    if (IsFull(&queue))
      break;
    Insert(&queue, name[i]);
  }

  printf("Elements: ");

  while(!IsEmpty(&queue))
  {
    printf("%c", Delete(&queue));
  }

  printf("\n");

  Destroy(&queue);

  return(0);
}
