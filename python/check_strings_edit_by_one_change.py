#!/usr/bin/env python

def one_edit_apart(s0, s):
    if len(s0) < len(s):
        s0, s = s, s0
    if abs(len(s0) - len(s)) > 1:
        return -1
    a, b = 0, 0
    change = 0
    while a < len(s0) and b < len(s):
        if s0[a] == s[b]:
            a += 1
            b += 1
        elif len(s0) == len(s):
            a += 1
            b += 1
            change += 1
        elif s0[a+1] == s[b]:
            a += 2
            b += 1
            change += 1
        if change > 1:
            return -1
    return 1

for aa, bb, result in [
    ('', '', 1),
    ('a', '', 1),
    ('', 'a', 1),
    ('a', 'a', 1),
    ('ab', 'ab', 1),
    ('ab', 'a', 1),
    ('b', 'ab', 1),
    ('abcd', 'abed', 1),
    ('', 'ab', -1),
    ('a', 'abc', -1),
    ('abcdd', 'abc', -1),
]:
    assert(result == one_edit_apart(aa, bb))
print("ok")

