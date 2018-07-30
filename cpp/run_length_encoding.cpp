#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string rle(string str) {
    string result = "";
    char prev = '0';
    int count = 0;
    int r = 0;
    while (1) {
        if (str[r] == prev) {
            count++;
        }
        
        if (str[r] != prev) {
            if (count) {
                result += prev;
                if (count > 1) {
                    result += to_string(count);
                }
            }
            count = 1;
            prev = str[r];
        }

        r++;

        if (r >= str.size()) {
            result += prev;
            if (count > 1) {
                result += to_string(count);
            }
            break;
        }

    }

    return result;
}

int main(void) {
    assert(rle("AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB") == "A4B3C2XYZD4E3F3A6B28");
    assert(rle("BBBBBBBBBBB") == "B11");
    assert(rle("ABC") == "ABC");
    return 0;
}