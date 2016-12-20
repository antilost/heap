// Heap

#include <iostream>

using namespace std;

const long N = 10;

class Heap {
	private:
		int _size;
		long _heap[N];

	public:
		Heap() : _size(0) {
			for (int i = 0; i < N; i++) {
				_heap[i] = 0;
			}

//			for (int i = 1; i < N + 1; i++) {
//				cout << i << " p: " << parent(i) << " left: " << left(i) << " right: " << right(i) << endl;
//			}
		}
		~Heap() {
			
		}

		int insert(long new_value) {
			if (_size >= N) {
				// heap already is full
				return 1;
			}

			_size++;
			int i = _size;
//			cout << "i: " << i << ": " << _heap[i - 1] << ", size: " << _size << ", parent: " << parent(i) << ": " << _heap[ parent(i) - 1 ] << endl;
			while (i > 1 && _heap[parent(i) - 1] < new_value) {
//				cout << "i: " << i << ": " << _heap[i - 1] << ", size: " << _size << ", parent: " << parent(i) << ": " << _heap[ parent(i) - 1 ] << endl;

				_heap[i - 1] = _heap[parent(i) - 1];
				i = parent(i);
			}
			_heap[i - 1] = new_value;

			return 0;
		}
		
		int parent(int i) {
			return i / 2;
		}

		int left(int i) {
			return 2 * i;
		}

		int right(int i) {
			return 2 * i + 1;
		}

		void show() {
			if (_size == 0) {
				cout << "Heap is empty" << endl;
				return;
			}

			for (int i = 0; i < _size - 1; i++) {
				cout << _heap[i] << ", ";
			}
			cout << _heap[_size - 1] << endl;
		}
};

int main(void) {
	Heap h;

	while (1) {
		long n;
		cout << "Input new value or '0' to exit: ";
		cin >> n;
		
		if (n < 1) {
			break;
		}

		h.insert(n);
		h.show();
		cout << endl;
	}
	
	return 0;
}
