import sys

input = sys.stdin.readline

n = int(input())
card = input().rstrip().split(" ")
m = int(input())
target = input().rstrip().split(" ")

d = {}

for item in card:
    if d.get(item):
        d[item] += 1
    else:
        d[item] = 1

for item in target:
    item = d.get(item)
    print(item if item else 0, end=" ")
