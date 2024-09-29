import sys

input = sys.stdin.readline

N = int(input().rstrip())
stack = []

for _ in range(N):
    command = input().rstrip().split()
    type = command[0]

    if type == 'push':
        stack.append(int(command[1]))
    elif type == 'pop':
        print(stack.pop() if stack else -1)
    elif type == 'size':
        print(len(stack))
    elif type == 'empty':
        print(0 if stack else 1)
    elif type == 'top':
        print(stack[-1] if stack else -1)
