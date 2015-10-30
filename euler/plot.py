from os import system, remove

class Plot:
	tmp_file = '\\tmp\\euler.dat'
	gnuplot = 'gnuplot'
	
	def plotFunctionAndCurve(function, curvePoints, outputFileName):
		output = '\'{0}\''.format(outputFileName)
		
		f = open(Plot.tmp_file, 'w')
		for x in curvePoints:
			f.write('{0} {1}\n'.format(x[0], x[1]))
		f.close()
	
		command = "plot {a} with lines, \'{e}\' with lines;".format(a = function, e = Plot.tmp_file)
		
		Plot.plotCommand(command, output)
		
		remove(Plot.tmp_file)
		
	def plotCommand(command, output):
		cmd = '{p} -e "set terminal png size 800,600 enhanced font \'Helvetica,8\'; set output {o}; {c}"'.format(c = command, o = output, p = Plot.gnuplot)
		system(cmd)
		
	