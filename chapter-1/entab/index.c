#include <stdio.h>

/* Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of
  tabs and blanks to achieve the same spacing. Use the same tab stops as for detab
  When either a tab or a single blank would suffice to reach a tab stop, which should
  be given preference? */

#define TAB_LENGTH 2 /* number of spaces to a single tab */

int main()
{
  int i, c;
  i = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++i;
    else {
      while (i > (TAB_LENGTH - 1)) {
        putchar('\t');
        i = i - TAB_LENGTH;
      }
      while (i > 0) {
        putchar(' ');
        --i;
      }
      putchar(c);
    }
  }

  putchar('\n');
}