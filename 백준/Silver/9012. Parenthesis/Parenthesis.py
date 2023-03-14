import sys
input = sys.stdin.readline

n = int(input())

for i in range(n):
    arr = []
    str = input().rstrip()
    for j in range(len(str)):
        if (str[j] == '('):
            arr.append(str[j])
        elif (str[j] == ')' and len(arr) == 0):
            arr.append(1)
            break
        else:
            arr.pop()
    if (len(arr) == 0):
        print("YES")
    else:
        print("NO")
