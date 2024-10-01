import sys
from collections import deque

input = sys.stdin.readline

N, K = map(int, input().split())

if N == K:
    print(0)
    exit()

visited = [False for _ in range(int(1e5) + 1)]
queue = deque()

queue.append((N, 0))
visited[N] = True

while queue:
    cur, time = queue.popleft()
    ways = [cur - 1, cur + 1, cur * 2]
    time += 1

    for way in ways:
        if 1e5 >= way >= 0 and not visited[way]:
            if way == K:
                print(time)
                exit(0)
            queue.append((way, time))
            visited[way] = True
