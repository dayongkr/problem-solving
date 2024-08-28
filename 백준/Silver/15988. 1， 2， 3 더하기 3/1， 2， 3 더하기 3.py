import sys

input = sys.stdin.readline

T = int(input())

dp = [0 for _ in range(1000001)]
dp[1], dp[2], dp[3] = 1, 2, 4
maxN = 4

for _ in range(T):
    N = int(input())
    for i in range(maxN, N + 1):
        dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009
    maxN = max(maxN, N)
    print(dp[N] % 1000000009)
