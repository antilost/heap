#include <iostream>
#include <string>
#include <map>
#include <cmath> // max
#include <cassert>

// get sum of two hex numbers
// result is presented as hex number too

using namespace std;

int char_to_num(char c) {
    if ( ('a' <= c) && (c <= 'f') ) {
        return 10 + (c - 'a');
    }

    return c - '0';
}

char num_to_char(int num) {
    if ( (0 <= num) && (num <= 9) ) {
        return static_cast<char>( '0' + num );
    }

    return static_cast<char>( 'a' + (num - 10) );
}

string sum(string a, string b) {
    string r = "";
    
    int i, j;
    i = a.length() - 1;
    j = b.length() - 1;
    int sum = 0;
    while ( (i >= 0) || (j >= 0) ) {
        int a_i = (i >= 0 ) ? char_to_num(a[i]) : 0;
        int b_j = (j >= 0 ) ? char_to_num(b[j]) : 0;

        sum += (a_i + b_j);

        r = num_to_char( sum % 16 ) + r;

        sum /= 16;
        
        i--;
        j--;
    }

    if (sum > 0) {
        r = num_to_char(sum) + r;
    }

    return r;
}

int main(void) {
    //string s1, s2;
    //cin >> s1 >> s2;

   // string result = sum(s1, s2);
   // cout << result << endl;

    assert( sum("fed", "13") == "1000" );
    assert( sum("e", "1") == "f");
    assert( sum("e", "0") == "e");
    assert( sum("2", "e") == "10");   
    return 0;
}
