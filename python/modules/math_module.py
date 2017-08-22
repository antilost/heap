#!/usr/bin/env python2.7

from __future__ import print_function

import math

# Trigonometric functions
# cos(x) Return the cosine of x (measured in radians).
# cosh(x) Return the hyperbolic cosine of x.
# sin(x) Return the sine of x (measured in radians).
# sinh(x) Return the hyperbolic sine of x.
# tan(x) Return the tangent of x (measured in radians).
# tanh(x) Return the hyperbolic tangent of x.

# Arc trigonometric functions
# acos(x) Return the arc cosine (measured in radians) of x.
# acosh(x) Return the inverse hyperbolic cosine of x.
# asin(x) Return the arc sine (measured in radians) of x.
# asinh(x) Return the inverse hyperbolic sine of x.
# atan(x) Return the arc tangent (measured in radians) of x.
# atan2(y, x) Return the arc tangent (measured in radians) of y/x. Unlike atan(y/x), the signs of both x and y are considered.
# atanh(x) Return the inverse hyperbolic tangent of x.

# DATA
#     pi = 3.141592653589793
# radians(x) Convert angle x from degrees to radians.
# degrees(x) Convert angle x from radians to degrees.
alpha_rad = math.pi / 2
alpha_degrees = math.degrees(alpha_rad)
alpha = math.radians(alpha_degrees + 90)
print('alpha_rad: {0:.2f}, alpha_degrees: {1:.2f}, alpha: {2:.2f}'.format(alpha_rad, alpha_degrees, alpha))

# copysign(x, y) Return x with the sign of y.
x = 10
y = -20
x = math.copysign(x, y)
print('x', x, sep=' = ')


# DATA
#     e = 2.718281828459045
# exp(x) Return e raised to the power of x.
print('e={0:.4f}, exp(1)={1:.4f}'.format(math.e, math.exp(1)))


# trunc(x:Real) -> Integral Truncates x to the nearest Integral toward 0. Uses the __trunc__ magic method.
print('trunc(x) Truncates x to the nearest Integral toward 0')
for x in [ -1.1, -0.9, -0.1, 0, 0.1, 0.9, 1.1 ]:
	print('x={0: 6.4f}, math.trunc(x)={1: 6.4f}'.format(x, math.trunc(x)))

# ceil(x) Return the ceiling of x as a float. This is the smallest integral value >= x.
print('ceil(x) Return the smallest integral value >= x')
for x in [ 0, 0.01, 0.49, 0.5, 0.51, 0.9, -0.9, -0.5, -0.1 ]:
	ceiled_x = math.ceil(x)
	print('ceil({0: 6.2f}) = {1: 6.2f}'.format( x, ceiled_x ) )

# floor(x) Return the floor of x as a float. This is the largest integral value <= x.
print('floor(x) Return the largest integral value <= x')
for x in [ -1.1, -0.9, -0.1, 0, 0.1, 0.9, 1.1 ]:
	print('x={0: 6.4f}, math.floor(x)={1: 6.4f}'.format(x, math.floor(x)))

# fabs(x) Return the absolute value of the float x.
for x in [ -2, -0.5, 0, 2, 4.5 ]:
	print('x = {0}, math.fabs(x) = {1}'.format(x, math.fabs(x)))

# fmod(x, y) Return fmod(x, y), according to platform C.  x % y may differ.
print('\nmath.fmod(10, 3):', math.fmod(10, 3))
print('10 % 3:', 10 % 3)

# factorial(x) -> Integral Find x!. Raise a ValueError if x is negative or non-integral.
print('\nmath.factorial(5) =', math.factorial(5))

# fsum(iterable) Return an accurate floating point sum of values in the iterable. Assumes IEEE-754 floating point arithmetic.
print('\nmath.fsum(range(1, 5)) = 1+2+3+4 =', math.fsum(range(1, 5)))

# modf(x) Return the fractional and integer parts of x.  Both results carry the sign of x and are floats.
print('\nmath.modf(2.5) =', math.modf(2.5))

# isinf(x) -> bool Check if float x is infinite (positive or negative).
# isnan(x) -> bool Check if float x is not a number (NaN).

# pow(x, y) Return x**y (x to the power of y).

# sqrt(x) Return the square root of x.
val='math.sqrt(2**2 + 3**2)'
print('\n' + val, eval(val), sep=' = ')

# hypot(x, y) Return the Euclidean distance, sqrt(x*x + y*y).
val='math.hypot(2, 3)'
print('\n' + val, eval(val), sep=' = ')


# erf(x) Error function at x.
# erfc(x) Complementary error function at x.
# expm1(x) Return exp(x)-1. This function avoids the loss of precision involved in the direct evaluation of exp(x)-1 for small x.

# frexp(x)
#         Return the mantissa and exponent of x, as pair (m, e).
#         m is a float and e is an int, such that x = m * 2.**e.
#         If x is 0, m and e are both 0.  Else 0.5 <= abs(m) < 1.0.

# gamma(x) Gamma function at x.
# lgamma(x) Natural logarithm of absolute value of Gamma function at x.

# ldexp(x, i) Return x * (2**i).
# log(x[, base]) Return the logarithm of x to the given base. If the base not specified, returns the natural logarithm (base e) of x.
# log10(x) Return the base 10 logarithm of x.
# log1p(x) Return the natural logarithm of 1+x (base e). The result is computed in a way which is accurate for x near zero.
