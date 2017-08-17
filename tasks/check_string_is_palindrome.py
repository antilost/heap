#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
    Программа проверяет, является ли введённая строка палиндромом или нет
'''

def is_palindrome(str_to_check):
	l = len(str_to_check) # len возвращает длину строки

	# // -- деление с округлением вниз, возвращает ближайшее целое снизу)
	for x in range(0, l // 2):
		if str_to_check[x] != str_to_check[l - x - 1]:
			return False
	return True

for s in [
	'abcba', # True
	'abba',  # True
	'',      # True
	'op',    # False
	'mnk'    # False
]:
	print( s, is_palindrome(s) )
