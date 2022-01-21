from collections import deque
import sys

#casenum = int(sys.stdin.readline())

while(True):
    input = sys.stdin.readline()
    if input[0] == "." and len(input) == 2:
        break
    data = deque()
    balance = True
    for i in range(len(input) - 1):
        if input[i] == "(" or input[i] == "[":
            data.append(input[i])
        elif input[i] == ")":
            if len(data) > 0 and data[-1] == "(":
                data.pop()
            else:
                balance = False
                break
        elif input[i] == "]":
            if len(data) > 0 and data[-1] == "[":
                data.pop()
            else:
                balance = False
                break
    if(len(data) > 0):
        balance = False
    if(balance):
        print("yes")
    else:
        print("no")
