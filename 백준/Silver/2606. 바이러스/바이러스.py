import sys

input = sys.stdin.readline

n = int(input())
f = int(input())

d = {}
visited = []
queue = []

for _ in range(f):
    a, b = map(int, input().split())
    if a in d:
        d[a].add(b)
    else:
        d[a] = {b}

    if b in d:
        d[b].add(a)
    else:
        d[b] = {a}

queue.append(d[1])

while len(queue) != 0:
    temp = queue.pop(0)
    for item in temp:
        if item not in visited:
            visited.append(item)
            queue.append(d[item])

print(len(visited) - 1)
