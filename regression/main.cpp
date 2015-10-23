#include <iostream>
#include <array>
#include "LinearRegression.h"

using namespace std;

int main(){
	/*
	 * flats onVolochaevskaya street
	 * @1 rooms
	 * @2 sq, m^2
	 * @3 price, thousand roubles
	 */
	array<array<int, 3>, 40> data {
		{
			{1,	32,	1700},	//1
			{2,	45,	1995},
			{3,	60,	2900},
			{3,	151,	10500},
			{3,	58,	2990},	//5
			{1,	31,	1750},
			{1,	34,	1850},
			{2,	45,	1995},
			{2,	46,	2150},
			{2,	42,	2490},	//10
			{2,	47,	2800},
			{2,	55,	3500},
			{3,	41,	2400},
			{3,	56,	2470},
			{3,	58,	2500},	//15
			{3,	59,	2890},
			{3,	64,	2900},
			{3,	52,	2950},
			{4,	59,	2560},
			{4,	62,	2800},	//20
			{4,	59,	3000},
			{4,	62,	3150},
			{4,	79,	3450},
			{4,	80,	3650},
			{4,	150,	21000},	//25
			{5,	287,	15000},
			{1,	31,	1800},
			{1,	32,	1850},
			{2,	46,	2200},
			{2,	45,	2350}	//30
		}
	};

	LinearRegression<double> r;

	for (auto &x: data)
		r.add(x[0], x[1], x[2]);

	/*
	 * Ⓐ for squatting purposes Ⓐ
	 */
	cout << r.predict(10, 600) << endl;
	return 0;
}

