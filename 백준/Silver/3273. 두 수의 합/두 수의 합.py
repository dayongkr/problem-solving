import sys

input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
x = int(input())

frequency = [0 for _ in range(int(1e6 + 1))]
result = 0

for a in arr:
    if 1e6 + 1 > x - a > 0 and frequency[x - a]:
        result += 1

    frequency[a] = 1

print(result)
