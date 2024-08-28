import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
d = [(-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1)]

for _ in range(N):
    I = int(input())
    startR, startC = map(int, input().split())
    targetR, targetC = map(int, input().split())

    if startR == targetR and startC == targetC:
        print(0)
        continue

    queue = deque()
    visited = set()
    result = -1

    queue.append((startR, startC, 0))

    while queue:
        r, c, cnt = queue.popleft()

        for dr, dc in d:
            nr, nc = r + dr, c + dc

            if 0 <= nr < I and 0 <= nc < I and (nr, nc) not in visited:
                if nr == targetR and nc == targetC:
                    result = cnt + 1
                    break

                visited.add((nr, nc))
                queue.append((nr, nc, cnt + 1))

        if result != -1:
            print(result)
            break
