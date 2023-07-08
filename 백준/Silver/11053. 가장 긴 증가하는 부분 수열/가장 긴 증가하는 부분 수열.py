import sys

input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
dp = [1 for _ in range(1001)]

for i in range(1, N):
    MAX = 1
    for j in range(i):
        if arr[i] > arr[j]:
            MAX = max(MAX, dp[arr[j]] + 1)
    dp[arr[i]] = MAX

print(max(dp))
