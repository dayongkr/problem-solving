#include <stdio.h>

int factorial(int num)
{
  if (num == 0)
  {
    return 1;
  }
  return num * factorial(num - 1);
}

int main(void)
{
  int n, k;
  scanf("%d %d", &n, &k);
  printf("%d\n", factorial(n) / (factorial(k) * factorial(n - k)));
  return 0;
}