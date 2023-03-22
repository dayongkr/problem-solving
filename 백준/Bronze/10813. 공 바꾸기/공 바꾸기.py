import sys
input = sys.stdin.readline

nums = list(map(int, input().split(" ")))
arr = []

for i in range(1, nums[0]+1):
    arr.append(i)

for i in range(nums[1]):
    a = list(map(int, input().split(" ")))
    temp = arr[a[0]-1]
    arr[a[0]-1] = arr[a[1]-1]
    arr[a[1]-1] = temp

for i in range(nums[0]):
    print(arr[i], end=" ")