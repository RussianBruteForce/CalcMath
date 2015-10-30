#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <vector>
#include <cmath>
#include <cassert>
#include <numeric>

template<class T>
class LinearRegression // with two independent variables
{
	using container_t = std::vector<T>;
public:
	LinearRegression() = default;
	/*
	 * append set
	 */
	void add(const T x, const T y, const T z);
	/*
	 * predict z
	 */
	T predict(const T x, const T y) const;

private:
	container_t X{}, Y{}, Z{}; // dataset
	mutable T a, b, c; // constants
	mutable typename container_t::size_type n; // dataset size
	mutable bool cached{false}; //is constants cached

	static inline typename container_t::value_type sum(const container_t& a)
	{
		return accumulate(a.begin(), a.end(), 0);
	}

	static inline typename container_t::value_type sum(const container_t& a, const container_t& b)
	{
		assert(a.size() == b.size());
		typename container_t::value_type ret{};
		for(typename container_t:: size_type i = 0; i < a.size(); i++)
			ret += a[i]*b[i];
		return ret;
	}

	static inline typename container_t::value_type sumPOW(const container_t& a)
	{
		typename container_t::value_type ret{};
		for(auto &x: a)
			ret += x*x;
		return ret;
	}
};


template<class T>
void LinearRegression<T>::add(const T x, const T y, const T z)
{
	cached = false;
	X.push_back(x);
	Y.push_back(y);
	Z.push_back(z);
}

template<class T>
T LinearRegression<T>::predict(const T x, const T y) const
{
	/*
	 * All formulas powered by Maxima, a Computer Algebra System
	 */
	if (!cached){
		n = X.size();
		a = -(sum(X, Z)*pow(sum(Y),2)-n*sum(X, Z)*sumPOW(Y)+(n*sum(X, Y)-sum( X)*sum( Y))*sum(Y, Z)+(sum( X)*sumPOW(Y)-sum(X, Y)*sum( Y))*sum(Z))/((n*sumPOW(X)-pow(sum( X),2))*sumPOW(Y)-sumPOW(X)*pow(sum( Y),2)+2*sum( X)*sum(X, Y)*sum( Y)-n*pow(sum(X, Y),2));
		b = -(n*sum(X, Y)*sum(X, Z)-sum( X)*sum(X, Z)*sum( Y)+(pow(sum( X),2)-n*sumPOW(X))*sum(Y, Z)+(sumPOW(X)*sum( Y)-sum( X)*sum(X, Y))*sum(Z))/((n*sumPOW(X)-pow(sum( X),2))*sumPOW(Y)-sumPOW(X)*pow(sum( Y),2)+2*sum( X)*sum(X, Y)*sum( Y)-n*pow(sum(X, Y),2));
		c = (sum(X, Y)*sum(X, Z)*sum(Y)-sum(X)*sum(X, Z)*sumPOW(Y)+(sum(X)*sum(X, Y)-sumPOW(X)*sum(Y))*sum(Y, Z)+(sumPOW(X)*sumPOW(Y)-pow(sum(X, Y),2))*sum(Z))/((n*sumPOW(X)-pow(sum(X),2))*sumPOW(Y)-sumPOW(X)*pow(sum(Y),2)+2*sum(X)*sum(X, Y)*sum(Y)-n*pow(sum(X, Y),2));
		cached = true;
	}
	return a*x + b*y + c;
}


#endif // LINEARREGRESSION_H
