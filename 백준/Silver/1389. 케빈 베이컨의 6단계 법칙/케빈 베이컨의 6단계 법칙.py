import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
arr = [[] for _ in range(N + 1)]
queue = deque()
min_sum = 100000000
min_index = -1

for i in range(M):
    a, b = map(int, input().rstrip().split())
    arr[a].append(b)
    arr[b].append(a)

for i in range(1, N+1):
    queue.clear()
    count = 0
    out = [0 for _ in range(N + 1)]
    out[i] = 1
    queue.append((i, 0))
    while queue:
        a, b = queue.popleft()
        for j in arr[a]:
            if out[j] == 0:
                count += b + 1
                queue.append((j, b + 1))
                out[j] = 1
    if min_sum > count:
        min_sum = count
        min_index = i
    elif min_sum == count:
        min_index = min(min_index, i)
print(min_index)
