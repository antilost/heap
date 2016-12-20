// Напишите программу, выводяющую таблицу
// 1990   135
// 1991  7290
// 1992 11300
// 1993 16200

using namespace std;

#include <iostream>
#include <iomanip>

int main()
{
	cout
	<< 1990 << " " << setw(10) << 135 << endl
	<< 1991 << " " << setw(10) << 7290 << endl
	<< 1992 << " " << setw(10) << 11300 << endl
	<< 1993 << " " << setw(10) << 16200 << endl
	<< endl;

	return 0;
}
