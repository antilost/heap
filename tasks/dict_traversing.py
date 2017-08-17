#!/usr/bin/env python3

'''
    Задача про обход словаря разной степени вложенности
'''

def dict_to_list(d, prefix=None):
    result = []
    for k,v in d.items():
        if isinstance(v, int):
            key = '.'.join((prefix or [])+[k])
            result.append([key, v])
        else:
            result.extend(dict_to_list(v, prefix=(prefix or []) + [k]))
    return result

d = {
	'a1': 1,
	'a2': {
		'b1': 2,
		'b2': {
			'c1': 3,
			'c2': 4
		},
		'b3': 5
	},
	'a3': {
		'b4': 6
	}
}

print( dict_to_list(d) )
