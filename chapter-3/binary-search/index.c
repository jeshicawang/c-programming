/* Exercise 3-1. Our binary search makes two tests inside the loop,
  when one would suffice (at the price of more tests outside). Write
  a version with only one test inside the loop and measure the
  difference in run time. */

#include <stdio.h>
#include <time.h>

#define LENGTH 8

int binarysearch1(int x, int v[], int n);
int binarysearch2(int x, int y[], int n);

int main()
{
  int v[] = {0,1,2,3,4,5,6,7};
  clock_t start, end;
  double cpu_time_used;

  if (binarysearch1(6, v, LENGTH) == 6
    && binarysearch1(12, v, LENGTH) == -1
    && binarysearch2(6, v, LENGTH) == 6
    && binarysearch2(12, v, LENGTH) == -1)
    printf("TEST CASES PASS\n");
  else
    printf("TEST CASES FAIL\n");

  int i, n[20000];
  for (i = 0; (n[i] = i) < 20000; i++)
    ;
  
  start = clock();
  binarysearch1(2, n, LENGTH);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("binarysearch1 took %f seconds\n", cpu_time_used);

  start = clock();
  binarysearch2(2, n, LENGTH);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("binarysearch2 took %f seconds\n", cpu_time_used);

  printf("the second implementation of binarysearch is typically faster\n");
}

int binarysearch1(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else /* found match */
      return mid;
  }
  return -1; /* no match */
}

int binarysearch2(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (x != v[mid = (low + high) / 2] && low <= high)
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  return (x != v[mid]) ? -1 : mid;
}