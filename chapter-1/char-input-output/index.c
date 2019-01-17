#include <stdio.h>

/* Use ctrl + D to send EOF char
  To use a file for input:
  cat sample.txt | ./a.out or ./a.out < sample.txt */

int main()
{
  int c;
  while((c = getchar()) != EOF)
    putchar(c);
}