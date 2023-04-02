import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    arr = list(map(int, input().split(" ")))
    m = arr[0]
    avg = sum(arr[1:]) / m
    stud = 0
    for s in arr[1:]:
        if s > avg:
            stud += 1
    print(f"{stud / m * 100:.3f}%")