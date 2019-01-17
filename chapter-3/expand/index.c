/* Exercise 3-3. Write a function expand(s1,s2) that expands shorthand
  notations like a-z in the string s1 into the equivilent complete list
  acb...xyz in s2. Allow for letters of either case and digits, and be
  prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that
  a leading or trailing - is taken literally. */

#include <stdio.h>

void expand(char s1[], char s2[]);

int main()
{
  char s2[5000];
  expand("-a-c-z0-9-", s2);
  printf("%s\n", s2);
  return 0;
}

void expand(char s1[], char s2[])
{
  int i, j, x, p, c, n;
  for (i = j = 0; (c = s1[i]) != '\0'; p = c, i++, j++) {
    if (c == '-' && i > 0 && (n = s1[i+1]) != '\0' && n != '-') {
      for (x = p + 1; x < n; x++, j++)
        s2[j] = x;
      j--;
    } else
      s2[j] = c;
  }
  s2[j] = '\0';
}