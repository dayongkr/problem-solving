import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())

arr = [-1] * 101
out = [False] * 101
for _ in range(N + M):
    a, b = map(int, input().split())
    arr[a] = b

queue = deque()

queue.append((1, 0))
out[1] = True

while queue:
    t, c = queue.popleft()
    if t == 100:
        print(c)
        break
    for i in range(1, 7):
        n = t + i
        if n <= 100 and not out[n]:
            if arr[n] != -1:
                n = arr[n]
            queue.append((n, c + 1))
            out[n] = True
