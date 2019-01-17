/* Exercise 2-8. Write a function rightrot(x,n) that returns the
  value of the integer x rotated to the right by n bit postions. */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);
unsigned binarylen(unsigned x);

int main()
{
  printf("%d should be 31\n", rightrot(59, 3));
}

/* x = 59 --> 11 1011 should be 01 1111
*/
unsigned rightrot(unsigned x, int n)
{
  int r, c;
  c = binarylen(x);
  r = n % c;
  return (x >> r) | ((x % (x >> r << r)) << (c - r));
}

unsigned binarylen(unsigned x)
{
  int n;
  for (n = 1; (x = x >> 1) > 0; n++)
    ;
  return n;
}