import sys

input = sys.stdin.readline

N = int(input())
result = 0
for _ in range(N):
    words = list(input().rstrip())
    stack = []

    for word in words:
        if stack:
            prev = stack.pop()
            if prev != word:
                stack.append(prev)
                stack.append(word)
        else:
            stack.append(word)

    if not stack:
        result += 1

print(result)
