import sys
from collections import deque
import heapq

input = sys.stdin.readline

def solution1(id_list, report, k):
    answer = []
    info = dict()

    answer_info = dict()
    for i in id_list:
        info.update({i : set()})
        answer_info.update({i : set()})
    for string in report:
        a,b = string.split(" ")
        info[b].add(a)

    for string in report:
        a,b = string.split(" ")
        if len(info[b]) >= k:
            answer_info[a].add(b)
    #print(answer_info)
    #print(info)
    for i in id_list:
        answer.append(len(answer_info[i]))
    return answer


def solution(id_list, report, k):
    answer = []

    count_id = {}
    reporter = {}
    for a, b in map(lambda x: x.split(), report):
        if a not in reporter:
            reporter.update({a: set()})
            reporter[a].add(b)
        else:
            reporter[a].add(b)

        if b not in count_id:
            count_id.update({b: set()})
            count_id[b].add(a)
        else:
            count_id[b].add(a)

    name_list = []
    print(count_id, reporter)
    for i in count_id:
        if len(count_id[i]) >= k:
            name_list.append(i)

    for i in id_list:
        tmp = 0
        if i in reporter:
            for j in reporter[i]:
                if j in name_list:
                    tmp += 1
        answer.append(tmp)
    return answer

solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"], 2)
