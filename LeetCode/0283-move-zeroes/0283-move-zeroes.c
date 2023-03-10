void moveZeroes(int *nums, int numsSize)
{
  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i] == 0)
    {
      for (int j = i; j < numsSize; j++)
      {
        if (nums[j] != 0)
        {
          nums[i] = nums[j];
          nums[j] = 0;
          break;
        }
      }
    }
  }
}