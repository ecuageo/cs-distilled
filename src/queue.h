#ifndef _Queue_Test
#define _Queue_Test

typedef char queueElementT;

typedef struct {
  queueElementT *contents;
  int queueSize;
  int front;
  int count;
} queueT;

void Insert(queueT *queueP, queueElementT element);
queueElementT Delete(queueT *queueP);

int IsEmpty(queueT *queueP);
int IsFull(queueT *queueP);

void Create(queueT *queueP, int queueSize);
void Destroy(queueT *queueP);

#endif
