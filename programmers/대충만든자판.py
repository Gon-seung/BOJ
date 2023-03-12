def solution(keymap, targets):
    answer = []
    dictionary = {}
    for key_info in keymap:
        for key_order in range(len(key_info)):
            value = key_info[key_order]
            if value in dictionary and dictionary[value] > key_order + 1:
                dictionary[value] = key_order + 1
            elif value not in dictionary:
                dictionary.update({value: key_order + 1})

    for target_info in targets:
        result_count = 0
        for value in target_info:
            if value in dictionary:
                result_count += dictionary[value]
            else:
                result_count = -1
                break
        answer.append(result_count)
    return answer
