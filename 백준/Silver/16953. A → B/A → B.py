import sys
from collections import deque

input = sys.stdin.readline

A, B = map(int, input().split())

queue = deque()

queue.append((A, 1))

while queue:
    t, c = queue.popleft()
    if t == B:
        print(c)
        exit(0)
    if t * 2 == B or t * 10 + 1 == B:
        print(c + 1)
        exit(0)
    if t * 2 < B:
        queue.append((t * 2, c + 1))
    if t * 10 + 1 < B:
        queue.append((t * 10 + 1, c + 1))

print(-1)
