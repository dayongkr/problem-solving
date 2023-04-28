import sys

input = sys.stdin.readline

n,m = map(int,input().split())
arr = sorted(list(map(int,input().split())))

max_val = 0

for i in range(n):
    for j in range(i+1,n):
        for k in range(j+1,n):
            sum_val = arr[i] + arr[j] + arr[k]
            if m > sum_val > max_val:
                max_val = sum_val
            if sum_val == m:
                print(m)
                exit(0)
print(max_val)