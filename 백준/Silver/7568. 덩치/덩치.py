import sys

input = sys.stdin.readline

n = int(input())

arr = []

rank = 1

for _ in range(n):
    arr.append(list(map(int, input().split(" "))))

for i in range(n):
    rank = 1
    for j in range(n):
        if i != j and arr[i][0] < arr[j][0] and arr[i][1] < arr[j][1]:
            rank += 1
    print(rank, end=" ")
