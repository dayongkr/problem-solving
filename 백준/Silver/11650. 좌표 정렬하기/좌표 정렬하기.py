import sys
input = sys.stdin.readline

c = int(input())
arr = []

for i in range(c):
    arr.append(list(map(int, input().split())))

for num in sorted(arr, key=lambda x: (x[0], x[1])):
    print(num[0], num[1])