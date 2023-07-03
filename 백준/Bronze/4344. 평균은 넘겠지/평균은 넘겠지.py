import sys
import heapq

input = sys.stdin.readline

C = int(input())

for _ in range(C):
    a = list(map(int, input().split()))
    avg = sum(a[1:]) / a[0]
    count = 0
    for item in a[1:]:
        if item > avg: count += 1
    print(f"{round(count / a[0] * 100, 3)}%")
