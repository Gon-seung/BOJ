def change_binary(num):
    answer = ""
    while num != 0:
        answer = str(num % 2) + answer
        num //= 2
    tar_length = 1
    while len(answer) + 1 > tar_length:
        tar_length *= 2
    while len(answer) + 1 != tar_length:
        answer = "0" + answer
    return answer


def check_1(binary):
    if len(binary) == 1:
        if binary[0] == '1':
            return 1
        else:
            return 0
    mid = len(binary) // 2
    if binary[mid] == '1':
        return check_1(binary[mid + 1:]) + check_1(binary[0:mid]) + 1
    return 0


def solution(numbers):
    answer = []
    for num in numbers:
        binary_int = change_binary(num)
        count_1 = 0
        for i in binary_int:
            if i == '1':
                count_1 += 1
        if count_1 != check_1(binary_int):
            answer.append(0)
        else:
            answer.append(1)
    return answer
