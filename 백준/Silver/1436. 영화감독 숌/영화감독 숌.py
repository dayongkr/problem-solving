import sys

input = sys.stdin.readline

n = int(input())
num = 665

while True:
    num += 1
    if '666' in str(num):
        n -= 1
    if n == 0:
        break

print(num)
