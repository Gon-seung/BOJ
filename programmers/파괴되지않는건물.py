import sys
from collections import deque
import heapq

input = sys.stdin.readline


def solution(board, skill):
    answer = 0
    n = len(board)
    m = len(board[0])
    dp = [[[dict() for _ in range(2)] for _ in range(m)] for _ in range(n)]
    # 0 가로, 1 세로
    for type, row1, col1, row2, col2, degree in skill:
        plus = degree
        if type == 1:
            plus = -plus
        for i in range(row1, row2 + 1):
            if col2 - col1 + 1 in dp[i][col1][0]:
                dp[i][col1][0][col2 - col1 + 1] += plus
            else:
                dp[i][col1][0].update({col2 - col1 + 1: plus})
        for i in range(col1, col2 + 1):
            if row2 - row1 + 1 in dp[row1][i][1]:
                dp[row1][i][1][row2 - row1 + 1] += plus
            else:
                dp[row1][i][1].update({row2 - row1 + 1: plus})

    for i in range(n):
        for j in range(m):
            for dis in dp[i][j][0]:
                for pos in range(dis):
                    board[i][j + pos] += dp[i][j][0][dis]
            for dis in dp[i][j][1]:
                for pos in range(dis):
                    board[i + pos][j] += dp[i][j][1][dis]

    for i in range(n):
        for j in range(m):
            if board[i][j] > 0:
                answer += 1
    print(board)
    return answer