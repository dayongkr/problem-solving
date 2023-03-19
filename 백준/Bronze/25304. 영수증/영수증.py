import sys
input = sys.stdin.readline

receipt = int(input())
n = int(input())
result = 0

for i in range(n):
    item = list(map(int, input().split(" ")))
    result += item[0] * item[1]

print("Yes" if receipt == result else "No")