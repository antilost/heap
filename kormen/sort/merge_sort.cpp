// Merge sort

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const long N = 10;

void merge_sort(long a[], int p, int r) {
	if (p >= r) {
		// sequence to sort is small enough (1 element only) to be already sorted
		return;
	}

	int q = (p + r) / 2;
	merge_sort(a, p, q);
	merge_sort(a, q + 1, r);

	int size = r - p + 1;
	long tmp[size];
	int i, j, k;
	i = p;
	j = q + 1;
	k = 0;
	while ( i <= q || j <= r ) {
		if ( i <= q && ( j > r || a[i] < a[j] ) ) {
			tmp[k] = a[i]; i++; k++;
		} else {
			tmp[k] = a[j]; j++; k++;
		}
	}

	for (int i = 0; i < size; i++)
		a[p + i] = tmp[i];
}

void fill_array_with_random_numbers(long[] );
void print_array(long[]);

int main() {
	long a[N];
srand( 100 );
	fill_array_with_random_numbers(a);
	print_array(a);
	merge_sort(a, 0, N - 1);
	print_array(a);
	return 0;
}

void fill_array_with_random_numbers(long a[]) {
	for (int i = 0; i < N; i++)
		a[i] = rand() % 100;
}

void print_array(long a[]) {
	for (int i = 0; i < N; i++) {
		cout << setiosflags( ios::fixed ) << setiosflags( ios::showpoint ) << setprecision( 2 ) << setw( 3 ) << a[i];
	}
	cout << endl;
}
