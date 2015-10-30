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
	kek(lambda x, y: 1-x-y, "sqrt(2*(x-x**2/2))", 0, 0, 2, 0.001), #61
	kek(lambda x, y: (x+3)/2-y, "x/2+1+4*2.71828**(-x)", 5, 0, 10, 0.001), #2
	#kek(lambda x, y: math.cos(y-x), "x+5",0,0,5,0.001), #62 Не знаю как выразить y
	kek(lambda x, y: (x+2*y)/x, "x*x-x",0,1,10,0.001), #101
	#kek(lambda x, y: (2*x-4*y+6)(x+y-3), "x",0,0,10,0.1), #113 не знаю как выразить y
	kek(lambda x, y: 0 if y == 0 else -x/y, "sqrt(16-x**2)",4,0,4,0.001), #5
	
	kek(lambda x, y: x*math.pow(2.71828,(2*x+3)), "(2.71828**(2*x+3))/2*(x-1/2)+2",1,-3/2,10,0.001),
	kek(lambda x, y: 1/(x*x+4),"atan(x/2)/2",0,0,10,0.001),
	kek(lambda x, y: math.cos(x)/math.sin(x), "log(sin(x))",-0.17260374626,1,3,0.001),
	kek(lambda x, y: x/y, "sqrt(x**2+16)",4,0,1,0.001)
	]

if __name__ == '__main__':
	#for key, value in diffs: 
	#	print(value(5,6)) WHY I CAN'T DO WHAT?
	
	i = 0
	for x in diffs:
		p = Euler.euler(x.dif, x.init, x.a, x.b, x.step)
		Plot.plotFunctionAndCurve(x.fa, p, str(i) + '.png')
		i+=1
