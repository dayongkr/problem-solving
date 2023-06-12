import sys

input = sys.stdin.readline

n, m = map(int, input().split(" "))
c = sorted(set(input().rstrip() for _ in range(n)) & set(input().rstrip() for _ in range(m)))
print(len(c))
print(*c, sep="\n")
