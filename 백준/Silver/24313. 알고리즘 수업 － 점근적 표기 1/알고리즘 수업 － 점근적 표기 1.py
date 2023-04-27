import sys

input = sys.stdin.readline
count = 0

a1, a0 = map(int, input().split())
c = int(input())
n = int(input())

f = a1 * n + a0
g = c * n

print(1 if f <= g and a1 <= c else 0)
