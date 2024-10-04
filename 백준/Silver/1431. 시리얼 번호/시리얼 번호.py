from functools import cmp_to_key
import sys
from collections import deque

input = sys.stdin.readline

N = int(input())

cards = [input().rstrip() for _ in range(N)]

cards.sort(key=lambda x: (len(x), sum(
    list(map(lambda x: int(x) if x.isdigit() else 0, list(x)))), x))

for card in cards:
    print(card)
