import sys

input = sys.stdin.readline

n = input()
f = int(input())

for i in range(100):
    s = str(i)
    if i < 10:
        s = "0" + s
    if (int(n[:-3] + s) % f) == 0:
        print(s)
        break
