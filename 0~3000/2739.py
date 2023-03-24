
from collections import deque
import sys

input_value = int(sys.stdin.readline())
def answer(num):
    for i in range(1, 10):
        print(num, "*", i, "=", i * num)


answer(input_value)
