#!/usr/bin/env python

def get_ranges(a):
    a.sort()
    min_value = a[0]

    answer = ''
    for i in range(1, len(a)):
        if a[i] - a[i - 1] != 1:
            if a[i - 1] == min_value:
                answer += str(min_value) + ','
            else: 
                answer += str(min_value) + '-' + str(a[i - 1]) + ','
                
            min_value = a[i]
            
    if a[-1] == min_value:
        answer += str(min_value) + ','
    else:
        answer += str(min_value) + '-' + str(a[-1]) + ','
    
    return answer.rstrip(',')


test_data = [
    ([1,4,5,2,3,9,8,11,0], "0-5,8-9,11"),
    ([1,4,3,2], "1-4"),
    ([1,4], "1,4")
]
for x, y in test_data:
    assert(get_ranges(x) == y)
