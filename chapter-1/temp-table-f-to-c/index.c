#include <stdio.h>

/* print Farenheit-Celsius table for fahr = 0, 20, ..., 300; */

int main()
{
  float fahr, cels;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  fahr = lower;

  printf("Fahrenheit to Celcius Conversion Table\n");

  while (fahr <= upper) {
    cels = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f\t%6.1f\n", fahr, cels);
    fahr = fahr + step;
  }
}