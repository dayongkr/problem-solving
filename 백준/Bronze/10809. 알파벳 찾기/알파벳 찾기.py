a = input()
b = [-1 for i in range(26)]

for c in range(len(a)):
    if (b[ord(a[c])-97] == -1):
        b[ord(a[c])-97] = c
for c in range(26):
    print(b[c], end=" ")