import sys

input = sys.stdin.readline

n, m = map(int, input().split(" "))

dp = [item for item in map(int, input().split(" "))]
result = ""

dp.insert(0, 0)
max_e = 0

for _ in range(m):
    s, e = map(int, input().split(" "))
    if e > max_e:
        for i in range(max_e + 1, e + 1):
            dp[i] += dp[i - 1]
        max_e = e
    print(dp[e] - dp[s - 1])
