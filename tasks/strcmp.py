#!/usr/bin/env python

'''
    Сравнение строк как в C string.h
'''

def strcmp(s1, s2):
	n1 = len(s1)
	n2 = len(s2)
	if n1 != n2:
		return n1 > n2 and 1 or -1
	for i, c in enumerate(s1):
		if c < s2[i]:
			return -1
		if c > s2[i]:
			return 1
	return 0


for c in [
		['abc', 'abc'], ['abc', 'abd'], ['abd', 'abc'], ['abcd', 'abdd'], ['abdd', 'abcd'],
		['a', ''], ['ab', 'a'], ['c', 'de'],
		['', 'a'], ['a', 'ab'], ['de', 'c']
	]:
	(s1, s2) = c
	print(s1, s2, strcmp(s1, s2))
