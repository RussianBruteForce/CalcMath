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
	kek(lambda x, y: 1-x-y, "sqrt(x*(2-x))", 0, 0, 1.8, 0.01), #61
	kek(lambda x, y: (x+3)/2-y, "x/2+1+665*2.71828**(-x)", 666, 0, 10, 0.001), #2
	kek(lambda x, y: math.cos(y-x), "x+2*atan(1/(x+1))",1.57079633,0,5,0.001), #62
	kek(lambda x, y: (x+2*y)/x, "x*(x-1)",0,1,10,0.001), #101
	kek(lambda x, y: (2*x-4*y+6)/(x+y-3), "-(2*((sqrt(3))/2-1/2))/(9*(sqrt(19)/(8*3**(3/2))-1/216)**(1/3))+(sqrt(19)/(8*3**(3/2))-1/216)**(1/3)*(-1/2-(sqrt(3))/2)+4/3",-1.577564625074028,0,10,0.01), #113 жесть
	kek(lambda x, y: 0 if y == 0 else -x/y, "sqrt(16-x**2)",4,0,4,0.001), #5
	
	kek(lambda x, y: math.pow(2.71828,(2*x+3)), "2.71828**(2*x+3)-10.042768",0,0,30,1),
	kek(lambda x, y: 1/(x*x+4),"atan(x/2)/2",0,0,10,0.001),
	kek(lambda x, y: math.cos(x)/math.sin(x), "log(sin(x))",-0.17260374626,1,3,0.001),
	kek(lambda x, y: x/y, "sqrt(x**2+16)",4,0,1,0.001)
	]

if __name__ == '__main__':
	i = 0
	for x in diffs:
		e = Euler.euler(x.dif, x.init, x.a, x.b, x.step)
		Plot.plotFunctionAndCurve(x.fa, e, str(i) + 'euler.png')
		rk1 = Euler.rungeKutta1(x.dif, x.init, x.a, x.b, x.step)
		Plot.plotFunctionAndCurve(x.fa, rk1, str(i) + 'rk1.png')
		rk4 = Euler.rungeKutta4(x.dif, x.init, x.a, x.b, x.step)
		Plot.plotFunctionAndCurve(x.fa, rk4, str(i) + 'rk4.png')
		i+=1
