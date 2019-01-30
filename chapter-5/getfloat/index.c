/* Exercise 5-2. Write getfloat, the floating-point analog of getint.
  What type does getfloat return as its function value?
  
  Answer: still returns an int, since type is only used to see if
  something / anything is returned. */

#include <stdio.h>
#include <ctype.h>
#include "getch.c"

#define SIZE 100

int main()
{
  int i, n, getfloat(double *);
  double array[SIZE];
  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    ;
  for (i = n; i >= 0; i--)
    printf("%f\n", array[n-i]);
  return 0;
}

/* getfloat: get next float from input unto *pn */
int getfloat(double *pn)
{
  int c, sign, sawsign;
  double power;

  while (isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if ((sawsign = (c == '+' || c == '-')))
    c = getch();
  if (!isdigit(c)) {
    ungetch(c);
    if (sawsign) {
      ungetch(c);
      return 0;
    }
  }
  for (*pn = 0.0; isdigit(c); c = getch())
    *pn = 10.0 * *pn + (c - '0');
  if (c == '.')
    c = getch();
  for (power = 1.0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
    power *= 10.0;
  }
  *pn *= sign;
  *pn /= power;
  if (c != EOF)
    ungetch(c);
  return c;
}

