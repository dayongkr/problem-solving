import sys

input = sys.stdin.readline

N, M = map(int, input().split())
arr = [0 for _ in range(M)]


def rec(m):
    global N, M, visited

    if m == M:
        for i in range(M):
            print(arr[i], end=" ")
        print()
        return

    for i in range(N):
        arr[m] = i+1
        rec(m + 1)


rec(0)
