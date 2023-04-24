import sys

input = sys.stdin.readline
sum = 0

n = int(input())
for i in range(1,n):
    sum += i
    
print(sum)
print("2")
