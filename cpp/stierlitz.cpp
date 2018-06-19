/*
 * Decoder
 * Source string encoded via algorithm:
 * 1. Remove all spaces, commas and dots
 * 2. Replace every sequence of several times repeated letter with only one that letter
 * 3. Inserted doubled letters at random places
 */

#include <iostream>

using namespace std;

int main(void) {
    string s = "wwstdaadierfflitzzmjjrtypozllzopytrffmz"; // stierlitz
    cout << s << endl;
    
    int write_to;
    for (int i = 0; i < s.size(); i++) {
        char now = s[i];
        if (write_to == 0 || now != s[write_to - 1]) {
            s[write_to] = now;
            write_to++;
        } else if (write_to > 0 && s[write_to - 1] == now) {
            write_to--;
        }
    }
    s.resize(write_to);

    cout << s << endl;

    return 0;    
}
