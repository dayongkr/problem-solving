class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        result = 0

        while left < right:
            height_left = height[left]
            height_right = height[right]
            result = max(result, min(height_left, height_right) * (right - left))

            if height_left > height_right:
                right -= 1
            else:
                left += 1

        return result
