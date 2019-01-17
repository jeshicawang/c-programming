/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes
  the rightmost 1-bit in x. Explain why. Use this observation to write a
  faster version of bitcount.

  Why-- The binary representation of (x-1) is the same as x except with the
  rightmost 1-bit and all following bits inverted, 1 -> 0 and 0 -> 1. When the
  bitwise & operator is used on x & (x-1) the bit values before the rightmost 1
  bit of x will remain the same, since they are the same for both values, but all
  following bits will be switched to 0 since they have opposite values. In
  conclusion the rightmost 1-bit in x will be deleted after execution of x &= (x-1).

  OG bitcount--

  int bitcount(unsigned x)
  {
    int b;
    for (b = 0; x != 0; x >>= 1)
      if (x & 01)
        b++;
    return b;
  }
*/

#include <stdio.h>

int bitcount(unsigned x);

int main()
{
  printf("%d should be 0\n", bitcount(0));
  printf("%d should be 5\n", bitcount(55));
  printf("%d should be 9\n", bitcount(7093));
  return 0;
}

/* count number of 1-bits in x */
int bitcount(unsigned x)
{
  int b = 0;
  while (x != 0) {
    x &= (x-1);
    b++;
  }
  return b;
}