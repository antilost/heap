// task_03_01.cpp
// Таблица 20x10 умножения на заданное число
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cout << "Введите число: ";
	cin >> n;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << setw(4) << n * (i * 10 + j + 1) << " ";
		cout << endl;
	}

	return 0;
}