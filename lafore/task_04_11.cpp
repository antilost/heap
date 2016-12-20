// task_04_11.cpp
// Сложение времени

#include <iostream>

using namespace std;

struct my_time {
	int hours, minutes, seconds;
};

int main()
{
	my_time t1, t2, t_sum;
	char dummy_char;

	cout << "Input time1 as HH:MM:SS: ";
	cin >> t1.hours >> dummy_char >> t1.minutes >> dummy_char >> t1.seconds;

	cout << "Input time2 as HH:MM:SS: ";
	cin >> t2.hours >> dummy_char >> t2.minutes >> dummy_char >> t2.seconds;

	long all_seconds1 = 60 * ( 60 * t1.hours + t1.minutes ) + t1.seconds;
	long all_seconds2 = 60 * ( 60 * t2.hours + t2.minutes ) + t2.seconds;

	long all_seconds_sum = all_seconds1 + all_seconds2;
	t_sum.hours = all_seconds_sum / 3600;
	t_sum.minutes = (all_seconds_sum % 3600) / 60;
	t_sum.seconds = all_seconds_sum % 60;

	cout << "Time 1: " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << " has " << all_seconds1 << " sec." << endl;
	cout << "Time 2: " << t2.hours << ":" << t2.minutes << ":" << t2.seconds << " has " << all_seconds2 << " sec." << endl;
	cout << "Time sum: " << t_sum.hours << ":" << t_sum.minutes << ":" << t_sum.seconds << " has " << all_seconds_sum << " sec." << endl;
	
	return 0;
}
