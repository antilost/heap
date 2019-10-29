#!/usr/bin/env python

# Classes to implement linked-list object
# Reverse list algorithm

class Node(object):
    def __init__(self, value, next):
        self.value = value
        self.next = next

class List(object):
    def __init__(self):
        self.head = None
    
    def add(self, value):
        n = Node(value, self.head)
        self.head = n
    
    def values(self):
        n = self.head
        while (n is not None):
            yield n.value
            n = n.next

    def reverse_list(self):
        h = self.head
        prev = None
        while (h is not None):
            t = h.next
            h.next = prev
            prev = h
            h = t
        self.head = prev
            

def main():
    l = List()
    l.add(1)
    l.add(3)
    l.add(8)
    l.add(5)
    l.add(4)
    print([ v for v in l.values()])
    l.reverse_list()
    print([ v for v in l.values()])

if __name__ == '__main__':
    main()
