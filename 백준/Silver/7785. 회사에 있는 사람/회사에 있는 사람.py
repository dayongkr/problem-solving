import sys
from collections import deque

input = sys.stdin.readline

N = int(input())

arr = set()

for _ in range(N):
    n, t = input().split()
    if t == 'enter':
        arr.add(n)
    elif t == 'leave':
        arr.remove(n)

arr = sorted(arr)
for i in range(len(arr) - 1, -1, -1):
    print(arr[i])
