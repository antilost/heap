#!/usr/bin/env python3

"""
Get two biggest elements (numbers) product
"""

def max_elements_product(data):
    max1, max2 = None, None
    for d in data:
        if max2 is None:
            max2 = d
        else:
            if d > max2:
                max1, max2 = max2, d
            elif max1 is None or d > max1:
                max1 = d
    if max1 is None:
        max1 = max2
    if max2 is None:
        return None
    result = max1 * max2
    return result

assert( max_elements_product([]) == None )
assert( max_elements_product([1]) == 1 )
assert( max_elements_product([4]) == 16 )
assert( max_elements_product([3,2,1]) == 6 )
assert( max_elements_product([1,1,1,9,7,8]) == 72 )

import random
a = sorted( set([ random.randint(10,99) for r in range(10)]) )
#print(a)
assert( max_elements_product(a) == a[-1] * a[-2] )
print("ok")

