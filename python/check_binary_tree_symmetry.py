#!/usr/bin/env python2.7

class Node(object):
    def __init__(self, value, left, right):
        self.value = value
        self.left = left;
        self.right = right;

class BinTree(object):
    def __init__(self, root):
        self.root = root

    def is_symmetric(self):
        if self.root is None:
            return True
        return self._is_symmetric_nodes(self.root.left, self.root.right)

    def _is_symmetric_nodes(self, nl, nr):
        if (nl is None) and (nr is None):
            return True
        if (nl is None) or (nr is None):
            return False
        return (nl.value == nr.value) and self._is_symmetric_nodes(nl.left, nr.right) and self._is_symmetric_nodes(nl.right, nr.left)

    def str_bfs(self):
        Q = [self.root]
        result = None
        while len(Q) > 0:
            tmp = " ".join([ str(n.value) if n is not None else "_" for n in Q])
            QN = []
            for n in Q:
                if n is not None:
                    QN.append(n.left)
                    QN.append(n.right)
            Q = QN
            if result is None:
                result = ""
            else:
                result += " | "
            result += tmp
        return result

#    a
#   / \
#  b   c
# / \ / \
# d e f g
def get_tree(a, b=None, c=None, d=None, e=None, f=None, g=None):
    nd = None
    if d is not None:
        nd = Node(d, None, None)
    ne = None
    if e is not None:
        ne = Node(e, None, None)
    nf = None
    if f is not None:
        nf = Node(f, None, None)
    ng = None
    if g is not None:
        ng = Node(g, None, None)
    nb = None
    if b is not None:
        nb = Node(b, nd, ne)
    nc = None
    if c is not None:
        nc = Node(c, nf, ng)
    na = None
    if a is not None:
        na = Node(a, nb, nc)
    return BinTree(na)

if __name__ == '__main__':
    assert( get_tree(None).is_symmetric() == True )
    assert( get_tree(1).is_symmetric() == True )
    assert( get_tree(1, 1, 1).is_symmetric() == True )
    assert( get_tree(1, 2, 2).is_symmetric() == True )
    assert( get_tree(1, 2, 2, None, 3, 3, None).is_symmetric() == True )
    assert( get_tree(1, 2, 2, 5, 3, 3, 5).is_symmetric() == True )
    assert( get_tree(1, 2, 2, 3, None, None, 3).is_symmetric() == True )
    assert( get_tree(1, None, 2).is_symmetric() == False )
    assert( get_tree(1, 2, None).is_symmetric() == False )
    assert( get_tree(1, 2, 5).is_symmetric() == False )
    assert( get_tree(1, 2, 2, 8, 3, 3, None).is_symmetric() == False )
    assert( get_tree(1, 2, 2, 5, 3, 4, 5).is_symmetric() == False )
    assert( get_tree(1, 2, 2, 3, None, 8, 3).is_symmetric() == False )
