#include <stdio.h>

/* Exercise 1-18. Write a program to remove trailing blanks and tabs
  from each line of input, and to delete entirely blank lines. */

#define MAXLINE 1000 /* maximum input line size */

int get_and_trim_line(char line[], int maxline);

int main()
{
  int len;            /* current line length */
  char line[MAXLINE]; /* current input line */

  while((len = get_and_trim_line(line, MAXLINE)) > 0)
    if (len > 1)
      printf("%s", line);

  return 0;
}

/* get_and_trim_line: read a line into s removing trailing blanks and tabs
  returning new line length */
int get_and_trim_line(char s[], int lim)
{
  int c, i, bi;
  char blanks[lim];
  bi = 0;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    if (c == ' ' || c == '\t')
      blanks[bi++] = c;
    else {
      s[i] = c;
      for (bi = bi; bi > 0; --bi)
        s[i - bi] = blanks[bi - 1];
    }

  i = i - bi;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}  
