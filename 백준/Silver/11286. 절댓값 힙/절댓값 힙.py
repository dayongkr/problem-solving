import heapq
import sys

input = sys.stdin.readline

N = int(input())
heap = []

for _ in range(N):
    t = int(input())
    if t == 0:
        if len(heap):
            print(heapq.heappop(heap)[1])
        else:
            print(0)
    else:
        heapq.heappush(heap, (abs(t), t))
