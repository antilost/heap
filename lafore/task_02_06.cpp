#include <iostream>

using namespace std;

int main()
{
	double
	pound_to_dollar_ratio = 1.487,
	franc_to_dollar_ratio = 0.172,
	mark_to_dollar_ratio = 0.584,
	yen_to_dollar_ratio = 0.00955;

	double sum_dollars;
	cout << "Sum ($): ";
	cin >> sum_dollars;

	cout << "Pounds: " << sum_dollars / pound_to_dollar_ratio << endl;
	cout << "Francs: " << sum_dollars / franc_to_dollar_ratio << endl;
	cout << "Marks:  " << sum_dollars / mark_to_dollar_ratio << endl;
	cout << "Yen:    " << sum_dollars / yen_to_dollar_ratio << endl;

	return 0;
}
