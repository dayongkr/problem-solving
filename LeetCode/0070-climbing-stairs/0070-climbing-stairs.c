int climbStairs(int n)
{
  int result = 0, n_1 = 1, n_2 = 0;
  for (int i = 0; i < n; i++)
  {
    result = n_1 + n_2;
    n_2 = n_1;
    n_1 = result;
  }
  return result;
}