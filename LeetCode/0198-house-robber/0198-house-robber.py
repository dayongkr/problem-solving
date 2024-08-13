class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0 for _ in range(n + 1)]
        dp[1] = nums[0]

        if n >= 2:
            dp[2] = nums[1]

        if n >= 3:
            dp[3] = dp[1] + nums[2]

        if n >= 4:
            for i in range(3, n):
                dp[i + 1] = max(dp[i - 1] + nums[i], dp[i - 2] + nums[i])

        return max(dp)
