class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        slide = sum(nums[:k])
        max_sum = slide

        for i in range(k, len(nums)):
            slide += -nums[i - k] + nums[i]
            max_sum = max(max_sum, slide)

        return max_sum / k
