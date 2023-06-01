import sys

input = sys.stdin.readline

n, m = map(int, input().split(" "))

g = [[] for _ in range(n)]
out = [True for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split(" "))
    g[u - 1].append(v - 1)
    g[v - 1].append(u - 1)

c = 0
stack = []

for i in range(n):
    if out[i]:
        c += 1
        stack.append(i)
    while len(stack) != 0:
        target = stack.pop()
        out[target] = False
        for item in g[target]:
            if out[item]:
                stack.append(item)
                out[item] = False

print(c)