import sys
import heapq

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    K = int(input())
    out = [1] * K
    min_heap = list()
    max_heap = list()
    for i in range(K):
        type, num = input().split()
        if type == "I":
            heapq.heappush(min_heap, (int(num), i))
            heapq.heappush(max_heap, (-int(num), i))
            out[i] = 0
        elif type == "D" and num == "1":
            while max_heap and out[max_heap[0][1]]:
                heapq.heappop(max_heap)
            if max_heap:
                out[max_heap[0][1]] = 1
                heapq.heappop(max_heap)
        elif type == "D" and num == "-1":
            while min_heap and out[min_heap[0][1]]:
                heapq.heappop(min_heap)
            if min_heap:
                out[min_heap[0][1]] = 1
                heapq.heappop(min_heap)
    while max_heap and out[max_heap[0][1]]:
        heapq.heappop(max_heap)
    while min_heap and out[min_heap[0][1]]:
        heapq.heappop(min_heap)

    if max_heap:
        print(-max_heap[0][0], min_heap[0][0])
    else:
        print("EMPTY")
