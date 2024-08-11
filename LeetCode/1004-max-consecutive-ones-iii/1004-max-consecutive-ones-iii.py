class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left = 0
        result = 0

        if nums[left] == 0 and k > 0:
            result = 1
            k -= 1

        for right in range(1, len(nums)):
            if nums[right] == 0:
                while k <= 0:
                    if nums[left] == 0:
                        k += 1
                    left += 1
                print(k)
                k -= 1
            
            result = max(right - left + 1, result)


        return result