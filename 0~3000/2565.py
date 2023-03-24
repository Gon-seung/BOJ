import sys

#num = int(sys.stdin.readline())
N, K = map(int, sys.stdin.readline().split())

info = []
for _ in range(N):
    W, V = map(int, sys.stdin.readline().split())
    info.append([W, V])
dict_info = {}
for w, v in info:
    new_dict_info = {}
    for i in dict_info:
        value = dict_info[i]
        if i <= K:
            if i in new_dict_info and new_dict_info[i] < value:
                new_dict_info[i] = value
            elif i not in new_dict_info:
                new_dict_info.update({i: value})
        if i + w <= K:
            if i + w in new_dict_info and new_dict_info[i + w] < value + v:
                new_dict_info[i + w] = value + v
            elif i + w not in new_dict_info:
                new_dict_info.update({i + w: value + v})
    if w <= K:
        if w in new_dict_info and new_dict_info[w] < v:
            new_dict_info[w] = v
        elif w not in new_dict_info:
            new_dict_info.update({w: v})
    dict_info = new_dict_info.copy()

answer = 0
for i in dict_info:
    if dict_info[i] > answer:
        answer = dict_info[i]
print(answer)
