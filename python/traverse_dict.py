#!/usr/bin/env python

from collections import deque

def get_metrics(dict):
    queue = deque()
    queue.append((None, dict))
    while len(queue) > 0:
        (prefix, dict) = queue.popleft()
        for key, value in dict.items():
            new_prefix = '.'.join([ prefix, key ]) if prefix is not None else key
            if isinstance(value, int):
                yield (new_prefix, value)
            elif isinstance(value, type({})):
                queue.append((new_prefix, value))
            else:
                print('No int, no dict: ' + str(value))

a = {
   'b' : 4,
   'c' : {
       'd': 3,
       'e': 5,
    },
   'k1': {
      'k21': {
        'k3': 77
      },
      'k22': 99
   }
}

print([d for d in get_metrics(a)])