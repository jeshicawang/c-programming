#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

double convertFahrToCels(int fahr);

int main() {
  int fahr;

  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
    printf("%3d\t%6.1f\n", fahr, convertFahrToCels(fahr));
  }

  return 0;
}

double convertFahrToCels(int fahr) {
  return (5.0 / 9.0) * (fahr - 32.0);
}
