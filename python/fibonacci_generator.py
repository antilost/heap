#!/usr/bin/env python

# Fibonacci numbers generator

def fibonacci():
    prev = 0
    yield prev
    current = 1
    yield current
    while True:
        now = prev + current
        yield now
        prev = current
        current = now    

if __name__ == '__main__':
    f = fibonacci()
    for i in range(0, 30):
        print(i, f.next())
