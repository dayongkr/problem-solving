import sys

input = sys.stdin.readline

points = [[], []]

for _ in range(3):
    x, y = map(int, input().split())
    if (x in points[0]):
        points[0].remove(x)
    else:
        points[0].append(x)
    if (y in points[1]):
        points[1].remove(y)
    else:
        points[1].append(y)

print(points[0][0], points[1][0])