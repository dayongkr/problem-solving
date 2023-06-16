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
    if x == -1:
        for j in range(M):
            if temp[j] == 2:
                x = j
                y = i
                break
    arr.append(temp)

out[y][x] = 0
queue.append([x, y])
while len(queue):
    temp = queue.popleft()
    for i in range(4):
        nx = temp[0] + dx[i]
        ny = temp[1] + dy[i]
        if 0 <= nx < M and 0 <= ny < N and out[ny][nx] == -1:
            if arr[ny][nx] == 0:
                out[ny][nx] = 0
            elif arr[ny][nx] == 1:
                out[ny][nx] = out[temp[1]][temp[0]] + 1
                queue.append([nx, ny])

for i in range(N):
    for j in range(M):
        if arr[i][j] == 0 and out[i][j] == -1:
            print(0, end=" ")
        else:
            print(out[i][j], end=" ")
    print()
