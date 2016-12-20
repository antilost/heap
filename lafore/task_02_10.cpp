// Устаревшая денежная система Великобритании: фунты, шиллинги и пенсы
// 1 фунт равен 20 шиллингам
// 1 шиллинг равен 12 пенсам
// Пример, J5.2.8 --- 5 фунтов, 2 шиллинга и 8 пенсов

// Современная денежная система Великобритании: фунты и пенсы
// 1 фунт равен 100 пенсам (десятичный фунт)

#include <iostream>

using namespace std;

void show_old_system_sum(int pounds, int shillings, int pence)
{
	cout << "J" << pounds << "." << shillings << "." << pence << endl;
}

int main()
{
	int old_pounds, old_shillings, old_pence, new_pounds, new_pence, all_pence;

	cout << "Input old-system sum," << endl;
	
	cout << "\tpounds: ";
	cin >> old_pounds;

	cout << "\tshillings: ";
	cin >> old_shillings;

	cout << "\tpence: ";
	cin >> old_pence;

	show_old_system_sum(old_pounds, old_shillings, old_pence);

	// Количество фунтов не меняется, меняется ценность пенсов
	// Один фунт равен 100 новых пенсов или 240 старых
	// 12 * 20 * o = 100 * n
	// n = 12 * 20 / 100 * 0
	all_pence = old_shillings * 12 + old_pence;
	new_pounds = old_pounds;
	new_pence = static_cast<double>(all_pence) / (12.0 * 20.0 / 100);
	cout << "Decimal system: " << new_pounds << " pounds and " << new_pence << " pence" << endl;

	return 0;
}