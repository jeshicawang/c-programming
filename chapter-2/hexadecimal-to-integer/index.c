/* Exercise 2-3. Write the function htoi(s), which converts a string of
  hexadecimal digits (including an optional 0x or 0X) into its equivilent
  integer value. The allowable digits are 0 through 9, a through f, and
  A through F. */

#include <stdio.h>
#include <ctype.h>

#define HEX_BASE 16

int htoi(char s[]);

int main()
{
  printf("%d should be 15\n", htoi("0XF"));
  printf("%d should be 15\n", htoi("F"));
  printf("%d should be 100\n", htoi("64"));
  printf("%d should be 2367\n", htoi("0x93F"));
  return 0;
}

int htoi(char s[])
{
  int i, base, result, num;
  base = 1;
  result = 0;

  for (i = 0; s[i] != '\0'; i++)
    ;

  while (i > 0 &&
    (isdigit(s[i-1]) || (s[i-1] >= 'a' && s[i-1] <= 'f') || (s[i-1] >= 'A' && s[i-1] <= 'F'))
  ) {
    if (isdigit(s[i-1]))
      num = s[i-1] - '0';
    else
      num = s[i-1] - 'A' + 10;
    result += (num * base);
    base *= HEX_BASE;
    --i;
  }

  return result;
}