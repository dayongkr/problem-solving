import sys

input = sys.stdin.readline

N, M = map(int, input().split())
nums = list(map(int, input().split()))
arr = [0 for _ in range(M)]
visited = [False for _ in range(N)]

nums.sort()


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

        arr[m] = nums[i]
        visited[i] = True
        rec(i, m + 1)
        visited[i] = False


rec(0, 0)
