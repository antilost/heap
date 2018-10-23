#!/usr/bin/env python3

def foo(x=[]):
	x.append(1)
	print(x)

foo()
y=[2]
foo(y)
foo()
foo(y)
