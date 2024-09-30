import sys

input = sys.stdin.readline

strings = list(input().rstrip())

result = 0
stack = []


for index in range(len(strings)):
    char = strings[index]
    if char == ')':
        if strings[index-1] == '(':
            result += len(stack) - 1
        else:
            result += 1
        stack.pop()
    else:
        stack.append('(')

print(result)
