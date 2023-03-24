import sys

n, m = map(int, sys.stdin.readline().split())
info = list(map(int, sys.stdin.readline().split()))
info = list(map(lambda x: x % m, info))
dict_info = {}
answer = 0
sum_of_value = 0
for new_value in info:
    tmp = new_value
    new_value = (m - sum_of_value) % m
    sum_of_value = (sum_of_value + tmp) % m
    if new_value not in dict_info:
        dict_info.update({new_value: 1})
    else:
        dict_info[new_value] += 1
    if (m - sum_of_value) % m in dict_info:
        answer += dict_info[(m - sum_of_value) % m]
    #print(sum_of_value)
    #print(dict_info)

print(answer)

