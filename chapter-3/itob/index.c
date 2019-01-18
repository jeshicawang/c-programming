/* Exercise 3-5. Write the function itob(n,s,b) that converts the integer
  n into a base b character representation in the string s. In particular,
  itob(n,s,16) formats n as a hexadecimal integer in s. */

#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);
void swap_char(char s[], int i1, int i2);

int main()
{
  char s[5000];
  itob(1000, s, 2);
  printf("base2, %s\n", s);
  itob(1000, s, 8);
  printf("base8, %s\n", s);
  itob(1000, s, 10);
  printf("base10, %s\n", s);
  itob(1000, s, 16);
  printf("base16, %s\n", s);
  return 0;
}

void itob(int n, char s[], int b)
{
  int i, x, sign;
  i = 0;
  do {
    s[i++] = ((x = n % b) < 10) ?
      (x + '0') :
      (x - 10 + 'a');
  } while ((n /= b) > 0);
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