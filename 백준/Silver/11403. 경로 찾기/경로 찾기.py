import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
adj_arr = [list(map(int, input().split())) for _ in range(N)]

for k in range(N):
    for i in range(N):
        for j in range(N):
            if adj_arr[i][k] == 1 and adj_arr[k][j] == 1:
                adj_arr[i][j] = 1

for item in adj_arr:
    print(*item)
