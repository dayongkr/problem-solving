import sys

input = sys.stdin.readline

K = int(input())
stack = []

for _ in range(K):
    cur = int(input())

    if cur == 0:
        stack.pop()
    else:
        stack.append(cur)

print(sum(stack))
