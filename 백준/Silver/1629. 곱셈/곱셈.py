import sys

input = sys.stdin.readline

A, B, C = map(int, input().split())

result = 1

while B > 0:
    if B % 2:
        result = result * A % C
    A = (A % C) * (A % C) % C
    B //= 2

print(result % C)
