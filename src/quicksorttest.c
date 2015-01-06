#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

void print_a(int *A, int length);

int main(void)
{
  int a[] = {4,1,2,6,5,3};
  int b[] = {2,5,1,3,6,4};

  printf("printing a: \n");
  print_a(a, 6);
  printf("sorting... \n");
  quicksort(a, 6);
  print_a(a, 6);

  printf("printing b: \n");
  print_a(b, 6);
  printf("sorting... \n");
  quicksort(b, 6);
  print_a(b, 6);

  return 0;
}

void print_a(int *A, int length)
{
  for (int i = 0; i < length; ++i)
    printf("%i", A[i]);
  printf("\n");
}
