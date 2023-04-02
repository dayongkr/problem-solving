import sys
input = sys.stdin.readline

s = input().rstrip()
s_f = s[0:len(s)//2]
s_b = s[len(s)//2 if len(s) % 2 == 0 else len(s) // 2 +1:][::-1]

if s_f == s_b:
    print(1)
else:
    print(0)