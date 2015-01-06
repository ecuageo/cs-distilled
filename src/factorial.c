#include <stdio.h>

int other();

int main(void)
{
  int i, num, j;
  printf("Enter the number: ");
  scanf("%d", &num);

  for (i = 1; i < num; i++)
    j = j * i;

  printf("The factorial of %d is %d\n", num, j);
}

int other()
{
  return 8;
}
