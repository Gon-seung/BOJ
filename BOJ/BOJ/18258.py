from collections import deque
import sys

save = deque()
num = int(sys.stdin.readline())

for i in range(num):
    order = sys.stdin.readline().split()
    if order[0] == 'push':
        save.append(int(order[1]))
    elif order[0] == "pop":
        if len(save) == 0:
            print(-1)
        else:
            number = save.popleft()
            print(number)
    elif order[0] == "size":
        print(len(save))
    elif order[0] == "empty":
        if(len(save)) == 0:
            print(1)
        else:
            print(0)
    elif order[0] == "front":
        if(len(save)) == 0:
            print(-1)
        else:
            print(save[0])
    elif order[0] == "back":
        if(len(save)) == 0:
            print(-1)
        else:
            print(save[-1])
