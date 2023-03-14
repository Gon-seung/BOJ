def solution(ingredient):
    answer = 0
    info = []
    for i in ingredient:
        info.append(i)
        while len(info) > 3:
            if info[-4:] == [1, 2, 3, 1]:
                answer += 1
                for _ in range(4):
                    info.pop()
            else:
                break

    return answer