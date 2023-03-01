from collections import deque
import sys
import time

casenum = int(sys.stdin.readline())


for _ in range(casenum):
    N,M = sys.stdin.readline().split()
    N = int(N)
    M = int(M)
    data = deque()
    data_imf =[0 for i in range(10)]

    input = sys.stdin.readline().split()
    for i in range(N):
        data.appendleft([i, int(input[i])])
        data_imf[int(input[i])] += 1

    while(data_imf[-1] == 0):
        data_imf.pop()
        
    count = 1
    while(True):
        if(data[-1][1] + 1 == len(data_imf)):
            if data[-1][0] == M:
                break
            data.pop()
            count += 1
            data_imf[-1] -= 1
            while(data_imf[-1] == 0):
                data_imf.pop()
        else:
            move = data.pop()
            data.appendleft(move)
        
    print(count)