import sys

input = sys.stdin.readline

n = int(input())

dp = [0, 1]

for _ in range(n):
    num = int(input())
    for i in range(len(dp), num + 1):
        dp.append(dp[i - 1] + dp[i - 2])
    print(f"{dp[num - 1 if num != 0 else 1]} {dp[num]}")
