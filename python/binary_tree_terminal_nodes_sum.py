#!/usr/bin/env python
# -*- coding: utf-8 -*-

from collections import deque

"""
Дано бинарное дерево, значения в нем - числа. Нужно написать функцию, которая возвращает сумму всех узлов дерева, у которых нет потомков.
Например, для дерева
    5
   / \
  4   2
 / \   \
1   6   3
       /
      7
Результатом будет число 14 (1 + 6 + 7).
"""

class Node(object):
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

d1 = Node(7)
c1 = Node(1)
c2 = Node(6)
c3 = Node(3, d1)
b1 = Node(4, c1, c2)
b2 = Node(2, None, c3)
a1 = Node(5, b1, b2)

def bfs(root):
    q = [root]
    result = 0
    while q:
        q_next = []
        for p in q:
            children_to_traverse = [
                c for c in (p.left, p.right) if c is None
            ]
            if children_to_traverse:
                q_next.extend(children_to_traverse)
            else:
                result += p.value
        q = q_next
    return result

def dfs(p):
    result = 0
    children_to_traverse = [
        c for c in (p.left, p.right) if c is not None
    ]
    if children_to_traverse:
        for c in children_to_traverse:
            result += dfs(c)
    else:
        return p.value
    return result

r = bfs(a1)
print(r)

r = dfs(a1)
print(r)
