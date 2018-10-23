#!/usr/bin/env python

# Linear-complexity algorithms to combine or intersect lists

def combine_lists(a, b):
    c = []
    (i, j) = (0, 0)
    while (i < len(a)) and (j < len(b)):
        while (i < len(a)) and (a[i] <= b[j]):
            c.append(a[i])
            i += 1
        while (j < len(b)) and (a[i] >= b[j]):
            c.append(b[j])
            j += 1
    while i < len(a):
        c.append(a[i])
        i += 1
    while j < len(b):
        c.append(b[b])
        j += 1
    return c

def intersect_lists(a, b):
    c = []
    (i, j) = (0, 0)
    while (i < len(a)) and (j < len(b)):
        while (i < len(a)) and (a[i] < b[j]):
            i += 1
        while (j < len(b)) and (a[i] > b[j]):
            j += 1
        while (i < len(a)) and (j < len(b)) and (a[i] == b[j]):
            c.append(a[i])
            i += 1
            j += 1
    return c

if __name__ == '__main__':
    aa = [1,1,2,4,5,5,5,9,10,11,12]
    bb = [1,3,6]
    cc = combine_lists(aa, bb)
    print(cc)

    aa = [1,1,1,2,4,5,5,5,9,10,11,12]
    bb = [1,1,1,3,5,5,6,10]
    cc = intersect_lists(aa, bb)
    print(cc)
