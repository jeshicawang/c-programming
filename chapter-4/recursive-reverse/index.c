/* Exercise 4-13. Write a recursive version of the function reverse(s),
  which reverses the string s in place. */

#include <stdio.h>

void reverse(char s[]);

int main()
{
  char s[] = "reversethisstring";
  reverse(s);
  printf("%s\n", s);
  reverse(s);
  printf("%s\n", s);
  return 0;
}

void reverse(char s[])
{
  static int lower;
  static int upper;
  char temp;
  if (upper == 0) {
    for (; s[upper+1] != '\0'; upper++);
  }
  if (lower < upper) {
    temp = s[upper];
    s[upper--] = s[lower];
    s[lower++] = temp;
    reverse(s);
  } else {
    lower = 0;
    upper = 0;
  }
}