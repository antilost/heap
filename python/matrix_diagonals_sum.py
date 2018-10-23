#!/usr/bin/env python
# -*- coding: utf-8 -*-


def get_sum():
    M = [ # 1 + 5 + 9 {15} + 7 + 3 {10} = 25
        [1,2,3],
        [4,5,6],
        [7,8,9],
    ]
    N = len(M)
    sum = 0
    for i in range(0, N):
        el = M[i][i]
        sum += el
        j = N - 1 - i
        if not( (i == j) and (N % 2 == 1) ):
            el = M[i][j]
            sum += el
    print(sum)
    

if __name__ == '__main__':
    get_sum()
