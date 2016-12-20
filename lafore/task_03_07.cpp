// task_03_07.cpp
// Расчёт суммы вклада
#include <iostream>
using namespace std;
int main()
{
	double init_sum, rate; // contribution sum and rate
	int duration;          // contribution duration, years

	cout << "Введите начальный вклад: $";
	cin >> init_sum;
	cout << "Введите количество лет: ";
	cin >> duration;
	cout << "Введите процентную ставку: ";
	cin >> rate;

	double sum = init_sum;
	for (int i = 0; i < duration; i++)
		sum += sum * rate / 100;

	cout << "Через " << duration << " лет вы получите $" << sum << " (доход составит $" << (sum - init_sum) << ")" << endl;

	return 0;
}
