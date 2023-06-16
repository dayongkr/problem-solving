import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split(" "))
arr = list()
queue = deque()
x = -1
y = -1
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
out = [[-1 for i in range(M)] for j in range(N)]

for i in range(N):
    temp = list(map(int, input().split(" ")))
    for j in range(M):
        if temp[j] == 2:
            x = j
            y = i
        if temp[j] == 0:
            out[i][j] = 0
    arr.append(temp)

out[y][x] = 0
queue.append((x, y))

while queue:
    x, y = queue.popleft()

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < M and 0 <= ny < N and out[ny][nx] == -1 and arr[ny][nx] == 1:
            out[ny][nx] = out[y][x] + 1
            queue.append((nx, ny))

for i in range(N):
    print(*out[i])
