import sys

num, length = map(int, sys.stdin.readline().split())
info = list(map(int, sys.stdin.readline().split()))
answer = sum(info[0:length])
sum_of_len = answer
for i in range(length, num):
    sum_of_len += info[i]
    sum_of_len -= info[i - length]
    if answer < sum_of_len:
        answer = sum_of_len
print(answer)

