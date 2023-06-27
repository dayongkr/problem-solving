import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
arr = []

for _ in range(N):
    arr.append(input().rstrip())

arr = set(arr)
count = 0

for _ in range(M):
    if input().rstrip() in arr:
        count += 1

print(count)
