#include <stdio.h>

int main(void)
{
  char a[4], b[4], *max;
  scanf("%s %s", a, b);
  for (int i = 2; i >= 0; i--)
  {
    if (a[i] > b[i])
    {
      max = a;
      break;
    }
    else if (a[i] < b[i])
    {
      max = b;
      break;
    }
  }
  printf("%c%c%c\n", max[2], max[1], max[0]);
  return 0;
}
