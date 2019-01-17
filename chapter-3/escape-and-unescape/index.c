/* Exercise 3-2. Write a function escape(s,t), that converts characters like
  newline and tab into visible escape sequences like \n and \t as it copies
  the string t to s. Use a switch. Write a function for the other direction
  as well, converting escape sequences into the real characters. */

#include <stdio.h>

#define MAXLEN 5000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
  char s[MAXLEN];

  printf("ESCAPE\n");
  escape(s, "heeeyyyaaa\nthis should be on a new line\n\tthis should have a tab before");
  printf("%s\n", s);

  printf("UNESCAPE\n");
  unescape(s, "heeeyyyaaa\\nthis should be on a new line\\n\\tthis should have a tab before");
  printf("%s\n", s);

  return 0;
}

void escape(char s[], char t[])
{
  int c, i, j;
  for (i = j = 0; (c = t[i]) != '\0'; i++) {
    switch (c) {
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    default:
      s[j++] = c;
      break;
    }
  }
  s[j] = '\0';
}

void unescape(char s[], char t[])
{
  int c, i, j;
  for (i = j = 0; (c = t[i++]) != '\0'; j++) {
    switch (c) {
    case '\\':
      switch (t[i]) {
      case 't':
        s[j] = '\t';
        i++;
        break;
      case 'n':
        s[j] = '\n';
        i++;
        break;
      default:
        s[j] = c;
        break;
      }
      break;
    default:
      s[j] = c;
      break;
    }
  }
  s[j] = '\0';
}