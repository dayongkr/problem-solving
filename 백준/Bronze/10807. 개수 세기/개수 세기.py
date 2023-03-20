import sys
input = sys.stdin.readline

int(input())

nums = list(map(int, input().split(" ")))
num = int(input())
print(nums.count(num))