import sys
from itertools import combinations

input = sys.stdin.readline

nums = [int(input()) for _ in range(9)]
nums = list(sorted(nums))

for comb in combinations(nums, 7):
    if sum(comb) == 100:
        for c in comb:
            print(c)
        break
