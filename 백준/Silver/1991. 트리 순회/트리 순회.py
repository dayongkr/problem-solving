import sys

input = sys.stdin.readline

N = int(input())
d = dict()

for _ in range(N):
    a, b, c = input().split()
    d[a] = []
    d[a].append(b)
    d[a].append(c)


def pre(target):
    if target != '.':
        print(target, end='')
        pre(d[target][0])
        pre(d[target][1])


def inorder(target):
    if target != '.':
        inorder(d[target][0])
        print(target, end='')
        inorder(d[target][1])


def post(target):
    if target != '.':
        post(d[target][0])
        post(d[target][1])
        print(target, end='')


pre('A')
print()
inorder('A')
print()
post('A')
