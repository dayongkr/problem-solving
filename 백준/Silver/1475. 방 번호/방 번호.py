import sys

input = sys.stdin.readline

nums = list(map(int, list(input().rstrip())))
counts = [0 for _ in range(10)]


for num in nums:
    if num == 9 or num == 6:
        if counts[9] > counts[6]:
            counts[6] += 1
        else:
            counts[9] += 1
    else:
        counts[num] += 1

print(max(counts))
