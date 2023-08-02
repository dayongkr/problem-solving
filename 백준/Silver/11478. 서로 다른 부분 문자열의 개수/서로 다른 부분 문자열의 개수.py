import sys

input = sys.stdin.readline

a = input().rstrip()
result = set()

for i in range(len(a)):
    for j in range(i, len(a)):
        result.add(a[i:j + 1])

print(len(result))
