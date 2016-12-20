// task_03_09.cpp
// Количество способов разместить N гостей по M мест (M <= N)
#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cout << "Введите количество гостей: ";
	cin >> n;
	cout << "Введите количество мест: ";
	cin >> m;

	if (m > n)
	{
		cout << "Мест больше, чем гостей (" << m << " > " << n << ")" << endl;

		return 0;
	}

	int placements_count = 1;
	while (m--)
		placements_count *= n--;

	cout << "Число способов разместить гостей " << placements_count << endl;

	return 0;
}
