/* Exercise 2-2.
  for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
  Write a loop equivilent to the for loop above without using && or ||. */

#include <stdio.h>

int main()
{
  int i, c, lim;
  lim = 50;
  char s[lim];

  for (i = 0; i < lim - 1; ++i) {
    if ((c = getchar()) == '\n')
      break;
    else if (c == EOF)
      break;
    s[i] = c;
  }

  return 0;
}
