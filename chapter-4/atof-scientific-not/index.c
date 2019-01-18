/* Exercise 4-2. Extend atof to handle scientific notation of the form
  123.45e-6, where a floating-point number may be followed by e or E
  and an optionally signed exponent. */

#include <stdio.h>

int main()
{
  double atof2(char s[]);
  printf("%f\n", atof2("-5.1234e-4"));
}