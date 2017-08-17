#!/usr/bin/env python2.7
# -*- coding: utf-8 -*-

'''
	!!!UNFINISHED!!!

    Найти максимальную по длине последовательность элементов в массиве, сумма которых равна 0
'''

from __future__ import print_function


def get_longest_subarray_with_target_sum(a, target_sum):
	# a -- array
	m1 = {}
	m2 = {}
	sum = 0
	for i in range(0, len(a)):
		sum += a[i]
		if sum not in m1:
			m1[sum] = i
		sum2 = sum - target_sum
		if (sum2 not in m2) or (m2[sum2] < i):
			m2[sum2] = i
	print(m1)
	print(m2)

a = [ 1, 2, 3, -4, 5 ]
get_longest_subarray_with_target_sum(a, 1)
