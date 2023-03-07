num = int(input())

n = 1
result = 0

while (n < num):
    n *= 5
    result += int(num / n)

print(result)