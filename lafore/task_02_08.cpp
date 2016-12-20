#include <iostream> // cout
#include <iomanip> // setw, setfill

using namespace std;

int main()
{
	long pop1 = 8425785, pop2 = 47, pop3 = 9761;

	cout
	<< setw(10) << "Население" << setw(12) << "Город" << endl
	<< setfill('.')
	<< setw(10) << "Москва"    << setw(12) << pop1    << endl
	<< setw(10) << "Киров"     << setw(12) << pop2    << endl
	<< setw(10) << "Угрюмовка" << setw(12) << pop3    << endl;

	return 0;
}
