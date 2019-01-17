#include <stdio.h>

int main() {
  int c;
  long bc, tc, lc;

  bc = 0;
  tc = 0;
  lc = 0;
  
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++bc;
    if (c == '\t')
      ++tc;
    if (c == '\n')
      ++lc;
  }

  printf("%ld blanks\n%ld tabs\n%ld lines\n", bc, tc, lc);
}