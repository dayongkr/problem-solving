import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
f = int(input())

d = [[] for _ in range(n + 1)]
visited = [0 for _ in range(n + 1)]
count = 0
queue = deque()

for _ in range(f):
    a, b = map(int, input().split())
    d[a].append(b)
    d[b].append(a)

queue.append(d[1])
visited[1] = 1

while queue:
    for item in queue.popleft():
        if visited[item] == 0:
            visited[item] = 1
            count += 1
            queue.append(d[item])

print(count)
