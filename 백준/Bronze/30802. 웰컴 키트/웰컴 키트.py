import sys
from math import ceil

input = sys.stdin.readline

N = int(input())
sizes = list(map(int, input().split()))
T, P = map(int, input().split())

clothes_cnt = 0
pens = divmod(N, P)

for size in sizes:
    clothes_cnt += ceil(size / T)

print(clothes_cnt)
print(pens[0], pens[1])
