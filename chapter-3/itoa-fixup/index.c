/* Exercise 3-4. In a two's complement number representation, our
  version of itoa does not handle the largest negative number, that
  is, the value of n equal to -(2^(wordsize - 1)). Explain why not.
  Modify it to print that value correctly, regardless of the machine
  on which it runs.

  Why not-- In a two's complement system the when you multiple the
  largest negative number by -1 the result is still the largest
  negative number. This is because the largest positive number in a
  two's complement system is the (largest negative number * -1) - 1.
  For example if an int is 8 bits, the largest negative number is
  -128 (1000 0000) and the largest position number is 127 (0111 1111).
  If we switch the sign of -128, we have +128, which we cannot
  represent because it is larger than the largest possible positive
  number. +128 is (1000 0000), but because we are working with a signed
  integer, this value is actually interpreted at -128. */

#include <stdio.h>
#include <limits.h>

void itoa(int n, char s[]);
void itoa2(int n, char s[]);
void reverse(char s[]);
void swap_char(char s[], int i1, int i2);

int main()
{
  char s[5000];
  itoa2(INT_MAX, s);
  printf("%s\n", s);
  itoa2(INT_MIN, s);
  printf("%s\n", s);
}

/* convert n to characters in s */
void itoa(int n, char s[])
{
  int i, sign;
  if ((sign = n) < 0) /* record sign */
    n = -n; /* make n positive */
  i = 0;
  do {
    s[i++] = n % 10 + '0'; /* get next digit */
  } while ((n /= 10) > 0); /* delete it */
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

/* convert n to characters in s */
void itoa2(int n, char s[])
{
  int i, sign;
  i = 0;
  sign = (n < 0) ? -1 : 1;
  do {
    s[i++] = ((n % 10) * sign) + '0';
  } while ((n /= 10) != 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

/* reverse string */
void reverse(char s[])
{
  int size, i, temp;
  for (size = 0; s[size] != '\0'; ++size);
  for (i = 0; i < size / 2; ++i)
    swap_char(s, i, size - 1 - i);
}

/* swap characters in s by index */
void swap_char(char s[], int i1, int i2)
{
  int temp;
  temp = s[i1];
  s[i1] = s[i2];
  s[i2] = temp;
}