import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

spaces = 0
cameras = []
camera3 = [(3, 0), (0, 1), (1, 2), (2, 3)]
directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

for r in range(N):
    for c in range(M):
        cur = graph[r][c]

        if cur == 0:
            spaces += 1
        elif cur != 6:
            cameras.append((r, c, cur))

cases = 4 ** len(cameras)
answer = spaces

for i in range(cases):
    brute = i
    queue = deque()
    visited = [[False for _ in range(M)] for _ in range(N)]
    result = spaces

    for cameraR, cameraC, cameraType in cameras:
        rotation = brute % 4

        if cameraType == 1:
            queue.append((cameraR, cameraC, directions[rotation]))
        elif cameraType == 2:
            queue.append((cameraR, cameraC, directions[rotation]))
            queue.append(
                (cameraR, cameraC, directions[rotation - 2 if rotation >= 2 else rotation + 2]))
        elif cameraType == 3:
            queue.append((cameraR, cameraC, directions[camera3[rotation][0]]))
            queue.append((cameraR, cameraC, directions[camera3[rotation][1]]))
        elif cameraType == 4:
            for dIndex in range(4):
                if dIndex == rotation:
                    continue
                queue.append((cameraR, cameraC, directions[dIndex]))
        else:
            for direction in directions:
                queue.append((cameraR, cameraC, direction))

        visited[cameraR][cameraC] = True

        while queue:
            r, c, d = queue.pop()
            nr, nc = r + d[0], c+d[1]

            if N > nr >= 0 and M > nc >= 0 and graph[nr][nc] != 6:
                if graph[nr][nc] == 0 and not visited[nr][nc]:
                    result -= 1
                    visited[nr][nc] = True
                queue.append((nr, nc, d))

        brute //= 4

    answer = min(result, answer)

print(answer)
