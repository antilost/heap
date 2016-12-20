// referst.cpp
//
#include <iostream>

using namespace std;


struct Distance {
	long feet;
	double inches;
};

void fill_dist( Distance& dist );
void scale ( Distance& dist, double scale_coef );
void disp_dist( Distance dist );
void norm_dist( Distance& dist );

int main() {
	Distance d1, d2;
	
	cout << "Fill the first distance" << endl;
	fill_dist( d1 );

	cout << "Fill the 2nd distance" << endl;
	fill_dist( d2 );

	cout << "0. d1: "; disp_dist(d1); cout << endl;
	cout << "0. d2: "; disp_dist(d2); cout << endl;

	scale( d1, 3.5 );
	scale( d2, 0.75 );


	cout << "1. d1: "; disp_dist(d1); cout << endl;
	cout << "1. d2: "; disp_dist(d2); cout << endl;
	return 0;
}


void fill_dist( Distance& dist ) {
	cout << "Feet count: ";
	cin >> dist.feet;
	cout << "Inches count: ";
	cin >> dist.inches;

	norm_dist(dist);
}

void scale ( Distance& dist, double scale_coef ) {
	dist.feet *= scale_coef;
	dist.inches *= scale_coef;

	norm_dist(dist);
}

void disp_dist( Distance dist ) {
	cout << dist.feet << "'-" << dist.inches << "''";
}

void norm_dist( Distance& dist ) {
	if (dist.inches >= 12) {
		dist.feet += static_cast<long>(dist.inches / 12);
		dist.inches = static_cast<long>(dist.inches) % 12;
	}
}