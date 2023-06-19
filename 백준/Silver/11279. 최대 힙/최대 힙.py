import heapq
import sys

input = sys.stdin.readline

N = int(input())
heap = list()

for _ in range(N):
    c = int(input())
    if c == 0:
        if len(heap) == 0:
            print(0)
        else:
            print(-heapq.heappop(heap))
    else:
        heapq.heappush(heap, -c)
