def solution(s):
    answer = 0
    count0 = 0
    count1 = 0
    pos = s[0]
    for i in range(len(s)):
        if s[i] == pos:
            count0 += 1
        else:
            count1 += 1

        if count0 == count1:
            if i < len(s) - 1:
                pos = s[i + 1]
            count0 = 0
            count1 = 0
            answer += 1
            print(i)
            continue
    if count0 != count1:
        answer += 1
    return answer