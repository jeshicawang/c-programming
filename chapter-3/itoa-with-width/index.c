/* Exercise 3-6. Write a version of itoa that accepts three arguments
  instead of two. The third argument is a minimum field width; the
  converted number must be padded with blanks on the left if nexessary
  to make it wide enough. */

#include <stdio.h>
#include <limits.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);
void swap_char(char s[], int i1, int i2);

int main()
{
  char s[5000];
  itoa(INT_MAX, s, 8);
  printf("%s\n", s);
  itoa(INT_MIN, s, 8);
  printf("%s\n", s);
  itoa(INT_MAX, s, 15);
  printf("%s\n", s);
  itoa(INT_MIN, s, 15);
  printf("%s\n", s);
}

/* convert n to characters in s */
void itoa(int n, char s[], int w)
{
  int i, sign;
  i = 0;
  sign = (n < 0) ? -1 : 1;
  do {
    s[i++] = ((n % 10) * sign) + '0';
  } while ((n /= 10) != 0);
  if (sign < 0)
    s[i++] = '-';
  for (; i < w; s[i++] = ' ')
    ;
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