import sys

input = sys.stdin.readline

N, M = map(int, input().split())
nums = list(map(int, input().split()))
arr = [0 for _ in range(M)]

nums.sort()


def rec(m):
    global N, M

    if m == M:
        for i in range(M):
            print(arr[i], end=" ")
        print()
        return

    temp = 0

    for i in range(N):
        if temp == nums[i]:
            continue

        temp = nums[i]
        arr[m] = nums[i]
        rec(m + 1)


rec(0)
