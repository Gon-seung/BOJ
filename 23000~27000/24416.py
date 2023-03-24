import sys


num = int(sys.stdin.readline())


def fib(n):
    start1 = 1
    start2 = 1
    answer = [1, 1]
    if n == 1 or n == 2:
        return 1
    for i in range(3, n+1):
        answer.append(answer[-1] + answer[-2])
    return answer[-1]

print(fib(num), num-2)
