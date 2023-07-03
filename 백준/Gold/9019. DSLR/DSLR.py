import sys
from collections import deque

T = int(input())


def cal(num, type):
    if type[-1] == "D":
        num = num * 2
        if num > 9999:
            num %= 10000
    elif type[-1] == "S":
        if num == 0:
            num = 9999
        else:
            num = num - 1
    elif type[-1] == "L":
        first = num // 1000
        num = num * 10 - first * 10000 + first
    else:
        last = num % 10
        num = num // 10 + last * 1000
    return num


for _ in range(T):
    A, B = map(int, input().rstrip().split())
    queue = deque()
    out = [False] * 10000
    queue.append((A, ""))
    if A != 0:
        out[A] = True
    while queue:
        temp, type = queue.popleft()
        if temp == B:
            print(type)
            break
        for item in ["D", "S", "L", "R"]:
            temp2 = cal(temp, type + item)
            if not out[temp2]:
                queue.append((temp2, type + item))
                out[temp2] = True
