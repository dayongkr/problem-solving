import sys

int(input())
p = list(map(int, input().split(' ')))
s = 0
cs = 0

for item in sorted(p):
    cs = cs + item
    s += cs

print(s)
