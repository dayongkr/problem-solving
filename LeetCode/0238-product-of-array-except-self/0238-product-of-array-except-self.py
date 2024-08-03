from functools import reduce


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [1]
        suffix = [1]
        n = len(nums)

        for i in range(n):
            prefix.append(nums[i] * prefix[i])
            suffix.append(nums[n - i - 1] * suffix[i])
        print(prefix)
        print(suffix)

        result = []

        for i in range(n):
            result.append(prefix[i] * suffix[n - i - 1])
        
        return result
