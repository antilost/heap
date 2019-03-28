#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Welcome to the Hotel California
# Such a lovely place
# Such a hardly case!

# O(n log n) + O(n) time complexity: sort + one scanning
# O(n) memory complexity
def comp(x, y):
    return x[1] - y[1] if x[0] == y[0] else x[0] - y[0]
def get_max_guests_at_hotel(guests):
    G = []
    for g in guests:
        G.append([g[0], 1])
        G.append([g[1], 0])
    G = sorted(G, cmp=comp)
    j = 0
    (now_guests_count, max_guests_count) = (0, 0)
    for g in G:
        if g[1] == 0:
            now_guests_count -= 1
        else:
            now_guests_count += 1
            max_guests_count = max([max_guests_count, now_guests_count])
    return max_guests_count


# O(n log n) + O(n) time complexity: sort + one scanning
# O(n) memory complexity
def get_max_guests_at_hotel_with_default_sort(guests):
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



test_cases = [
    ([], 0),
    ([ [2,3], [1,2], [5,7] ], 1),
    ([ [1,3], [2,4], [3,7] ], 2),
    ([ [1,5], [1,5], [1,5], [2,5], [0,1] ], 4),
    ([ [0,2], [2,5], [0,4], [0,3], [1,5], [2,3], [0,5], [0,3], ], 7),
    ([ [0,5], [4,5], [3,5], [1,5], [4,5], [2,5], ], 6),
    ([ [0,1], [4,5], [1,2], ], 1),
    ([ [0,5], [2, 3], [1,2], [1,3], ], 3),
    ([ [7,8], [6,7], [4,5], [0,1], [1,4], [0,10] ], 2),
    ([ [1,4], [2,4], [3,4], [4,9], [4,10], [4,5], [4,8], [4,8] ], 5),
]
for input, result in test_cases:
    assert(get_max_guests_at_hotel(input) == result)
for input, result in test_cases:
    assert(get_max_guests_at_hotel_with_default_sort(input) == result)
print("Ok")
