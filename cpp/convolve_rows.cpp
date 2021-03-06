/*
 * Convolve integer rows list
 */

// g++ convolve_rows.cpp --std=c++11

#include <iostream>
#include <vector>
//#include <algorithm>
#include <string>

using std::sort;

using namespace std;

string get_convolved_row(vector<int>& v);

int main(void) {
    int count;
    cin >> count;
    vector<int> v(count);

    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }

    string result = get_convolved_row(v);
    cout << result << endl;

    return 0;
}

string get_convolved_row(vector<int>& v) {
    if (!v.size()) {
        return "";
    }

    sort(v.begin(), v.end());

    string r = to_string(v[0]);
    int i = 1;
    bool more_than_one = false;
    while (i < v.size()) {
        if (v[i] - v[i - 1] > 1) {
            if (more_than_one) {
                r += '-';
                r += to_string(v[i-1]);
            }
            r += ',';

            r += to_string(v[i]);
            more_than_one = false;
        } else {
            more_than_one = true;
        }
        i++;
    }
    if (more_than_one) {
        r += '-';
        r += to_string(v[i-1]);
    }

    return r;
}
