def make_prime_array(e):
    answer = []
    int_array = [True for _ in range(e + 1)]
    int_array[0] = False
    int_array[1] = False
    for pos in range(1, e + 1):
        if int_array[pos]:
            answer.append(pos)
            new_pos = pos * 2
            while new_pos <= e:
                int_array[new_pos] = False
                new_pos += pos
    return answer


def find_number(prime_array, num):
    answer = 1
    div_info = 0
    for prime in prime_array:
        if prime > num:
            break
        count = 0
        while num % prime == 0:
            count += 1
            num /= prime
        answer *= (count + 1)
    return answer


def solution(e, starts):
    answer = []
    prime_array = make_prime_array(e)

    count_array = [0 for _ in range(e + 1)]
    for i in range(min(starts), e + 1):
        count_array[i] = find_number(prime_array, i)

    max_value_array = [e for _ in range(e + 1)]
    max_value = e
    for i in range(e, -1, -1):
        if count_array[i] >= count_array[max_value]:
            max_value_array[i] = i
            max_value = i
        else:
            max_value_array[i] = max_value
    for i in starts:
        answer.append(max_value_array[i])
    return answer
