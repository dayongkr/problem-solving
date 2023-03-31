import sys
input = sys.stdin.readline

n = int(input())

def print_star(i):
    star_count = i * 2 - 1
    blank_count = n-i
    print(" " * blank_count+"*" * star_count)


for i in range(1, n+1):
    print_star(i)

for i in range(n-1, 0, -1):
    print_star(i)