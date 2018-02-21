#!/usr/bin/env python

def fuzzysearch(string, pattern):
    result = False
    i = 0
    j = 0
    while ((i < len(string)) and (j < len(pattern))):
        s = string[i]
        p = pattern[j]
        if s == p:
            i += 1
        j += 1
 
    if i >= len(string):
        result = True
    return result

def main():
    pattern = "cartwheel"
    for s, r in [
        ('car', True),
        ('cwhl', True),
        ('cwheel', True),
        ('cartwheel', True),
        ('wee', True),
        ('cwheeel', False),
        ('lw', False)
    ]:
        result = fuzzysearch(s, pattern)
        print('{} {} {}'.format(pattern, s, result))
        assert(result == r)

if __name__ == '__main__':
    main()
