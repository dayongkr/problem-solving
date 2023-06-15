import sys
from collections import deque

input = sys.stdin.readline
a, b = map(int, input().split())
queue = deque()
out = [1 for _ in range(100001)]

queue.append([a, 0])

while True:
    c = queue.popleft()
    if c[0] == b:
        print(c[1])
        break
    for item in [c[0] + 1, c[0] - 1, 2 * c[0]]:
        if item == b:
            print(c[1] + 1)
            exit(0)
        if 100000 >= item >= 0 and out[item]:
            queue.append([item, c[1] + 1])
            out[item] = 0
