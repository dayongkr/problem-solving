import sys

input = sys.stdin.readline

S = list(input().rstrip())
result = [0 for _ in range(26)]

for c in S:
    result[ord(c) - ord('a')] += 1

for num in result:
    print(num, end=" ")
