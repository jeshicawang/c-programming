#include <stdio.h>

/* Exercise 1-19. Write a function reverse(s) that reverses the character string s.
  Use it to write a program that reverses its input a line at a time. */

#define MAXLINE 1000

int get_line(char s[], int lim);
void reverse(char s[]);
void swap_char(char s[], int i1, int i2);

int main()
{
  char line[MAXLINE];

  while (get_line(line, MAXLINE) > 0) {
    reverse(line);
    printf("%s\n", line);
  }

  return 0;
}

int get_line(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  if (c == '\n')
    ++i;
  return i;
}

void reverse(char s[])
{
  int size, i, temp;

  for (size = 0; s[size] != '\0'; ++size);

  for (i = 0; i < size / 2; ++i)
    swap_char(s, i, size - 1 - i);
}

void swap_char(char s[], int i1, int i2)
{
  int temp;
  temp = s[i1];
  s[i1] = s[i2];
  s[i2] = temp;
}