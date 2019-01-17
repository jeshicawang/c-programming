#include <stdio.h>

/* Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
  of blanks to space to the next tab stop. Assume a fixed set of tab stops,
  say every n columns. Should n be a variable of a symbolic parameter? */

#define TAB_LENGTH 2 /* number of spaces to a single tab */

int main()
{
  int i, c;

  while ((c = getchar()) != EOF) {
    if (c != '\t')
      putchar(c);
    else
      for (i = 0; i < TAB_LENGTH; i++)
        putchar(' ');
  }

  putchar('\n');
}