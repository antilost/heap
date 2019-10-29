#!/usr/bin/env python

from collections import defaultdict
import random

def group_logogriphs(input):
    groups = dict()
    for s in input:
        key = ''.join( sorted(s) )
        if key not in groups:
            groups[key] = [s]
        else:
            i = 0
            while (i < len(groups[key])) and (groups[key][i] < s):
                i += 1
            groups[key].insert(i, s)
    return groups

def group_logogriphs2(input):
    groups = defaultdict(list)
    for s in input:
        key = frozenset( s )

        if key not in groups:
            groups[key] = [s]
        else:
            i = 0
            while (i < len(groups[key])) and (groups[key][i] < s):
                i += 1
            groups[key].insert(i, s)
    return groups


for i in range(0,10):
    input_list = ["eat", "tea", "tan", "ate", "nat", "bat", "ant"]
    random.shuffle( input_list )
    G = group_logogriphs(input_list)
    assert( G == {'ant': ['ant', 'nat', 'tan'], 'abt': ['bat'], 'aet': ['ate', 'eat', 'tea']} )
    G2 = group_logogriphs2(input_list)
    assert( G2 == { frozenset('ant'): ['ant', 'nat', 'tan'], frozenset('abt'): ['bat'], frozenset('aet'): ['ate', 'eat', 'tea']} )
print("ok")

