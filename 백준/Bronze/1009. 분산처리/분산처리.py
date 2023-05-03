import sys

input = sys.stdin.readline

n = int(input())

for i in range(n):
    a, b = map(int, input().split())
    o_a =a
    for j in range(b):
        a %= 10
        if j == 0:
            continue
        a *= o_a

    print(a % 10 if a / 10 != 0 else 10)
