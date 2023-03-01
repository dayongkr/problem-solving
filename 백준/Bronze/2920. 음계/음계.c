#include <stdio.h>

int main(void)
{
  int arr[8];
  int type;
  scanf("%d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7]);

  type = arr[0] == 1 ? 1 : arr[0] == 8 ? 2
                                       : 0;

  if (type)
  {
    int pre = arr[0];
    if (type == 1)
    {
      for (int i = 1; i < 8; i++)
      {
        if (pre > arr[i])
        {
          printf("mixed\n");
          return 0;
        }
        pre = arr[i];
      }
      printf("ascending\n");
    }
    else
    {
      for (int i = 1; i < 8; i++)
      {
        if (pre < arr[i])
        {
          printf("mixed\n");
          return 0;
        }
        pre = arr[i];
      }
      printf("descending\n");
    }
  }
  else
  {
    printf("mixed\n");
  }
  printf("\n");
  return 0;
}