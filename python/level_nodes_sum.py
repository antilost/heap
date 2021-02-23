#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Дано дерево с выделенным корнем.
Далее приходит K запросов, каждый запрос - целое неотрицательное число, расстояние от корня.
Для каждого запроса нужно найти сумму элементов в дереве на расстоянии от корня не более заданного.
В более простом варианте можно спрашивать сумму элементов в дереве на заданном расстоянии от корня.

Ограничения:
* Исходное дерево менять нельзя.
* При препроцессинге можно использовать доп. память.
* Ограничения на обработку одного запроса — O(1) по времени и по памяти.
"""

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

class Handler:
    def __init__(self, root):
        self.root = root
        self.levels = []
        self._construct_levels(root, 0)
    
    def _construct_levels(self, node, level):
        if level > len(self.levels) - 1:
            self.levels.append(node.value)
        else:
            self.levels[level] += node.value
        if node.left is not None:
            self._construct_levels(node.left, level + 1)
        if node.right is not None:
            self._construct_levels(node.right, level + 1)

    def sum(self, level):
        return self.levels[level]

"""
    5
   / \
  4   2
 / \   \
1   6   3
       /
      7
"""
t = Node(5)
t.left = Node(4)
t.left.left = Node(1)
t.left.right = Node(6)
t.right = Node(2)
t.right.right = Node(3)
t.right.right.left = Node(7)

handler = Handler(t)
for i in range(0,4):
    print(i, handler.sum(i))
