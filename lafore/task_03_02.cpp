// task_03_02.cpp
// перевод градусов Цельсия в градусы Фаренгейта и наоборот
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int action;
	double temp_celsius, temp_fahrenheit;
	do
	{
		cout
		<< endl
		<< "Выберите действие" << endl
		<< "1) Перевод из шкалы Цельсия в шкалу Фаренгейта" << endl
		<< "2) Перевод из шкалы Фаренгейта в шкалу Цельсия" << endl
		<< "0) Выход" << endl;
		cin >> action;

		switch (action)
		{
			case 1:
				cout << "Температура в градусах Цельсия: ";
				cin >> temp_celsius;
				temp_fahrenheit = temp_celsius * 9 / 5 + 32;
				cout << "Температура в градусах Фаренгейта: " << temp_fahrenheit << endl;
				break;
			case 2:
				cout << "Температура в градусах Фаренгейта: ";
				cin >> temp_fahrenheit;
				temp_celsius = (temp_fahrenheit - 32) * 5 / 9;
				cout << "Температура в градусах Цельсия: " << temp_celsius << endl;
				break;
			case 0:
				cout << "Пока!" << endl;
				break;
			default:
				cout << "Попробуйте ещё раз..." << endl;
		}
	}
	while (action);

	return 0;
}
