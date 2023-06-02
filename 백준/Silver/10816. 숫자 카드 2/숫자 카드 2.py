import sys

input = sys.stdin.readline

n = int(input())
card = list(map(int, input().split(" ")))
m = int(input())
target = list(map(int, input().split(" ")))

d = dict()

for item in card:
    if d.get(item):
        d[item] += 1
    else:
        d[item] = 1

for item in target:
    print(d.get(item) if d.get(item) else 0, end=" ")
