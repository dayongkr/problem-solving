import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, list(input().rstrip()))) for _ in range(N)]

d = [(-1, 0), (0, 1), (1, 0), (0, -1)]
visited = set()
result = 1e6

visited.add((0, 0))
queue = deque([(0, 0, 1)])

while queue:
    r, c, count = queue.popleft()
    count += 1

    for dr, dc in d:
        nr, nc = r + dr, c + dc

        if N > nr >= 0 and M > nc >= 0 and (nr, nc) not in visited and graph[nr][nc] == 1:
            if nr == N - 1 and nc == M - 1:
                result = min(result, count)
                continue
            queue.append((nr, nc, count))
            visited.add((nr, nc))

print(result)
