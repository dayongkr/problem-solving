import sys

input = sys.stdin.readline
n = int(input())
arr = [list(map(int, input().split(" "))) for _ in range(n)]
white = 0
blue = 0


def rec(a, x, y):
    global white
    global blue
    pre_v = 0
    if a == 1 and arr[y][x]:
        blue += 1
        return
    elif a == 1:
        white += 1
        return
    for i in range(x, x + a):
        for j in range(y, y + a):
            if i == x and j == y:
                pre_v = arr[j][i]
            if arr[j][i] != pre_v:
                d = int(a / 2)
                rec(d, x, y)
                rec(d, x + d, y)
                rec(d, x, y + d)
                rec(d, x + d, y + d)
                return
            pre_v = arr[j][i]
    if pre_v:
        blue += 1
    else:
        white += 1


rec(n, 0, 0)

print(white, blue, sep="\n")
