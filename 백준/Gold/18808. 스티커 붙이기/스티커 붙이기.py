import sys
from collections import deque

input = sys.stdin.readline

N, M, K = map(int, input().split())
visited = [[False for _ in range(M)] for _ in range(N)]


def rotate(R, C, sticker):
    temp = [[0 for _ in range(10)] for _ in range(10)]

    for i in range(C):
        for j in range(R):
            temp[i][j] = sticker[R-1-j][i]

    return (C, R, temp)


def pastable(n, m, R, C, sticker):
    global visited
    for sr in range(R):
        for sc in range(C):
            if (sticker[sr][sc] == 1 and visited[sr + n][sc + m]):
                return False

    for sr in range(R):
        for sc in range(C):
            if sticker[sr][sc]:
                visited[sr + n][sc + m] = True

    return True


for _ in range(K):
    R, C = map(int, input().split())
    sticker = [list(map(int, input().split())) for _ in range(R)]

    for __ in range(4):
        next = False
        for r in range(N-R+1):
            for c in range(M-C+1):
                if pastable(r, c, R, C, sticker):
                    next = True
                    break
            if next:
                break
        if next:
            break

        R, C, sticker = rotate(R, C, sticker)

result = 0

for i in range(N):
    for j in range(M):
        if visited[i][j]:
            result += 1

print(result)
