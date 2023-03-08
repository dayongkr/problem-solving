a = list(map(int, input().split(" ")))

if (a[1] >= 45):
    print("{0} {1}".format(a[0], a[1] - 45))
elif (a[0] == 0):
    print("{0} {1}".format(23, 60-45+a[1]))
else:
    print("{0} {1}".format(a[0]-1, 60-45+a[1]))