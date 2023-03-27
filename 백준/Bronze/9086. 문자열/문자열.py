import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    str = input().rstrip()
    print(str[0] + str[-1])