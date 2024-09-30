import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
positions = map(int, input().split())

queue = deque(range(1, N+1))
result = 0

for position in positions:
    shiftLeft = 0
    while queue[0] != position:
        queue.append(queue.popleft())
        shiftLeft += 1

    for _ in range(shiftLeft):
        queue.appendleft(queue.pop())

    shiftRight = 0
    while queue[0] != position:
        queue.appendleft(queue.pop())
        shiftRight += 1

    if shiftLeft >= shiftRight:
        result += shiftRight
    else:
        for _ in range(shiftRight):
            queue.append(queue.popleft())

        while queue[0] != position:
            queue.append(queue.popleft())
        result += shiftLeft

    queue.popleft()


print(result)
