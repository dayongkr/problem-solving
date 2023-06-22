import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
M = int(input())
S = list(input().rstrip())
count = 0

e = 0

for s in range(M):
    if s > e:
        e = s
    if S[s] == 'I':
        while M > s + N * 2 > e:
            if S[e] == S[e + 1]:
                break
            e += 1
    if e - s == N * 2:
        count += 1
print(count)
