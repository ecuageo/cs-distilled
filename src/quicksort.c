#include "quicksort.h"

int partition(int *A, int start, int end);
void qsort(int *A, int start, int end);
void swap(int *A, int a, int b);

void quicksort(int *A, int length) {
  qsort(A, 0, length - 1);
}

void qsort(int *A, int start, int end)
{
  if (start < end) {
    int pivot = partition(A, start, end);
    qsort(A, start, pivot - 1);
    qsort(A, pivot + 1, end);
  }
}

int partition(int *A, int start, int end)
{
  int i = 0;
  for (int j = start; j < end; ++j) {
    if (A[j] < A[end]) {
      swap(A, start + i, j);
      ++i;
    }
  }
  swap(A, start + i, end);
  return start + i;
}

void swap(int *A, int a, int b)
{
  int t = A[a];
  A[a] = A[b];
  A[b] = t;
}
