import sys

input = sys.stdin.readline

N = int(input())
dp = [1 for _ in range(50001)]
temp = 0
dp[0] = 0
for i in range(1, N + 1):
    if i == (temp + 1) ** 2:
        temp += 1
    t_min = 50000
    for j in range(temp, 0, -1):
        if dp[i - j ** 2] < t_min:
            t_min = dp[i - j ** 2]
    dp[i] += t_min

print(dp[N])