import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]

spaces = 0
cameras = []
camera3 = [(3, 0), (0, 1), (1, 2), (2, 3)]
directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

# CCTV가 감시할 수 있는 방향 미리 계산
def watch_area(r, c, d, visited):
    while True:
        nr, nc = r + d[0], c + d[1]
        if not (0 <= nr < N and 0 <= nc < M) or graph[nr][nc] == 6:
            break
        if graph[nr][nc] == 0 and not visited[nr][nc]:
            visited[nr][nc] = True
        r, c = nr, nc

# 감시 영역 미리 계산
def calc_watch(visited, brute):
    for cameraR, cameraC, cameraType in cameras:
        rotation = brute % 4
        brute //= 4

        if cameraType == 1:
            watch_area(cameraR, cameraC, directions[rotation], visited)
        elif cameraType == 2:
            watch_area(cameraR, cameraC, directions[rotation], visited)
            watch_area(cameraR, cameraC, directions[(rotation + 2) % 4], visited)
        elif cameraType == 3:
            watch_area(cameraR, cameraC, directions[camera3[rotation][0]], visited)
            watch_area(cameraR, cameraC, directions[camera3[rotation][1]], visited)
        elif cameraType == 4:
            for dIndex in range(4):
                if dIndex != rotation:
                    watch_area(cameraR, cameraC, directions[dIndex], visited)
        else:  # type 5
            for direction in directions:
                watch_area(cameraR, cameraC, direction, visited)

# 감시하지 않는 영역 카운트
def count_unwatched(visited):
    unwatched = 0
    for r in range(N):
        for c in range(M):
            if graph[r][c] == 0 and not visited[r][c]:
                unwatched += 1
    return unwatched

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
    visited = [[False for _ in range(M)] for _ in range(N)]
    calc_watch(visited, i)
    answer = min(answer, count_unwatched(visited))

print(answer)