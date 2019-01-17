#include <stdio.h>

int main() {
  int c, prevc;

  while ((c = getchar()) != EOF) {
    if (c != ' ' || prevc != ' ')
      putchar(c);
    prevc = c;
  }
}