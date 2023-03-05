import sys
input = sys.stdin.readline

a = list(map(int, input().split(" ")))

arr = []
b = 0
print("<", end="")
for _ in range(a[0]):
    c = 0
    if (_ != 0):
        print(", ", end="")
    while 1:
        b += 1
        if b > a[0]:
            b = 1
        if b in arr:
            continue
        c += 1
        if c == a[1]:
            arr.append(b)
            print(b, end="")
            break
print(">")
