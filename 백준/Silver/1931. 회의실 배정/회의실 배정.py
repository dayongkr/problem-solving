import sys

input = sys.stdin.readline

arr = sorted([list(map(int, input().split())) for _ in range(int(input()))], key=lambda x: (x[1], x[0], x[1] - x[0]))
end = 0
c = 0
for item in arr:
    if item[0] >= end:
        end = item[1]
        c += 1

print(c)
