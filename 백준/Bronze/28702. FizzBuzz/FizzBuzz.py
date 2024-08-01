import sys
from math import ceil

input = sys.stdin.readline
strings = [input().strip() for _ in range(3)]

for i in range(3):
    string = strings[i]
    if string[0] not in ['F', 'B']:
        num = int(string) + 3 - i
        if num % 3 == 0:
            if num % 5 == 0:
                print("FizzBuzz")
            else:
                print("Fizz")
        elif num % 5 == 0:
            print("Buzz")
        else:
            print(num)
        break
