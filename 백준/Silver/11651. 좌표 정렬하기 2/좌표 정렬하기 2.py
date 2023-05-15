import sys

input = sys.stdin.readline

n = int(input())

arr = []

for _ in range(n):
    arr.append(list(map(int, input().split())))

for item in sorted(arr, key=lambda x: (x[1], x[0])):
    print(item[0], item[1])
