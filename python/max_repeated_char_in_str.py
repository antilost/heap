#!/usr/bin/env python2.7

import sys


def get_max_repeated_char_count(str):
    max_count = 0
    now_char = None
    now_count = 0
    for c in str:
        if now_char is None:
            now_char = c
            now_count += 1
        elif c != now_char:
            if now_count > max_count:
                max_count = now_count
            now_char = c
            now_count = 1
        else:
            now_count += 1
    if now_count > max_count:
        max_count = now_count
    return max_count

for str, expected in [
    ("", 0),
    ("aaaAAa", 3),
    ("bcd", 1),
    ("abbccccddeaabbbbbbddd", 6),
    ("aavvaaaBBBBd", 4)
]:
    got = get_max_repeated_char_count(str)
    assert(expected == got)
print("ok")
