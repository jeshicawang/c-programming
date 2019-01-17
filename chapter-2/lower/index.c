/* Exercise 2-10. Rewrite the function lower, which converts upper
  case letters to lower case, with a conditional expression instead
  of if-else. */

#include <stdio.h>

void lower(char s[]);

int main()
{
  char s[] = "HELLO";
  lower(s);
  printf("%s\n", s);
  return 0;
}

void lower(char s[])
{
  int i, c;
  for (i = 0; (c = s[i]) != '\0'; i++) {
    s[i] = (c >= 'A' || c <= 'Z') ? ('a' + c - 'A') : c;
  }
}