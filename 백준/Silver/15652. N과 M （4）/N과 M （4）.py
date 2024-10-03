import sys

input = sys.stdin.readline

N, M = map(int, input().split())
arr = [0 for _ in range(M)]


def rec(n, m):
    global N, M, visited

    if m == M:
        for i in range(M):
            print(arr[i], end=" ")
        print()
        return

    for i in range(n, N):
        arr[m] = i+1
        rec(i, m + 1)


rec(0, 0)
