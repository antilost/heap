#!/usr/bin/env python2.7
# -*- encoding: utf-8 -*-

from __future__ import print_function

# Задачи из книги Абрамов, Зима "Начала информатики". - М.: 1989.

def task_31():
	# Вычислить (|x| - |y|) / (1 + |xy|)
	from math import fabs
	print('#31')
	(x, y) = map( (lambda v: float(v)), raw_input().split() )
	r = ( fabs(x) - fabs(y) ) / (1 + fabs(x * y))
	print('result:', r)

def task_75():
	# Даны положительные x, y, z. Проверить, существует ли трегольник со сторонами x, y, z. 01:11-01:54
	from math import fabs, acos, degrees
	x = float( input('x=') )
	y = float( input('y=') )
	z = float( input('z=') )
	bad = False
	sum = 0
	for (a, b, c) in [ (x,y,z), (y,z,x), (z,x,y) ]:
		cos_angle = (a*a - b*b - c*c) / (2 * b * c)
		if (cos_angle < -1.0) or (1.0 < cos_angle):
			bad = True
			break
		sum += degrees( acos( fabs( cos_angle ) ) )

	if (not bad) and (fabs(sum - 180) > 1e-2):
		bad = True
	if not bad:
		print('Трегуольник существует')
	else:
		print('Треугольник с такими сторонами не существует')

def task_129():
	# Часовая стрелка образует угол phi с лучом, проходящим через центр циферблата и через точку, соответствующую 12 часам
	# Определить значение угла для минутной стрелки, а также количество часов и полных минут
	from math import radians, modf
	phi = float( input() )
	float_hours = phi / 360. * 12.
	(float_minutes, hours) = modf(float_hours)
	hours = int(hours)
	minutes_angle = int( float_minutes * 360 )
	minutes = int( float_minutes * 60 )
	print('minutes angle =', minutes_angle)
	print('time: {0}h {1}m'.format(hours, minutes))

task_75()
#task_129()

