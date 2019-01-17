/* Write an alternate version of squeeze(s1, s2) that deletes
  each character in s1 that matches any character in the string s2. */

#include <stdio.h>

#define MATCH 1
#define NO_MATCH 0

void squeeze(char s1[], char s2[]);

int main()
{
  char s1[] = "hello";
  squeeze(s1, "le");
  printf("%s should be ho\n", s1);

  char s2[] = "abcdefghijklmnopqrstuvwxyz";
  squeeze(s2, "bdghjklmnoprvyz");
  printf("%s should be acefiqstuwx\n", s2);

  return 0;
}

void squeeze(char s1[], char s2[])
{
  int i, j, i2, state;
  state = NO_MATCH;

  for (i = j = 0; s1[i] != '\0'; i++) {
    for (i2 = 0; s2[i2] != '\0'; i2++) {
      if (s1[i] == s2[i2]) {
        state = MATCH;
        break;
      }
    }
    if (state == NO_MATCH)
      s1[j++] = s1[i];
    state = NO_MATCH;
  }
  s1[j] = '\0';
}