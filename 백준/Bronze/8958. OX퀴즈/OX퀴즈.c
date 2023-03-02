#include <stdio.h>

int main(void)
{
  int a, b;
  scanf("%d", &a);
  getchar();
  for (int i = 0; i < a; i++)
  {
    int score = 1, sum = 0;
    while (1)
    {
      char c;
      scanf("%c", &c);
      if (c == '\n')
      {
        break;
      }
      else if (c == 'O')
      {
        sum += score;
        score += 1;
      }
      else
      {
        score = 1;
      }
    }
    printf("%d\n", sum);
  }
}