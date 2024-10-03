import sys

input = sys.stdin.readline

N, M = map(int, input().split())


def rec(N, M, visited, stack):
    if M == len(stack):
        for num in stack:
            print(num, end=" ")
        print()
        return

    for i in range(N):
        if visited[i]:
            continue
        visited[i] = True
        stack.append(i+1)
        rec(N, M, visited, stack)
        visited[i] = False
        stack.pop()


rec(N, M, [False for _ in range(N)], [])
