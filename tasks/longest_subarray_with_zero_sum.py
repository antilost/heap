#!/usr/bin/env python2.7
# -*- coding: utf-8 -*-

'''
    Найти максимальную по длине последовательность элементов в массиве, сумма которых равна 0
'''

from __future__ import print_function

a = [ -13,  13, -3, -25,  20, -3, -16, -23,  19,  20,  -7,  12, -5, -22,  15,  -4,   7 ]
#       0, -13,  0,  -3, -28, -8, -11, -27, -50, -31, -11, -18, -6, -11, -33, -18, -22
#a = [1, 2, 3, -6]

a.append(0)

print(map( (lambda x: '{0:4.0f}'.format(x)), range(0, len(a))))
print(map( (lambda x: '{0:4.0f}'.format(x)), a))

s = 0
d = {}
for i in range(0, len(a)):
	e = i - 1
	if not s in d:
		d[s] = dict(l=i, r=e)
	else:
		if e > d[s]['r']:
			d[s]['r'] = e
	s += a[i]

(max_len, l, r) = (None, None, None)
for s in d:
	this_len = d[s]['r'] - d[s]['l']
	if max_len is None or this_len > max_len:
		(max_len, l, r) = (this_len, d[s]['l'], d[s]['r'])
print(max_len, l, r, sum(a[l:r+1]))
