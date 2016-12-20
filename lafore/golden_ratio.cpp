#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double func(double x) {
	return (x - 4.1) * (x - 4.1) + 3;
}

double minimum_by_golden_ratio(double a, double b, double eps) {
	double golden_ratio = (sqrt(5) - 1) / 2;

	double fa, fb;
	fa = func(a);
	fb = func(b);
	double length = abs(b - a);
	while (length > eps) {
		double x1, x2, f1, f2;
		double golden_half = length * golden_ratio;
		x1 = b - golden_half;
		x2 = a + golden_half;
		f1 = func(x1);
		f2 = func(x2);

		if (f1 < f2) {
			b = x2;
			fb = f2;
		} else {
			a = x1;
			fa = f1;
		}
		length = abs(b - a);
	}

	double x_min = (b + a) / 2;
	return x_min;
}

int main() {
	double x, min;
	x = minimum_by_golden_ratio(-15, 15, 0.001);
	min = func(x);
	cout << "x: " << x << ", min: " << min << endl;
	return 0;
}