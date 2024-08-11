class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left, right = 0, 0
        length = len(nums)
        result = 0

        while right < length:
            if nums[right] == 0:
                while k <= 0:
                    if nums[left] == 0:
                        k += 1
                    left += 1
                k -= 1
            
            result = max(right - left + 1, result)
            right = max(left, right + 1)


        return result