#include <iostream>

using namespace std;

int get_highest_common_factor(int a, int b)
{
	int hcf = (a < b) ? a : b;
	do
	{
		if (a % hcf == 0 && b % hcf == 0)
			break;
	}
	while (hcf--);

	return hcf;
}

int main()
{
	int frac1_num, frac1_den, frac2_num, frac2_den, result_frac_num, result_frac_den;
	char char_to_skip;

	cout << "Первая дробь: ";
	cin >> frac1_num >> char_to_skip >> frac1_den;

	cout << "Вторая дробь: ";
	cin >> frac2_num >> char_to_skip >> frac2_den;

	result_frac_num = frac1_num * frac2_den + frac2_num * frac1_den;
	result_frac_den = frac1_den * frac2_den;
	cout << "Результат: " << result_frac_num << "/" << result_frac_den << endl;

	int hcf = get_highest_common_factor(result_frac_num, result_frac_den);
	result_frac_num /= hcf;
	result_frac_den /= hcf;
	cout << "Результат: " << result_frac_num << "/" << result_frac_den << endl;

	return 0;
}
