/*
 * Find sub-array with minimal length that contains every characters than one can find at this array
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    string src = "bcbacabadbaa"; // cabad
    
    map<char, int> m;
    
    int left, right;
    left = right = -1;
    for (int i = 0; i < src.size(); i++) {
        char c = src[i];
        if (left < 0) {
            left = right = i;
            m[c] = 1;
            continue;
        }

        map<char, int>::iterator it = m.find(c);
        if (it == m.end()) {
            m[c] = 0;
            for (int j = right + 1; j < i + 1; j++) {
                m[ src[j] ]++;
            }
            right = i;
        }
    }

    for (int i = left; i <= right; i++) {
        char c = src[i];
        if (m[c] == 1) {
            break;
        }

        m[c]--;
        left++;
    }

    for (int i = left; i <= right; i++) {
        cout << src[i];
    }
    cout << endl;

    return 0;
}
