import sys
from collections import deque
import heapq

input = sys.stdin.readline

N, M = map(int, input().split())
miro = [list(input().rstrip()) for _ in range(M)]
heap = [(0, 0, 0)]
visited = {(0, 0): 0}
d = [(0, 1), (1, 0), (0, -1), (-1, 0)]

while heap:
    b, r, c = heapq.heappop(heap)
    if r == M - 1 and c == N - 1:
        print(b)
        break

    for dr, dc in d:
        nr, nc, nb = r + dr, c + dc, b
        if 0 <= nr < M and 0 <= nc < N:
            if miro[nr][nc] == '1':
                nb += 1

            if visited.get((nr, nc), 1e9) > nb:
                heapq.heappush(heap, (nb, nr, nc))
                visited[(nr, nc)] = nb
