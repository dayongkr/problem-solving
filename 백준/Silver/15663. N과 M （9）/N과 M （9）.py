import sys

input = sys.stdin.readline

N, M = map(int, input().split())
nums = list(map(int, input().split()))
arr = [0 for _ in range(M)]
visited = [False for _ in range(N)]
visited2 = [[False for _ in range(10001)] for _ in range(N)]

nums.sort()


def rec(m):
    global N, M, visited, visited2

    if m == M:
        for i in range(M):
            print(arr[i], end=" ")
        print()
        return

    for i in range(N):
        if visited[i] or visited2[m][nums[i]]:
            continue

        arr[m] = nums[i]
        visited[i] = True
        visited2[m][nums[i]] = True
        rec(m + 1)
        visited[i] = False

    for num in nums:
        visited2[m][num] = False


rec(0)
