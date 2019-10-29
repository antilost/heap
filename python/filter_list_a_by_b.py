#!/usr/bin/env python3

def filter(a, b):
    res = []
    b_i = 0
    for elem in a:
        while b_i < len(b) and b[b_i] < elem:
            b_i += 1
        if b_i == len(b) or b[b_i] > elem:
            res.append(elem)
    return res

assert( filter([], []) == [])
assert( filter([1,2,3,4], []) == [1,2,3,4] )
assert( filter([1,2,3,4], [2]) == [1,3,4] )
assert( filter([1,2,3,4], [0,1,3,4]) == [2] )
assert( filter([1,2,3,4], [0,9,10,12]) == [1,2,3,4] )
print("ok")

