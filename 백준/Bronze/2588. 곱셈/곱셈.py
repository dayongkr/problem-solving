import sys
input = sys.stdin.readline

num1 = int(input().rstrip())
num2 = input().rstrip()

print(num1 * int(num2[2]))
print(num1 * int(num2[1]))
print(num1 * int(num2[0]))
print(num1 * int(num2))