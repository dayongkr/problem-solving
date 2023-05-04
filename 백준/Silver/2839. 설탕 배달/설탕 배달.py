import sys

input = sys.stdin.readline

n = int(input())

a = n // 5

if n % 5 == 0:
    print(a)
    exit(0)

for i in range(a + 1):
    if (n - 5 * (a - i)) % 3 == 0:
        print(a - i + (n - 5 * (a - i)) // 3)
        exit(0)

print(-1)
