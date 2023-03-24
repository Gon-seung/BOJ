import sys


def make_string_to_num(str_value):
    answer = 0
    for i in map(int, str_value.split('+')):
        answer += i
    return answer


input_value = sys.stdin.readline()[:-1]
split_value = input_value.split('-')
answer = make_string_to_num(split_value[0])
for i in split_value[1:]:
    answer -= make_string_to_num(i)
print(answer)
