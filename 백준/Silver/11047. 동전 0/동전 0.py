import sys

input = sys.stdin.readline

n, m = map(int, input().split(" "))
arr = []
c = 0

for _ in range(n):
    arr.append(int(input()))

for i in range(n - 1, -1, -1):
    c += m // arr[i]
    m %= arr[i]

print(c)
