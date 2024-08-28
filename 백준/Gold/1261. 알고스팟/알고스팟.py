import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
miro = [list(input().rstrip()) for _ in range(M)]
queue = deque([(0, 0, 0)])
visited = {(0, 0): 0}
d = [(0, 1), (1, 0), (0, -1), (-1, 0)]
result = 1e9

if N == 1 and M == 1:
    result = 0

while queue:
    r, c, broken = queue.popleft()

    for dr, dc in d:
        nr, nc, nb = r + dr, c + dc, broken
        if nr == M - 1 and nc == N - 1:
            result = min(result, nb)
        elif 0 <= nr < M and 0 <= nc < N:
            if miro[nr][nc] == '1':
                nb += 1

            if visited.get((nr, nc), 1e9) > nb:
                visited[(nr, nc)] = nb
                queue.append((nr, nc, nb))

print(result)
