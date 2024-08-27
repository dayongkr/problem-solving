import math
import sys
from collections import Counter

input = sys.stdin.readline
result = 0

N = int(input())
board = [list(input().rstrip()) for _ in range(N)]


def get_max_continuous(list):
    count = 0
    cur = 'None'
    maxCount = 0

    for item in list:
        if cur == item:
            count += 1
        else:
            cur = item
            maxCount = max(maxCount, count)
            count = 1

    maxCount = max(maxCount, count)

    return maxCount


for i in range(N):
    result = max(result, get_max_continuous(board[i]))
    result = max(result, get_max_continuous([board[j][i] for j in range(N)]))


for row in range(N):
    for col in range(N):
        if row != N - 1:
            board[row][col], board[row + 1][col] = board[row + 1][col], board[row][col]
            result = max(result, get_max_continuous(board[row]))
            result = max(result, get_max_continuous(board[row + 1]))
            result = max(result, get_max_continuous([board[i][col] for i in range(N)]))
            board[row][col], board[row + 1][col] = board[row + 1][col], board[row][col]

        if col != N - 1:
            board[row][col], board[row][col + 1] = board[row][col + 1], board[row][col]
            result = max(result, get_max_continuous(board[row]))
            result = max(result, get_max_continuous([board[i][col] for i in range(N)]))
            result = max(result, get_max_continuous([board[i][col + 1] for i in range(N)]))
            board[row][col], board[row][col + 1] = board[row][col + 1], board[row][col]

print(result)
