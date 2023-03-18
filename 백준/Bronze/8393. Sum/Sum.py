import sys
input = sys.stdin.readline

num = int(input())
result = (num+1)*(int(num/2))

if num % 2:
    result += (int(num/2)+1)

print(result)