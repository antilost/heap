#!/usr/bin/env python

# Eratostenes sieve algorithm to get first prime numbers less than N

def get_prime_numbers_less_than(n):
    numbers_less_than_n = range(2, n)
    sieve = {
        i: True for i in numbers_less_than_n
    }
    for i in numbers_less_than_n:
        if not sieve[i]:
            continue
        for j in range(i+i, n, i):
            sieve[j] = False
    return [i for i in numbers_less_than_n if sieve[i]]

def main():
    prime_numbers = get_prime_numbers_less_than(1000)
    print(prime_numbers)

if __name__ == '__main__':
    main()
