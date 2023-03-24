import sys

input1 = sys.stdin.readline()
input2 = sys.stdin.readline()
num = len(input1)
dp = [[0 for _ in range(num)] for _ in range(num)]

for i in range(num):
    alphabet = input1[i]
    for j in range(num):
        if input2[j] == alphabet:
            dp[i][j] = max(dp[i][j-1], dp[i-1][j] + 1)
        else:
            dp[i][j] = dp[i][j-1]
