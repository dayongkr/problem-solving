import sys
input = sys.stdin.readline

n = int(input().rstrip())
arr = []

for i in range(n):
    a = input().rstrip().split(" ")
    if a[0] == "push":
        arr.append(int(a[1]))
    elif a[0] == "front":
        if len(arr):
            print(arr[0])
        else:
            print(-1)
    elif a[0] == "back":
        if len(arr):
            print(arr[len(arr)-1])
        else:
            print(-1)
    elif a[0] == "size":
        print(len(arr))
    elif a[0] == "empty":
        if len(arr):
            print(0)
        else:
            print(1)
    elif a[0] == "pop":
        if len(arr):
            print(arr[0])
            arr = arr[1:]
        else:
            print(-1)