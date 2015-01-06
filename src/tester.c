#include <stdlib.h>
#include <stdio.h>

int sample();

int main(void)
{
  int s = sample();
  printf("%d\n", s);
  return 0;
}

int sample()
{
  return 10;
  printf("But I still got here\n");
}
