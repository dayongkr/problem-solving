import sys

input = sys.stdin.readline

t = int(input())
dp = [0] * 12
dp[0] = 1
dp[1] = 1
dp[2] = 2
max_n = 3
for _ in range(t):
    n = int(input())
    for i in range(max_n, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
    if n > max_n:
        max_n = n
    print(dp[n])
