import sys

input = sys.stdin.readline

n = int(input())
arr = list()
arr_dict = dict()
r_sum = 0

for i in range(n):
    c = int(input())
    r_sum += c
    arr.append(c)
    arr_dict[c] = arr_dict.get(c,0) + 1
arr = sorted(arr)
# 평균
print(round(r_sum/n))
# 중앙값
print(arr[n//2])
# 최빈값
arr_dict = sorted(arr_dict.items(), key=lambda x: (-x[1], x[0]))
print(arr_dict[0][0] if len(arr_dict) == 1 or arr_dict[0][1] != arr_dict[1][1] else arr_dict[1][0])
# 범위
print(arr[n-1] - arr[0])
