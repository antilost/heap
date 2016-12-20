// call_main.cpp
// вызов функции main (рекурсия с использованием глобальной переменной-счётчика)
#include <iostream>
using namespace std;
int global_count = 10;
int main()
{
	cout << "global_count: " << global_count << endl;

	if (!global_count)
		return 0;

	global_count--;
	main();
}
