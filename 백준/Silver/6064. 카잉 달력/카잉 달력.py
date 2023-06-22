import sys
from collections import deque
from math import lcm

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    M, N, x, y = map(int, input().split())
    max_year = lcm(M, N)
    a, b = (0, 0)
    while True:
        if M * a + x == N * b + y:
            print(M * a + x)
            break
        if M * a + x > max_year or N * b + y > max_year:
            print(-1)
            break
        if M * a + x > N * b + y:
            b += 1
        else:
            a += 1
