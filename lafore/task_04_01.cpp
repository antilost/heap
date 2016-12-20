// task_04_01.cpp
// Телефонные номера

#include <iostream>

using namespace std;

struct phone {
	int city_code, station, number;
};

int main()
{
	phone my = { 495, 125, 1717 }, other;

	char skip_char;
	cout << "Введите свой номер в формате DDD-DDD-DDDD: ";
	cin >> other.city_code >> skip_char
		>> other.station >> skip_char
		>> other.number;

	cout << "Мой номер: (" << my.city_code << ") " << my.station << "-" << my.number << endl;
	cout << "Ваш номер: (" << other.city_code << ") " << other.station << "-" << other.number << endl;

	return 0;
}
