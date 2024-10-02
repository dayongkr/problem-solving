import sys

input = sys.stdin.readline

N, R, C = map(int, input().split())


def rec(n, r, c):
    if n == 0:
        return 0

    value = rec(n - 1, r % 2 ** (n - 1), c % 2 ** (n - 1))

    if r >= 2 ** (n - 1):
        value += 2 ** (2 * n - 1)

    if c >= 2 ** (n-1):
        value += 2 ** (2 * n - 2)

    return value


print(rec(N, R, C))
