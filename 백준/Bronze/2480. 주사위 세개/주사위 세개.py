import sys
input = sys.stdin.readline

num = list(map(int, input().split(" ")))

if num[0] == num[1]:
    if (num[1] == num[2]):
        print(10000 + num[0] * 1000)
    else:
        print(1000 + num[0]*100)
elif num[0] == num[2]:
    print(1000 + num[0]*100)
elif num[1] == num[2]:
    print(1000 + num[1]*100)
else:
    print(max(num) * 100)