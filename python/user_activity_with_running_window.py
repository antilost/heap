#!/usr/bin/env python

'''
    Поступают события вида
      ('+', user, time) 
      ('?', count, time) 
    в порядке возрастания  time . Время в секундах.
    События типа  '+' соответствуют активности пользователя (прослушивание трека, клик по ссылке и т.п.).
    Для событий типа  '?' нужно возвращать количество пользователей,
    которые за последние 5 минут (на полуинтервале времени (time - 5 min, time]),
    совершили ровно  count действий (можно считать, что  count > 0 ,
    но, вообще, здорово, если кандидат сам подумает, что  count == 0 особый случай).
'''

import sys
from collections import defaultdict

class EventStats:
    def __init__(self):
        self.queues = defaultdict(list)

    def _update_queues(self, time):
        for user in self.queues:
            while self.queues[user] and self.queues[user][0] < time - 5:
                del self.queues[user][0]

    def register_event(self, user, time):
        self._update_queues(time)
        self.queues[user].append(time)
        print(self.queues)

    def query(self, count, time):
        self._update_queues(time)
        result = 0
        for user in self.queues:
            if len(self.queues[user]) == count:
                result += 1
        return result

def main():
    es = EventStats()
    while True:
        (action, value, time) = sys.stdin.readline().strip().split(' ')
        time = int(time)
        if action == '+':
            es.register_event(value, time)
        if action == '?':
            count = int(value)
            result = es.query(count, time)
            print(result)

if __name__ == '__main__':
    main()
