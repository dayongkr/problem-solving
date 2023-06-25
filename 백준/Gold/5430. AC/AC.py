import sys
from collections import deque

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    F = list(input().rstrip())
    P = int(input())
    rev = False
    N = input()[1:-2]
    if P == 0:
        N = deque()
    else:
        N = deque(map(int, N.split(',')))
    if F.count('D') > P:
        print('error')
        continue
    for item in F:
        if item == 'R':
            rev = not rev
        elif rev:
            N.pop()
        else:
            N.popleft()
    if rev:
        N.reverse()
    print('[', end='')
    print(*N, sep=',', end="")
    print(']')
