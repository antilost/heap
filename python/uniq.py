#!/usr/bin/env python3
import sys

prev = None
for line in sys.stdin.readlines():
    if (prev is None) or (prev != line):
        prev = line
        print(prev, end='')
    elif prev == line:
        continue