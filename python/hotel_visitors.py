#!/usr/bin/env python

def get_max_visitors_count(visitors):
    visitors_count_change = []
    for time_check_in, time_check_out in visitors:
        visitors_count_change.append( (time_check_in, +1) )
        visitors_count_change.append( (time_check_out, -1) )
    visitors_count_change.sort()

    max_capacity = 0
    capacity = 0
    for _, count_change in visitors_count_change:
        capacity += count_change
        if capacity > max_capacity:
            max_capacity = capacity
    return max_capacity


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
    assert(get_max_visitors_count(input) == result)
print("Ok")
