// Считая, что кубический фут равен 7,481 галлона, написать программу,
// запрашивающую у пользователя число галлонов и выводящую на экран
// эквивалентный объём в кубических футах

using namespace std;

#include <iostream> // cout, cin

int main()
{
	double gallons, cubic_feet;

	cout << "Gallons: ";
	cin >> gallons;
	cubic_feet = 7.481 * gallons;
	cout << "Cubic feet: " << cubic_feet << endl;

	return 0;
}
