#include <iostream>
using namespace std;
int main()
{
	char end, dummy_char;
	do
	{
		char operation;
		double operand1, operand2;
		cout << "Введите первый операнд, операцию и второй операнд: ";
		cin >> operand1 >> operation >> operand2;

		float result;
		switch (operation)
		{
			case '+':
				result = operand1 + operand2; break;
			case '-':
				result = operand1 - operand2; break;
			case '*':
				result = operand1 * operand2; break;
			case '/':
				result = operand1 / operand2; break;
			default:
				cout << "Неверная операция, попробуйте ещё раз" << endl;
		}

		if (operation == '+' || operation == '-' || operation == '*' || operation == '/')
			cout << "Результат: " << operand1 << " " << operation << " " << operand2 << " = " << result << endl;

		cout << "Выполнить ещё одну операцию (y/n): ";
		cin >> end;
	}
	while (end == 'y' || end == 'Y');

	cout << endl;

	return 0;
}