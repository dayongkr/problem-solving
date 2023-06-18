import sys
from collections import deque

input = sys.stdin.readline

s = input().rstrip()
temp = ""
result = 0
flag = 1

for c in s:
    if '0' <= c <= '9':
        temp += c
    elif c == '+' or c == '-':
        result += int(temp) * flag
        temp = ""
    if c == '-':
        flag = -1
result += int(temp) * flag
print(result)
