import sys

input = sys.stdin.readline

N = int(input())

nums = list(map(lambda x: (x[0], int(x[1])),
            enumerate(input().rstrip().split())))
stack = [nums.pop()]
result = [0 for _ in range(N)]

for curIndex, curHeight in reversed(nums):
    while stack:
        tempIndex, tempHeight = stack[-1]

        if curHeight > tempHeight:
            result[tempIndex] = curIndex + 1
            stack.pop()
        else:
            break
    stack.append((curIndex, curHeight))


for curIndex, _ in stack:
    result[curIndex] = 0

print(*result)
