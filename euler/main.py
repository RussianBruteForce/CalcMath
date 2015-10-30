#!/usr/bin/python
from euler import Euler
from plot import Plot
import math

#diffs = { WHY I CAN'T STORE LAMBDAS IN A DICT????????
#	"62": (lambda x, y: math.cos(x-y)),
#	"61": (lambda x, y: math.cos(x-y)),
#	"2": (lambda x, y: x*0.7)
#	} WHHYYYYYYY???

class kek:
	def __init__(self, dif, fa, init, a, b, step):
		self.fa = fa
		self.dif = dif
		self.init = init
		self.a = a
		self.b = b
		self.step = step

diffs = [
	kek(lambda x, y: 1-x-y, "sqrt(2*(x-x**2/2))", 0, 0, 2, 0.33)
	]

array_of_analytics = [
	"sqrt(2*(x-x**2/2))", #61
	"2",
	"62",
	"101",
	"113",
	"x**2/2" # 5
	]

array_of_difs = [
	lambda x, y: 1-x-y,# 61
	lambda x, y: math.cos(x-y),# 2
	lambda x, y: math.cos(x-y), # 62
	lambda x, y: math.cos(x-y), # 62
	lambda x, y: math.cos(x-y), # 62
	lambda x, y: 0 if y == 0 else -x/y # 5
	]

if __name__ == '__main__':
	#for key, value in diffs: 
	#	print(value(5,6)) WHY I CAN'T DO WHAT?
	
	for x in diffs:
		p = Euler.euler(x.dif, x.init, x.a, x.b, x.step)
		Plot.plotFunctionAndCurve(x.fa, p, 'c' + '.png')
