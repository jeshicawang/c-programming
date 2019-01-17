#include <stdio.h>

/* print Celsius-Fahrenheit table for cels = 0, 20, ..., 300; */

int main()
{
  float cels, fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  cels = lower;

  printf("Celcius to Fahrenheit Conversion Table\n");

  while (cels <= upper) {
    fahr = cels * (9.0 / 5.0) + 32;
    printf("%3.0f\t%3.0f\n", cels, fahr);
    cels = cels + step;
  }
}