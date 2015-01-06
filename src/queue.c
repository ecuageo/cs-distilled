#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void Insert(queueT *queueP, queueElementT element)
{
  int insertPosition;

  if (IsFull(queueP))
  {
    printf("Trying to insert into a full queue\n");
    exit(1);
  }
  
  insertPosition = (queueP->front + queueP->count) % queueP->queueSize;
  queueP->count++;
  queueP->contents[insertPosition] = element;
}
queueElementT Delete(queueT *queueP)
{
  queueElementT element;

  if (IsEmpty(queueP))
  {
    printf("Trying to delete from an empty queue\n");
    exit(1);
  }

  element = queueP->contents[queueP->front];
  queueP->front = (queueP->front + 1) % queueP->queueSize;
  queueP->count -= 1;
  return element;
}

int IsFull(queueT *queueP)
{
  return queueP->count == queueP->queueSize;
}
int IsEmpty(queueT *queueP)
{
  return queueP->count == 0;
}

void Create(queueT *queueP, int queueSize)
{
  queueElementT *contents;
  contents = (queueElementT *)malloc(sizeof(queueElementT) * queueSize);

  if (contents == NULL) {
    fprintf(stderr, "Insufficient memory to initialize queue. \n");
    exit(1);
  }

  queueP->contents = contents;
  queueP->queueSize = queueSize;
  queueP->front = 0;
  queueP->count = 0;
}

void Destroy(queueT *queueP)
{
  free(queueP->contents);

  queueP->contents = NULL;
  queueP->queueSize = 0;
  queueP->front = 0;
  queueP->count = 0;
}
