#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Welcome to the Hotel California
# Such a lovely place
# Such a hardly case!

# O(n log n) + O(n) time complexity: sort + one scanning
# O(n) memory complexity

def get_max_guests_at_hotel(guests):
    arrival = sorted([ g[0] for g in guests ])   # dates of arrival sorted
    departure = sorted([ g[1] for g in guests ]) # dates of departure sorted
    j = 0
    (now_guests_count, max_guests_count) = (0, 0)
    for a in arrival:
        while (j < len(departure)) and (departure[j] <= a):
            j += 1
            now_guests_count -= 1
        now_guests_count += 1
        max_guests_count = max([max_guests_count, now_guests_count])
    return max_guests_count

assert(get_max_guests_at_hotel([]) == 0)
assert(get_max_guests_at_hotel([ [2,3], [1,2], [5,7] ]) == 1)
assert(get_max_guests_at_hotel([ [1,3], [2,4], [3,7] ]) == 2)
assert(get_max_guests_at_hotel([ [1,5], [1,5], [1,5], [2,5], [0,1] ]) == 4)
assert(get_max_guests_at_hotel([ [0,2], [2,5], [0,4], [0,3], [1,5], [2,3], [0,5], [0,3], ]) == 7)
assert(get_max_guests_at_hotel([ [0,5], [4,5], [3,5], [1,5], [4,5], [2,5], ]) == 6)
assert(get_max_guests_at_hotel([ [0,1], [4,5], [1,2], ]) == 1)
assert(get_max_guests_at_hotel([ [0,5], [2, 3], [1,2], [1,3], ]) == 3)
assert(get_max_guests_at_hotel([ [7,8], [6,7], [4,5], [0,1], [1,4], [0,10] ]) == 2)
