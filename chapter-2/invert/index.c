/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the
  n bits that begin at position p inverted (i.e., 1 changed into 0 and
  vice versa), leaving the others unchanged. */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
  printf("%d should be 39\n", invert(59, 4, 3));
  return 0;
}

/* 59 = 0011 1011
  0011 1011 turns into 0010 0111
  ^
  0001 1100 = ~(~0 << n) << (p-n+1)
  0010 0111
*/
unsigned invert(unsigned x, int p, int n)
{
  return x ^ (~(~0 << n) << (p-n+1));
}

