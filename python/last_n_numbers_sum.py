#!/usr/bin/env python3

from collections import deque

class LastNumbersSum(object):
    def __init__(self, n):
        self.deque = deque(maxlen=n)

    def append(self, number):
        self.deque.append(number)

    def sum(self):
        sum = 0
        for i in self.deque:
            sum += i
        return sum


last = LastNumbersSum(3)
assert last.sum() == 0

last.append(1)
assert last.sum() == 1

last.append(2)
last.append(4)
assert last.sum() == 7

last.append(2)
assert last.sum() == 8
