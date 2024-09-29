import sys

input = sys.stdin.readline

N = int(input())

nums = [int(input()) for _ in range(N)]
stack = []
cursor = 0
result = []
i = 1

while cursor < len(nums):
    cur = nums[cursor]

    while i < cur:
        stack.append(i)
        result.append('+')
        i += 1

    if i == cur:
        result.extend(['+', '-'])
        i += 1
    elif i > cur:
        temp = stack.pop()
        if temp != cur:
            break
        result.append('-')

    cursor += 1


if cursor == len(nums):
    print('\n'.join(result))
else:
    print('NO')
