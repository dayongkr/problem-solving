def result(a, b):
    x = 0
    y = 0
    for i in range(len(a)):
        for j in range(len(b)):
            if a[i] > b[j]:
                x += 1
    for i in range(len(b)):
        for j in range(len(a)):
            if b[i] > a[j]:
                y += 1
    return x > y


n = int(input())
for i in range(n):
    str = list(map(int, input().split()))
    status = 0
    dieA = str[0:4]
    dieB = str[4:8]
    for a in range(1, 11):
        for b in range(1, 11):
            for c in range(1, 11):
                for d in range(1, 11):
                    dieC = [a, b, c, d]
                    if (result(dieA, dieB) and result(dieB, dieC) and result(dieC, dieA)):
                        status = 1
                        break
                    if (result(dieB, dieA) and result(dieA, dieC) and result(dieC, dieB)):
                        status = 1
                        break
    if (status):
        print("yes")
    else:
        print("no")
