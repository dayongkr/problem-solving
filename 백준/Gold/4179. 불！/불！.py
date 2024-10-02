import sys
from collections import deque

input = sys.stdin.readline

R, C = map(int, input().split())
graph = [list(input().rstrip()) for _ in range(R)]

d = [(-1, 0), (0, 1), (1, 0), (0, -1)]

jQ = deque()
fQ = deque()

for r in range(R):
    for c in range(C):
        if graph[r][c] == 'J':
            if r == 0 or r == R-1 or c == 0 or c == C-1:
                print(1)
                exit(0)
            jQ.append((r, c, 1))
        elif graph[r][c] == 'F':
            fQ.append((r, c))


while jQ:
    for _ in range(len(fQ)):
        fr, fc = fQ.popleft()

        for dr, dc in d:
            nfr, nfc = fr + dr, fc + dc

            if R > nfr >= 0 and C > nfc >= 0 and (graph[nfr][nfc] == '.' or graph[nfr][nfc] == 'J'):
                fQ.append((nfr, nfc))
                graph[nfr][nfc] = 'F'

    for _ in range(len(jQ)):
        r, c, t = jQ.popleft()
        for dr, dc in d:
            nr, nc, nt = r + dr, c + dc, t + 1

            if R > nr >= 0 and C > nc >= 0 and graph[nr][nc] == '.':
                if nr == 0 or nr == R-1 or nc == 0 or nc == C-1:
                    print(nt)
                    exit(0)
                jQ.append((nr, nc, nt))
                graph[nr][nc] = "J"


print("IMPOSSIBLE")
