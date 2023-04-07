import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    quarters = int(n / 25)
    n = n % 25
    dimes = int(n / 10)
    n = n % 10
    nickels = int(n / 5)
    n = n % 5
    pennies = n
    print(quarters, dimes, nickels, pennies)