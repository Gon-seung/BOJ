
import sys

wei_num = int(sys.stdin.readline())
wei = list(map(int,sys.stdin.readline().split()))
check_num = int(sys.stdin.readline())
check = list(map(int,sys.stdin.readline().split()))

dp = [set() for _ in range(wei_num)]

dp[0] = set([wei[0]])
for i in range(1,wei_num):
    dp[i].add(wei[i])
    for j in dp[i-1]:
        dp[i].add(j + wei[i])
        dp[i].add(j)
        dp[i].add(abs(j - wei[i]))

for i in range(check_num):
    if(check[i] in dp[-1]):
        print("Y" , end = " ")
    else:
        print("N" , end = " ")