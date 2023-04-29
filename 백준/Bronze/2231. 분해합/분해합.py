import sys

input = sys.stdin.readline

n = int(input())
flag = False
min_gen = n

for i in reversed(range(n + 1)):
    sum = i
    for j in str(i):
        sum += int(j)
    if sum == n and min_gen > i:
        min_gen = i
        flag = True

if flag:
    print(min_gen)
else:
    print(0)
