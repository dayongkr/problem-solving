import sys
input = sys.stdin.readline

special_str = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

str = input().rstrip()

count = 0

for s in special_str:
    str = str.replace(s, '*')

print(len(str))