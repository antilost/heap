#include <iostream>
#include <cstdlib>

using namespace std;

void print_array(long[]);
void insertion_sort(long[]);

const long N = 10;

int main() {
	long a[N];

	for (int i = 0; i < N; i++)
		a[i] = rand() % 100;

	print_array(a);

	insertion_sort(a);

	print_array(a);

	return 0;
}

void insertion_sort(long a[]) {
	for (int i = 1; i < N; i++) {
		long key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void print_array(long a[]) {
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
