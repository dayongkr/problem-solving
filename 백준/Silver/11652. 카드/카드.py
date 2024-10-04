import sys

input = sys.stdin.readline

N = int(input())

integers = [int(input()) for _ in range(N)]

integers.sort()

dic = {}

for integer in integers:
    if integer in dic:
        dic[integer] += 1
    else:
        dic[integer] = 1

result = 0
MAX = 0

for key, value in zip(dic.keys(), dic.values()):
    if value > MAX:
        result = key
        MAX = value


print(result)
