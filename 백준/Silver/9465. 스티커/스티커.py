import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(2)]
    dp = [[0, 0] for _ in range(N + 1)]
    dp[1][0] = arr[0][0]
    dp[1][1] = arr[1][0]
    for i in range(2, N + 1):
        dp[i][0] = max(dp[i - 1][1], dp[i - 2][0], dp[i - 2][1]) + arr[0][i - 1]
        dp[i][1] = max(dp[i - 1][0], dp[i - 2][0], dp[i - 2][1]) + arr[1][i - 1]
    print(max(dp[N]))
