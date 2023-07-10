import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
graph = [[] for _ in range(N + 1)]
q = deque()
result = [-1 for _ in range(N + 1)]

for _ in range(N - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

q.append(1)

while q:
    temp = q.popleft()
    for item in graph[temp]:
        if result[item] == -1:
            result[item] = temp
            q.append(item)

print(*result[2:], sep="\n")
