import sys
input = sys.stdin.readline

t = list(map(int, input().split(" ")))
a = int(input())

h = int((t[1] + a)/60)

t[1] = (t[1] + a) % 60
t[0] = (t[0] + h) % 24
print("{0} {1}".format(t[0], t[1]))