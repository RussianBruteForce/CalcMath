import std.stdio;
import std.math;
import std.exception;

class Simpson(D_OH) {
	alias function_t = D_OH function(D_OH x);
	immutable function_t f;
	immutable D_OH h;

	this (function_t f, const D_OH eps) {
		enforce(eps > 0, "I'm Bart Simpson. Who the hell are you?");//"Must be greater than 0!");
		this.f = f;
		this.h = pow(eps, 0.25);
	}

	auto solve(const D_OH a, const D_OH b) const {
		enforce(b > a, "Why, you litle!!11!1!");//"The second one must be greater than the first!");
		auto n = ceil((b-a)/h); // computing n
		while (n%4 != 0)
			n++; // make n divisibile by 4 without rest
		immutable auto local_h = (b-a)/n; // computing new h
		D_OH S = f(a) + f(b); // init by sum of verges
		// also, perhaps, should use loop without if statement, but with two variables
		foreach(i; 1 .. n) {
			immutable auto current = f(a+i*local_h);
			if (i%2 == 0)
				S += 2*current;
			else
				S += 4*current;
		}
		return S*local_h/3;
	}
}

int main() {
	enum shorts = 0.0001;
	alias range_t = typeof(shorts);

	auto My = function (range_t x) {return x*x;}; // can't sovle сложно

	auto eat = new Simpson!range_t(My, shorts);

	auto S = eat.solve(-6, 6.6);
	writeln("Don't have a cow, man! Your definite integral is ", S, " c:");
	return 0;
}
