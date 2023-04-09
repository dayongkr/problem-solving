import sys
input = sys.stdin.readline

dec, b = map(int, input().split())
result = ""

while dec > 0:
    item = dec % b
    item = chr(item + 55) if item > 9 else str(item)
    result += item
    dec //= b

print(result[::-1])
