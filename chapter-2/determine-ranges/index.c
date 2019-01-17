/* Exercise 2-1. Write a program to determine the ranges of char, short, int
  and long variables, both signed and unsigned, by printing appropriate
  values from standard headers and by direct computation. Harder if you
  compute them: determine the ranges of the various floating point types. */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#define SHRT_BIT 16 /* bits in a short int */
#define INT_BIT 32 /* bits in a standard int */

void analyze_char(void);
void analyze_short(void);
void analyze_int(void);
void analyze_long(void);
void analyze_float(void);
void analyze_double(void);

int main()
{
  analyze_char();
  analyze_short();
  analyze_int();
  analyze_long();
  analyze_float();
  analyze_double();
  return 0;
}

void analyze_char(void)
{
  signed char char_min, char_max;
  unsigned char uchar_max;

  char_min = pow(2, CHAR_BIT - 1) * -1;
  char_max = pow(2, CHAR_BIT - 1) - 1;
  uchar_max = pow(2, CHAR_BIT) - 1;

  printf("COMPUTED\n");
  printf("char signed-- min %d, max %d\n", char_min, char_max);
  printf("char unsigned-- min %u, max %u\n", 0, uchar_max);
  printf("LIMITS HEADER\n");
  printf("char signed-- min %d, max %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("char unsigned-- min %u, max %d\n\n", 0, UCHAR_MAX);
}

void analyze_short(void)
{
  signed short shrt_min, shrt_max;
  unsigned short ushrt_max;

  shrt_min = pow(2, SHRT_BIT - 1) * -1;
  shrt_max = pow(2, SHRT_BIT - 1) -1;
  ushrt_max = pow(2, SHRT_BIT) - 1;

  printf("COMPUTED\n");
  printf("short signed-- min %d, max %d\n", shrt_min, shrt_max);
  printf("short unsigned-- min %u, max %u\n", 0, ushrt_max);
  printf("LIMITS HEADER\n");
  printf("short signed-- min %d, max %d\n", SHRT_MIN, SHRT_MAX);
  printf("short unsigned-- min %u, max %u\n\n", 0, USHRT_MAX);
}

void analyze_int(void)
{ 
  signed int int_min, int_max;
  unsigned int uint_max;

  int_min = pow(2, INT_BIT - 1) * -1;
  int_max = pow(2, INT_BIT - 1) - 1;
  uint_max = pow(2, INT_BIT) - 1;

  printf("COMPUTED\n");
  printf("int signed-- min %d, max %d\n", int_min, int_max);
  printf("int unsigned-- min %u, max %u\n", 0, uint_max);
  printf("LIMITS HEADER\n");
  printf("int signed-- min %d, max %d\n", INT_MIN, INT_MAX);
  printf("int unsigned-- min %u, max %u\n\n", 0, UINT_MAX);
}

void analyze_long(void)
{
  double long_min, long_max;
  double ulong_max;

  long_min = pow(2, LONG_BIT - 1) * -1;
  long_max = pow(2, LONG_BIT - 1) - 1;
  ulong_max = pow(2, LONG_BIT) - 1;

  printf("COMPUTED\n");
  printf("long signed-- min %.0f, max %.0f\n", long_min, long_max);
  printf("long unsigned-- min %d, max %.0f\n", 0, ulong_max);
  printf("LIMITS HEADER\n");
  printf("long signed-- min %ld, max %ld\n", LONG_MIN, LONG_MAX);
  printf("long unsigned-- min %lu, max %lu\n\n", (unsigned long)0, ULONG_MAX);
}

void analyze_float(void)
{
  printf("LIMITS HEADER\n");
  printf("float-- min %.0f, max %.0f\n\n", FLT_MIN, FLT_MAX);
}

void analyze_double(void)
{
  printf("LIMITS HEADER\n");
  printf("double-- min %.0f, max %.0f\n\n", DBL_MIN, DBL_MAX);
}
