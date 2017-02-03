#include <iostream>
#include <iomanip>

#include <cstdlib> // include "stdlib.h" C-library
#include <ctime>   // include "time.h"

using namespace std;
const long N = 10;
const long D = 5;
int main() {
	// RAND_MAX is system-dependent constant
	cout << "Max. rand() result is " << RAND_MAX << endl;

	long a = rand();
	cout << "a always is " << a << endl;

	// Init. random generator by time()
	// Being called as time(NULL) it return number for seconds from 1970-01-01 00:00:00 
	srand(time(NULL));

	long b[N];
	for (int i = 0; i < N; i++) {
		b[i] = rand() % 100;
	}

	// Print array b
	cout << "Array b: ";
	for (int i = 0; i < N; i++)
		cout << b[i] << " ";
	cout << endl;

	// Init. with user-defined number
	srand( 0 );
	double m[D][D];
	for (int i = 0; i < D; i++)
		for (int j = 0; j < D; j++)
			m[i][j] = static_cast<double>(rand() % 1000) / 10;

	// Print matrix m
	cout << "Matrix m is" << endl;
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < D; j++) {
			cout << setiosflags( ios::fixed ) << setiosflags( ios::showpoint ) << setprecision( 2 ) << setw( 6 );
			cout << m[i][j];
		}
		cout << endl;
	}

	return 0;
}