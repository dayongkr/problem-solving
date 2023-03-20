import sys
input = sys.stdin.readline

nums = list(map(int, input().split(" ")))
arr = [0 for _ in range(nums[0])]

for i in range(nums[1]):
    a = list(map(int, input().split(" ")))
    for j in range(a[0]-1, a[1]):
        arr[j] = a[2]
for i in range(nums[0]):
    print(arr[i], end=" ")