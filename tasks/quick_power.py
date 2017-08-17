#!/usr/bin/env python2.7

'''
    Быстрое возведение в степень
'''

from __future__ import print_function

from time import clock
import math

def get_power(a, n):
	if n > 1:
		r = 1
		if n % 2 == 1:
			r = a
			n -= 1
		p = get_power(a, n // 2)
		return r * p * p
	else:
		return a

def get_power_cycle(a, n):
	r = 1
	for i in range(0, n):
		r *= a
	return r

if __name__ == '__main__':
	for (a, n) in [ (2,1), (2,4), (2,5), (2,15), (2,25), (2,40), (3,33) ]:
		t0 = clock()
		for i in range(0, 60):
			r_rec = get_power(a, n)
#				print('{0}**{1} = {2}'.format(a, n, get_power(a, n)))
		t1 = clock()
		t_rec = t1 - t0

		t0 = clock()
		for i in range(0, 60):
			r_std = math.pow(a, n)
		t1 = clock()
		t_std = t1 - t0

		t0 = clock()
		for i in range(0, 60):
			r_cyc = get_power_cycle(a, n)
		t1 = clock()
		t_cyc = t1 - t0

		print('{0} {1} '.format(a, n) + '{0:.6f} {1:.6f} {2:.6f}'.format(t_rec, t_std, t_cyc) + ' - ' + '{0:.0f} {1:.0f} {2:.0f}'.format(r_rec, r_std, r_cyc) )
