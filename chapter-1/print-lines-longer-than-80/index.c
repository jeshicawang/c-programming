#include <stdio.h>

/* Exercise 1-17. Write a program to print
  all input lines longer than 80 characters */

#define MAXLINE   1000 /* maximum input line size */
#define MINLENGTH   80 /* minimum number of characters a line needs to be printed */

int get_line(char line[], int maxline);

/* print longest input line */
int main()
{
  int len;               /* current line length */
  char line[MAXLINE];    /* current input line */

  while((len = get_line(line, MAXLINE)) > 0)
    if (len > MINLENGTH)
      printf("%s", line);

  return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    if (i < lim - 1)
      s[i] = c;

  if (c == '\n') {
    if (i < lim - 1)
      s[i] = c;
    ++i;
  }

  if (i < lim) {
    s[i] = '\0';
  } else {
    s[lim - 1] = '\0';
  }
  return i;
}