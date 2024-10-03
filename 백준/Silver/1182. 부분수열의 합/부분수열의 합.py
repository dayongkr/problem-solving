import sys

input = sys.stdin.readline

N, S = map(int, input().split())
nums = list(map(int, input().split()))
cnt = 0


def rec(cur, total):
    global N, S, cnt

    if cur == N:
        if total == S:
            cnt += 1
        return

    rec(cur + 1, total)
    rec(cur + 1, total + nums[cur])


if S == 0:
    cnt -= 1

rec(0, 0)
print(cnt)
