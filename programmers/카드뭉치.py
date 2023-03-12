def solution(cards1, cards2, goal):
    answer = ''

    pos1 = 0
    pos2 = 0
    for i in goal:
        if pos1 < len(cards1) and i == cards1[pos1]:
            pos1 += 1
        elif pos2 < len(cards2) and i == cards2[pos2]:
            pos2 += 1
        else:
            return "No"
    return "Yes"


asd = ["1 1", "2 2", "3 3"]


def a(input1):
    return input1.split()


print(list(map(a, asd)))
