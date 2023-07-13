import sys

input = sys.stdin.readline

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
dp = [0 for _ in range(N * N + 1)]
for i in range(N):
    for j in range(N):
        dp[i * N + j + 1] = dp[i * N + j] + arr[i][j]

for _ in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    y_min = min(y1, y2)
    y_max = max(y1, y2)
    s = 0
    for i in range(x1, x2 + 1):
        s += dp[(i - 1) * N + y_max] - dp[(i - 1) * N + y_min - 1]
    print(s)
