#include <stdio.h>

/* Exercise 1-22. Write a program to "fold" long input lines into two or more shorter lines
  after the last non-blank character that occurs before the n-th column of
  input. Make sure your program does something intelligent with very long lines,
  and if there are no blanks or tabs before the specified column. */

#define MAX_LINE 50 /* maximum number of characters per line */

int get_line(char s[], int max_len);
void trim_and_print(char s[]);

int main()
{
  char line[MAX_LINE];

  while (get_line(line, MAX_LINE) > 0)
    trim_and_print(line);
  
  return 0;
}

int get_line(char s[], int max_len)
{
  int i, c;
  for (i = 0; i < max_len && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c != EOF)
    s[i++] = '\n';
  s[i] = '\0';
  return i;
}

void trim_and_print(char s[])
{
  int i;
  for (i = 0; s[i] != '\n'; ++i)
    ;
  for (--i; s[i] == ' ' || s[i] == '\t'; --i)
    ;
  if (i >= 0) {
    s[++i] = '\n';
    s[++i] = '\0';
  }
  printf("%s", s);
}
