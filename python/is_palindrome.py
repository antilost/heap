#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

def check_palindrome_by_me(input_line):
    x, y = 0, len(input_line) - 1
    is_palindrome = True
    while x < y:
        if not str.isalpha(input_line[x]):
            x += 1
            continue
        if not str.isalpha(input_line[y]):
            y -= 1
            continue
        if str.lower(input_line[x]) != str.lower(input_line[y]):
            is_palindrome = False
            break
        x += 1
        y -= 1
    return is_palindrome

def check_palindrome_by_candidate(s):
    a = 0
    b = len(s) - 1
    while a < b:
        while a < len(s) and ( not str.isalpha(s[a]) ):
            a += 1
        while b >= 0 and ( not str.isalpha(s[b]) ):
            b -= 1
        if a >= b:
            return True
        elif s[a].upper() != s[b].upper():
            return False
        a += 1
        b -= 1
    return True 

for p_true in [
    'Казак',
    'А роза упала на лапу Азора',
    'Do geese see God?',
    'Madam, I’m Adam'
]:
    assert( check_palindrome_by_me(p_true) == True )

for p_false in [
    'дом',
    'О роза упала на лапу Азора',
    'Do geese seen God?',
    'Madam, I’d Adam'
]:
    assert( check_palindrome_by_me(p_false) == False )
print("ok")
