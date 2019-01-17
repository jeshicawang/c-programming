/* Exercise 2-6. Write a function setbits(x, p, n, y) that returns
  x with the n bits that begin at position p set to the rightmost
  n bits of y, leaving the other bits unchanged. */

#include <stdio.h>
#include <math.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
  printf("%d should be 47\n", setbits(59, 4, 3, 75));
  return 0;
}

/* x = 59 --> 0011 1011
  y = 75 --> 0100 1011
  p = 4
  n = 3
  result should be  0010 1111 aka 47
  0011 1011 | 0001 1100 --> 0011 1111
  0011 1111
  1110 1111
  0010 1111

  0000 1100, y << (8-n) >> (7-p)
  |
  1110 0011, ~(~(~0 << n) << (p-n+1))
  =
  1110 1111
*/
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  return (x >> (p + 1) << (p + 1))
    | ((y % (y >> n << n)) << (p-n+1))
    | (x % (x >> (p-n+1) << (p-n+1)));
}
