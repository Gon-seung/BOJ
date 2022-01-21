from collections import deque
import sys

casenum = int(sys.stdin.readline()) - 1

data = []

road = sys.stdin.readline().split()
city = sys.stdin.readline().split()

for i in range(casenum):
    road[i] = int(road[i])
    data.append([i, int(city[i])])


data = sorted(data, key = lambda x : x[1], reverse = True)
#print(data)

dis = 0
pos = len(road)
answer = 0
while(len(road) != 0):
    pos -= 1
    dis += road[-1]
    while(pos < data[-1][0]):
        data.pop()
    if(pos == data[-1][0]):
        answer += dis * data[-1][1]
        dis = 0
        data.pop()
    road.pop()
print(answer)
