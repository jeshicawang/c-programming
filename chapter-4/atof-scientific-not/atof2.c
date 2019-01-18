#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* atof2: convert string s to double, handling scientific notation */
double atof2(char s[])
{
  double val, power;
  int i, sign, e, esign;

  for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power--;
  }
  if (s[i] == 'e' || s[i] == 'E')
    i++;
  esign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (e = 0; isdigit(s[i]); i++)
    e = 10 * e + (s[i] - '0');
  power += (esign * e);
  return sign * val * pow(10, power);
}