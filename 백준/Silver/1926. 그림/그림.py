import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

d = [(-1, 0), (0, 1), (1, 0), (0, -1)]
visited = set()
count = 0
maxArea = 0

for i in range(N):
    for j in range(M):
        if graph[i][j] == 0 or (i, j) in visited:
            continue

        visited.add((i, j))
        queue = deque([(i, j)])
        area = 1

        while queue:
            r, c = queue.pop()

            for dr, dc in d:
                nr, nc = r + dr, c + dc

                if N > nr >= 0 and M > nc >= 0 and (nr, nc) not in visited and graph[nr][nc] == 1:
                    queue.append((nr, nc))
                    visited.add((nr, nc))
                    area += 1

        count += 1
        maxArea = max(maxArea, area)

print(count)
print(maxArea)
