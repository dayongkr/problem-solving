import sys

input = sys.stdin.readline

strings = list(input().rstrip())

stack = []


def error():
    print(0)
    exit(0)


for char in strings:
    if char == ')' or char == ']':
        temp = 0

        while stack:
            cur = stack.pop()

            if cur.isdigit():
                temp += int(cur)
            elif cur == '(' and char == ')':
                stack.append(str(2 * temp) if temp else "2")
                break
            elif cur == '[' and char == ']':
                stack.append(str(3 * temp) if temp else "3")
                break
            else:
                error()

        if not stack:
            error()
    else:
        stack.append(char)


if any(not x.isdigit() for x in stack):
    error()

print(sum(map(int, stack)))
