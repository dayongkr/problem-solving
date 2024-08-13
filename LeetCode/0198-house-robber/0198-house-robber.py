class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0 for _ in range(n + 1)]
        dp[1] = nums[0]

        for i in range(1, n):
            dp[i + 1] = max(dp[i - 1] + nums[i], dp[i - 2] + nums[i])

        return max(dp[n], dp[n-1])
