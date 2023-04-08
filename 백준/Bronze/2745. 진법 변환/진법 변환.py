import sys
input = sys.stdin.readline

num, b = input().split()
b = int(b)
dec = 0

for i in range(len(num)):
    if ord(num[i]) >= 65:
        dec += (ord(num[i]) - 55) * (b**(len(num)-i-1))
    else:
        dec += int(num[i]) * (b**(len(num)-i-1))
print(dec)