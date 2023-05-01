import sys

input = sys.stdin.readline

n = int(input())

if(n == 1):
    exit(0)

i = 2

while i <= n:
    if n % i == 0:
        print(i)
        n //= i
    else:
        i += 1