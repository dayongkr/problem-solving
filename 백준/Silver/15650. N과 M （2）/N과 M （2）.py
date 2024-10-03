import sys

input = sys.stdin.readline

N, M = map(int, input().split())
visited = [False for _ in range(N)]
arr = [0 for _ in range(M)]


def rec(n, m):
    global N, M, visited

    if m == M:
        for i in range(M):
            print(arr[i], end=" ")
        print()
        return

    for i in range(n, N):
        if visited[i]:
            continue

        visited[i] = True
        arr[m] = i+1
        rec(i+1, m + 1)
        visited[i] = False


rec(0, 0)
