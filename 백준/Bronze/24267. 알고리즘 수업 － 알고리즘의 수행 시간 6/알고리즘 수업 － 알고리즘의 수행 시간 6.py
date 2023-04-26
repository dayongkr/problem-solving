import sys

input = sys.stdin.readline
count = 0

n = int(input())

for i in range(1, n - 1):
    count += (n - i - 1) * (n - i) // 2

print(count)
print(3)
