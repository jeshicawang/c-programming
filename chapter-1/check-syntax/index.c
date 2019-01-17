#include <stdio.h>

/* Exercise 1-24. Write a program to check a C program for rudimentary syntax errors
  unbalanced parentheses, brackets and braces. Don't forget about quotes, both single
  and double, excape sequences, and comments. (This program is hard if you do it in
  full generality.) */

#define MAX_SYNTAX 50 /* max length for the syntax array */
#define ERROR 1 /* file has syntax error */ 
#define OKAY 0 /* file has no syntax errors */

int main()
{
  int c, next, i, state;
  char syntax[50];
  c = getchar();
  i = 0;
  state = OKAY;

  while ((next = getchar()) != EOF) {
    if (i > 0 && c == syntax[i-1] && (c != '*' || next == '/'))
      --i;
    else if (i > 0 && syntax[i-1] == '*') {
      /* do nothing */
    } else if (i > 0 && (syntax[i-1] == '\'' || syntax[i-1] == '"')) {
      if (c == '\\')
        next = getchar();
    } else if (c == '/' && next == '*')
      syntax[i++] = '*';
    else if (c == '\'' || c == '"')
      syntax[i++] = c;
    else if (c == '(')
      syntax[i++] = ')';
    else if (c == '[')
      syntax[i++] = ']';
    else if (c == '{')
      syntax[i++] = '}';
    else if (c == ')' || c == ']' || c == '}' || c == '\'' || c == '"')
      state = ERROR;
    c = next;
  }

  if (state == ERROR || i < 0)
    printf("SYNTAX ERROR\n");
  else
    printf("SYNTAX OKAY\n");

  return 0;
}