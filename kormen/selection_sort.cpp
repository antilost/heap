// Task 2.2.2
// Selection sort

#include <iostream>
#include <cstdlib>

using namespace std;

const long N = 10;

void fill_array_with_random_numbers(long[] );
void print_array(long[]);
void selection_sort(long[]);

int main() {
	long a[N];
	fill_array_with_random_numbers(a);
	print_array(a);
	selection_sort(a);
	print_array(a);
	return 0;
}

void fill_array_with_random_numbers(long a[]) {
	for (int i = 0; i < N; i++)
		a[i] = rand() % 100;
}

// 'inline' means that each function call will be replaced with function text while compiling
inline void swap(long& a, long &b) {
	long tmp = a;
	a = b;
	b = tmp;
}

void selection_sort(long a[]) {
	for (int i = 0; i < N; i++) {
		long index_min = i;
		for (int j = i + 1; j < N; j++)
			if (a[j] < a[index_min])
				index_min = j;

		swap( a[i], a[index_min] );
	}
}

void print_array(long a[]) {
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
