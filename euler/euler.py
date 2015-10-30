
class Euler():
	def euler(f, init, range_a, range_b, step):
		assert range_a < range_b
		#assert type(f) == type(lambda:0)

		points = []
		y = init
		x = range_a
		while x <= range_b:
			points.append([x, y])
			y += step*f(x, y)
			x += step
		return points
