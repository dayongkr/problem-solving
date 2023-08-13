import sys

input = sys.stdin.readline

N = input().rstrip()
T = len(N)
N = int(N)
M = int(input())
broken = list(map(int, input().split())) if M != 0 else []
key = []
min_result = abs(N - 100)
for i in range(10):
    if i not in broken:
        key.append(i)


def rec(n, result):
    global key
    global min_result
    min_result = min(abs(N - result) + len(str(result)), min_result)
    if n == 0:
        if min_result == 0:
            print(0)
            exit(0)
        return
    for e in key:
        rec(n - 1, int(str(result) + str(e)))


for item in key:
    rec(T, item)

print(min_result)