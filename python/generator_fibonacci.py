#!/usr/bin/env python

def fibonacci():
    prev = 0
    yield(prev)
    this = 1
    yield(this)
    while True:
        new = prev + this
        yield(new)
        prev = this
        this = new

def main():
    g = fibonacci()
    for i in range(0, 100):
        print('{} {}'.format(i, g.next()))

if __name__ == '__main__':
    main()
