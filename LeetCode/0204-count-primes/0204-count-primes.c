int countPrimes(int n)
{
  int result = 0;
  int *arr = (int *)calloc(n + 1, sizeof(int));

  for (int i = 2; i < n; i++)
  {
    if (!arr[i])
    {
      result++;
      int j = 2;
      while (i * j <= n)
      {
        arr[i * j] = 1;
        j++;
      }
    }
  }
  free(arr);
  return result;
}