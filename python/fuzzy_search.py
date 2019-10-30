#!/usr/bin/env python

def fuzzy_search_my(pattern, str):
    result = False
    i = 0
    j = 0
    while ((i < len(str)) and (j < len(pattern))):
        s = str[i]
        p = pattern[j]
        if s == p:
            j += 1
        i += 1
 
    if j >= len(pattern):
        result = True
    return result

def fuzzy_search_20191030(pattern, str):
    i = 0
    for s in str:
        if pattern[i] == s:
            i += 1
            if i == len(pattern):
                break
    return i == len(pattern)

def main():
    fuzzy_search_implementations = [fuzzy_search_my, fuzzy_search_20191030]
    for fuzzy_search in fuzzy_search_implementations:
        str = "cartwheel"
        for pattern, expected in [
            ('car', True),
            ('cwhl', True),
            ('cwheel', True),
            ('cartwheel', True),
            ('wee', True),
            ('cwheeel', False),
            ('lw', False)
        ]:
            got = fuzzy_search(pattern, str)
            print('{} {} {} {}'.format(fuzzy_search.__name__, pattern, str, got))
            assert(got == expected)

if __name__ == '__main__':
    main()
