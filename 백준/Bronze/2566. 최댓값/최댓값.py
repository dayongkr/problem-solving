import sys
input = sys.stdin.readline

max = x = y = 0

for i in range(9):
    arr = list(map(int, input().split()))
    for j in range(9):
        if arr[j] == 100:
            max = arr[j]
            x = i
            y = j
            break
        if arr[j] > max:
            max = arr[j]
            x = i
            y = j
    if max == 100:
        break
print(max)
print(x+1, y+1)