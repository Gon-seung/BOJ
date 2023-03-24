import sys


num = int(sys.stdin.readline())
info = list(map(int, sys.stdin.readline().split()))
dict_info = {}
for i in info:
    if i not in dict_info:
        dict_info.update({i: 1})
    else:
        dict_info[i] += 1

stack = []
answer = [-1 for _ in range(num)]
for i in range(num):
    value = dict_info[info[i]]
    while stack:
        if stack[-1][1] < value:
            pos, _ = stack.pop()
            answer[pos] = info[i]
        else:
            break
    stack.append([i, value])
answer_string = " ".join(map(str, answer))
print(answer_string)


