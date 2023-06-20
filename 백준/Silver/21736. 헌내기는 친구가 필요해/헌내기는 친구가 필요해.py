from collections import deque
import sys

input = sys.stdin.readline
queue = deque()
N, M = map(int, input().split())
arr = [[item for item in input().rstrip()] for _ in range(N)]
out = [[0 for _ in range(M)] for _ in range(N)]
y, x = (-1, -1)
for i in range(N):
    for j in range(M):
        if arr[i][j] == 'I':
            y, x = (i, j)
            break
    if y != -1:
        break

queue.append((x, y))
out[y][x] = 1
d = [[0, 1], [0, -1], [1, 0], [-1, 0]]
count = 0

while queue:
    x, y = queue.popleft()
    for i in range(4):
        nx = x + d[i][0]
        ny = y + d[i][1]
        if 0 <= nx < M and 0 <= ny < N and out[ny][nx] == 0 and arr[ny][nx] != 'X':
            if arr[ny][nx] == 'P':
                count += 1
            queue.append((nx, ny))
            out[ny][nx] = 1

if count:
    print(count)
else:
    print("TT")