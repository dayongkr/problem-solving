import sys

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
op = list(map(int, input().split()))
max_result = -1000000001
min_result = 1000000001


def rec(n, a, b, c, d, s):
    global max_result
    global min_result
    if n == N:
        if s > max_result:
            max_result = s
        if s < min_result:
            min_result = s
    else:
        for i in range(4):
            if i == 0 and a > 0:
                rec(n + 1, a - 1, b, c, d, s + A[n])
            elif i == 1 and b > 0:
                rec(n + 1, a, b - 1, c, d, s - A[n])
            elif i == 2 and c > 0:
                rec(n + 1, a, b, c - 1, d, s * A[n])
            elif i == 3 and d > 0:
                if s < 0:
                    rec(n + 1, a, b, c, d - 1, -(-s // A[n]))
                else:
                    rec(n + 1, a, b, c, d - 1, s // A[n])


rec(1, op[0], op[1], op[2], op[3], A[0])

print(max_result)
print(min_result)
