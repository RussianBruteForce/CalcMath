#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>
#include <iomanip>

using namespace std;

/*
 * Determine
 */
class Integral {
public:
	Integral() = delete;

	enum class Method {
		LeftTriangle,
		Trapezium,
		CentralTriangle
	};

	template<typename T, typename R>
	static auto solve(T&& f, pair<R, R> range, Method t) {
		assert(range.second > range.first);
		switch (t) {
		case Method::LeftTriangle:
			return leftTriangle(forward<T>(f), forward<decltype(range)>(range));
			break;
		case Method::Trapezium:
			return trapezium(forward<T>(f), forward<decltype(range)>(range));
			break;
		case Method::CentralTriangle:
			return centralTriangle(forward<T>(f), forward<decltype(range)>(range));
			break;
		default:
			break;
		}
		throw invalid_argument("Wrong method!");
	}

private:
	static constexpr size_t n{100000000};

	template<typename T, typename R>
	static auto leftTriangle(T&& f, pair<R, R> range) {
		using ret_type = remove_cv_t<decltype(f(range.first))>;
		ret_type ret{0};
		const ret_type h { static_cast<ret_type>(range.second - range.first) / n };
		for (remove_cv_t<decltype(n)> i = 0; i < n; i++)
			/*
			 * SUM(f(x_i))
			 */
			ret += f( range.first
				  +
				  i * h
				 );
		return ret * h;
	}

	template<typename T, typename R>
	static auto trapezium(T&& f, pair<R, R> range) {
		using ret_type = remove_cv_t<decltype(f(range.first))>;
		ret_type ret{0};
		const ret_type h { static_cast<ret_type>(range.second - range.first) / n };
		for (remove_cv_t<decltype(n)> i = 1; i <= n; i++)
			/*
			 * SUM(f(x_i) + f(x_(i-1)))
			 */
			ret +=  f(range.first
				  +
				  h * i)
				+
				f(range.first
				  +
				  h * (i - 1));
		return ret * h / 2;
	}

	template<typename T, typename R>
	static auto centralTriangle(T&& f, pair<R, R> range) {
		using ret_type = remove_cv_t<decltype(f(range.first))>;
		ret_type ret{0};
		const ret_type h { static_cast<ret_type>(range.second - range.first) / n };
		for (remove_cv_t<decltype(n)> i = 0; i < n; i++)
			/*
			 * SUM(f(x_i+h/2))
			 */
			ret += f( range.first
				  +
				  h * (2 * i + 1)
					 /
					 2
				 );
		return ret * h;
	}
};

int main()
{
	auto my_integral = [](auto x) -> double {
		return (x*x); // Только такое могу сам решить(
//		return (x*x*x - 4*sin(x*M_PI))/(x);
	};
	auto my_range = make_pair(-10, 10);
//	auto a = Integral::solve([](auto x) -> double { return x; }, 2, 5, Integral::Method::LeftTriangle);
	auto ansCT = Integral::solve(my_integral,
				     my_range,
				     Integral::Method::CentralTriangle);
	auto ansLT = Integral::solve(my_integral,
				     my_range,
				     Integral::Method::LeftTriangle);
	auto ansT = Integral::solve(my_integral,
				    my_range,
				    Integral::Method::Trapezium);

	cout << "Left Tri" << "\t| " << "Center Tri" << "\t| " << "Trapez\n"
	     << ansLT << "\t| " << ansCT << "\t| " << ansT << endl;
	return 0;
}


