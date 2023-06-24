import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
queue = deque()

adj_arr = [list(map(int, input().split())) for _ in range(N)]
result = [[0 for _ in range(N)] for _ in range(N)]

for i in range(N):
    output = [[0 for _ in range(N)] for _ in range(N)]
    for j in range(N):
        if adj_arr[i][j] == 1 and output[i][j] == 0:
            output[i][j] = 1
            result[i][j] = 1
            queue.append((i, j))
            while queue:
                y, x = queue.popleft()
                for k in range(N):
                    if adj_arr[x][k] == 1 and output[x][k] == 0:
                        output[x][k] = 1
                        result[x][k] = 1
                        queue.append((x, k))
                        if output[i][k] == 0:
                            output[i][k] = 1
                            result[i][k] = 1

for item in result:
    print(*item)
