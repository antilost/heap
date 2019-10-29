#!/usr/bin/env python

def rle(str):
    prev = None
    count = 0
    result = ""
    for c in str:
        if prev is None:
            count = 1
            prev = c;
        elif c != prev:
            if count > 1:
                result += '{}{}'.format(prev, count)
            else:
                result += prev
            count = 1
            prev = c
        else:
            count += 1
    if prev is not None:
        if count > 1:
            result += '{}{}'.format(prev, count)
        else:
            result += prev
    return result

assert( rle("AABBCDDDDFFFFFF") == "A2B2CD4F6" )
assert( rle("AAAAAAAAAAE") == "A10E" )
assert( rle("") == "" )
assert( rle("dd") == "d2" )
assert( rle("d") == "d" )
print("ok")

