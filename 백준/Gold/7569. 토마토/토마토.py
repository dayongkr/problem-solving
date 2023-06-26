import sys
from collections import deque

input = sys.stdin.readline

M, N, H = map(int, input().split())
box = [[list(map(int, input().split())) for _ in range(N)] for _ in range(H)]
out = [[[0 for _ in range(M)] for _ in range(N)] for _ in range(H)]
queue = deque()
max_count = 0
count = 0
day = 0
d = [(1, 0, 0), (-1, 0, 0), (0, 1, 0), (0, -1, 0), (0, 0, 1), (0, 0, -1)]

for i in range(H):
    for j in range(N):
        for k in range(M):
            if box[i][j][k] == 1:
                count += 1
                queue.append((i, j, k))
            if box[i][j][k] != -1:
                max_count += 1
            if box[i][j][k] != 0:
                out[i][j][k] = 1

while queue:
    temp = [item for item in queue]
    queue.clear()
    for z, y, x in temp:
        for dx, dy, dz in d:
            nx = x + dx
            ny = y + dy
            nz = z + dz
            if M > nx >= 0 and N > ny >= 0 and H > nz >= 0 and out[nz][ny][nx] == 0:
                count += 1
                queue.append((nz, ny, nx))
                out[nz][ny][nx] = 1
    if queue:
        day += 1

if count == max_count:
    print(day)
else:
    print(-1)
