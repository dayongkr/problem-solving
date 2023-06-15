import sys

input = sys.stdin.readline
count = 0
n, r, c = map(int, input().split())


def rec(a, y, x):
    global count
    if a == 0:
        print(count)
        return
    d = a - 1
    sd = pow(2, d)
    if r >= y + sd:
        y += sd
        count += pow(sd, 2) * 2
    if c >= x + sd:
        x += sd
        count += pow(sd, 2)
    rec(d, y, x)


rec(n, 0, 0)
