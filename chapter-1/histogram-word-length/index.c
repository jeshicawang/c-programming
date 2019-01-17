#include <stdio.h>
 
#define IN                1  /* inside of a word */
#define OUT               0  /* outside of a word */
#define MAX_WORD_LENGTH  30  /* arbitrary max length of word */

/* Write a program to print a histogram of the lengths of words in its input.
  It is easy to draw the histogram with the bars horizontal;
  a vertical orientation is more challenging. */
int main()
{
  int c, i, il, nc, state;
  int wordLength[MAX_WORD_LENGTH + 1];
  state = OUT;
  nc = 0;

  for (i = 0; i <= MAX_WORD_LENGTH; ++i)
    wordLength[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (nc > 0)
        ++wordLength[nc];
      state = OUT;
      nc = 0;
    } else {
      state = IN;
      ++nc;
    }
  }

  if (nc > 0)
    ++wordLength[nc];

  for (i = 1; i <= MAX_WORD_LENGTH; ++i) {
    printf("%2d ", i);
    for (il = 0; il < wordLength[i]; ++il)
      putchar('-');
    putchar('\n');
  }
}