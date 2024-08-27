import math
import sys

input = sys.stdin.readline

N = int(input())
divide = 10
result = 0

while N // divide >= 1:
    result += 0.9 * divide * round(math.log(divide, 10))
    divide *= 10

result += (N - (divide / 10) + 1) * round(math.log(divide, 10))

print(int(result))
