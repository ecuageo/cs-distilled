#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Push: places an object on the top of the stack
// Pop: removes an object from the top of the stack and produces that object
// IsEmpty: Reports whether the stack is empty or not
// OVERFLOW/UNDERFLOW

void push(char new_value);
char pop();
bool is_empty(char *contents);
void print_contents(char *contents, int size);
void error(char *msg);

char contents[4] = "    ";
// top points to the next empty position
int top = 0;

int main()
{
  int size = 4;
  char c;
  push('A');
  c = pop();
  push('B');
  push('C');
  push(c);

  print_contents(contents, size);
  printf(is_empty(contents) ? "true" : "false");
  return 0;
}

void push(char new_value)
{
  contents[top++] = new_value;
}

char pop()
{
  char c;
  if (is_empty(contents))
    error("Trying to pop when the stack is empty\n");
  c = contents[top-1];
  contents[--top] = ' ';
  return c;
}

bool is_empty(char *contents)
{
  return top == 0;
}

void print_contents(char *contents, int size)
{
  for (int i=0; i < size; i++)
    printf("%c", contents[i]);
}

void error(char *msg)
{
  printf("%s", msg);
  exit(1);
}
