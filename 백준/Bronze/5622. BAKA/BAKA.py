import sys
import math
input = sys.stdin.readline

dial = input().rstrip()
count = 0

for c in dial:
    asc = ord(c)
    if(c == 'S'):
        count += 8
    elif(c == 'V'):
        count += 9
    elif(asc >= ord('Y')):
        count += 10
    else:
        count += math.ceil((asc - 64) / 3) + 2

print(count)