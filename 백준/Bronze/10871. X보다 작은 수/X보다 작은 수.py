nums = list(map(int, input().split(" ")))

for num in list(map(int, input().split(" "))):
    if nums[1] > num:
        print(num, end=" ")
