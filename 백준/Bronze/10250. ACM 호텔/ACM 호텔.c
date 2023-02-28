#include <stdio.h>
#include <math.h>

int main(void)
{
  int a;
  scanf("%d", &a);
  for (int i = 0; i < a; i++)
  {
    double h, w, n;
    scanf("%lf %lf %lf", &h, &w, &n);
    printf("%d", (int)n % (int)h != 0 ? (int)n % (int)h : (int)h);
    (int)ceil(n / h) < 10 ? printf("0%d", (int)ceil(n / h)) : printf("%d", (int)ceil(n / h));
    printf("\n");
  }
}