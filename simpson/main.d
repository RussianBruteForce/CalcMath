import std.stdio;
import std.math;

class Simpson(RANGE_T) {
	alias function_t = RANGE_T function(RANGE_T x);
	function_t f;
	RANGE_T h;
	this (function_t f, const RANGE_T eps) {
		assert(eps > 0);
		this.f = f;
		this.h = pow(eps, 0.25);
		writeln(this.h);
	}

	auto solve(const RANGE_T a, const RANGE_T b) {
		assert(b > a);
		auto n = ceil((b-a)/h);
		writeln(n);
	}
}

int main() {
	enum eps = 0.001;
	alias range_t = typeof(eps);

	auto myF = function (range_t x) {return x*x;};

	auto simpson = new Simpson!range_t(myF, eps);

	simpson.solve(0.6, 2.2);
	return 1;
}
