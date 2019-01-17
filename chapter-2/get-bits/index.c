/* Example 2-9. Write a function to get n bits from position p */

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main()
{
  printf("%d should be 6\n", getbits(59, 4, 3));
}

/* Working through using the example x = 59
  59 --> 0011 1011
  p+1-n --> 4+1-3 --> 2
  x >> 2 --> 59 >> 2 --> 0011 1011 >> 2 --> 0000 1110
  ~0 --> ~(0000 0000) --> 1111 1111
  (1111 1111) << n --> (1111 1111) << 3 --> 1111 1000
  ~(1111 1000) --> 0111
  1110 & 0111 --> 0110 --> 6
  */
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}