#include <iostream>

using namespace std;

int main() {
	void intfrac(double number, double& int_part, double& frac_part);

	cout << "Started" << endl;

	double number;
	do
	{
		cout << "Input new number: ";
		cin >> number;
		double int_part, frac_part;
		intfrac(number, int_part, frac_part);
		cout << "Integer part is " << int_part << endl;
		cout << "Fractional part is " << frac_part << endl;
		cout << "(number is still the same: " << number << ")" << endl;
	}
	while (number != 0.0);

	cout << "Finished" << endl;

	return 0;
}

void intfrac(double number, double& int_part, double& frac_part)
{
	long tmp = static_cast<long>(number);
	int_part = static_cast<double>(tmp);	
	frac_part = number - tmp;

	number = 42; // try to change number
}
