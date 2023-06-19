import sys

input = sys.stdin.readline
d = dict()

N = int(input())
for _ in range(N):
    d.clear()
    M = int(input())
    for _ in range(M):
        _, b = input().rstrip().split(" ")
        if b in d:
            d[b] += 1
        else:
            d[b] = 1
    result = 1
    for item in d.values():
        result *= item + 1
    result -= 1
    print(result)
