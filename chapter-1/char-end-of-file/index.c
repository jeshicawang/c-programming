#include <stdio.h>

/* Use ctrl + D to send EOF char
  Verifies that getchar() != EOF is 0 or 1 */

int main()
{
  int isNotEOF;
  isNotEOF = getchar() != EOF;
  printf("%d\n", isNotEOF);
}