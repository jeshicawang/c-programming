/* Exercise 4-1. Write the function strrindex(s,t), which returns the
  position of the rightmost occurrence of t in s, or -1 if there is none. */

#include <stdio.h>

int strrindex(char s[], char t);

int main() 
{
  printf("%d should be 3\n", strrindex("hello", 'l'));
  printf("%d should be -1\n", strrindex("hello", 'f'));
  return 0;
}

int strrindex(char s[], char t)
{
  int i, ri;
  for (ri = -1, i = 0; s[i] != '\0'; i++)
    if (s[i] == t)
      ri = i;
  return ri;
}