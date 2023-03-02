#include <stdio.h>

int main(void)
{
  int a, b = 0, c = 0, arr[10] = {
                           0,
                       };
  for (int i = 0; i < 10; i++)
  {
    scanf("%d", &a);
    a = a % 42;
    for (int j = 0; j < 10; j++)
    {
      if (!c && !a)
      {
        b++;
        c++;
        break;
      }
      else if (arr[j] == a)
      {
        break;
      }
      else if (!arr[j])
      {
        arr[j] = a;
        b++;
        break;
      }
    }
  }
  printf("%d\n", b);
  return 0;
}