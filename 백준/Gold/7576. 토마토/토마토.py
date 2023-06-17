import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split(" "))
graph = [list(map(int, input().split())) for _ in range(M)]
out = [[0 for _ in range(N)] for _ in range(M)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
queue = deque()
max_t_count = 0
t_count = 0
day_count = -1

for i in range(N):
    for j in range(M):
        if graph[j][i] == -1:
            continue
        elif graph[j][i] == 1:
            queue.append((i, j))
            out[j][i] = 1
        max_t_count += 1

while queue:
    t_count += len(queue)
    temp = [queue.popleft() for _ in range(len(queue))]
    day_count += 1
    for x, y in temp:
        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y
            if N > nx >= 0 and M > ny >= 0 and not out[ny][nx] and graph[ny][nx] != -1:
                queue.append((nx, ny))
                out[ny][nx] = 1

if t_count == max_t_count:
    print(day_count)
else:
    print(-1)
