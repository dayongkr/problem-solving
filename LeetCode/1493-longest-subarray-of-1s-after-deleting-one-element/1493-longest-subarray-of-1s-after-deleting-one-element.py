class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        prevZeroIndex = -1
        left = 0
        result = 0

        for right, rightNum in enumerate(nums):
            if rightNum == 0:
                print(left, right, result)
                result = max(result, right - left - 1)
                left = prevZeroIndex + 1
                prevZeroIndex = right

            if right + 1 == len(nums):
                result = max(result, right - left)
                
        
        return result