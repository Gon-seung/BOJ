import sys


input_value = sys.stdin.readline()[:-1]
bomb = sys.stdin.readline()[:-1]

answer = ""
for i in input_value:
    answer += i
    while len(answer) >= len(bomb) and answer[-len(bomb):] == bomb:
        answer = answer[:-len(bomb)]


if not answer:
    answer = "FRULA"
print(answer)
