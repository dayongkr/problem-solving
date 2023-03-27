import sys
input = sys.stdin.readline

n = 0;

for _ in range(int(input())):
    str = input().rstrip()
    arr = ""
    for i in range(len(str)):
        if i + 1 == len(str):
            n+=1
            break
        elif str[i] != str[i + 1] and str[i+1:].find(str[i]) != -1:
            break

print(n)