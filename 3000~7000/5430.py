import sys
from collections import deque


num = int(sys.stdin.readline())
for _ in range(num):
    orders = sys.stdin.readline()[:-1]
    length = int(sys.stdin.readline())
    list_info = deque(sys.stdin.readline()[1:-2].split(','))
    if list_info[0] == '':
        list_info.pop()
    del_mode = 'left'
    answer = "["
    for order in orders:
        answer = "["
        if order == 'R':
            if del_mode == 'right':
                del_mode = 'left'
            else:
                del_mode = 'right'
        else:
            if not list_info:
                answer = "error"
                break
            if del_mode == 'left':
                list_info.popleft()
            else:
                list_info.pop()
    if answer != "error":
        while list_info:
            if del_mode == 'right':
                answer += list_info.pop()
            else:
                answer += list_info.popleft()
            answer += ","
        if answer[-1] == ',':
            answer = answer[:-1]
        answer += "]"
    print(answer)
