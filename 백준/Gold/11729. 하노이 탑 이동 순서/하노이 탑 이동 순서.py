import sys

input = sys.stdin.readline

K = int(input())


def rec(a, b, n):
    if n == 1:
        print(f'{a} {b}')
        return
    rec(a, 6 - a - b, n - 1)
    print(f'{a} {b}')
    rec(6 - a - b, b, n-1)


print((1 << K) - 1)
rec(1, 3, K)
