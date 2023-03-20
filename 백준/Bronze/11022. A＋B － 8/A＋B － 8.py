import sys
input = sys.stdin.readline

n = int(input())

for i in range(n):
    nums = list(map(int, input().split()))
    print("Case #{0}: {1} + {2} = {3}".format(i +
          1, nums[0], nums[1], sum(nums)))