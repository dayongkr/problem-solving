import sys
from collections import deque

N = int(input())
graph_a = [list(input().rstrip()) for _ in range(N)]
graph_b = [["B" if graph_a[i][j] == "B" else "R" for j in range(N)] for i in range(N)]
a, b = (0, 0)
out_a = [[False for _ in range(N)] for _ in range(N)]
out_b = [[False for _ in range(N)] for _ in range(N)]
d = [(0, 1), (0, -1), (1, 0), (-1, 0)]


def bfs(g, x, y, out, m):
    queue = deque()
    item = g[y][x]
    out[y][x] = True
    queue.append((x, y))
    while queue:
        ox, oy = queue.popleft()
        for dx, dy in d:
            nx = ox + dx
            ny = oy + dy
            if 0 <= nx < m and 0 <= ny < m and not out[ny][nx] and g[ny][nx] == item:
                queue.append((nx, ny))
                out[ny][nx] = True


for i in range(N):
    for j in range(N):
        if not out_a[i][j]:
            a += 1
            bfs(graph_a, j, i, out_a, N)
        if not out_b[i][j]:
            b += 1
            bfs(graph_b, j, i, out_b, N)

print(a, b)
