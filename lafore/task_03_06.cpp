// task_03_06.cpp
// подсчёт факториала числа с помощью цикла for
#include <iostream>
using namespace std;
int main()
{
	while (1)
	{
		unsigned int numb;
		unsigned long fact = 1;         // тип long для результата
		cout << "Введите целое число: ";
		cin >> numb;                    // ввод числа для вычисления факториала

		if (!numb)
			break;

		for (int j = numb; j > 0; j--)  // умножение j на
			fact *= j;                  // numb, numb-1, ..., 2, 1

		cout << "Факториал числа равен: " << fact << endl;
	}
	return 0;
}
