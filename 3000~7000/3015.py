import sys


num = int(sys.stdin.readline())
stack_info = []
answer = 0
for pos in range(num):
    value = int(sys.stdin.readline())
    while stack_info and stack_info[-1][1] < value:
        asis_pos, _ = stack_info.pop()
        answer += 1
    stack_info.append([pos, value])
