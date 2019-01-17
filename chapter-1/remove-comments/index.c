#include <stdio.h>

/* Exercise 1-23. Write a program to remove all comments from a C program.
  Do not forget to handle quoted strings and character constants properly.
  C comments do not nest. "this shoud not be printed" */

#define IN  1 /* inside a comment */
#define OUT 0 /* outside a comment */

int main()
{
  int c, next, state;
  char match[2];
  state = OUT;
  c = getchar();

  while ((next = getchar()) != EOF) {
    if (match[0] == '\0' && (c == '\'' || c == '"')) {
      match[0] = c;
      match[1] = '\0';
    } else if (match[0] == '\0' && c == '/' && next == '*') {
      match[0] = '*';
      match[1] = '/';
      state = IN;
      next = getchar();
    } else if (match[0] != '\0' && match[1] == '\0' && c == '\\') {
      putchar(c);
      c = next;
      next = getchar();
    } else if (match[0] != '\0' && c == match[0] && (c != '*' || next == match[1])) {
      if (c == '*') {
        state = OUT;
        c = getchar();
        next = getchar();
      }
      match[0] = '\0';
    }
    if (state == OUT)
      putchar(c);
    c = next;
  }
} /* this should not be printed */