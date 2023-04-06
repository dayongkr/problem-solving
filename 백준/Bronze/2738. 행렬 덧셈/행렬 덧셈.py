import sys
input = sys.stdin.readline

n,m = map(int,input().split())

arr = [ list(map(int,input().split())) for _ in range(n)]

for i in range(n):
    temp = list(map(int,input().split()))
    for j in range(m):
        print(arr[i][j] + temp[j],end=' ')
    print()