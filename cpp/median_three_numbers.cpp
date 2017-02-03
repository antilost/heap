//17:22, 17:27
#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cout << "a: "; cin >> a;
	cout << "b: "; cin >> b;
	cout << "c: "; cin >> c;
	
	int result = -1;
	if (a < b) {
		if (a < c) {
			result = (b < c) ? b : c;
		} else {
			result = a;
		}
	} else {
		if (b < c) {
			result = (a < c) ? a : c;
		} else {
			result = b;
		}
	}

	cout << "result: " << result << endl;

	return 0;
}
