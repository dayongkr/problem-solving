import sys

input = sys.stdin.readline

N = int(input())
fruits = list(map(int, input().split()))


def add(dic, fruit):
    if fruit in dic:
        dic[fruit] += 1
    else:
        dic[fruit] = 1


def pop(dic, fruit):
    if dic[fruit] == 1:
        del (dic[fruit])
    else:
        dic[fruit] -= 1


if N <= 2:
    print(N)
else:
    p1 = 0
    p2 = 1
    result = 2
    tang = dict()

    add(tang, fruits[p1])

    while p1 < p2 < N:
        add(tang, fruits[p2])
        if len(tang) > 2:
            pop(tang, fruits[p1])
            p1 += 1
        else:
            result = max(p2 - p1 + 1, result)
        p2 += 1

    print(result)
