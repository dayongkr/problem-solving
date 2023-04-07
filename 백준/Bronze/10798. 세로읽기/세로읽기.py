import sys
input = sys.stdin.readline

strArr = []

for _ in range(5):
    strArr.append(input().rstrip().ljust(15, ' '))
for i in range(15):
    for j in range(5):
        if strArr[j][i] != ' ':
            print(strArr[j][i], end='')