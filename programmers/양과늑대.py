def solution(info, edges):
    answer = 0
    total_info = save_info(info, edges, 0)
    print(total_info)
    return total_info[0]


def save_info(info, edges, now):
    answer = {}
    # 마지막일 경우
    if info[now] == 0:
        answer.update({0: 1})
    else:
        answer.update({1: 0})

    for node1, node2 in edges:
        if now == node1:
            child_info = save_info(info, edges, node2)
            new_answer = {}
            for wolf1 in answer:
                for wolf2 in child_info:
                    if wolf1 + wolf2 in new_answer and new_answer[wolf1 + wolf2] < answer[wolf1] + child_info[wolf2]:
                        new_answer[wolf1 + wolf2] = answer[wolf1] + child_info[wolf2]
                    elif wolf1 + wolf2 not in new_answer:
                        new_answer.update({wolf1 + wolf2: answer[wolf1] + child_info[wolf2]})
            for wolf1 in answer:
                if wolf1 not in new_answer:
                    new_answer.update({wolf1: answer[wolf1]})
            answer = new_answer.copy()
    print(now, answer)
    return answer

solution([0,0,1,1,1,0,1,0,1,0,1,1],	[[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]])