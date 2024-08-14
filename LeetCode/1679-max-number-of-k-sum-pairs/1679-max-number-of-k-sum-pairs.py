class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        if len(nums) == 1:
            return 0

        cnt = 0
        nums = list(sorted(nums))
        left, right = 0, len(nums) - 1


        while left < right:
            leftNum, rightNum = nums[left], nums[right]
            sumResult = leftNum + rightNum

            if sumResult == k:
                left += 1
                right -= 1
                cnt += 1
            elif sumResult > k:
                right -= 1
            else:
                left += 1


        return cnt