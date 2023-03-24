import sys

num = int(sys.stdin.readline())
info = list(map(int, sys.stdin.readline().split()))

dict_info = {}
for i in info:
    if i not in dict_info:
        dict_info.update({i: 1})
    for num in dict_info:
        value = dict_info[num]
        if num < i and dict_info[i] < value + 1:
            dict_info[i] = value + 1

#print(dict_info)
answer = 0
for i in dict_info:
    if dict_info[i] > answer:
        answer = dict_info[i]
print(answer)