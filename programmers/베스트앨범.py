def find_two(genres, plays):
    answer = {}
    for i in genres:
        if i not in answer:
            answer.update({i: []})
    for i in range(len(genres)):
        genre = genres[i]
        new_value = []
        value = answer[genre]
        if len(value) == 0:
            new_value.append(i)
        elif len(value) == 1:
            if plays[value[0]] < plays[i]:
                new_value = [i, value[0]]
            else:
                new_value = [value[0], i]
        else:
            if plays[value[0]] < plays[i]:
                new_value = [i, value[0]]
            elif plays[value[1]] < plays[i]:
                new_value = [value[0], i]
            else:
                new_value = [value[0], value[1]]
        answer[genre] = new_value.copy()
    return answer


def solution(genres, plays):
    answer = []
    genres_info = {}
    num = len(genres)
    for i in range(num):
        if genres[i] not in genres_info:
            genres_info.update({genres[i]: plays[i]})
        else:
            genres_info[genres[i]] += plays[i]

    genres_info = sorted(genres_info.items(), key=lambda x: -x[1])
    top_two_info = find_two(genres, plays)
    for genre, _ in genres_info:
        for pos in top_two_info[genre]:
            answer.append(pos)
    return answer

