#!/usr/bin/env python2.7

'''
    Number of bits need to represent number (input from keyboard)
'''

from __future__ import print_function
import re

# Get input value as string
'''
raw_input(...)
    raw_input([prompt]) -> string
    
    Read a string from standard input.  The trailing newline is stripped.
    If the user hits EOF (Unix: Ctl-D, Windows: Ctl-Z+Return), raise EOFError.
    On Unix, GNU readline is used if enabled.  The prompt string, if given,
    is printed without a trailing newline before reading.
'''
str_input = raw_input()
print('input value:', str_input)

# Check input with regular expression
'''
match(pattern, string, flags=0)
    Try to apply the pattern at the start of the string, returning
    a match object, or None if no match was found
'''
if not re.match('^\d+$', str_input):
	raise ValueError('Positive integer value expected')

# Convert raw input string to decimal number
'''
class int(object)
 |  int(x=0) -> int or long
 |  int(x, base=10) -> int or long
 |  
 |  Convert a number or string to an integer, or return 0 if no arguments
 |  are given.  If x is floating point, the conversion truncates towards zero.
 |  If x is outside the integer range, the function returns a long instead.
 |  
 |  If x is not a number or if base is given, then x must be a string or
 |  Unicode object representing an integer literal in the given base.  The
 |  literal can be preceded by '+' or '-' and be surrounded by whitespace.
 |  The base defaults to 10.  Valid bases are 0 and 2-36.  Base 0 means to
 |  interpret the base from the string as an integer literal.
 |  >>> int('0b100', base=0)
 |  4
'''
number = int(str_input, base=10)

# Get string with binary form of the number
'''
bin(...)
    bin(number) -> string
    
    Return the binary representation of an integer or long integer.
'''
bin_format_value = bin(number)
print('binary form: ', bin_format_value)

# bin_format_value is string: 0bxxx, where x is 0 or 1
# so result, bits count is length of bin_format_value string - first 2 chars
'''
len(...)
    len(object) -> integer
    
    Return the number of items of a sequence or collection.
'''
bits_count = len(bin_format_value) - 2
print('we need', bits_count, 'bits to represent whole value')
