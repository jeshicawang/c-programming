#include <stdio.h>

#define TOTAL_CHARS 52 /* total characters A-Z and a-z */

/* Write a program to print a histogram of the frequencies
  of different characters in its input. */
int main()
{
  int c, i, ic, label;
  int chars[TOTAL_CHARS];

  for (i = 0; i < TOTAL_CHARS; ++i)
    chars[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c >= 'A' && c <= 'Z')
      ++chars[c - 'A'];
    else if (c >= 'a' && c <= 'z')
      ++chars[c - 'a' + (TOTAL_CHARS / 2)];
  }

  for (i = 0; i < TOTAL_CHARS; ++i) {
    if (i < (TOTAL_CHARS / 2))
      label = 'A' + i;
    else
      label = 'a' + i - (TOTAL_CHARS / 2);
    printf("%c ", label);
    for (ic = 0; ic < chars[i]; ++ic)
      putchar('-');
    putchar('\n');
  }
}