// task_04_09.cpp
// Количество секунд в введенном времени

#include <iostream>

using namespace std;

struct my_time {
	int hours, minutes, seconds;
};

int main()
{
	my_time t;
	char dummy_char;

	cout << "Input time as HH:MM:SS: ";
	cin >> t.hours >> dummy_char >> t.minutes >> dummy_char >> t.seconds;

	long all_seconds = 60 * ( 60 * t.hours + t.minutes ) + t.seconds;
	cout << "Your time " << t.hours << ":" << t.minutes << ":" << t.seconds << " has " << all_seconds << " sec." << endl;
	
	return 0;
}
