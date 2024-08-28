import sys

input = sys.stdin.readline

N = int(input())

dp = [0, 1]
cur = 1
squared = cur ** 2
nextSquared = (cur + 1) ** 2

for i in range(2, N + 1):
    if i == nextSquared:
        cur += 1
        squared = nextSquared
        nextSquared = (cur + 1) ** 2
    dp.append(min([dp[i - num ** 2] + 1 for num in range(1, cur + 1)]))

print(dp[N])
