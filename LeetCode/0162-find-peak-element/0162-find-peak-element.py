class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        length = len(nums)

        if length <= 2:
            maxNum = max(nums)
            return nums.index(maxNum)
        else:
            left, right = 0, length - 1

            while left <= right:
                mid = (right - left) // 2 + left

                if mid == 0:
                    return 0 if nums[0] > nums[1] else 1
                elif mid == length - 1:
                    return (
                        length - 1
                        if nums[length - 1] > nums[length - 2]
                        else length - 2
                    )
                elif nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]:
                    return mid
                elif nums[mid + 1] > nums[mid]:
                    left = mid + 1
                else:
                    right = mid - 1
