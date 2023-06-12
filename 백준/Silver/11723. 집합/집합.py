import sys

input = sys.stdin.readline

n = int(input())
b = 0b0

for _ in range(n):
    s = list(input().rstrip().split(" "))
    if s[0] == "add":
        b |= 1 << int(s[1])
    elif s[0] == "check":
        print((b & (1 << int(s[1]))) >> int(s[1]))
    elif s[0] == "remove":
        b &= 1 << (int(s[1]) - 1)
    elif s[0] == "toggle":
        b ^= 1 << int(s[1])
    elif s[0] == "all":
        b = (1 << 22) - 1
    elif s[0] == "empty":
        b = 0
