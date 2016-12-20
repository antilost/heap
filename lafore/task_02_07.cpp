#include <iostream>

// no 'using namespace std'

int main()
{
	double t_celsius, t_fahrenheit;

	std::cout << "Temperature Celsius: ";
	std::cin >> t_celsius;

	t_fahrenheit = t_celsius * 9 / 5 + 32;
	std::cout << "Temperature Fahrenheit: " << t_fahrenheit << std::endl;

	return 0;
}
