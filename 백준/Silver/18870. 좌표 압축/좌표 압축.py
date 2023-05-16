import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

s_arr = sorted(arr)
index = 0
d = {}

for item in s_arr:
    if item not in d:
        d[item] = index
        index += 1

for item in arr:
    print(d[item], end=" ")