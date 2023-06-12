import sys

input = sys.stdin.readline

n, m = map(int, input().split(" "))

a = {}
b = {}

for i in range(1, n + 1):
    s = input().rstrip()
    a[s] = i
    b[str(i)] = s

for _ in range(m):
    s = input().rstrip()
    if s.isdecimal():
        print(b[s])
    else:
        print(a[s])
