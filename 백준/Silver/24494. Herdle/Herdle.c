#include <stdio.h>

int main(void)
{
  char a[10], b[10];
  int x = 0, y = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      scanf("%c", &a[i * 3 + j]);
    }
    getchar();
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      scanf("%c", &b[i * 3 + j]);
      if (a[i * 3 + j] == b[i * 3 + j])
      {
        x++;
        a[i * 3 + j] = 0;
        b[i * 3 + j] = 0;
      }
    }
    getchar();
  }

  for (int i = 0; i < 10; i++)
  {
    if (b[i] == 0)
    {
      continue;
    }
    for (int j = 0; j < 10; j++)
    {
      if (a[j] != 0 && a[j] == b[i])
      {
        y++;
        a[j] = 0;
        break;
      }
    }
  }

  printf("%d\n", x);
  printf("%d\n", y);
}