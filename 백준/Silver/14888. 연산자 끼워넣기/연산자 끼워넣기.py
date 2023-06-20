import sys

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
op = list(map(int, input().split()))
max_result = -1000000001
min_result = 1000000001

def rec(n, plus, minus, mul, div, prev_result):
    global max_result
    global min_result
    if n == N:
        if prev_result > max_result:
            max_result = prev_result
        if prev_result < min_result:
            min_result = prev_result
        return

    if plus:
        rec(n + 1, plus - 1, minus, mul, div, prev_result + A[n])
    if minus:
        rec(n + 1, plus, minus - 1, mul, div, prev_result - A[n])
    if mul:
        rec(n + 1, plus, minus, mul - 1, div, prev_result * A[n])
    if div:
        rec(n + 1, plus, minus, mul, div - 1, int(prev_result / A[n]))


rec(1, op[0], op[1], op[2], op[3], A[0])

print(max_result)
print(min_result)
