import sys

input = sys.stdin.readline

n = int(input())
max_w = max_h = -10000
min_w = min_h = 10000

for _ in range(n):
    w, h = map(int, input().split())
    if (w > max_w):
        max_w = w
    if (w < min_w):
        min_w = w
    if (h > max_h):
        max_h = h
    if (h < min_h):
        min_h = h
print((max_w - min_w) * (max_h - min_h))