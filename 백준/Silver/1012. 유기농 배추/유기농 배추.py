import sys

input = sys.stdin.readline
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

t = int(input())

for _ in range(t):
    m, n, k = map(int, input().split())
    arr = [[0 for _ in range(m)] for _ in range(n)]
    c = 0
    for _ in range(k):
        a, b = map(int, input().split())
        arr[b][a] = 1

    for j in range(m):
        for i in range(n):
            if arr[i][j] == 0:
                continue
            c += 1
            stack = [[i, j]]
            while len(stack):
                y, x = stack.pop()
                arr[y][x] = 0
                for k in range(4):
                    ny = y + dy[k]
                    nx = x + dx[k]
                    if 0 <= ny < n and 0 <= nx < m and arr[ny][nx] == 1:
                        stack.append([ny, nx])
    print(c)
