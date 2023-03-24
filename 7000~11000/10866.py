from collections import deque
import sys


num = int(sys.stdin.readline())
info = deque([])
for _ in range(num):
    orders = sys.stdin.readline().split()
    if orders[0] == "push_back":
        info.append(orders[1])
    elif orders[0] == "push_front":
        info.appendleft(orders[1])
    elif orders[0] == "pop_front":
        if info:
            value = info.popleft()
        else:
            value = "-1"
        print(value)
    elif orders[0] == "pop_back":
        if info:
            value = info.pop()
        else:
            value = "-1"
        print(value)
    elif orders[0] == "size":
        print(len(info))
    elif orders[0] == "empty":
        if not info:
            print("1")
        else:
            print("0")
    elif orders[0] == "front":
        if info:
            print(info[0])
        else:
            print("-1")
    elif orders[0] == "back":
        if info:
            print(info[-1])
        else:
            print("-1")
    else:
        print("error")
