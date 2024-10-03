import sys

input = sys.stdin.readline

N, M = map(int, input().split())
nums = list(map(int, input().split()))
arr = [0 for _ in range(M)]
visited = [False for _ in range(N)]

nums.sort()


def rec(m):
    global N, M, visited, visited2

    if m == M:
        for i in range(M):
            print(arr[i], end=" ")
        print()
        return

    temp = 0

    for i in range(N):
        if visited[i] or temp == nums[i]:
            continue

        arr[m] = nums[i]
        visited[i] = True
        temp = nums[i]
        rec(m + 1)
        visited[i] = False


rec(0)
