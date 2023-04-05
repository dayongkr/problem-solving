import sys
input = sys.stdin.readline

valid = [1,1,2,2,2,8]
pieces = list(map(int, input().split(" ")))

for i in range(6):
    print(valid[i] - pieces[i], end=" ")