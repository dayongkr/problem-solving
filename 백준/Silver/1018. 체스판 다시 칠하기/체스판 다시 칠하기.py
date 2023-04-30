import sys

input = sys.stdin.readline

n, m = map(int, input().split())

board = [list(input().strip()) for _ in range(n)]
min_count = 64

for j in range(n - 7):
    for i in range(m - 7):
        count1 = 0
        count2 = 0
        flag = 0 if board[j][i] == "W" else 1
        for y in range(8):
            for x in range(8):
                if (x + y + flag) % 2 == 0 and board[y + j][x + i] != "W":
                    count1 += 1
                elif (x + y + flag) % 2 == 1 and board[y + j][x + i] != "B":
                    count1 += 1

                if (x + y + flag) % 2 == 0 and board[y + j][x + i] != "B":
                    count2 += 1
                elif (x + y + flag) % 2 == 1 and board[y + j][x + i] != "W":
                    count2 += 1

        if min_count > min(count1, count2):
            min_count = min(count1, count2)

print(min_count)
