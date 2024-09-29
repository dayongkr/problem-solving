import sys

input = sys.stdin.readline

N = int(input())

nums = list(map(lambda x: (x[0], int(x[1])),
            enumerate(input().rstrip().split())))
temps = [nums.pop()]
result = [0 for _ in range(N)]

while nums:
    curIndex, curHeight = nums.pop()

    while temps:
        tempIndex, tempHeight = temps[-1]

        if curHeight > tempHeight:
            result[tempIndex] = curIndex + 1
            temps.pop()
        else:
            break

    temps.append((curIndex, curHeight))


while temps:
    curIndex, _ = temps.pop()
    result[curIndex] = 0

for num in result:
    print(num, end=" ")
