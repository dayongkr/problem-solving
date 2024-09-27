import sys

input = sys.stdin.readline

N, X = map(int, input().split())
nums = map(int, input().split())

result = filter(lambda x: x < X, nums)

for num in result:
    print(num, end=" ")
