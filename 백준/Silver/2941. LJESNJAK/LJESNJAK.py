import sys
input = sys.stdin.readline

special_str = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

str = input().rstrip()

count = 0

for s in special_str:
    count += str.count(s)

print(len(str) - count)