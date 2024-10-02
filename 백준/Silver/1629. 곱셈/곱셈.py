import sys

input = sys.stdin.readline

A, B, C = map(int, input().split())


def rec(A, B, C):
    if B == 1:
        return A % C

    value = rec(A, B // 2, C)
    value = value ** 2 % C

    if B % 2:
        return value * A % C

    return value


print(rec(A, B, C))
