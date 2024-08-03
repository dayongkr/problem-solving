from functools import reduce


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [1]
        n = len(nums)

        for i in range(n - 1):
            result.append(nums[i] * result[i])

        num = nums[n - 1]

        for i in range(n - 2, -1, -1):
            result[i] *= num
            num *= nums[i]
        
        return result
