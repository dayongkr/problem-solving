#include <stdio.h>

int main(void)
{
  int a, min, max;
  scanf("%d", &a);
  scanf("%d", &min);
  max = min;
  for (int i = 1; i < a; i++)
  {
    int b;
    scanf("%d", &b);
    if (b < min)
    {
      min = b;
    }
    else if (b > max)
    {
      max = b;
    }
  }
  printf("%d %d\n", min, max);
}