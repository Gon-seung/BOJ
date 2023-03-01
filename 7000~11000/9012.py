from collections import deque
import sys

casenum = int(sys.stdin.readline())

for _ in range(casenum):
    input = sys.stdin.readline()
    count = 0
    VPS = True

    for i in range(len(input) - 1):
        if input[i] == "(":
            count += 1
        else:
            count -=1
        if count < 0 :
            VPS = False
            break
    if count != 0:
        VPS = False
    
    if(VPS):
        print("YES")
    else:
        print("NO")