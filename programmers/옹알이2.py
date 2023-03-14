def solution(babbling):
    answer = 0
    can_say = ['aya', 'ye', 'woo', 'ma']
    for word in babbling:
        pos = 0
        before_word = ""
        while pos != len(word):
            if pos + 3 <= len(word) and word[pos:pos+3] == 'aya' and before_word != 'aya':
                pos += 3
                before_word = 'aya'
            elif pos + 3 <= len(word) and word[pos:pos+3] == 'woo' and before_word != 'woo':
                pos += 3
                before_word = 'woo'
            elif pos + 2 <= len(word) and word[pos:pos+2] == 'ye' and before_word != 'ye':
                pos += 2
                before_word = 'ye'
            elif pos + 2 <= len(word) and word[pos:pos+2] == 'ma' and before_word != 'ma':
                pos += 2
                before_word = 'ma'
            else:
                break
        if pos == len(word):
            #print(word)
            answer += 1
    return answer
