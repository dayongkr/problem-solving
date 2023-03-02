#include <stdio.h>
#include <math.h>

int main(void)
{
  int a, b, v;
  scanf("%d %d %d", &a, &b, &v);
  v = v - a;
  printf("%d\n", (int)ceil((double)v / (double)(a - b)) + 1);

  return 0;
}
