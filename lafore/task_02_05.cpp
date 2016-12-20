#include <iostream>
#include <cctype> // Для использования islower(), ctype.h

using namespace std;

int main()
{
	char letter;
	cout << "Letter: ";
	cin >> letter;

	// islowe(): в качестве аргумента принимает символьную переменную и возвращает ненулевое значение для строчных букв; иначе, 0
	cout << "islower(): " << islower(letter) << endl;

	return 0;
}
