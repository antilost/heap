#!/usr/bin/env python
# -*- coding: utf-8 -*-

def compress_numbers_intervals(numbers):
    result = None
    count = 0
    for i in sorted(numbers):
        if result is None:
            result = '{}'.format(i)
            count = 1
        elif i > prev + 1:
            if count > 1:
                result += '-{}'.format(prev)
            result += ',{}'.format(i)
            count = 1
        else:
            count += 1
        prev = i
    if count > 1:
        result += '-{}'.format(prev)
    return result

test_cases = [
    ([], None),
    ([2], '2'),
    ([3,2], '2-3'),
    ([4,2,3], '2-4'),
    ([6,4,2,7,3,9], '2-4,6-7,9'),
    ([6,10,11,4,2,7,3,9], '2-4,6-7,9-11'),
]
for input, expected_result in test_cases:
    got_result = compress_numbers_intervals(input)
    assert( got_result == expected_result )
print("Ok")
