#include <stdio.h>

int main(void)
{
  int a, b = 0;
  scanf("%d", &a);
  for (int i = 0; i < a; i++)
  {
    int c;
    scanf("%1d", &c);
    b += c;
  }
  printf("%d\n", b);
}