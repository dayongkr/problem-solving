import sys

input = sys.stdin.readline

n = int(input())

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

arr = []
cnt = []
count = 0
quque = []

for _ in range(n):
    arr.append(list(map(int, input().rstrip())))

for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            quque.append([i, j])
            arr[i][j] = 0
            cnt.append([])
            while (len(quque)):
                temp = quque.pop(0)
                cnt[count].append(temp)
                for k in range(4):
                    x = temp[1] + dx[k]
                    y = temp[0] + dy[k]
                    if x < 0 or x >= n or y < 0 or y >= n:
                        continue
                    if arr[y][x] == 1:
                        quque.append([y, x])
                        arr[y][x] = 0

            count += 1

print(len(cnt))
for i in range(len(cnt)):
    cnt.sort(key=lambda x: len(x))
    print(len(cnt[i]))
