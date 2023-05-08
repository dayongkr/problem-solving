import sys

input = sys.stdin.readline

n = int(input())
s = input()
s_size = len(s)

if n != 1:
    for _ in range(n - 1):
        t = input()
        for j in range(s_size):
            if s[j] == '?':
                continue
            if s[j] != t[j]:
                s = s[:j] + '?' + s[j + 1:]

print(s)
