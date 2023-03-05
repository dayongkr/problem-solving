import sys
input = sys.stdin.readline

n = int(input())
str = []
for _ in range(4):
    str.append(input().rstrip())

strSet = set()
for a in range(4):
    for b in range(4):
        if a in [b]:
            continue
        for c in range(4):
            if c in [a, b]:
                continue
            for d in range(4):
                if d in [a, b, c]:
                    continue
                for s1 in str[a]:
                    strSet.add(s1)
                    for s2 in str[b]:
                        strSet.add(s1+s2)
                        for s3 in str[c]:
                            strSet.add(s1+s2+s3)
                            for s4 in str[d]:
                                strSet.add(s1+s2+s3+s4)
for _ in range(n):
    chr = input().rstrip()
    if (chr in strSet):
        print("YES")
    else:
        print("NO")
