class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        length = len(nums)
        left, right = 0, length - 1

        while left < right - 1:
            mid = (right - left) // 2 + left

            if nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]:
                return mid
            elif nums[mid + 1] > nums[mid]:
                left = mid + 1
            else:
                right = mid - 1
        
        return left if nums[left] > nums[right] else right
