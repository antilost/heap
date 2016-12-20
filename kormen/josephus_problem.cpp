//
// Josepus problem
//
// People are standing in a circle waiting to be executed.
// Counting begins at a specified point in the circle and proceeds around the circle in a specified direction.
// After a specified number of people are skipped, the next person is executed.
// The procedure is repeated with the remaining people, starting with the next person,
// going in the same direction and skipping the same number of people, until only one person remains, and is freed.
// The problem — given the number of people, starting point, direction,
// and number to be skipped — is to choose the position in the initial circle to avoid execution.
//
// Here below code that represents solution for common case: people count is variable n, step is variable m, consequently
//

// Example
// 1 2 3 4 5 6 7	(-1 + 0 + 3) % 7 = 2 => 3
// 1 2 4 5 6 7		(-1 + 2 + 3) % 6 = 4 => 6
// 1 2 4 5 7		(-1 + 4 + 3) % 5 = 1 => 2
// 1 4 5 7			(-1 + 1 + 3) % 4 = 3 => 7
// 1 4 5			(-1 + 3 + 3) % 3 = 2 => 5
// 1 4				(-1 + 2 + 3) % 2 = 0 => 1
// 4				(-1 + 0 + 3) % 1 = 0 => 4
//
// 3 6 2 7 5 1 4

#include <iostream>

void print_array(int& array, int length, char separator);

int main(int argc, char** argv) {
	// Check and get arguments via converting argv values
	if (argc < 3) {
		std::cout << "Insufficient number of parameters (required 3, got " << argc << ")" << std::endl;

		return 1;
	}

	int m, n;
	m = std::stoi( argv[1] );
	n = std::stoi( argv[2] );


	// Check m, n got
	if (m > n) {
		std::cout << "Incorrect parameters: m = " << m << " is greater than n = " << n << std::endl;

		return 1;
	}

	if ( !(m > 0) ) {
		std::cout << "Incorrect parameters: m = " << m << " is less than zero" << std::endl;

		return 1;
	}

	if ( !(m > 0) ) {
		std::cout << "Incorrect parameters: m = " << m << " is less than zero" << std::endl;

		return 1;
	}


	// Initialize alive_people array
	int* alive_people;
	alive_people = new int[n];
	for (int i = 0; i < n; i++)
		alive_people[i] = i + 1;


	// Calculate permutation
	// O(n * log(n) )
	int* permutation;
	permutation = new int[n];
	int j = 0;
	int alive_people_count = n;
	int new_member_index = 0;
	for (int i = 0; i < n; i++) {
		new_member_index = (-1 + new_member_index + m) % alive_people_count;

		permutation[j++] = alive_people[new_member_index];

		for (int k = new_member_index; k < alive_people_count - 1; k++) {
			alive_people[k] = alive_people[k + 1];
		}
		alive_people_count--;
	}

	delete(alive_people);

	std::cout << "Josephus permutation (" << m << ", " << n << "):";
	print_array(*permutation, n, ' ');

	delete(permutation);

	return 0;
}

void print_array(int& array, int length, char separator) {
	for (int i = 0; i < length; i++)
		std::cout << separator << (&array)[i];
	std::cout << std::endl;
}
