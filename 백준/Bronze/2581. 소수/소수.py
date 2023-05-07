import sys

input = sys.stdin.readline

sum_value = 0
min_value = 10001

m = int(input())
n = int(input())

for i in range(m, n + 1):
    if i == 2:
        sum_value += i
        min_value = i
        continue
    elif i % 2 == 0:
        continue
    for j in range(3, i + 1, 2):
        if i % j == 0:
            if i == j:
                sum_value += i
                if min_value > i:
                    min_value = i
            break

if sum_value == 0:
    print(-1)
else:
    print(sum_value)
    print(min_value)
