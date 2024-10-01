import sys
from collections import deque

input = sys.stdin.readline

M, N = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

d = [(-1, 0), (0, 1), (1, 0), (0, -1)]
visited = [[False for _ in range(M)] for _ in range(N)]
queue = deque()
count = 0  # 익기 전 토마토 갯수
result = 0


for i in range(N):
    for j in range(M):
        cur = graph[i][j]
        if cur == 1:
            queue.append((i, j, 0))
            visited[i][j] = True
        if cur == 0:
            count += 1

while queue:
    r, c, day = queue.popleft()

    for dr, dc in d:
        nr, nc, nday = r + dr, c + dc, day + 1

        if N > nr >= 0 and M > nc >= 0 and not visited[nr][nc] and graph[nr][nc] == 0:
            count -= 1
            result = max(result, nday)
            queue.append((nr, nc, nday))
            visited[nr][nc] = True

if count != 0:  # 다 익지 못하면 -1
    result = -1

print(result)
