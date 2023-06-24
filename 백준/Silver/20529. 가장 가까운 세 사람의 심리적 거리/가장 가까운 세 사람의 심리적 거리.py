import sys
from collections import deque
import difflib

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    mbti = list(input().split())
    if N >= 48:
        print(0)
        continue
    min_count = int(1e9)
    for i in range(N - 2):
        if min_count == 0:
            break
        for j in range(i + 1, N - 1):
            for k in range(j + 1, N):
                min_count = min(sum(1 for a, b in zip(mbti[i], mbti[j]) if a != b) + sum(
                    1 for a, b in zip(mbti[i], mbti[k]) if a != b) + sum(1 for a, b in zip(mbti[j], mbti[k]) if a != b),
                                min_count)
    print(min_count)
